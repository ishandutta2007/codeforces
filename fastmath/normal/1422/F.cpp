#include<bits/stdc++.h>
using namespace std;
#define ii pair <int, int>
#define app push_back
#define all(a) a.begin(), a.end()
#define bp __builtin_popcountll
#define ll long long
#define mp make_pair
#define f first
#define s second
#define Time (double)clock()/CLOCKS_PER_SEC
#define debug(x) std::cout << #x << ": " << x << '\n';
const int N = 1e5+7, MOD = 1e9+7;

//need define int long long
int mod(ll n) {
    n %= MOD;
    if (n < 0) return n + MOD;
    else return n;
}   
int fp(ll a, ll p) {
    ll ans = 1, c = a;
    for (int i = 0; (1ll << i) <= p; ++i) {
        if ((p >> i) & 1) ans = mod(ans * c);
        c = mod(c * c);
    }   
    return ans;
}   

const int C = N << 1;
bool isp[C];
vector <int> primes[C];
vector <ii> d[N];
int prv[C];

signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cout.setf(ios::fixed); cout.precision(20); 
    #endif
    for (int i = 2; i < C; ++i)
        isp[i] = 1;
    for (int i = 2; i < C; ++i) {
        if (isp[i]) {
            primes[i] = {i};
            for (int j = i * 2; j < C; j += i) {
                isp[j] = 0;
                primes[j].app(i);
            }   
        }
    }   
    memset(prv, -1, sizeof prv);
    auto add_suff = [&] (int i, ii e) {
        for (; i < N; i |= i + 1) 
            d[i].app(e);
    };  
    int n;
    cin >> n;
    vector <int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        for (int p : primes[a[i]]) {
            int x = 1;
            while (a[i] % p == 0) {
                x *= p;
                a[i] /= p;
                if (prv[x] != -1) {
                    add_suff(i, mp(prv[x], fp(p, MOD-2)));
                }
                add_suff(i, mp(i, p));
                prv[x] = i;
            }   
        }   
    }
    for (int i = 0; i < N; ++i) {
        sort(all(d[i]));
        for (int j = (int)d[i].size() - 2; j >= 0; --j)
            d[i][j].s = ((ll)d[i][j].s * d[i][j + 1].s) % MOD;
    }   
    int q;
    cin >> q;
    int last = 0;
    while (q--) {
        int x, y;
        cin >> x >> y;
        int l = (last + x) % n;
        int r = (last + y) % n;
        if (r < l)
            swap(l, r);
        
        ll ans = 1;
        for (int i = r; i >= 0; i &= i + 1, --i) {
            auto t = lower_bound(all(d[i]), mp(l, 0));
            if (t != d[i].end()) {
                ans *= t->s;
                ans %= MOD;
            }
        }   
        cout << ans << endl;
        last = ans;
    }   
}