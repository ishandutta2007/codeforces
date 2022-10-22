
#include "bits/stdc++.h"

using namespace std;

#define DEBUG(x) cout<<#x<<": "<<x<<endl;
#define DEBUG_VEC(v) cout<<#v<<":";for(int i=0;i<v.size();i++) cout<<" "<<v[i]; cout<<endl

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
#define fi first
#define se second
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rep1(i,n) for(int i=1;i<=(int)(n);i++)
#define in(x, a, b) (a <= x && x < b)
#define all(c) c.begin(),c.end()
const ll inf = 1000000001;
const ll INF = 2e18;
const ll MOD = 1000000007;
//const ll mod = 1000000009;
const double pi = 3.14159265358979323846;
#define Sp(p) cout<<setprecision(15)<< fixed<<p<<endl;
int dx[4] = { 1,0, -1,0 }, dy[4] = { 0,1,0,-1 };
int dx2[8] = { 1,1,0,-1,-1,-1,0,1 }, dy2[8] = { 0,1,1,1,0,-1,-1,-1 };
#define fio() cin.tie(0); ios::sync_with_stdio(false);

const int N = 100010;
const int K = 110;
vii G(N);
vi d(N);


int main() {
	fio();
	int n, m, k, s;
	cin >> n >> m >> k >> s;
	vii sina2town(k);
	vi town2sina(n);
	vii near(n, vi(k));
	rep(i, n) {
		cin >> town2sina[i];
		town2sina[i]--;
		sina2town[town2sina[i]].push_back(i);
	}
	rep(i, m) {
		int u, v;
		cin >> u >> v;
		u--; v--;
		G[u].push_back(v); G[v].push_back(u);
	}
	rep(i, k) {
		fill(all(d), inf);
		queue<pii> que;
		rep(j, sina2town[i].size()) {
			que.push(pii(sina2town[i][j], 0));
			d[sina2town[i][j]] = 0;
		}
		while (!que.empty()) {
			pii now = que.front();
			que.pop();
			int u = now.first;
			int cost = now.second;
			if (d[u] < cost) {
				continue;
			}
			rep(j, G[u].size()) {
				if (d[G[u][j]] > cost + 1) {
					d[G[u][j]] = cost + 1;
					que.push(pii(G[u][j], cost + 1));
					near[G[u][j]][i] = cost + 1;
				}
			}
		}
	}
	rep(i, n) {
		sort(all(near[i]));
	}
	rep(i, n) {
		int cnt = 0;
		rep(j, s) {
			cnt += near[i][j];
		}
		cout << cnt << " ";
	}
	cout << endl;

}