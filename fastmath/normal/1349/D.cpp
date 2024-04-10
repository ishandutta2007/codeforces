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

const int MOD = 998244353;
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

signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    int n;
    cin >> n;
    vector <int> a(n);
    int m = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        m += a[i];
    }
    
    //check overflow!

    #ifdef HOME
    cout << "1/2=" << dv(1,2) << endl;
    cout << "3/2=" << dv(3,2) << endl;
    #endif

    vector <int> f(m + 1), d(m + 1), b(m + 1);
    d[m] = dv(dv(1,n-1), mod(1-dv(n-2,n-1)));
    b[m] = dv(1, mod(1-dv(n-2,n-1)));
    for (int i = m - 1; i; --i) {
        int x = i;
        d[x] = mod(dv(x,m)*dv(1,n-1));
        b[x] = mod(b[x+1]*dv(m-x,m)+1);
        int t = mod(1 - dv(x,m)*dv(n-2,n-1) - dv(m-x,m)*d[x+1]);
        d[x] = dv(d[x],t);
        b[x] = dv(b[x],t);
    }   

    for (int i = 1; i <= m; ++i) {
        f[i] = mod(f[i - 1] * d[i] + b[i]);
    }   

    #ifdef HOME
    cout << "f : ";
    for (auto e : f)
        cout << e << ' ';
    cout << endl;
    #endif                        

    for (int i = 1; i < m; ++i) {
        int x = i;
        int w = mod(f[x-1]*mod(dv(x,m)*dv(1,n-1))+f[x+1]*dv(m-x,m)+f[x]*mod(dv(x,m)*dv(n-2,n-1))+1);
        if (f[x] != w) {
            cout << "bad " << x << " : " << w << endl;
            exit(1);
        }   
    }   

    int C = f[m];
    int E = 0;
    for (int i = 0; i < n; ++i) {
        E = mod(E + f[m - a[i]]);

        #ifdef HOME
        cout << "E(" << i << ") : " << f[m - a[i]] << endl;
        #endif
    }

    #ifdef HOME
    cout << "C : " << C << endl;
    #endif

    int ans = mod(E - (n - 1) * C);
    ans = dv(ans, n);
    cout << ans << endl;
}