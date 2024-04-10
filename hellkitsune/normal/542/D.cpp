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
#define foreach(e, x) for (__typeof(x.begin()) e = x.begin(); e != x.end(); ++e)
typedef long long LL;
typedef pair<int, int> PII;

LL n;
vector<pair<LL, int> > cnt, ncnt;
bool pp[1000003];
vector<int> p;

int main() {
    cin >> n;
    if (n == 1) {
        cout << 1 << endl;
        return 0;
    }
    cnt.pb(mp(n, 1));
    REP(i, 1000003) pp[i] = true;
    for (int i = 2; i < 1005; ++i) if (pp[i]) {
        for (int j = i * i; j < 1000003; j += i)
            pp[j] = false;
    }
    for (int i = 2; i < 1000003; ++i) if (pp[i])
        p.pb(i);
    int ans = 0;
    for (int pr : p) {
        bool flag = false;
        for (LL x = pr; x + 1 <= n; x *= pr) if (n % (x + 1) == 0) {
            flag = true;
            break;
        }
        if (!flag) continue;
        for (pair<LL, int> entry : cnt) {
            for (LL x = pr; x + 1 <= entry.first; x *= pr) if (entry.first % (x + 1) == 0) {
                if (entry.first == x + 1) {
                    ans += entry.second;
                } else {
                    ncnt.pb(mp(entry.first / (x + 1), entry.second));
                }
            }
        }
        if (!ncnt.empty()) {
            for (pair<LL, int> x : cnt) ncnt.pb(x);
            sort(ncnt.begin(), ncnt.end());
            cnt.clear();
            for (pair<LL, int> x : ncnt) if (x.first > pr + 1) {
                if (cnt.empty() || cnt.back().first != x.first)
                    cnt.pb(x);
                else
                    cnt.back().second += x.second;
            }
            ncnt.clear();
        }
    }
    for (pair<LL, int> x : cnt) if (!(x.first & 1) && x.first - 1 > p.back()) {
        LL y = x.first - 1;
        bool flag = true;
        for (int z : p) {
            if ((LL)z * z > y) break;
            if (y % z == 0) {
                flag = false;
                break;
            }
        }
        if (flag) ans += x.second;
    }
    printf("%d\n", ans);
    return 0;
}