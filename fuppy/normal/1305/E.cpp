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

int n;
vii G;

vi used;
vi d;

void dfs(int now, int par, int depth) {
	d[now] = depth;
	rep (i, G[now].size()) {
		int ch = G[now][i];
		if (ch == par) continue;
		if (used[ch]) continue;
		dfs(ch, now, depth + 1);
	}
}

pii farest() {
	int r;
	rep (i, n) {
		if (not used[i]) {
			r = i;
			break;
		}
	}
	fill(all(d), -inf);
	dfs(r, -1, 0);
	pii ma(-1, inf);
	rep (i, n) {
		chmax(ma, pii(d[i], i));
	}
	int u = ma.second;
	fill(all(d), -inf);
	dfs(u, -1, 0);
	ma = pii(-1, inf);
	rep (i, n) {
		chmax(ma, pii(d[i], i));
	}
	int v = ma.second;
	return pii(u, v);
}

bool dfs2(int now, int par, int tar, vi &path) {
	path.push_back(now);
	if (now == tar) {
		return true;
	}
	
	rep (i, G[now].size()) {
		int ch = G[now][i];
		if (ch == par) continue;
		if (used[ch]) continue;
		if (dfs2(ch, now, tar, path)) {
			return true;
		}
	}
	path.pop_back();
	return false;
}

int ask(int u, int v) {
	cout << "? " << u + 1 << " " << v + 1 << endl << flush;
	int res;
	cin >> res;
	res--;
	return res;
}

void ans(int u) {
	cout << "! " << u + 1 << endl << flush;
}

void dfs3(int now, int par) {
	used[now] = true;
	rep (i, G[now].size()) {
		int ch = G[now][i];
		if (ch == par) continue;
		if (used[ch]) continue;
		dfs3(ch, now);
	}
}

void mid(int u, int v) {
	vi path;
	dfs2(u, -1, v, path);
	if (path.size() == 1) {
		ans(path[0]);
		exit(0);
	}
	if (path.size() <= 3) {
		int w = ask(path[0], path.back());
		if (w == path[0] or w == path.back()) {
			ans(w);
			exit(0);
		}
		else {
			used[path[0]] = true;
			used[path.back()] = true;
		}
	}
	else {
		int m = path.size();
		int u = path[m / 2 - 1], v = path[m / 2];
		int w = ask(u, v);
		int make;
		if (w == u) make = v;
		else make = u;
		dfs3(make, w);
	}
}

signed main() {
	fio();
	int n, m;
	cin >> n >> m;
	int k;
	if (n % 2 == 0) {
		k = (n - 2) / 2;
		k = k * (k + 1);
	}		
	else {
		k = n / 2;
		k = k * k;
	}

	if (k < m) {
		cout << -1 << endl;
		return 0;
	}

	ll now = 0;
	vi a;
	a.push_back(1);
	a.push_back(2);
	while (now < m) {
		int t = a.size() / 2;
		if (now + t <= m) {
			now += t;
			int x = a.back();
			a.push_back(x + 1);
		}
		else {
			int k = m - now;
			int x = a.back();
			int y = x - 2 * k + 1;
			a.push_back(x + y);
			now += k;
		}
	}

	if (a.size() < n) {
		a.push_back(1e8);
	}
	while (a.size() < n) {
		int x = a.back();
		a.push_back(x + 6000);
	}

	rep (i, n) {
		cout << a[i] << " ";
	}
	cout << endl;
}