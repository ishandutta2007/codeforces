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
typedef unsigned long long LL;
typedef pair<int, int> PII;

int n;
int a[3005];
bool si[3005];
char s[5005];
int sum[3005];
LL beg[3005], ed[3005];
vector<int> pos;
int lo, hi;

int main() {
    scanf("%s", s);
    pos.clear();
    n = (strlen(s) + 1) / 2;
    REP(i, n) {
        a[i] = s[2 * i] - '0';
        si[i] = i < n - 1 && s[2 * i + 1] == '*';
        if (si[i]) pos.pb(i);
    }
    sum[0] = 0;
    REP(i, n) sum[i + 1] = sum[i] + a[i];
    LL ans = 0;
    LL cur = 0, mul = 0;
    REP(i, n) {
        if (mul == 0) mul = a[i];
        else if (si[i - 1]) mul *= a[i];
        else {
            cur += mul;
            mul = a[i];
        }
        beg[i] = mul + cur;
    }
    cur = 0, mul = 0;
    for (int i = n - 1; i >= 0; --i) {
        if (mul == 0) mul = a[i];
        else if (si[i]) mul *= a[i];
        else {
            cur += mul;
            mul = a[i];
        }
        ed[i] = mul + cur;
    }
    pos.pb(12345);
    int lo = 0, hi = 0;
    REP(i, n) {
        if (i > pos[lo]) ++lo;
        hi = lo;
        for (int j = i; j < n; ++j) {
            if (j > pos[hi]) ++hi;
            cur = sum[j + 1] - sum[i];
            LL lastMul = 0;
            for (int z = lo; z < hi; ++z) {
                int ps = pos[z];
                if (z > lo && pos[z] == pos[z - 1] + 1) {
                    cur -= a[ps + 1] + lastMul;
                    lastMul *= a[ps + 1];
                    cur += lastMul;
                } else {
                    cur -= a[ps] + a[ps + 1];
                    cur += lastMul = a[ps] * a[ps + 1];
                }
            }
            int from = i - 1;
            while (from >= 0 && si[from]) {
                cur *= a[from];
                --from;
            }
            int to = j + 1;
            while (si[to - 1]) {
                cur *= a[to];
                ++to;
            }
            if (from >= 0) cur += beg[from];
            if (to < n) cur += ed[to];
            ans = max(ans, cur);
        }
    }
    cout << ans << endl;
    return 0;
}