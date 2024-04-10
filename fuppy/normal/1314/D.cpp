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

vii hyou;
vector<vector<vector<pii>>> mi;

int ans = inf;
int n, k;

bitset<80> even;
vector<vector<pii>> G(5);
vii dp(6, vi(5, inf));

int solve(vi &use) {
	rep (i, use.size()) even[use[i]] = true;

	int n = use.size();
	rep (i, n) G[i].clear();

	rep (i, use.size()) {
		int u = use[i];
		rep (j, use.size()) {
			int v = use[j];
			bool flag = false;
			rep (k, mi[u][v].size()) {
				int x = mi[u][v][k].second;
				if (even[x]) continue;
				G[i].push_back(pii(mi[u][v][k].first, j));
				flag = true;
				break;
			}
			if (not flag) return inf;
		}
	}
	//DEBUG_MAT(G);

	dp[0][0] = 0;
	rep (i, k / 2) {
		fill(all(dp[i + 1]), inf);
		rep (j, n) {
			if (dp[i][j] == inf) continue;
			if (i == 0 and j != 0) break;
			rep (l, G[j].size()) {
				int nj = G[j][l].second;
				chmin(dp[i + 1][nj], dp[i][j] + G[j][l].first);
			}
		}
	}

	rep (i, use.size()) even[use[i]] = false;
	return dp[k / 2][0];
}

void dfs(vi &use, int now) {
	if (now == n or use.size() == k / 2) {
		chmin(ans, solve(use));
		return;
	}
	dfs(use, now + 1);
	if (use.size() < k / 2) {
		use.push_back(now);
		dfs(use, now + 1);
		use.pop_back();
	}

}


signed main() {
	scanf("%d %d", &n, &k);
	//cin >> n >> k;
	hyou.resize(n);
	mi.resize(n);
	rep (i, n) {
		hyou[i].resize(n);
		mi[i].resize(n);
		rep (j, n) {
			scanf("%d", &hyou[i][j]);
		}
	}
	rep (i, n) {
		rep (j, n) {
			rep (x, n) {
				if (i == x or j == x) continue;
				mi[i][j].push_back({hyou[i][x] + hyou[x][j], x});
			}
			sort(all(mi[i][j]));
		}
	}

	vi use;
	use.push_back(0);
	dfs(use, 1);
	printf("%d\n", ans);
}