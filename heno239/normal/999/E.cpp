#include<iostream>
#include<cstdio>
#include<string>
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
#include<complex>
using namespace std;
typedef long long ll;
const ll MOD = 1000000007;
const ll INF = (ll)1000000007 * 1000000007;
const double EPS = 1e-9;
typedef pair<int, int> P;
typedef unsigned int ui;
#define stop char nyaa;cin>>nyaa;
#define rep(i,n) for(int i=0;i<n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per1(i,n) for(int i=n;i>=1;i--)
#define Rep1(i,sta,n) for(int i=sta;i<=n;i++)
typedef long double ld;
typedef complex<ld> Point;
const ld eps = 1e-8;
const ld pi = acos(-1.0);
const int MAX_V = 5000;
int V;
vector<int>G[MAX_V];
vector<int>rG[MAX_V];
vector<int>vs;
bool used[MAX_V];
int cmp[MAX_V];
void add_edge(int from, int to) {
	G[from].push_back(to);
	rG[to].push_back(from);
}
void dfs(int v) {
	used[v] = true;
	rep(i, (int)G[v].size()) {
		if (!used[G[v][i]])dfs(G[v][i]);
	}
	vs.push_back(v);
}
void rdfs(int v, int k) {
	used[v] = true;
	cmp[v] = k;
	rep(i, (int)rG[v].size()) {
		if (!used[rG[v][i]])rdfs(rG[v][i], k);
	}
}
int scc() {
    rep(v,V){
        used[v]=false;
    }
	vs.clear();
	rep(v, V) {
		if (!used[v])dfs(v);
	}
	rep(v,V){
	    used[v]=false;
	}
	int k = 0;
	per(i, (int)vs.size()) {
		if (!used[vs[i]])rdfs(vs[i], k++);
	}
	return k;
}
int main() {
	int m,s;
	cin >> V >> m >> s; s--;
	rep(i, m) {
		int x, y; cin >> x >> y; x--; y--; add_edge(x, y);
	}
	int n = scc();
	int par[5000] = {};
	rep(v, V) {
		int len = G[v].size();
		rep(i, len) {
			if (cmp[v] != cmp[G[v][i]]) {
				par[cmp[G[v][i]]] = 1;
			}
		}
	}
	int cnt = 0;
	rep(i, n) {
		if (i != cmp[s] && par[i] == 0)cnt++;
	}
	cout << cnt << endl;
	return 0;
}