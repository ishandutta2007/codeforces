#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <bitset>
#include <fstream>
using namespace std;
#define ii pair <int, int>
#define app push_back
#define all(a) a.begin(), a.end()
#define bp __builtin_popcountll
#define ll long long
#define mp make_pair
#define x first
#define y second
#define Time (double)clock()/CLOCKS_PER_SEC
#define debug(x) std::cerr << #x << ": " << x << '\n';
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
ll div_up(ll a, ll b) { return a/b+((a^b)>0&&a%b); } // divide a by b rounded up
ll div_down(ll a, ll b) { return a/b-((a^b)<0&&a%b); } // divide a by b rounded down 
ll math_mod(ll a, ll b) { return a - b * div_down(a, b); }
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
ll gcd(ll a, ll b) {
    while (b) {
        tie(a, b) = mp(b, a % b);
    }
    return a;
}

const int N = 6e5+7;

namespace Tree {
vi g[N];
const int LG = 20;
int ptr = 0, to[N][LG], h[N], l[N], r[N];
void calc(int u, int p) {
    to[u][0] = p;
    for (int i = 1; i < LG; ++i)
        to[u][i] = to[to[u][i-1]][i-1];
    l[u] = ptr;
    ptr++;    
    for (int v : g[u])  
        if (v != p) {
            h[v] = h[u]+1;
            calc(v, u);
        }
   r[u] = ptr - 1;
}   
bool anc(int u, int v) { return l[u] <= l[v] && r[v] <= r[u]; }
int lca(int u, int v) {
    if (anc(u,v))   
        return u;
    for (int i = LG - 1; i >= 0; --i)
        if (!anc(to[u][i], v))
            u = to[u][i];
    return to[u][0];
}   
int dist(int u, int v) { return h[u] + h[v] - 2 * h[lca(u,v)]; }
};

mt19937_64 rnd(2007);
ll val[N];
int a[N];
vi d[N];
vi vert[N];
vi want[N];

int type[N]; // 0 - dk, 1 - exist, -1 - doesnt exist
int L[N], R[N];
int sum[N];

struct Fen {
ll f[N];
void clear() {
    for (int i = 0; i < N; ++i) f[i] = 0;
}   
void add(int i, ll x) {
    for (; i < N; i |= i + 1) 
        f[i] ^= x;
}   
void add(int l, int r, ll x) {
    add(l, x);
    add(r + 1, x);
}
ll get(int i) {
    ll ans = 0;
    for (; i >= 0; i &= i + 1, --i) ans ^= f[i];
    return ans;
}   
} f;

signed main() {
	#ifdef ONLINE_JUDGE
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif

    FOR (i, N)
    	val[i] = rnd()%(1 << 22);

    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; ++i) {
    	cin >> a[i];
    	vert[a[i]].app(i);
    }

    FOR (i, n - 1) {
    	int u, v;
    	cin >> u >> v;
    	Tree::g[u].app(v);
    	Tree::g[v].app(u);
    	//read tree
    }

    //precalc for lca
    Tree::calc(1, 1);
    int ptr = 0;
    FOR (i, q) {
    	d[i].resize(4);
    	re(d[i]);
    	d[i].app(Tree::lca(d[i][0], d[i][1]));
    	tie(L[i], R[i]) = mp(d[i][2], d[i][3]);
    }

    FOR (it, 21) {
    	FOR (i, N) {
    		want[i].clear();
    		sum[i] = 0;
    	}
    	FOR (i, q) {
            if (type[i] == -1 || (type[i] && L[i] == R[i]))
                continue;

			int u = d[i][0], v = d[i][1];
			auto add = [&] (int l, int r) {
				want[l - 1].app(i);
				want[r].app(i);
			};
			if (type[i] == 0) {
				add(L[i], R[i]);
			}
			else if (L[i] < R[i]) {
				int m = (L[i] + R[i]) / 2;
				add(L[i], m);
			}
    	}
        f.clear();
    	for (int x = 1; x <= n; ++x) {
    		trav (u, vert[x])
    			f.add(Tree::l[u], Tree::r[u], val[a[u]]);
    		trav (i, want[x]) {
    			int u = d[i][0], v = d[i][1];
    			sum[i] ^= f.get(Tree::l[u]) ^ f.get(Tree::l[v]);
    		}
    	}
    	FOR (i, q) {
            if (type[i] == -1 || (type[i] && L[i] == R[i]))
                continue;

			int lc = d[i][4];

			int l = L[i], r;
			if (type[i] == 0)
				r = R[i];
			else
				r = (L[i] + R[i]) / 2;

			if (L[i] <= a[lc] && a[lc] <= r)
				sum[i] ^= val[a[lc]];

			if (type[i] == 0) {
				if (sum[i] == 0)
					type[i] = -1;
				else
					type[i] = 1;
			}
			else {
				if (sum[i] == 0)
					L[i] = r + 1;
				else
					R[i] = r;
			}
    	}
    }

    FOR (i, q) {
    	if (type[i] == -1) {
    		cout << -1 << endl;
        }
    	else {
    		assert(L[i] == R[i]);
    		cout << L[i] << endl;
    	}
    }
}