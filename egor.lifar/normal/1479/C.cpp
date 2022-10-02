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
template<typename T1, typename T2> inline void chkmin(T1 &a, T2 b) {if (a > b) a = b;}
template<typename T1, typename T2> inline void chkmax(T1 &a, T2 b) {if (a < b) a = b;}
#define files(FILENAME) read(FILENAME); write(FILENAME)
#define read(FILENAME) freopen((FILENAME + ".in").c_str(), "r", stdin)
#define write(FILENAME) freopen((FILENAME + ".out").c_str(), "w", stdout)
#define all(c) (c).begin(), (c).end()
#define sz(c) (int)(c).size()
#define left left228
#define right right228
#define y1 y1228
#define mp make_pair
#define pb push_back
#define y2 y2228
#define rank rank228
using ll = long long;
using ld = long double; 
const string FILENAME = "input";
const int Mod = 998244353;


int sum(int a, int b) {
	return (a + b >= Mod ? a + b - Mod: a + b);
}


int mul(int a, int b) {
	return ((ll)a * b) % Mod;
}


int powm(int a, int b) {
	int res = 1;
	while (b) {
		if (b & 1) {
			res = mul(res, a);
		}
		a = mul(a, a);
		b >>= 1;
	}
	return res;
}


int inv(int a) {
    return powm(a, Mod - 2);
}



int l, r;
int uk;
vector<pair<int, int> > g[200];

int m = 0;


void add_edge(int a, int b, int c) {
	assert(b >= 1);
	g[a].pb(mp(b, c));
	m++;
}



void build(int s, int t, int len) {
	if (len == 1) {
		add_edge(s, t, 1);
		return;
	}
	if (len == 2) {
		add_edge(s, uk, 1);
		add_edge(s, t, 1);
		add_edge(uk, t, 1);
		uk--;
		return;
	}
	if (len % 2 == 0) {
		int pf = len / 2;
		build(s, t, pf);
		for (auto y: g[s]) {
			add_edge(uk, y.first, y.second);
		}
		add_edge(s, uk, pf);
		uk--;
	} else {
		int pf = len / 2;
		build(s, t, len - pf);
		for (auto y: g[s]) {
			if (y.first == t) {
				continue;
			}
			add_edge(uk, y.first, y.second);
		}
		add_edge(s, uk, pf);
		uk--;
	}
}


set<int> ss;
int cnts = 0;

void dfs(int u, int cur = 0) {
	if (u == 32) {
		ss.insert(cur);
		cnts++;
		return;
	}
	for (auto h: g[u]) {
		dfs(h.first, cur + h.second);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
   //  read(FILENAME);
   	cin >> l >> r;
   	int s = 1;
   	if (l != 1) {
   		add_edge(1, 2, l - 1);
   		r -= (l - 1);
   		s = 2;
   	}	
   	uk = 31;
   	build(s, 32, r);
  // 	assert(uk + 1 > s);
  //	dfs(1);
   //	assert(sz(ss) == cnts);
   	cout << "YES\n";
   	cout << 32 << ' ' << m << '\n';
   	for (int i = 1; i <= 32; i++) {
   		for (auto y: g[i]) {
   			cout << i << ' ' << y.first << ' ' << y.second << '\n';
   		}
   	}
   	return 0;
}