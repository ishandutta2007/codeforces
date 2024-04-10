
#include "bits/stdc++.h"
using namespace std;

#define DEBUG(x) cout<<#x<<": "<<x<<endl;
#define DEBUG_VEC(v) cout<<#v<<":";for(int i=0;i<v.size();i++) cerr<<" "<<v[i]; cerr<<endl


typedef long long ll;
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
#define rep(i,n) for(int i=0;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define rrep(i,n) for(int i=n-1;i>=0;i--)
#define rrep1(i,n) for(int i=n;i>0;i--)
#define REP(i,a,b) for(int i=a;i<b;i++)
#define in(x, a, b) (a <= x && x < b)
#define all(v) v.begin(),v.end()
#define UNIQUE(v) v.erase(unique(all(v)), v.end())
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a = b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a = b; return 1; } return 0; }
const ll inf = 1000000001;
const ll INF = 2e18;
const ll MOD = 1000000007;
const double pi = 3.14159265358979323846;
#define Sp(p) cout<<setprecision(15)<< fixed<<p<<endl;
int dx[4] = { 1,0, -1,0 }, dy[4] = { 0,1,0,-1 };
int dx2[8] = { 1,1,0,-1,-1,-1,0,1 }, dy2[8] = { 0,1,1,1,0,-1,-1,-1 };
#define fio() cin.tie(0); ios::sync_with_stdio(false);
//#define mp make_pair

const int N = 1000010;
vi l(N, -1), r(N, -1), p(N, -1);
vs op(N);
vi value(N, -1);
vi cp(N, -1);


int dfs_v(int now, int par) {
	if (op[now] == "IN") {
		return value[now];
	}
	else if (op[now] == "NOT") {
		int res = 1 - dfs_v(l[now], now);
		value[now] = res;
		return res;
	}
	else if (op[now] == "AND") {
		int res = dfs_v(l[now], now) & dfs_v(r[now], now);
		value[now] = res;
		return res;
	}
	else if (op[now] == "OR") {
		int res = dfs_v(l[now], now) | dfs_v(r[now], now);
		value[now] = res;
		return res;
	}
	else {
		int res = dfs_v(l[now], now) ^ dfs_v(r[now], now);
		value[now] = res;
		return res;
	}
}

int dfs_c(int now, int par) {
	if (now == -1) {
		return 0;
	}
	if (par == -1) {
		cp[now] = 0;
	}
	else {
		if (op[par] == "NOT") {
			cp[now] = cp[par];
		}
		else {
			int other;
			if (l[par] == now) {
				other = r[par];
			}
			else {
				other = l[par];
			}
			if (op[par] == "AND") {
				if (value[par] != (value[other] & (1 - value[now]))) {
					cp[now] = cp[par];
				}
				else {
					cp[now] = now;
				}
			}
			if (op[par] == "OR") {
				if (value[par] != (value[other] | (1 - value[now]))) {
					cp[now] = cp[par];
				}
				else {
					cp[now] = now;
				}
			}
			if (op[par] == "XOR") {
				if (value[par] != (value[other] ^ (1 - value[now]))) {
					cp[now] = cp[par];
				}
				else {
					cp[now] = now;
				}
			}
		}
	}
	dfs_c(l[now], now);
	dfs_c(r[now], now);
}

int main() {
	fio();
	int n;
	cin >> n;
	p[0] = -1;
	vi in;
	rep(i, n) {
		cin >> op[i];
		if (op[i] == "NOT") {
			int c;
			cin >> c;
			c--;
			l[i] = c;
			p[c] = i;
		}
		else if (op[i] == "IN") {
			int c;
			cin >> c;
			value[i] = c;
			in.push_back(i);
		}
		else {
			int lc, rc;
			cin >> lc >> rc;
			lc--; rc--;
			l[i] = lc; r[i] = rc;
			p[lc] = p[rc] = i;
		}
	}
	dfs_v(0, -1);
	dfs_c(0, -1);

	rep(i, in.size()) {
		int u = in[i];
		int o = value[0];
		if (cp[u] == 0) {
			o = 1 - o;
		}
		cout << o;
	}
	cout << endl;

}