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
string a[3];
const int N = 501;
vector <ii> dp[N];
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        for (int i = 0; i < 3; ++i)
            cin >> a[i];
        for (int i = 0; i < N; ++i)
            dp[i].clear();
        for (int i = 0; i < 3; ++i) {
            if (a[i][0] == 's') {
                dp[0].app(mp(i, 0));
            }   
        }   
        string ans = "NO";
        for (int i = 0; i < N; ++i) {
            sort(all(dp[i]));
            dp[i].resize(unique(all(dp[i])) - dp[i].begin());
            for (ii p : dp[i]) {
                if (a[p.f][p.s] != 's' && a[p.f][p.s] != '.')
                    continue;
                if (i % 4 == 1) {
                    dp[i + 1].app(p);
                    if (p.f)
                        dp[i + 1].app(mp(p.f - 1, p.s));
                    if (p.f < 2)
                        dp[i + 1].app(mp(p.f + 1, p.s));
                }   
                else {
                    if (p.s == n - 1) {
                        ans = "YES";
                    }
                    else {
                        dp[i + 1].app(mp(p.f, p.s + 1));
                    }   
                }   
            }   
        }   
        cout << ans << '\n';
    }   
}