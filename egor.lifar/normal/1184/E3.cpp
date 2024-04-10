/*














 */
#include <iostream>
#include <complex>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdio>
#include <numeric>
#include <cstring>
#include <ctime>
#include <cstdlib>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <cmath>
#include <bitset>
#include <cassert>
#include <queue>
#include <stack>
#include <deque>
 
 
using namespace std;
template<typename T1, typename T2>inline void chkmin(T1 &x, T2 y) { if (x > y) x = y; }
template<typename T1, typename T2>inline void chkmax(T1 &x, T2 y) { if (x < y) x = y; }
#define sz(c) (int)(c).size()
#define all(c) (c).begin(), (c).end()
#define rall(c) (c).rbegin(), (c).rend()
#define left left228
#define right right228
#define next next228
#define rank rank228
#define prev prev228
#define y1 y1228
#define read(FILENAME) freopen((FILENAME + ".in").c_str(), "r", stdin)
#define write(FILENAME) freopen((FILENAME + ".out").c_str(), "w", stdout)
#define files(FILENAME) read(FILENAME), write(FILENAME)
#define pb push_back
#define mp make_pair
const string FILENAME = "input";
const int MAXN = 100228;


int n, m;
int parent[MAXN], parent1[MAXN];
int rank[MAXN], rank1[MAXN];
 
 
int findset(int v) {
    if (v == parent[v]) {
        return v;
    }
    return parent[v] = findset(parent[v]);
}
 
bool unite(int a, int b) {
    a = findset(a);
    b = findset(b);
    if (a == b) {
        return false;
    }
    if (rank[a] < rank[b]) {
    	swap(a, b);
    }
    parent[a] = b;
    chkmax(rank[a], rank[b] + 1);
    return true;
}


vector<pair<int, int> > g[MAXN];
int jump[MAXN][18];
int mt[MAXN][18];
int in[MAXN];
int out[MAXN];
int timer = 0;
int ans[MAXN * 10];
int deep[MAXN];
int as[MAXN * 10], bs[MAXN *10], cs[MAXN * 10];


void dfs(int u, int pr = -1) {
    timer++;
    in[u] = timer;
    for (auto h: g[u]) {    
        if (h.first == pr) {
            continue;
        }   
        jump[h.first][0] = u;
        mt[h.first][0] = cs[h.second];
        deep[h.first] = deep[u] + 1;
        dfs(h.first, u);
    }
    out[u] = timer;
}


bool isp(int a, int b) {
    return in[a] <= in[b] && out[b] <= out[a];
} 


int lca(int a, int b) {
    if (isp(a, b)) {
        return a;
    }
    if (isp(b, a)) {
        return b;
    }
    for (int k = 17; k >= 0; k--) {
        if (!isp(jump[a][k], b)) {
            a = jump[a][k];
        }
    }
    return jump[a][0];
}


int getv(int a, int b) {
    int res = 0;
    for (int k = 17; k >= 0; k--) {
        if (!isp(jump[a][k], b)) {
            chkmax(res, mt[a][k]);
            a = jump[a][k];
        }
    }
    chkmax(res, mt[a][0]);
    return res;
}


vector<int> add[MAXN];
vector<int> del[MAXN];


int getmax(int a, int b, int i) {
    if (!isp(a, b)) {
        swap(a, b);
    }
    if (isp(a, b)) {
        add[b].pb(cs[i]);
        del[a].pb(cs[i]);
        return getv(b, a);
    }
    int c = lca(a, b);
    add[b].pb(cs[i]);
    add[a].pb(cs[i]);
    del[c].pb(cs[i]);
     del[c].pb(cs[i]);
    return max(getv(b, c), getv(a, c));
} 


void dfs1(int u, multiset<int> &s, int pr = -1) {
    for (auto h: g[u]) {
        if (h.first == pr) {
            continue;
        }
        multiset<int> s1;
        dfs1(h.first, s1, u);
        ans[h.second] = (s1.empty() ? 1000000000: *s1.begin());
        if (sz(s) < sz(s1)) {
            swap(s, s1);
        }
        for (auto x: s1) {
            s.insert(x);
        }
    }
    for (auto x: add[u]) {
        s.insert(x);
    }
    for (auto x: del[u]) {
        s.erase(s.find(x));
    }
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	//read(FILENAME);
	cin >> n >> m;
	int ta, tb;
	vector<pair<pair<int, int> , pair<int, int> > > st;
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		a--, b--;
		st.pb({{c, i}, {a, b}});
		as[i] = a;
		bs[i] = b;
		cs[i] = c;
	} 
	sort(all(st));
	for (int i = 0; i < n; i++) {
		parent[i] = i;
		rank[i] = 0;
	}
	vector<int> good, good1;
	for (auto x: st) {
		int a = x.second.first;
		int b = x.second.second;
		if (findset(a) == findset(b)) {
			good.pb(x.first.second);
            
		} else {
			unite(a, b);
			good1.pb(x.first.second);
            g[x.second.first].pb({x.second.second, x.first.second});
            g[x.second.second].pb({x.second.first, x.first.second});
		}
	}
	dfs(0);
    for (int k = 1; k <= 17; k++) {
        for (int i = 0; i < n; i++) {
            jump[i][k] = jump[jump[i][k - 1]][k - 1];
            mt[i][k] = max(mt[i][k - 1], mt[jump[i][k - 1]][k - 1]);
        }
    }
    for (auto x: good) {
        ans[x] = getmax(as[x], bs[x], x);
    }
    multiset<int> h;
    dfs1(0, h);
    for (int x = 0; x < m; x++) {
        cout << ans[x] << '\n';
    }
	return 0;
}