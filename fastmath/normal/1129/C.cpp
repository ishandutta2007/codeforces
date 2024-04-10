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
#define lb lower_bound
#define ub upper_bound
#define Time (double)clock()/CLOCKS_PER_SEC
const int N = 3007, MOD = 1000 * 1000 * 1000 + 7;
int preff(string s) {
    reverse(all(s));
    int n = (int) s.length();
    vector<int> pi (n);
    int mx = 0;
    for (int i=1; i<n; ++i) {
        int j = pi[i-1];
        while (j > 0 && s[i] != s[j])
            j = pi[j-1];
        if (s[i] == s[j])  ++j;
        pi[i] = j;
        mx = max(mx, pi[i]);
    }
    return mx;
}   
int dp[N];
set <string> ban = { "0011", "0101", "1110", "1111" };
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    int n; cin >> n;
    dp[0] = 1;
    string s;
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        char c; cin >> c;
        s += c;
        int p = preff(s);
        string post;
        for (int j = i; j; --j) {
            post += s[j - 1];
            dp[post.size()] = 0;
            for (int len = 1; len <= 4 && len <= post.size(); ++len) {
                string c = post.substr(post.size() - len, len);
                reverse(all(c));
                if (ban.find(c) == ban.end()) dp[post.size()] += dp[post.size() - len];
                dp[post.size()] %= MOD;
            }   
            if (post.size() > p) ans += dp[post.size()];
        }   
        ans %= MOD;
        cout << ans << '\n';
    }   
}