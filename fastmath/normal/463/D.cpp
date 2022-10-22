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
#define debug(x) std::cout << #x << ": " << x << '\n';
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cout.setf(ios::fixed); cout.precision(20); 
    #endif

    int n, k;
    cin >> n >> k;
    vector <vector <int> > d(n);
    for (int i = 0; i < k; ++i) {
        vector <int> p(n);
        for (int j = 0; j < n; ++j) {
            cin >> p[j];
            d[p[j] - 1].app(j);
        }   
    }
    sort(all(d));

    vector <int> dp(n, 1);
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            bool c = 1;
            for (int t = 0; t < k; ++t) {
                c &= d[i][t] < d[j][t];
            }   
            if (c) {
                dp[j] = max(dp[j], dp[i]+1);
            }   
        }   
        ans = max(ans, dp[i]);
    }   
    cout << ans << endl;
}