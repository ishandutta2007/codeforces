#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ii pair <int, int>
#define app push_back
#define all(a) a.begin(), a.end()
#define bp __builtin_popcountll
#define ll long long
#define mp make_pair
#define x first
#define y second
#define Time (double)clock()/CLOCKS_PER_SEC
#define debug(x) std::cout << #x << ": " << x << '\n';
#define FOR(i, n) for (int i = 0; i < n; ++i)
#define pb push_back
#define trav(a, x) for (auto& a : x)
using vi = vector<int>;
template <typename T>
std::ostream& operator <<(std::ostream& output, const pair <T, T> & data)
{
    output << "(" << data.x << "," << data.y << ")";
    return output;
}
template <typename T>
std::ostream& operator <<(std::ostream& output, const std::vector<T>& data)
{
    for (const T& x : data)
        output << x << " ";
    return output;
}
//ll div_up(ll a, ll b) { return a/b+((a^b)>0&&a%b); } // divide a by b rounded up
//ll div_down(ll a, ll b) { return a/b-((a^b)<0&&a%b); } // divide a by b rounded down 
#define tcT template<class T
#define tcTU tcT, class U
tcT> using V = vector<T>; 
tcT> void re(V<T>& x) { 
    trav(a, x)
        cin >> a;
}
tcT> bool ckmin(T& a, const T& b) {
    return b < a ? a = b, 1 : 0; 
} // set a = min(a,b)
tcT> bool ckmax(T& a, const T& b) {
    return a < b ? a = b, 1 : 0; 
}

//need define int long long
namespace Stuff {
const int MOD = 1e9+7;
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
};
struct M {
ll x;
M (int x_) { x = Stuff::mod(x_); }   
M () { x = 0; }
M operator + (M y) {
    int ans = x + y.x;
    if (ans >= Stuff::MOD)
        ans -= Stuff::MOD;
    return M(ans);
}
M operator - (M y) {
    int ans = x - y.x;
    if (ans < 0)
        ans += Stuff::MOD;
    return M(ans);            
}   
M operator * (M y) { return M(x * y.x % Stuff::MOD); }   
M operator / (M y) { return M(x * Stuff::fp(y.x, Stuff::MOD - 2) % Stuff::MOD); }   
M operator + (int y) { return (*this) + M(y); }
M operator - (int y) { return (*this) - M(y); }   
M operator * (int y) { return (*this) * M(y); }   
M operator / (int y) { return (*this) / M(y); }   
M operator ^ (int p) { return M(Stuff::fp(x, p)); }   
void operator += (M y) { *this = *this + y; }   
void operator -= (M y) { *this = *this - y; }   
void operator *= (M y) { *this = *this * y; }
void operator /= (M y) { *this = *this / y; }   
void operator += (int y) { *this = *this + y; }   
void operator -= (int y) { *this = *this - y; }   
void operator *= (int y) { *this = *this * y; }
void operator /= (int y) { *this = *this / y; }   
void operator ^= (int p) { *this = *this ^ p; }
};  
std::ostream& operator << (std::ostream& o, const M& a)
{
    cout << a.x;
    return o;
}


struct Dsu {
int n;
vector <int> par, cnt, have;
Dsu (int n_) {
    n = n_;
    par.resize(n + 1);
    cnt.resize(n + 1, 1);
    have.resize(n + 1, 0);
    FOR (i, n + 1)
        par[i] = i;
}   
int root(int u) {
    if (par[u] == u)
        return u;
    else
        return par[u] = root(par[u]);                
}   
int get_cnt(int u) {
    return cnt[root(u)];
}   
bool merge(int u, int v) {
    u = root(u);
    v = root(v);
    if (u == v)
        return 0;
    par[u] = v;
    cnt[v] += cnt[u];
    have[v] |= have[u];
    return 1;
}
bool connected(int u, int v) {
    return root(u) == root(v);
}   
};  


signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif

    int n, m;
    cin >> n >> m;
    Dsu dsu(m);

    vi ans;
    FOR (i, n) {
        int k;
        cin >> k;
        if (k == 1) {
            int u;
            cin >> u;
            u = dsu.root(u);
            if (!dsu.have[u]) {
                dsu.have[u] = 1;
                ans.app(i);
            }
        }   
        else {
            int u, v;
            cin >> u >> v;
            if (dsu.connected(u, v)) {
                //can du (u, v)
            }   
            else {
                u = dsu.root(u);
                v = dsu.root(v);
                if (dsu.have[u] && dsu.have[v]) {
                    //can do (u, v)
                }   
                else {
                    dsu.merge(u, v);
                    ans.app(i);
                }   
            }   
        }   
    }   
    int sz = ans.size();
    cout << (M(2)^sz) << ' ' << sz << endl;
    trav (i, ans)
        cout << i + 1 << ' ';
    cout << endl;
}