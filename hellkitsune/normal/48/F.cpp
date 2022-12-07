#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#include <sstream>
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <map>
#include <set>
#include <list>
#include <queue>
#include <stack>
#include <vector>
#include <cassert>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n, m, W;
int w[500000], c[500000], a[500000];
pair<double, int> cc[500000];
long double ans = 0;
LL dans = 0;
int rem;

typedef unsigned long long ULL;
ULL MUL = 6364136223846793005ll;
ULL ADD = 1442695040888963407ll;
ULL randSeed = 1234567;

int myRand(int bound) {
    randSeed = MUL * randSeed + ADD;
    return (randSeed >> 32) % bound;
}

void getSome(int from, int to) {
    if (to - from == 1) {
        int ind = cc[from].second;
        long double cur = rem / (long double)w[ind];
        LL dcur = floor(cur);
        cur -= dcur;
        dans += dcur * c[ind];
        cur *= c[ind];
        LL tmp = floor(cur);
        dans += tmp;
        ans += cur - tmp;
        while (ans >= 1) {
            ans -= 1;
            ++dans;
        }
        return;
    }
    double mid = cc[from + myRand(to - from)].first;
    int l = from, r = to - 1;
    LL some = 0;
    while (l < r) {
        while (cc[l].first < mid) some += w[cc[l++].second];
        while (cc[r].first > mid) --r;
        if (l < r) {
            swap(cc[l], cc[r]);
            some += w[cc[l++].second];
            --r;
        }
    }
    if (l == r && cc[l].first < mid) {
        some += w[cc[l++].second];
    }
    if (some <= rem) {
        for (int i = from; i < l; ++i) {
            dans += c[cc[i].second];
            rem -= w[cc[i].second];
        }
        if (rem) {
            getSome(l, to);
        }
    } else {
        getSome(from, l);
    }
}

int main() {
    scanf("%d%d%d", &n, &m, &W);
    REP(i, m) scanf("%d", w + i);
    REP(i, m) scanf("%d", c + i);
    REP(i, m) scanf("%d", a + i);

    REP(i, n) {
        REP(j, m) cc[j] = mp(c[j] / (double)w[j], j);
        rem = W;
        getSome(0, m);
        if (i < n - 1) {
            REP(j, m) c[j] -= a[j];
        }
    }
    ostringstream oss;
    oss << setprecision(15) << fixed << (double)ans;
    string s = oss.str();
    while (s[0] != '.') s.erase(0, 1);
    printf("%I64d%s", dans, s.c_str());
    return 0;
}