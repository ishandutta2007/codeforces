#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ii pair <int, int>
#define app push_back
#define all(a) a.begin(), a.end()
#define bp __builtin_popcount
#define ll long long
#define mp make_pair
#define f first
#define s second
#define Time (double)clock()/CLOCKS_PER_SEC
const int N = 5007, INF = 1e18 + 7;
int dp[N], a[N];

int l[N], r[N];
bool used[N];

signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    for (int i = 0; i < N; ++i) {
        l[i] = N;
        r[i] = -1;
    }   
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        l[a[i]] = min(l[a[i]], i);
        r[a[i]] = max(r[a[i]], i);
    }   
    for (int i = 1; i <= n; ++i) {
        dp[i] = dp[i - 1];
        int cl = N, cr = -1;
        memset(used, 0, sizeof used);
        int cur = 0;
        for (int j = i; j >= 1; --j) {
            cl = min(cl, l[a[j]]);
            cr = max(cr, r[a[j]]);

            if (!used[a[j]]) {
                cur ^= a[j];
                used[a[j]] = 1;
            }
                                             
            if (cl == j && cr == i) {
                dp[i] = max(dp[i], dp[j - 1] + cur);
            }   
        }   
    }   
    cout << dp[n] << '\n';
}