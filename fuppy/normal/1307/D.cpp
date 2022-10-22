#include <bits/stdc++.h>
 
//#include <unistd.h>
//#include <iostream>
 
using namespace std;
 
#define DEBUG(x) cerr<<#x<<": "<<x<<endl;
#define DEBUG_VEC(v) cerr<<#v<<":";for(int i=0;i<v.size();i++) cerr<<" "<<v[i]; cerr<<endl;
#define DEBUG_MAT(v) cerr<<#v<<endl;for(int i=0;i<v.size();i++){for(int j=0;j<v[i].size();j++) {cerr<<v[i][j]<<" ";}cerr<<endl;}
typedef long long ll;
//#define int ll
 
#define vi vector<int>
#define vl vector<ll>
#define vii vector< vector<int> >
#define vll vector< vector<ll> >
#define vs vector<string>
#define pii pair<int,int>
#define pis pair<int,string>
#define psi pair<string,int>
#define pll pair<ll,ll>
template<class S, class T> pair<S, T> operator+(const pair<S, T> &s, const pair<S, T> &t) { return pair<S, T>(s.first + t.first, s.second + t.second); }
template<class S, class T> pair<S, T> operator-(const pair<S, T> &s, const pair<S, T> &t) { return pair<S, T>(s.first - t.first, s.second - t.second); }
template<class S, class T> ostream& operator<<(ostream& os, pair<S, T> p) { os << "(" << p.first << ", " << p.second << ")"; return os; }
#define X first
#define Y second
#define rep(i,n) for(int i=0;i<(n);i++)
#define rep1(i,n) for(int i=1;i<=(n);i++)
#define rrep(i,n) for(int i=(n)-1;i>=0;i--)
#define rrep1(i,n) for(int i=(n);i>0;i--)
#define REP(i,a,b) for(int i=a;i<b;i++)
#define in(x, a, b) (a <= x && x < b)
#define all(c) c.begin(),c.end()
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a = b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a = b; return 1; } return 0; }
#define UNIQUE(v) v.erase(std::unique(v.begin(), v.end()), v.end());
const ll inf = 1000000001;
const ll INF = (ll)1e18 + 1;
const long double pi = 3.1415926535897932384626433832795028841971L;
#define Sp(p) cout<<setprecision(25)<< fixed<<p<<endl;
//int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
//int dx2[8] = { 1,1,0,-1,-1,-1,0,1 }, dy2[8] = { 0,1,1,1,0,-1,-1,-1 };
vi dx = {1, 0, -1, 0}, dy = {0, 1, 0, -1};
vi dx2 = { 1,1,0,-1,-1,-1,0,1 }, dy2 = { 0,1,1,1,0,-1,-1,-1 };
#define fio() cin.tie(0); ios::sync_with_stdio(false);
const ll MOD = 1000000007;
//const ll MOD = 998244353;
// #define mp make_pair
//#define endl '\n'

vii G;
	
int n, m, k;

vi bfs(int start) {
	vi dist(n, inf);
	dist[start] = 0;
	queue<pii> qu;
	qu.push(pii(0, start));
	while (not qu.empty()) {
		pii temp = qu.front();
		qu.pop();
		int cost = temp.first, u = temp.second;
		if (cost > dist[u]) continue;
		for (int v: G[u]) {
			int ncost = cost + 1;
			if (dist[v] <= ncost) continue;
			dist[v] = ncost;
			qu.push(pii(ncost, v));
		}
	}
	return dist;
}

signed main() {
	fio()
	cin >> n >> m >> k;
	G.resize(n);
	vi a(k);
	rep (i, k) {
		cin >> a[i];
		a[i]--;
	}

	rep (i, m) {
		int u, v;
		cin >> u >> v;
		u--; v--;
		G[u].push_back(v);
		G[v].push_back(u);
	}

	vi d1 = bfs(0), d2 = bfs(n - 1);

	set<pii> st;
	rep (i, k) {
		int u = a[i];
		st.insert(pii(d2[u], u));
	}

	int ans = d1[n - 1];
	int ma = 0;	
	vector<pii> du;
	rep (i, k) {
		int u = a[i];
		du.push_back(pii(d1[u], u));
	}
	sort(all(du));

	rep (i, du.size()) {
		int cost1 = du[i].first;
		int u = du[i].second;
		st.erase(pii(d2[u], u));
		if (st.size() == 0) break;
		auto itr = st.end();
		itr--;
		chmax(ma, cost1 + 1 + itr->first);
	}
	//DEBUG(ma);
	chmin(ans, ma);
	cout << ans << endl;
}