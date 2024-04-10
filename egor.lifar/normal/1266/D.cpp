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
#include <random>
 
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
using ll = long long;
using ld = long double;
// const int MAXMEM = 200 * 1000 * 1024;
// char _memory[MAXMEM];
// size_t _ptr = 0;
// void* operator new(size_t _x) { _ptr += _x; return _memory + _ptr - _x; }
// void operator delete (void*) noexcept {}
const string FILENAME = "input";
const int MAXN = 300228;


int n, m;
unordered_map<int, ll> out[MAXN], in[MAXN];

void proceed(int i) {
	vector<pair<int, ll> > st;
	for (auto x: in[i]) {
		if (x.first == i || x.second == 0) continue;
		st.pb(x);
	}
	vector<pair<int, ll> > st1;
	for (auto x: out[i]) {
		if (x.first == i || x.second == 0) continue;
		st1.pb(x);
	}
	while (!st.empty() && !st1.empty()) {
		auto a = st.back();
		auto b = st1.back();
		st.pop_back();
		st1.pop_back();
		ll fk = min(a.second, b.second);
		in[i][a.first] -= fk;
		out[a.first][i] -= fk;
		out[i][b.first] -= fk;
		in[b.first][i] -= fk;
		a.second -= fk;
		b.second -= fk;
		if (a.second) {
			st.pb(a);
		}
		if (b.second) {
			st1.pb(b);
		}
		out[a.first][b.first] += fk;
		in[b.first][a.first] += fk;
	} 
}


bool used[MAXN];
vector<int> gv[MAXN];


void dfs(int u) {
	proceed(u);
	used[u] = true;
	for (auto h: gv[u]) {
		if (!used[h]) {
			dfs(h);
		}
	}
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //read(FILENAME);
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
    	int a, b;
    	ll c;
    	cin >> a >> b >> c;
    	a--, b--;
    	out[a][b] += c;
    	in[b][a] += c;
    	gv[a].pb(b);
    	gv[b].pb(a);
    }
   	for (int i = 0; i < n; i++) {
   		if (!used[i]) {
   			dfs(i);
   		}
   	}
    vector<pair<pair<int, int>, ll> > res;
    for (int i = 0; i < n; i++) {
    	for (auto x: out[i]) {
    		if (x.second == 0 || x.first == i) {
    			continue;
    		}
    		res.pb({{i, x.first}, x.second});
    	}
    }
    cout << sz(res) << '\n';
    for (auto x: res) {
    	cout << x.first.first + 1 << ' ' << x.first.second + 1 << ' ' << x.second << '\n';
    }
}