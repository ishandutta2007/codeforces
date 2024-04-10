#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ii pair <int, int>
#define app push_back
#define all(a) a.begin(), a.end()
#define bp __builtin_popcountll
#define ll long long
#define mp make_pair
#define f first
#define s second
#define Time (double)clock()/CLOCKS_PER_SEC
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    int n;
    cin >> n;
    vector <ii> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i].f;
        a[i].s = i + 1;
    }   
    sort(all(a));
    const int INF = 5e18;
    vector <int> dp(n + 1, INF);
    dp[0] = 0;
    for (int i = 1; i <= n; ++i) {
        for (int r = 3; r <= 10 && r <= i; ++r) {
            dp[i] = min(dp[i], dp[i - r] + a[i - 1].f - a[i - r].f);
        }   
    }   

    vector <int> ans(n + 1);
    int i = n;
    int num = 1;
    while (i) {
        for (int r = 3; ; ++r) {
            if (dp[i] == dp[i - r] + a[i - 1].f - a[i - r].f) {
                for (int j = i - 1; j >= i - r; --j)
                    ans[a[j].s] = num;
                ++num;
                i -= r;
                break;
            }   
        }   
    }   

    cout << dp[n] << ' ' << num - 1 << endl;
    for (int i = 1; i <= n; ++i)
        cout << ans[i] << ' ';
    cout << endl;
}