#include <bits/stdc++.h>
using namespace std;

#define inf 1000000000
#define inf_ull 1000000000000000000
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define pb push_back

#ifdef ONLINE_JUDGE
#pragma GCC optimize ("O3")
#define debug(...)
#define fin cin
#else
#include "../../debug.cpp"
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
ifstream fin("../../input.in");
#define cin fin
#endif

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int t; fin >> t;
    while (t--) {
        int a, b, p; fin >> a >> b >> p;
        string s; fin >> s;
        int n = s.size();
        vector<int> dp(n+1, 0);
        dp[n-1] = 0;
        s[n-1] = '$';
        for (int i = n-2; i >= 0; i--) {
            if (s[i] == s[i+1])
                dp[i] = dp[i+1];
            else if (s[i] == 'A')
                dp[i] = dp[i+1]+a;
            else if (s[i] == 'B')
                dp[i] = dp[i+1]+b;
            // debug(dp);
            if (dp[i] > p) {
                cout << i+2 << "\n"; break;
            }
            if (i == 0)
                cout << 1 << "\n";
        }
    }
}