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

const int N = 3e5+7;
int ptr = 0;
vi t1[N], t2[N];
int l[N], r[N];
int who[N];
void dfs2(int u, int p) {
	l[u] = ptr;
	who[ptr] = u;
	ptr++;
	trav (v, t2[u]) {
		dfs2(v, u);
	}
	r[u] = ptr - 1;
}

int mx[N << 2];

void setpoint(int v, int tl, int tr, int i, int x) {
	if (tl == tr) {
		mx[v] = x;
		return;
	}
	int tm = (tl + tr) >> 1;
	if (i <= tm) {
		setpoint(v * 2 + 1, tl, tm, i, x);
	}
	else {
		setpoint(v * 2 + 2, tm + 1, tr, i, x);
	}
	mx[v] = max(mx[v * 2 + 1], mx[v * 2 + 2]);
}
int find_father(int v, int tl, int tr, int l, int r, int x) {
	if (tr < l || r < tl || mx[v] < x) {
		return -1;
	}
	if (tl == tr) {
		return who[tl];
	}
	int tm = (tl + tr) >> 1;
	int t = find_father(v * 2 + 2, tm + 1, tr, l, r, x);
	if (t != -1) {
		return t;
	}
	else {
		return find_father(v * 2 + 1, tl, tm, l, r, x);
	}
}

int n;
int leaf = 0, ans = 0;
int de[N];
void dfs1(int u, int p) {

	int fa = -1;
	if (u > 1) {	
		fa = find_father(0, 0, n - 1, 0, l[u], r[u]);
		leaf++;
		leaf -= de[fa]==0;
		de[fa]++;
	}
	else {
		leaf++;
	}

	setpoint(0, 0, n - 1, l[u], r[u]);

	//debug(u);debug(fa);debug(leaf);
	//debug(l[u]); debug(r[u]);

	ckmax(ans, leaf);

	trav (v, t1[u]) {
		dfs1(v, u);
	}

	setpoint(0, 0, n - 1, l[u], -1);

	if (fa != -1) {
		de[fa]--;
		leaf += de[fa]==0;
		leaf--;
	}
	else {
		leaf--;
	}
}

signed main() {
    #ifdef LOCAL
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    int t;
    cin >> t;
    while (t--) {
    	cin >> n;
    	ptr = 0;
    	FORN (i, n) {
    		t1[i].clear();
    		t2[i].clear();
    	}
    	for (int i = 2; i <= n; ++i) {
    		int p;
    		cin >> p;
    		t1[p].app(i);
    	}
    	for (int i = 2; i <= n; ++i) {
    		int p;
    		cin >> p;
    		t2[p].app(i);
    	}
    	dfs2(1, 1);

    	for (int i = 0; i < (n << 2); ++i) {
    		mx[i] = -1;
    	}

    	FORN (i, n) {
    		de[i] = 0;
    	}
    	leaf = 0;
    	ans = 0;
    	dfs1(1, 1);
    	cout << ans << endl;
    }
}