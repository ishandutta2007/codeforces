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

const int m = 1<<20;

bool sub[m];
int dp[m];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    string s; fin >> s;
    int n = s.size();
    for (int i = 0; i < n; i++) {
        int mask = 0, j = i;
        while (j < n && !(mask&(1<<(s[j]-'a')))) {
            mask |= 1<<(s[j]-'a');
            sub[mask] = 1;
            j++;
        }
    }
    for (int i = 0; i < m; i++) {
        dp[i] = sub[i] ? __builtin_popcount(i) : 0;
        for (int j = 1; j < m; j <<= 1)
            dp[i] = max(dp[i], dp[i^j]);
    }
    int out = 0;
    for (int i = 0; i < m; i++)
        out = max(out, dp[i]+dp[i^(m-1)]);
    cout << out << "\n";
}