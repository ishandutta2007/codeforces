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
const int N = 2007, MOD = 998244353;
int mod(int n) {
    n %= MOD;
    if (n < 0) return n + MOD;
    else return n;
}
int C[N][N], CC[N][N], ans[N];
string s;
int n;
int cnt[N][3];
int type(char c) {
    if (c == '(') return 0;
    else if (c == ')') return 1;
    return 2;
}   
int solve(int k) {
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        if (cnt[i][0] <= k && s[i - 1] == '(') {
            ans = mod(ans + C[cnt[i][2]][k - cnt[i][0]] * CC[cnt[n][2] - cnt[i][2]][max(0ll, k - (cnt[n][1] - cnt[i][1]))]);
        }   
        else if (cnt[i][0] < k && s[i - 1] == '?') {
            ans = mod(ans + C[cnt[i][2] - 1][k - cnt[i][0] - 1] * CC[cnt[n][2] - cnt[i][2]][max(0ll, k - (cnt[n][1] - cnt[i][1]))]);            
        }   
    }
    return ans;
}   
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    for (int i = 0; i < N; ++i)
        C[i][0] = 1;
    for (int i = 1; i < N; ++i)
        for (int j = 1; j < N; ++j)
            C[i][j] = mod(C[i - 1][j - 1] + C[i - 1][j]);
    for (int i = 0; i < N; ++i)
        for (int j = N - 2; j >= 0; --j)
            CC[i][j] = mod(C[i][j] + CC[i][j + 1]);
    cin >> s;
    n = s.size();
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < 3; ++j)
            cnt[i][j] = cnt[i - 1][j];
        cnt[i][type(s[i - 1])]++;
    }   
    for (int i = 1; i * 2 <= n; ++i)
        ans[i] = solve(i);
    int sum = 0, c = 0;
    for (int i = N - 1; i; --i) {
        ans[i] = mod(ans[i] - c);
        c = mod(c + ans[i]);
        sum = mod(sum + ans[i] * i);
    }
    cout << sum << '\n';
}