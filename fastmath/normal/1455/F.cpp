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
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;

        auto go = [&] (char c) {
            if (c == 'a')
                return 'a';
            else if (c == 'a' + k - 1)
                return 'a';
            else
                return (char)(c - 1);
        };  

        auto relax = [&] (string &a, string b) {
            if (a.empty())
                a = b;
            else
                a = min(a, b);
        };  

        vector <string> dp(n + 1);
        for (int i = 0; i < n; ++i) {
            relax(dp[i + 1], dp[i] + go(s[i]));
            if (dp[i].size()) {
                auto t = dp[i];
                t.pop_back();
                t += s[i];
                t += dp[i].back();
                relax(dp[i + 1], t);
            }   
            if (i + 1 < n) {
                if (dp[i].size()) {
                    auto t = dp[i];
                    t.pop_back();
                    t += s[i + 1];
                    t += dp[i].back();
                    t += s[i];
                    relax(dp[i + 2], t);
                }      
                auto t = dp[i];
                t += go(s[i + 1]);
                t += s[i];
                relax(dp[i + 2], t);
            }                       
        }   
        cout << dp[n] << endl;
    }   

}