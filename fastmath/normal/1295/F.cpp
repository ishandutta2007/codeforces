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
const int N = 107, MOD = 998244353;
int mod(int n) {
    n %= MOD;
    if (n < 0) return n + MOD;
    else return n;
}   
void addmod(int &a, int b) {
    a = mod(a + b);
}   
int fp(int a, int p) {
    int ans = 1, c = a;
    for (int i = 0; (1ll << i) <= p; ++i) {
        if ((p >> i) & 1) ans = mod(ans * c);
        c = mod(c * c);
    }   
    return ans;
}   
int dv(int a, int b) { return mod(a * fp(b, MOD - 2)); }
int C(int n, int k) {
    if (k == 0)
        return 1;
    int a = 1;
    for (int i = n; i > n - k; --i)
        a = mod(a * i);
    int b = 1;
    for (int i = 1; i <= k; ++i)
        b = mod(b * i);        
    return dv(a, b);
}   
int l[N], r[N], dp[N][N];
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) 
        cin >> l[i] >> r[i];
    reverse(l, l + n);
    reverse(r, r + n);
    vector <int> c;      
    for (int i = 0; i < n; ++i) {
        c.app(l[i]);
        c.app(r[i] + 1);
    }   
    sort(all(c));
    c.resize(unique(all(c)) - c.begin());
    dp[0][0] = 1;
    for (int i = 0; i + 1 < c.size(); ++i) {
        for (int j = 0; j <= n; ++j) {
            for (int add = 0; j + add <= n; ++add) {
                bool ch = 1;
                for (int k = j; k < j + add; ++k)
                    ch &= l[k] <= c[i] && c[i + 1] - 1 <= r[k];
                if (ch) {
                    addmod(dp[i + 1][j + add], dp[i][j] * C(c[i + 1] - c[i] + add - 1, add));
                }
            }   
        }   
    }   
    #ifdef HOME
    for (int i = 0; i < c.size(); ++i) {
        for (int j = 0; j <= n; ++j)
            cout << dp[i][j] << ' ';
        cout << '\n';
    }   
    #endif
    int all = 1;
    for (int i = 0; i < n; ++i)
        all = mod(all * (r[i] - l[i] + 1));
    cout << dv(dp[c.size() - 1][n], all) << '\n';
}