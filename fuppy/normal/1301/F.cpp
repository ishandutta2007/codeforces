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

int h, w, k;
int p2u(pii a) {
	return a.first * w + a.second;
}
pii u2p(int u) {
	return pii(u / w, u % w);
}

vector<pii> G[1000100];
int dist[40][1000100];
int c[1000][1000];
vector<pii> c2yx[40];

signed main() {
	scanf("%d %d %d", &h, &w, &k);
	rep (i, h) {
		rep (j, w) {
			scanf("%d", &c[i][j]);
			c[i][j]--;
			c2yx[c[i][j]].emplace_back(i, j);
		}
	}

	int n = h * w + k;
	
	rep (i, k) rep (j, n) dist[i][j] = inf;
	rep (i, k) {
		deque<pii> qu;
		qu.push_back(pii(0, h * w + i));
		dist[i][h * w + i] = 0;
		while (qu.size() > 0) {
			int cost = qu.front().first, u = qu.front().second;
			qu.pop_front();
			if (u >= h * w) {
				int color = u - h * w;
				for (pii p: c2yx[color]) {
					int v = p2u(p);
					if (dist[i][v] <= cost) continue;
					dist[i][v] = cost;
					qu.push_front({cost, v});
				}
				continue;
			}
			else {
				pii p = u2p(u);
				int v = h * w + c[p.first][p.second];
				if (dist[i][v] > cost + 1) {
					qu.push_back({cost + 1, v});
					dist[i][v] = cost + 1;
				}
			}
			pii p = u2p(u);
			rep (k, 4) {
				pii q = p;
				q.first += dy[k];
				q.second += dx[k];
				if (not in(q.first, 0, h) or not in(q.second, 0, w)) continue;
				int v = p2u(q);
				if (dist[i][v] > cost + 1) {
					qu.push_back({cost + 1, v});
					dist[i][v] = cost + 1;
				}
			}
		}
	}
	//DEBUG_MAT(dist);

	int q;
	scanf("%d", &q);
	while (q--) {
		int y1, x1, y2, x2;
		scanf("%d %d %d %d", &y1, &x1, &y2, &x2);
		y1--; x1--; y2--; x2--;
		int u = p2u(pii(y1, x1)), v = p2u(pii(y2, x2));
		int ans = abs(y2 - y1) + abs(x2 - x1);
		rep (i, k) {
			chmin(ans, dist[i][u] + dist[i][v] + 1);
		}
		printf("%d\n", ans);
	}
}