#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <vector>
#include <set>
#include <map>          
#include <queue>
#include <cstring>
#include <algorithm>
#include <sstream>
#include <ctime>
#include <cmath>
#include <iomanip>
#include <cassert>
                   
using namespace std;

#define forn(i, n) for (int i = 0; i < int(n); i++) 
#define ford(i, n) for (int i = int(n) - 1; i >= 0; i--)
#define forab(i, a, b) for (int i = int(a); i < int(b); i++)

#define sqr(x) ((x)*(x))
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define mp make_pair
#define X first
#define Y second

typedef vector<int> vi;
typedef pair<int, int> pii;
typedef long long ll;
typedef double ld;

const int INF = 1E9;    
const ld eps = 1e-9;
const ld pi = acos(-1.0);
const int MAXN = 111111;
    
int sz = 0;
struct vertex {
	
	int nxt[30];	

	vertex(){
		memset(nxt, -1, sizeof(nxt));	
	}; 	
};
int n, k;
string s;
vector<vertex> t;
vector<vi> g;
vi used, state;

void add(int v) {
	forn(i, s.size()) {
		if (t[v].nxt[s[i] - 'a'] == -1) {
			t[v].nxt[s[i] - 'a'] = sz;
			sz++;
			t.pb(vertex());
		}
		v = t[v].nxt[s[i] - 'a'];				
	}
}

bool f;

void dfs(int v) {
	used[v] = 1;
	if (g[v].empty()) {
		state[v] = f;
		return;	
	}
	
	state[v] = 0;
	for (auto w: g[v]) {
		if (!used[w])
			dfs(w);
		if (state[w] == 0)
			state[v] = 1;	
	}
}

int main() {

	cin >> n >> k;
	t.pb(vertex());
	sz++;
	
	forn(i, n) {
		cin >> s;
		add(0);
	}
	g.resize(sz);
	forn(i, sz)
		forn(j, 30)
			if (t[i].nxt[j] != -1)
				g[i].pb(t[i].nxt[j]);
	 
	used.resize(sz, 0);
	state.resize(sz);
	
	f = 0;
	dfs(0);
	if (state[0] == 0) {
		cout << "Second";	
	} else {
		if (k == 1) {
			cout << "First";
			return 0;
		}
		
		f = 1;
		forn(i, sz)
			used[i] = 0;
		dfs(0);
		if (state[0] == 1) {
			cout << "First";
			return 0;
		}
	
		if (k & 1) {
			cout << "First";	
		} else
			cout << "Second";
	}
	
	return 0;
}