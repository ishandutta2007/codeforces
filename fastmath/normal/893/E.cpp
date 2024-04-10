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
const int N = 1e6 + 2007, MOD = 1000 * 1000 * 1000 + 7;

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

int f[N];
int C(int n, int k) {
    if (n < k)
        return 0;
    return dv(f[n], mod(f[k] * f[n - k]));
}   
bool p[N];
vector <int> pd[N];

signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    f[0] = 1;
    for (int i = 1; i < N; ++i)
        f[i] = f[i - 1] * i % MOD;
    for (int i = 2; i < N; ++i)
        p[i] = 1;
    for (int i = 2; i < N; ++i) {
        if (p[i]) {
            pd[i] = {i};
            for (int j = i * 2; j < N; j += i) {
                p[j] = 0;
                pd[j].app(i);
            }   
        }   
    }   
    int q;
    cin >> q;
    while (q--) {
        int x, y;
        cin >> x >> y;

        int ans = 1;        
        for (int t : pd[x]) {
            int pw = 0;
            while (x % t == 0) {
                ++pw;
                x /= t;
            }   
            ans = ans * C(y + pw - 1, pw) % MOD;
        }   
                    
        ans = ans * fp(2, y - 1) % MOD;
        cout << ans << '\n';
    }   
}