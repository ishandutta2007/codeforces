#include <bits/stdc++.h>
 
//#include <unistd.h>
//#include <iostream>
 
using namespace std;
 
#define DEBUG(x) cerr<<#x<<": "<<x<<endl;
#define DEBUG_VEC(v) cerr<<#v<<":";for(int i=0;i<v.size();i++) cerr<<" "<<v[i]; cerr<<endl;
#define DEBUG_MAT(v) cerr<<#v<<endl;for(int i=0;i<v.size();i++){for(int j=0;j<v[i].size();j++) {cerr<<v[i][j]<<" ";}cerr<<endl;}
typedef long long ll;
#define int ll
 
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

vector<vector<pii>> G;
vi p;
vector<map<int, int>> mp;
vi wst(32);
vi w;
vii ww;
int zero;
bitset<111111> visited;
vector<int> sum;


bool dfs(int now, int par, int x) {
	visited[now] = true;
	sum[now] = x;
	for (pii ch: G[now]) {
		int v = ch.first;
		if (v == par) continue;
		if (v == p[now]) continue;
		int y = ch.second;
		if (visited[v]) {
			if (now < v) {
				int temp = x ^ sum[v] ^ y;
				if (wst[temp] < 2) {
					w.push_back(temp);
					wst[temp]++;
					if (wst[temp] == 2) {
						return false;
					}
				}
			}
		}
		else {
			bool temp = dfs(v, now, x ^ y);
			if (not temp) return false;
		}
	}
	return true;
}

vii basis;
map<vi, int> basis2idx;

int max_bit(int x) {
	if (x == 0) return 0;
	int res = 1 << 5;
	while ((x & res) == 0) {
		res >>= 1;
	}
	return res;
}

vector<vector<pair<int, bool>>> hyou(400, vector<pair<int, bool>>(400, pii(-1, false)));

tuple<vi, bool> merge(vi &a, vi b, bool early_stop) {
	vi v;
	rep (i, a.size()) v.push_back(a[i]);
	rep (j, b.size()) v.push_back(b[j]);
	sort(all(v));
	reverse(all(v));
	rep (i, v.size()) {
		if (v[i] == 0) continue;
		int mask = max_bit(v[i]);
		rep (j, v.size()) {
			if (i == j) continue;
			if (v[j] & mask) {
				v[j] = v[j] ^ v[i];
				if (early_stop and v[j] == 0) return {v, true};
			}
		}
	}
	sort(all(v));
	reverse(all(v));
	if (v.size() == 0) {
		return {v, false};
	}
	bool flag = false;
	if (v.back() == 0) flag = true;
	while (v.size() > 0 and v.back() == 0) {
		v.pop_back();
	}
	return {v, flag};
}

tuple<int, bool> merge2(int t1, int t2, bool early_stop) {
	if (hyou[t1][t2].first != -1) {
		return {hyou[t1][t2].first, hyou[t1][t2].second};
	}	
	vi v;
	rep (i, basis[t1].size()) v.push_back(basis[t1][i]);
	rep (j, basis[t2].size()) v.push_back(basis[t2][j]);
	sort(all(v));
	reverse(all(v));
	rep (i, v.size()) {
		if (v[i] == 0) continue;
		int mask = max_bit(v[i]);
		rep (j, v.size()) {
			if (i == j) continue;
			if (v[j] & mask) {
				v[j] = v[j] ^ v[i];
				if (early_stop and v[j] == 0) {
					hyou[t1][t2] = hyou[t2][t1] = {basis2idx[v], true};
					return {basis2idx[v], true};
				}
			}
		}
	}
	sort(all(v));
	reverse(all(v));
	if (v.size() == 0) {
		return {0, false};
	}
	bool flag = false;
	if (v.back() == 0) flag = true;
	while (v.size() > 0 and v.back() == 0) {
		v.pop_back();
	}
	hyou[t1][t2] = hyou[t2][t1] = {basis2idx[v], flag};
	return {basis2idx[v], flag};
}

void make_basis() {
	basis.push_back(vi(0));
	basis2idx[basis[0]] = 0;
	int cnt = 1;
	rep1 (i, 31) {
		vi v1(1, i);
		rep (j, basis.size()) {
			vi v2 = basis[j];
			auto [v, flag] = merge(v1, v2, false);
			if (basis2idx.count(v) == 0) {
				basis.push_back(v);
				basis2idx[v] = cnt++;
			}
			int t1 = basis2idx[v1], t2 = basis2idx[v2];
			hyou[t1][t2] = hyou[t2][t1] = {basis2idx[v], flag};
		}
	}
}

signed main() {
	fio();
	make_basis();
	DEBUG(basis.size());
	int n, m;
	cin >> n >> m;
	G.resize(n);
	p.resize(n);
	fill(all(p), -1);
	mp.resize(n);
	sum.resize(n);

	rep (i, m) {
		int u, v, w;
		cin >> u >> v >> w;
		u--; v--;
		G[u].push_back(pii(v, w));
		G[v].push_back(pii(u, w));
		mp[u][v] = w;
		mp[v][u] = w;
	}
	rep (i, n) sort(all(G[i]));

	rep (u, n) {
		if (G[u][0].first != 0) continue;
		for (int j = 0; j < G[u].size(); j++) {
			int v = G[u][j].first;
			if (v == 0) continue;
			if (G[v][0].first == 0) {
				p[u] = v;
				p[v] = u;
			}
		}
	}
	//DEBUG_MAT(G);

	vl dp(basis.size()), dp2(basis.size());
	dp[0] = 1;
	visited[0] = true;
	rep (i, G[0].size()) {
		int u = G[0][i].first;
		if (visited[u]) continue;
		int v = p[u];
		if (v != -1) {
			zero = mp[u][v] ^ mp[0][u] ^ mp[0][v];
		}
		else {
			zero = -1;
		}
		w.clear();
		fill(all(wst), 0);
		bool fff = dfs(u, 0, G[0][i].second);
		if (v != -1) {
			bool fff2 = dfs(v, 0, mp[0][v]);
			if (not fff2) fff = false;
		}
		if (not fff) continue;
		//DEBUG_VEC(w);
		sort(all(w));
		if (w.size() > 0 and w[0] == 0) {
			continue;
		}
		auto [w2, flag] = merge(w, vl(0), true);
		if (flag == true) continue;
		fill(all(dp2), 0);
		int t2 = basis2idx[w2];
		int t0 = basis2idx[vl(1, zero)];
		rep (i, dp.size()) {
			if (dp[i] == 0) continue;
			(dp2[i] += dp[i]) %= MOD;
			if (zero == -1) {
				auto [w3, flag] = merge2(i, t2, true);
				if (flag) continue;
				(dp2[w3] += dp[i]) %= MOD;
			}
			else {
				auto [w3, flag] = merge2(i, t2, true);
				if (flag) continue;
				(dp2[w3] += dp[i] * 2) %= MOD;
				if (zero == 0) continue;
				auto [w4, flag2] = merge2(w3, t0, true);
				if (flag2) continue;
				(dp2[w4] += dp[i]) %= MOD;
			}
		}
		swap(dp, dp2);
	}
	ll ans = 0;
	rep (i, basis.size()) {
		ans += dp[i];
	}
	cout << ans % MOD << endl;
}