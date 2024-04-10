#include <bits/stdc++.h>
using namespace std;

#define inf 1000000000
#define inf_ll 1000000000000000000ll
#define inf_ull 1000000000000000000ull
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb push_back

#ifdef ONLINE_JUDGE
#define debug(...)
#define fin cin
#else
#include "../../debug.cpp"
#endif

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    ll n, k; fin >> n >> k;
    string s; fin >> s;
    vector<ll> dp(n), p(n);
    for (ll i = n-1; i >= 0; i--) {
        if (s[i] == '1')
            p[i] = i;
        else
            p[i] = (i == n-1 ? -1 : p[i+1]);
    }
    multiset<ll> pre;
    for (ll i = 0; i < n; i++) {
        dp[i] = i+1+(i == 0 ? 0 : dp[i-1]);
        if (p[i] != -1 && p[i] <= i+k) {
            ll j = max(p[i]-k, 0ll);
            dp[i] = min(dp[i], p[i]+1+(j == 0 ? 0 : dp[j-1]));
        }
        if (pre.size() > 0)
            dp[i] = min(dp[i], *pre.begin());
        if (s[i] == '1') {
            ll j = max(i-k, 0ll);
            pre.insert(i+1+(j == 0 ? 0 : dp[j-1]));
        }
        if (i >= k && s[i-k] == '1') {
            ll j = max(i-2*k, 0ll);
            pre.erase(pre.find(i+1-k+(j == 0 ? 0 : dp[j-1])));
        }
    }
    cout << dp[n-1] << "\n";
}