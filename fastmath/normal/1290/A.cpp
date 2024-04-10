#include<bits/stdc++.h>
using namespace std;
#define ii pair <int, int>
#define app push_back
#define all(a) a.begin(), a.end()
#define bp __builtin_popcount
#define ll long long
#define mp make_pair
#define f first
#define s second
#define Time (double)clock()/CLOCKS_PER_SEC
const int N = 4007;
int a[N], val[N], mn[N][N];
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    int t;
    cin >> t;
    while (t--) {
        int n, m, k;
        cin >> n >> m >> k;
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
        }   
        int len = n - (m - 1);
        for (int i = 1; i + len - 1 <= n; ++i) {
            val[i] = max(a[i], a[i + len - 1]);
        }   
        int seg = n - len + 1;
        const int INF = 1e9 + 7;
        for (int i = 1; i <= seg; ++i) {
            mn[i][i - 1] = INF;
            for (int j = i; j <= seg; ++j)
                mn[i][j] = min(mn[i][j - 1], val[j]);
        }
        k = min(k, m - 1);
        int ans = 0;
        for (int l = 0; l <= k; ++l) {
            for (int r = 0; l + r <= k; ++r) {
                int lseg = l + 1;
                int rseg = (m - 1 - r) + 1;
                ans = max(ans, mn[lseg][rseg]);
            }   
        }   
        cout << ans << '\n';
    }
}