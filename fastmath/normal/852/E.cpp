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

const int MOD = 1000 * 1000 * 1000 + 7;
int mod(int n) {
    n %= MOD;
    if (n < 0) return n + MOD;
    else return n;
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

const int N = 1e5 + 7;

vector <int> g[N];
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    int n;
    cin >> n;

    if (n == 1) {
        cout << 1 << endl;
        exit(0);
    }   

    for (int i = 0; i < n - 1; ++i) {
        int u , v;
        cin >> u >> v;
        g[u].app(v); g[v].app(u);
    }   
    int lief = 0;
    for (int i = 1; i <= n; ++i)
        lief += g[i].size() == 1;
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        bool is = g[i].size() == 1;
        ans = mod(ans + fp(2, n - (lief - is)));
    }
    cout << ans << endl;
}