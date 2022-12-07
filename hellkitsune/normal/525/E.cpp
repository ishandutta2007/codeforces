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

int n, k;
int a[25];
LL s, f[19];
bool flag = false;
int b[13], len;
map<pair<LL, int>, int> ma;
LL ans = 0;

void go(int pos, int kUsed, LL sum) {
    if (pos == len) {
        if (!flag) {
            ++ma[mp(sum, kUsed)];
        } else {
            for (int z = 0; z <= k - kUsed; ++z) {
                auto it = ma.find(mp(s - sum, z));
                if (it != ma.end()) {
                    ans += it->second;
                }
            }
        }
        return;
    }
    go(pos + 1, kUsed, sum);
    if (sum + b[pos] <= s) {
        go(pos + 1, kUsed, sum + b[pos]);
    }
    if (b[pos] <= 18 && kUsed < k && sum + f[b[pos]] <= s) {
        go(pos + 1, kUsed + 1, sum + f[b[pos]]);
    }
}

int main() {
    f[0] = 1;
    for (int i = 1; i <= 18; ++i) f[i] = f[i - 1] * i;
    cin >> n >> k >> s;
    REP(i, n) cin >> a[i];
    len = (n + 1) / 2;
    REP(i, len) b[i] = a[i];
    go(0, 0, 0ll);
    flag = true;
    REP(i, n - len) b[i] = a[len + i];
    len = n - len;
    go(0, 0, 0ll);
    cout << ans << endl;
    return 0;
}