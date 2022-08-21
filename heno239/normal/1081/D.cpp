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
#include<complex>
#include<bitset>
#include<stack>
#include<unordered_map>
#include<utility>
using namespace std;
typedef long long ll;
typedef unsigned int ui;
const ll mod = 1000000007;
const ll INF = (ll)1000000007 * 1000000007;
typedef pair<int, int> P;
#define stop char nyaa;cin>>nyaa;
#define rep(i,n) for(int i=0;i<n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per1(i,n) for(int i=n;i>=1;i--)
#define Rep1(i,sta,n) for(int i=sta;i<=n;i++)
typedef long double ld;
typedef complex<ld> Point;
const ld eps = 1e-11;
const ld pi = acos(-1.0);
typedef pair<ll, ll> LP;
typedef pair<ld, ld> LDP;
typedef unsigned long long ul;

int par[100000];
int rank1[100000];
void init(int n) {
	for (int i = 0; i < n; i++) {
		par[i] = i;
		rank1[i] = 0;
	}
}
int find(int x) {
	if (par[x] == x) {
		return x;
	}
	else {
		return par[x] = find(par[x]);
	}
}
void unite(int x, int y) {
	x = find(x);
	y = find(y);
	if (x == y)return;
	if (rank1[x] < rank1[y]) {
		par[x] = y;
	}
	else {
		par[y] = x;
		if (rank1[x] == rank1[y])rank1[x]++;
	}
}
bool same(int x, int y) {
	return find(x) == find(y);
}
struct edge { int u, v, w; };
vector<edge> e;
vector<int>s;
int n, m, k;
bool can(int x) {
	init(n);
	rep(i, m) {
		if (x < e[i].w)continue;
		unite(e[i].u, e[i].v);
	}
	int id = s[0];
	rep(i, k) {
		if (!same(id, s[i]))return false;
	}
	return true;
}
int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin >> n >> m >> k;
	rep(i, k) {
		int t; cin >> t; s.push_back(t-1); 
	}
	rep(i, m) {
		int u, v, w; cin >> u >> v >> w; u--; v--;
		e.push_back({ u,v,w });
	}
	int le = 0; int ri = mod;
	while (ri - le > 1) {
		int mid = (le + ri) / 2;
		if (can(mid))ri = mid;
		else le = mid;
	}
	rep(i, k) {
		if (i > 0)cout << " ";
		cout << ri;
	}
	cout << endl;
	return 0;
}