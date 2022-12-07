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

int tt, m, k;
int a[100005];
int t[100005], r[100005];
char ans[100005];
int zc, zzc;
bool f[100005];

int main() {
    scanf("%d", &tt);
    REP(test, tt) {
        zc = zzc = 0;
        scanf("%d%d", &m, &k), --m;
        REP(i, k) scanf("%d", a + i);
        REP(i, m) scanf("%d%d", t + i, r + i), --t[i];
        int pos = -1;
        REP(i, m) if (r[i] == 1) {
            pos = i;
            break;
        }
        REP(i, k) f[i] = true;
        REP(i, m) {
            if (t[i] != -1) {
                --a[t[i]];
                if (i >= pos) f[t[i]] = false;
            } else {
                ++zc;
                if (i < pos) ++zzc;
            }
        }
        if (pos == -1) {
            REP(i, k) {
                if (zc >= a[i]) ans[i] = 'Y';
                else ans[i] = 'N';
            }
        } else {
            int best = 2e9;
            REP(i, k) if (f[i] && a[i] <= zzc)
                best = min(best, a[i]);
            REP(i, k) {
                if (f[i] && a[i] <= zzc) {
                    ans[i] = 'Y';
                    continue;
                }
                if (a[i] <= zc - best) {
                    ans[i] = 'Y';
                } else {
                    ans[i] = 'N';
                }
            }
        }
        ans[k] = '\0';
        printf("%s\n", ans);
    }
    return 0;
}