#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 998244353;
int mod(int n) {
    return (n % MOD + MOD) % MOD;
}   
const int N = 2e5 + 7;
int pw[N];
int n, k;

int dp[2][N];
int get(int n, bool t) {
    return dp[t][n];
}   

int get(vector <int> a) {
    int n = a.size();
    int ans = 1;
    
    bool ch = 1;
    for (int i = 0; i < n; ++i) ch &= a[i] == -1;
    if (ch) return mod(k * pw[n - 1]);
    
    int l = 0;
    while (a[l] == -1) ++l;
    ans = mod(ans * pw[l]);

    int r = 0;
    while (a[n - 1 - r] == -1) ++r;
    ans = mod(ans * pw[r]);
    
    for (int l = 0; l < n; ++l) {
        if (a[l] == -1) continue;
        int r = l + 1;
        while (r < n && a[r] == -1) ++r;
        if (r == n) break;
        ans = mod(ans * get(r - l - 1, a[l] == a[r]));
    }   

    return ans;
}   

int a[N];
vector <int> b[2];
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);            
    #else
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif

    cin >> n >> k;
    
    pw[0] = 1;
    for (int i = 1; i < N; ++i) {
        pw[i] = mod(pw[i - 1] * (k - 1));
    }   

    dp[0][0] = 1;
    dp[1][0] = 0;
    for (int i = 0; i < 2; ++i) {
        for (int j = 1; j < N; ++j) {
            dp[i][j] = mod(pw[j] - dp[i][j - 1]);
        }   
    }

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        b[i & 1].push_back(a[i]);
    }   
    cout << mod(get(b[0]) * get(b[1])) << '\n';
}