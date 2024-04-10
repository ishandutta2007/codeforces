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

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define foreach(e, x) for (__typeof(x.begin()) e = x.begin(); e != x.end(); e++)
typedef long long LL;
typedef pair<int, int> PII;

int n, m, k;
LL ans = 0;

int main() {
    cin >> n >> m >> k;
    if (k > 100000) {
        for (int i = 1; i <= 100000; ++i) {
            int kk = n / i - 1;
            if (kk == -1) break;
            kk = min(k, kk);
            int mm = m / (k - kk + 1);
            ans = max(ans, (LL)i * mm);
        }
        swap(n, m);
        for (int i = 1; i <= 100000; ++i) {
            int kk = n / i - 1;
            if (kk == -1) break;
            kk = min(k, kk);
            int mm = m / (k - kk + 1);
            ans = max(ans, (LL)i * mm);
        }
    } else {
        REP(i, k + 1) {
            int nn = n / (i + 1);
            int mm = m / (k - i + 1);
            ans = max(ans, (LL)nn * mm);
        }
    }
    if (ans == 0) cout << -1 << endl;
    else cout << ans << endl;
    return 0;
}