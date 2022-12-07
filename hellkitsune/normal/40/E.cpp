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

int n, m, k, mod;
int cnt[1000] = {}, prod[1000];

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> m >> k;
    if (n % 2 != m % 2) {
        cout << 0 << endl;
        return 0;
    }
    int g = 0;
    REP(i, 1000) prod[i] = 1;
    REP(i, k) {
        int a, b, c;
        cin >> a >> b >> c;
        if (n > m) {
            prod[a] *= c;
            if (++cnt[a] == m) {
                ++g;
                if (prod[a] == 1) {
                    cout << 0 << endl;
                    return 0;
                }
            }
        } else {
            prod[b] *= c;
            if (++cnt[b] == n) {
                ++g;
                if (prod[b] == 1) {
                    cout << 0 << endl;
                    return 0;
                }
            }
        }
    }
    cin >> mod;
    --n, --m;
    n = max(0, n * m - k + g);
    int ans = 1;
    REP(i, n) ans = (ans * 2) % mod;
    cout << ans << endl;
    return 0;
}