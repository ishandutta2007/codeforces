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
#define debug(x) std::cerr << #x << ": " << x << '\n';
#define FOR(i, n) for (int i = 0; i < n; ++i)
#define FORN(i, n) for (int i = 1; i <= n; ++i)
#define pb push_back
#define trav(a, x) for (auto& a : x)
using vi = vector<int>;
template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& data)
{
    for (T& x : data)
        input >> x;
    return input;
}
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
struct Dsu {
int n;
vector <int> par, cnt, l, r;
Dsu (int n_) {
    n = n_;
    par.resize(n + 1);
    cnt.resize(n + 1, 1);
    l.resize(n + 1);
    r.resize(n + 1);
    FOR (i, n + 1) {
        par[i] = i;
        l[i] = r[i] = i;
    }
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
    ckmin(l[v], l[u]);
    ckmax(r[v], r[u]);
    cnt[v] += cnt[u];
    return 1;
}
bool connected(int u, int v) {
    return root(u) == root(v);
}   
};  
signed main() {
    #ifdef LOCAL
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    int t;
    cin >> t;
    while (t--) {
    	int n, p;
    	cin >> n >> p;
    	vi a(n);
    	cin >> a;
    	Dsu d(n);
    	vi l(n), r(n);

    	auto push = [&] (vi &s, int i) {
    		int x = a[i];
    		int sz = s.size();
    		vi ans = {i};
    		int cur = x;
    		for (int j = sz - 1; j >= 0; --j) {
    			int val = a[s[j]];
    			if (val%cur) {
    				cur = gcd(cur, val);
    				ans.app(s[j]);
    			}
    		}
    		reverse(all(ans));
    		s = ans;
    	};	

    	{
    	vi s;
    	FOR (i, n) {
    		push(s, i);
    		int sz = s.size();
    		l[i] = -1;
    		for (int j = sz - 1; j >= 0; --j) {
    			if (a[s[j]]%a[i]) {
    				l[i] = s[j];
    				break;
    			}
    		}
    	}    		
    	}

    	{
    	vi s;
    	for (int i = n - 1; i >= 0; --i) {
    		push(s, i);
    		int sz = s.size();
    		r[i] = n;
    		for (int j = sz - 1; j >= 0; --j) {
    			if (a[s[j]] % a[i]) {
    				r[i] = s[j];
    				break;
    			}
    		}
    	}
    	}

    	V <ii> ord;
    	FOR (i, n) {
    		ord.app(mp(a[i], i));
    	}
    	sort(all(ord));

    	int ans = 0;
    	int rem = n - 1;
    	trav (e, ord) {
    		//debug(e);
    		if (e.x > p) {
    			break;
    		}
    		int i = e.y;
    		int p = l[i] + 1;
    		while (d.r[d.root(p)] < r[i] - 1) {
    			int u = d.root(p);
    			int nxt = d.r[u] + 1;
    			assert(nxt < n);
    			int v = d.root(nxt);
    			d.merge(u, v);
    			//debug(u); debug(v);
    			rem--;
    			ans += e.x;
    		}
    	}
    	ans += rem * p;
    	cout << ans << endl;
    }
}