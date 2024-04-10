#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")

#include<iostream>
#include<string>
#include<cstdio>
#include<vector>
#include<cmath>
#include<algorithm>
#include<functional>
#include<iomanip>
#include<queue>
#include<ciso646>
#include<random>
#include<map>
#include<set>
#include<bitset>
#include<stack>
#include<unordered_map>
#include<unordered_set>
#include<utility>
#include<cassert>
#include<complex>
#include<numeric>
#include<array>
using namespace std;

//#define int long long
typedef long long ll;

typedef unsigned long long ul;
typedef unsigned int ui;
constexpr ll mod = 998244353;
const ll INF = mod * mod;
typedef pair<int, int>P;
#define stop char nyaa;cin>>nyaa;
#define rep(i,n) for(int i=0;i<n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per1(i,n) for(int i=n;i>=1;i--)
#define Rep1(i,sta,n) for(int i=sta;i<=n;i++)
#define all(v) (v).begin(),(v).end()
typedef pair<ll, ll> LP;
typedef long double ld;
typedef pair<ld, ld> LDP;
const ld eps = 1e-12;
const ld pi = acosl(-1.0);

ll mod_pow(ll x, ll n, ll m = mod) {
	if (n < 0) {
		ll res = mod_pow(x, -n, m);
		return mod_pow(res, m - 2, m);
	}
	if (abs(x) >= m)x %= m;
	if (x < 0)x += m;
	ll res = 1;
	while (n) {
		if (n & 1)res = res * x % m;
		x = x * x % m; n >>= 1;
	}
	return res;
}
struct modint {
	ll n;
	modint() :n(0) { ; }
	modint(ll m) :n(m) {
		if (n >= mod)n %= mod;
		else if (n < 0)n = (n % mod + mod) % mod;
	}
	operator int() { return n; }
};
bool operator==(modint a, modint b) { return a.n == b.n; }
modint operator+=(modint& a, modint b) { a.n += b.n; if (a.n >= mod)a.n -= mod; return a; }
modint operator-=(modint& a, modint b) { a.n -= b.n; if (a.n < 0)a.n += mod; return a; }
modint operator*=(modint& a, modint b) { a.n = ((ll)a.n * b.n) % mod; return a; }
modint operator+(modint a, modint b) { return a += b; }
modint operator-(modint a, modint b) { return a -= b; }
modint operator*(modint a, modint b) { return a *= b; }
modint operator^(modint a, ll n) {
	if (n == 0)return modint(1);
	modint res = (a * a) ^ (n / 2);
	if (n % 2)res = res * a;
	return res;
}

ll inv(ll a, ll p) {
	return (a == 1 ? 1 : (1 - p * inv(p % a, a)) / a + p);
}
modint operator/(modint a, modint b) { return a * modint(inv(b, mod)); }
modint operator/=(modint& a, modint b) { a = a / b; return a; }
const int max_n = 1 << 19;
modint fact[max_n], factinv[max_n];
void init_f() {
	fact[0] = modint(1);
	for (int i = 0; i < max_n - 1; i++) {
		fact[i + 1] = fact[i] * modint(i + 1);
	}
	factinv[max_n - 1] = modint(1) / fact[max_n - 1];
	for (int i = max_n - 2; i >= 0; i--) {
		factinv[i] = factinv[i + 1] * modint(i + 1);
	}
}
modint comb(int a, int b) {
	if (a < 0 || b < 0 || a < b)return 0;
	return fact[a] * factinv[b] * factinv[a - b];
}
modint combP(int a, int b) {
	if (a < 0 || b < 0 || a < b)return 0;
	return fact[a] * factinv[a - b];
}

int gcd(int a, int b) {
	if (a < b)swap(a, b);
	while (b) {
		int r = a % b; a = b; b = r;
	}
	return a;
}

template<typename T>
class dynamic_connectivity {
    class euler_tour_tree {
    public:
        struct node;
        using np = node*;
        using lint = long long;
        struct node {
            np ch[2] = { nullptr,nullptr };
            np p = nullptr;
            int l, r, sz;
            T val = et, sum = et;
            bool exact;
            bool child_exact;
            bool edge_connected = 0;
            bool child_edge_connected = 0;
            node() {}
            node(int l, int r) :l(l), r(r), sz(l == r), exact(l < r), child_exact(l < r) {}
            bool is_root() {
                return !p;
            }
        };
        vector<unordered_map<int, np>>ptr;
        np get_node(int l, int r) {
            if (ptr[l].find(r) == ptr[l].end())ptr[l][r] = new node(l, r);
            return ptr[l][r];
        }
        np root(np t) {
            if (!t)return t;
            while (t->p)t = t->p;
            return t;
        }
        bool same(np s, np t) {
            if (s)splay(s);
            if (t)splay(t);
            return root(s) == root(t);
        }
        np reroot(np t) {
            auto s = split(t);
            return merge(s.second, s.first);
        }
        pair<np, np> split(np s) {
            splay(s);
            np t = s->ch[0];
            if (t)t->p = nullptr;
            s->ch[0] = nullptr;
            return { t,update(s) };
        }
        pair<np, np> split2(np s) {
            splay(s);
            np t = s->ch[0];
            np u = s->ch[1];
            if (t)t->p = nullptr;
            s->ch[0] = nullptr;
            if (u)u->p = nullptr;
            s->ch[1] = nullptr;
            return { t,u };
        }
        tuple<np, np, np> split(np s, np t) {
            auto u = split2(s);
            if (same(u.first, t)) {
                auto r = split2(t);
                return make_tuple(r.first, r.second, u.second);
            }
            else {
                auto r = split2(t);
                return make_tuple(u.first, r.first, r.second);
            }
        }
        template<typename First, typename... Rest>
        np merge(First s, Rest... t) {
            return merge(s, merge(t...));
        }
        np merge(np s, np t) {
            if (!s)return t;
            if (!t)return s;
            while (s->ch[1])s = s->ch[1];
            splay(s);
            s->ch[1] = t;
            if (t)t->p = s;
            return update(s);
        }
        int size(np t) { return t ? t->sz : 0; }
        np update(np t) {
            t->sum = et;
            if (t->ch[0])t->sum = fn(t->sum, t->ch[0]->sum);
            if (t->l == t->r)t->sum = fn(t->sum, t->val);
            if (t->ch[1])t->sum = fn(t->sum, t->ch[1]->sum);
            t->sz = size(t->ch[0]) + (t->l == t->r) + size(t->ch[1]);
            t->child_edge_connected = (t->ch[0] ? t->ch[0]->child_edge_connected : 0) | (t->edge_connected) | (t->ch[1] ? t->ch[1]->child_edge_connected : 0);
            t->child_exact = (t->ch[0] ? t->ch[0]->child_exact : 0) | (t->exact) | (t->ch[1] ? t->ch[1]->child_exact : 0);
            return t;
        }
        void push(np t) {
            //
        }
        void rot(np t, bool b) {
            np x = t->p, y = x->p;
            if ((x->ch[1 - b] = t->ch[b]))t->ch[b]->p = x;
            t->ch[b] = x, x->p = t;
            update(x); update(t);
            if ((t->p = y)) {
                if (y->ch[0] == x)y->ch[0] = t;
                if (y->ch[1] == x)y->ch[1] = t;
                update(y);
            }
        }
        void splay(np t) {
            push(t);
            while (!t->is_root()) {
                np q = t->p;
                if (q->is_root()) {
                    push(q), push(t);
                    rot(t, q->ch[0] == t);
                }
                else {
                    np r = q->p;
                    push(r), push(q), push(t);
                    bool b = r->ch[0] == q;
                    if (q->ch[1 - b] == t)rot(q, b), rot(t, b);
                    else rot(t, 1 - b), rot(t, b);
                }
            }
        }
        void debug(np t) {
            if (!t)return;
            debug(t->ch[0]);
            cerr << t->l << "-" << t->r << " ";
            debug(t->ch[1]);
        }
    public:
        euler_tour_tree() {}
        euler_tour_tree(int sz) {
            ptr.resize(sz);
            for (int i = 0; i < sz; i++)ptr[i][i] = new node(i, i);
        }
        int size(int s) {
            np t = get_node(s, s);
            splay(t);
            return t->sz;
        }
        bool same(int s, int t) {
            return same(get_node(s, s), get_node(t, t));
        }
        void set_size(int sz) {
            ptr.resize(sz);
            for (int i = 0; i < sz; i++)ptr[i][i] = new node(i, i);
        }
        void update(int s, T x) {
            np t = get_node(s, s);
            splay(t);
            t->val = fn(t->val, x);
            update(t);
        }
        void edge_update(int s, function<void(int,int)> g) {
            np t = get_node(s, s);
            splay(t);
            function<void(np)>dfs = [&](np t) {
                assert(t);
                if (t->l < t->r && t->exact) {
                    splay(t);
                    t->exact = 0;
                    update(t);
                    g(t->l, t->r);
                    return;
                }
                if (t->ch[0] && t->ch[0]->child_exact)dfs(t->ch[0]);
                else dfs(t->ch[1]);
            };
            while (t && t->child_exact) {
                dfs(t);
                splay(t);
            }
        }
        bool try_reconnect(int s, function<bool(int)> f) {
            np t = get_node(s, s);
            splay(t);
            function<bool(np)>dfs = [&](np t)->bool {
                assert(t);
                if (t->edge_connected) {
                    splay(t);
                    return f(t->l);
                }
                if (t->ch[0] && t->ch[0]->child_edge_connected)return dfs(t->ch[0]);
                else return dfs(t->ch[1]);
            };
            while (t->child_edge_connected) {
                if (dfs(t))return 1;
                splay(t);
            }
            return 0;
        }
        void edge_connected_update(int s, bool b) {
            np t = get_node(s, s);
            splay(t);
            t->edge_connected = b;
            update(t);
        }
        bool link(int l, int r) {
            if (same(l, r))return 0;
            merge(reroot(get_node(l, l)), get_node(l, r), reroot(get_node(r, r)), get_node(r, l));
            return 1;
        }
        bool cut(int l, int r) {
            if (ptr[l].find(r) == ptr[l].end())return 0;
            np s, t, u;
            tie(s, t, u) = split(get_node(l, r), get_node(r, l));
            merge(s, u);
            np p = ptr[l][r];
            np q = ptr[r][l];
            ptr[l].erase(r);
            ptr[r].erase(l);
            delete p; delete q;
            return 1;
        }
        T get_sum(int p, int v) {
            cut(p, v);
            np t = get_node(v, v);
            splay(t);
            T res = t->sum;
            link(p, v);
            return res;
        }
        T get_sum(int s) {
            np t = get_node(s, s);
            splay(t);
            return t->sum;
        }
    };
    int dep = 1;
    vector<euler_tour_tree> ett;
    vector<vector<unordered_set<int>>>edges;
    int sz;
public:
    dynamic_connectivity(int sz) :sz(sz) {
        ett.emplace_back(sz);
        edges.emplace_back(sz);
    }
    bool link(int s, int t) {
        if (s == t)return 0;
        if (ett[0].link(s, t))return 1;
        edges[0][s].insert(t);
        edges[0][t].insert(s);
        if (edges[0][s].size() == 1)ett[0].edge_connected_update(s, 1);
        if (edges[0][t].size() == 1)ett[0].edge_connected_update(t, 1);
        return 0;
    }
    bool same(int s, int t) {
        return ett[0].same(s, t);
    }
    int size(int s) {
        return ett[0].size(s);
    }
    vector<int>get_vertex(int s) {
        return ett[0].vertex_list(s);
    }
    void update(int s, T x) {
        ett[0].update(s, x);
    }
    T get_sum(int s) {
        return ett[0].get_sum(s);
    }
    bool cut(int s, int t) {
        if (s == t)return 0;
        for (int i = 0; i < dep; i++) {
            edges[i][s].erase(t);
            edges[i][t].erase(s);
            if (edges[i][s].size() == 0)ett[i].edge_connected_update(s, 0);
            if (edges[i][t].size() == 0)ett[i].edge_connected_update(t, 0);
        }
        for (int i = dep - 1; i >= 0; i--) {
            if (ett[i].cut(s, t)) {
                if (dep - 1 == i) {
                    dep++;
                    ett.emplace_back(sz);
                    edges.emplace_back(sz);
                }
                return !try_reconnect(s, t, i);
            }
        }
        return 0;
    }
    bool try_reconnect(int s, int t, int k) {
        for (int i = 0; i < k; i++) {
            ett[i].cut(s, t);
        }
        for (int i = k; i >= 0; i--) {
            if (ett[i].size(s) > ett[i].size(t))swap(s, t);
            auto g = [&](int s, int t) {ett[i + 1].link(s, t); };
            ett[i].edge_update(s, g);
            auto f = [&](int x)->bool {
                for (auto itr = edges[i][x].begin(); itr != edges[i][x].end();) {
                    auto y = *itr;
                    itr = edges[i][x].erase(itr);
                    edges[i][y].erase(x);
                    if (edges[i][x].size() == 0)ett[i].edge_connected_update(x, 0);
                    if (edges[i][y].size() == 0)ett[i].edge_connected_update(y, 0);
                    if (ett[i].same(x, y)) {
                        edges[i + 1][x].insert(y);
                        edges[i + 1][y].insert(x);
                        if (edges[i + 1][x].size() == 1)ett[i + 1].edge_connected_update(x, 1);
                        if (edges[i + 1][y].size() == 1)ett[i + 1].edge_connected_update(y, 1);
                    }
                    else {
                        for (int j = 0; j <= i; j++) {
                            ett[j].link(x, y);
                        }
                        return 1;
                    }
                }
                return 0;
            };
            if (ett[i].try_reconnect(s, f))return 1;
        }
        return 0;
    }
    constexpr static T et = T();
    constexpr static T fn(T s, T t) {
        return s + t;
    }
};
void solve() {
    int n, m; cin >> n >> m;
    dynamic_connectivity<int> dc(n);
    int las = 0;
    map<P, bool> mp;
    string ans;
    rep(i, m) {
        int t, x, y; cin >> t >> x >> y;
        x = (x + las - 1) % n;
        y = (y + las - 1) % n;
        if (t == 1) {
            if (x > y)swap(x, y);
            if (mp.find({ x,y }) == mp.end()) {
                mp[{x, y}] = true;
                dc.link(x, y);
            }
            else {
                mp.erase({ x,y });
                dc.cut(x, y);
            }
        }
        else {
            if (dc.same(x, y)) {
                las = 1; ans.push_back('1');
            }
            else {
                las = 0; ans.push_back('0');
            }
        }
    }
    cout << ans<<"\n";
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(10);
	//init_f();
	//init();
	//expr();
	//int t; cin >> t; rep(i, t)
	solve();
	return 0;
}