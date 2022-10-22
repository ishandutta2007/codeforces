#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ii pair <int, int>
#define app push_back
#define all(a) a.begin(), a.end()
#define bp __builtin_popcountll
#define ll long long
#define mp make_pair
#define l first
#define r second
#define Time (double)clock()/CLOCKS_PER_SEC
#define debug(x) std::cout << #x << ": " << x << '\n';

const int N = 1e6+7, MOD = 998244353;

struct Fen {
int f[N];
void clear() {
    for (int i = 0; i < N; ++i) f[i] = 0;
}   
void add(int i, int x) {
    for (; i < N; i |= i + 1) 
        f[i] += x;
}   
int get(int i) {
    int ans = 0;
    for (; i >= 0; i &= i + 1, --i) ans += f[i];
    return ans;
}   
int get(int l, int r) {
    //check r < l!
    return get(r) - get(l - 1);
}   
} fe;


//need define int long long
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

struct M {
ll x;
M (int x_) {
    x = mod(x_);
}   
M () {
    x = 0;
}
M operator + (M y) {
    int ans = x + y.x;
    if (ans >= MOD)
        ans -= MOD;
    return M(ans);
}
M operator - (M y) {
    int ans = x - y.x;
    if (ans < 0)
        ans += MOD;
    return M(ans);            
}   
M operator * (M y) {
    return M(x * y.x % MOD);   
}   
M operator / (M y) {
    return M(x * fp(y.x, MOD - 2) % MOD);
}   
M operator + (int y) {
    return (*this) + M(y);
}
M operator - (int y) {
    return (*this) - M(y);
}   
M operator * (int y) {
    return (*this) * M(y);
}   
M operator / (int y) {
    return (*this) / M(y);
}   
M operator ^ (int p) {
    return M(fp(x, p));
}   
void operator += (M y) {
    *this = *this + y;
}   
void operator -= (M y) {
    *this = *this - y;
}   
void operator *= (M y) {
    *this = *this * y;
}
void operator /= (M y) {
    *this = *this / y;
}   
void operator += (int y) {
    *this = *this + y;
}   
void operator -= (int y) {
    *this = *this - y;
}   
void operator *= (int y) {
    *this = *this * y;
}
void operator /= (int y) {
    *this = *this / y;
}   
void operator ^= (int p) {
    *this = *this ^ p;
}
};  

M f[N], inv[N];
void prec() {
    f[0] = M(1);
    for (int i = 1; i < N; ++i)
        f[i] = f[i - 1] * M(i);
    inv[N - 1] = f[N - 1] ^ (MOD - 2);
    for (int i = N - 2; i >= 0; --i)
        inv[i] = inv[i + 1] * M(i + 1);
}
M C(int n, int k) {
    if (n < k)
        return M(0);
    else
        return f[n] * inv[k] * inv[n - k];
}   


signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cout.setf(ios::fixed); cout.precision(20); 
    #endif

    prec();

    int n, k;
    cin >> n >> k;

    vector <ii> a(n);
    vector <int> c;
    for (int i = 0; i < n; ++i) {
        cin >> a[i].l >> a[i].r;
        c.app(a[i].l);
        c.app(a[i].r);
    }

    sort(all(c));
    for (ii &e : a) {
        e.l = lower_bound(all(c), e.l) - c.begin();
        e.r = lower_bound(all(c), e.r) - c.begin();
    }   

    auto comp = [&] (ii a, ii b) {
        return a.r > b.r;
    };  

    sort(all(a), comp);
    M ans(0);
    for (auto e : a) {
        int good = fe.get(e.r);       
        ans += C(good, k - 1);
        fe.add(e.l, 1);
    }                           
    cout << ans.x << endl;
}