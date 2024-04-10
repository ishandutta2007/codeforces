#include <bits/stdc++.h>
#include <unistd.h>

using namespace std;

#define DEBUG(x) cerr<<#x<<": "<<x<<endl;
#define DEBUG_VEC(v) cerr<<#v<<":";for(int i=0;i<v.size();i++) cerr<<" "<<v[i]; cerr<<endl
#define DEBUG_MAT(v) cerr<<#v<<endl;for(int i=0;i<v.size();i++){for(int j=0;j<v[i].size();j++) {cerr<<v[i][j]<<" ";}cerr<<endl;}


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
const ll MOD = 1000000007;
//const ll MOD = 998244353;
const double pi = 3.14159265358979323846;
#define Sp(p) cout<<setprecision(15)<< fixed<<p<<endl;
int dx[4] = { -1,0, 1,0 }, dy[4] = { 0,1,0,-1 };
int dx2[8] = { 1,1,0,-1,-1,-1,0,1 }, dy2[8] = { 0,1,1,1,0,-1,-1,-1 };
#define fio() cin.tie(0); ios::sync_with_stdio(false);
// #define mp make_pair
//#define endl '\n'


//  {}
struct edge { int to; ll cap; int rev; };

class Dinic {
public:
	int n;
	vector< vector<edge> > G; //
	vl level; //s
	vi iter; //


	Dinic(int n) :n(n), level(n), iter(n), G(n) {}

	//fromtocap
	void add_edge(int from, int to, ll cap) {
		edge a;
		a.to = to; a.cap = cap; a.rev = G[to].size();
		G[from].push_back(a);
		a.to = from; a.cap = 0; a.rev = G[from].size() - 1;
		G[to].push_back(a);
	}

	//sBFS
	void bfs(int s) {
		fill(level.begin(), level.end(), -1);
		queue<int> que;
		level[s] = 0;
		que.push(s);
		while (!que.empty()) {
			int v = que.front(); que.pop();
			for (int i = 0; i < G[v].size(); i++) {
				edge &e = G[v][i];
				if (e.cap > 0 && level[e.to] < 0) {
					level[e.to] = level[v] + 1;
					que.push(e.to);
				}
			}
		}
	}

	//DFS
	ll dfs(int v, int t, ll f) {
		if (v == t) return f;
		for (int &i = iter[v]; i < G[v].size(); i++) {
			edge &e = G[v][i];
			if (e.cap > 0 && level[v] < level[e.to]) {
				ll d = dfs(e.to, t, min(f, e.cap));
				if (d > 0) {
					e.cap -= d;
					G[e.to][e.rev].cap += d;
					return d;
				}
			}
		}
		return 0;
	}

	//st
	ll max_flow(int s, int t) {
		ll flow = 0;
		for (;;) {
			bfs(s);
			if (level[t] < 0) return flow;
			fill(iter.begin(), iter.end(), 0);
			ll f;
			while ((f = dfs(s, t, INF)) > 0) {
				flow += f;
			}
		}
	}
};

int main() {
  int n, m;
  cin >> n >> m;
  set<int> x, y;
  vi x1(m), y1(m), x2(m), y2(m);
  rep (i, m) {
    cin >> x1[i] >> y1[i] >> x2[i] >> y2[i];
    x.insert(x1[i]);
    x.insert(x2[i]);
    y.insert(y1[i]);
    y.insert(y2[i]);
  }

  map<pii, int> xp, yp;
  int nx = 1;
  auto itr = x.begin();
  while (itr != x.end()) {
    ll temp1 = *itr;
    xp[pii(temp1, temp1)] = nx++;
    itr++;
    if (itr != x.end()) {
      ll temp2 = *itr;
      if (temp2 - 1 > temp1) {
        xp[pii(temp1 + 1, temp2 - 1)] = nx++;
      }
    }
  }

  itr = y.begin();
  while (itr != y.end()) {
    ll temp1 = *itr;
    yp[pii(temp1, temp1)] = nx++;
    itr++;
    if (itr != y.end()) {
      ll temp2 = *itr;
      if (temp2 - 1 > temp1) {
        yp[pii(temp1 + 1, temp2 - 1)] = nx++;
      }
    }
  }
  nx++;
  
  Dinic din(nx);
  // DEBUG("x");
  for (auto itr = xp.begin(); itr != xp.end(); itr++) {
    //DEBUG(*itr);
    ll cost = itr->first.second - itr->first.first + 1;
    din.add_edge(0, itr->second, cost);
  }
  //DEBUG("y");
  for (auto itr = yp.begin(); itr != yp.end(); itr++) {
    //DEBUG(*itr);
    ll cost = itr->first.second - itr->first.first + 1;
    din.add_edge(itr->second, nx - 1, cost);
  }
  
  rep (i, m) {
    for (auto itr1 = xp.lower_bound(pii(x1[i], -1)); itr1 != xp.end() and itr1->first.second <= x2[i]; itr1++) {
      for (auto itr2 = yp.lower_bound(pii(y1[i], -1)); itr2 != yp.end() and itr2->first.second <= y2[i]; itr2++) {
        int u = itr1->second, v = itr2->second;
        //DEBUG(pii(u, v));
        din.add_edge(u, v, INF);
      }
    }
  }

  ll ans = din.max_flow(0, nx - 1);
  cout << ans << endl;
}