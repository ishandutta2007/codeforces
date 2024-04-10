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
const int N = 1e4 + 7, C = 24;
int dp[1 << C];
int n;
string a[N];
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        int mask = 0;
        for (int j = 0; j < 3; ++j)
            mask |= 1 << (a[i][j] - 'a');
        ++dp[mask];
    }    
    for (int i = 0; i < C; ++i)
        for (int mask = 0; mask < (1 << C); ++mask)
            if ((mask >> i) & 1)
                dp[mask] += dp[mask - (1 << i)];
    int ans = 0;
    for (int i = 0; i < (1 << C); ++i)
        ans ^= (n - dp[i]) * (n - dp[i]);
    cout << ans << '\n';
}