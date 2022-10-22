#include <bits/stdc++.h>
#define rf(x) (x)=0;while(*p<48)p++;while(47<*p)(x)=((x)<<3)+((x)<<1)+(*p++&15);
//#define rf(x) (x)=0;while(*p<48)im=*p=='-';while(47<*p)(x)=((x)<<3)+((x)<<1)+(*p++&15);if(im)(x)=-(x);
#define pb push_back
#define eb emplace_back
#define sz(V) ((int)(V).size())
#define allv(V) ((V).begin()),((V).end())
#define befv(V) ((V)[(sz(V)-2)])
#define sorv(V) sort(allv(V))
#define revv(V) reverse(allv(V))
#define univ(V) (V).erase(unique(allv(V)),(V).end())
#define clv(V) (V).clear()
#define upmin(a,b) (a)=min((a),(b))
#define upmax(a,b) (a)=max((a),(b))
#define rb(x) ((x)&(-(x)))
#define cb(x) (x)=(!(x))
#define INF (0x3f3f3f3f)
#define INFLL (0x3f3f3f3f3f3f3f3fll)
#define INFST (0x7f7f7f7f)
#define INFLLST (0x7f7f7f7f7f7f7f7fll)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<int, ll> pil;
typedef pair<ll, int> pli;
typedef pair<ld, ld> pdd;
typedef complex<ld> base;
const ld EPS = (ld)1e-7;
const ld PI = acos(0) * 2;
bool isZero(const ld& x) { return abs(x) <= EPS; }
int sign(const ld& x) { return isZero(x) ? 0 : (0 < x ? 1 : -1); }
ll gcd(ll a, ll b) { for(;b;a%=b,swap(a,b)){} return abs(a); }
pll operator + (const pll& a, const pll& b) { return pll(a.first+b.first, a.second+b.second); }
pll operator - (const pll& a, const pll& b) { return pll(a.first-b.first, a.second-b.second); }
pll operator * (const pll& a, const ll& b) { return pll(a.first*b, a.second*b); }
ll operator * (const pll& a, const pll& b) { return a.first*b.second - b.first*a.second; }
ll ccw(const pll& a, const pll& b, const pll& c) { return a*b + b*c + c*a; }
void fg(vector<int> G[], int a, int b) { G[a].pb(b); G[b].pb(a); }
void fg(vector<pii> G[], int a, int b, int c) { G[a].pb({b, c}); G[b].pb({a, c}); }

namespace STWG {
	const int MX = 455;
	ll G[MX][MX];
	int vst[MX];

	void init(int n) { memset(G, 0, sizeof G); }
	void add(int a, int b, int d) {
		if(a != b) G[a][b] = G[b][a] = d;
	}

	pii min_cut(int n, int st, ll &res) {
		ll dist[MX] = {};
		int vis[MX];
		ll cur = INFLL;
		int s = st, e = -1;
		memcpy(vis, vst, sizeof vst);
		dist[st] = INFLL;
		while(true) {
			int mx = 0;
			for(int i = 1; i <= n; i++)
				if(!vis[i] && (!mx || dist[mx] < dist[i])) mx = i;
			if(!mx) break;
			cur = dist[mx]; e = s; s = mx; vis[mx] = 1;
			for(int i = 1; i <= n; i++) dist[i] += G[mx][i];
		}
		upmin(res, cur);
		return pii(s, e);
	}
	ll run(int n) {
		if(n < 2) return 0;
		memset(vst, 0, sizeof vst);
		ll res = INFLL;
		int t = 1, u;
		for(int i = 0; i < n-1; i++) {
			tie(t, u) = min_cut(n, t, res);
			vst[u] = 1;
			for(int i = 1; i <= n; i++) {
				if(vst[i] || t == i) continue;
				G[t][i] += G[u][i];
				G[i][t] += G[u][i];
			}
		}
		return res;
	}
};


typedef long long lint;
namespace DINIC {
	const int MAXN = 455;
	struct edg{ int pos, cap, rev; };
	vector<edg> gph[MAXN];
	void clear(){ for(int i=0; i<MAXN; i++) gph[i].clear(); }
	void add(int s, int e, int x){
		gph[s].push_back({e, x, (int)gph[e].size()});
		gph[e].push_back({s, 0, (int)gph[s].size()-1});
	}
	int dis[MAXN], pnt[MAXN];
	bool bfs(int src, int sink){
		memset(dis, 0, sizeof(dis));
		memset(pnt, 0, sizeof(pnt));
		queue<int> que;
		que.push(src);
		dis[src] = 1;
		while(!que.empty()){
			int x = que.front();
			que.pop();
			for(auto &e : gph[x]){
				if(e.cap > 0 && !dis[e.pos]){
					dis[e.pos] = dis[x] + 1;
					que.push(e.pos);
				}
			}
		}
		return dis[sink] > 0;
	}
	int dfs(int x, int sink, int f){
		if(x == sink) return f;
		for(; pnt[x] < gph[x].size(); pnt[x]++){
			edg e = gph[x][pnt[x]];
			if(e.cap > 0 && dis[e.pos] == dis[x] + 1){
				int w = dfs(e.pos, sink, min(f, e.cap));
				if(w){
					gph[x][pnt[x]].cap -= w;
					gph[e.pos][e.rev].cap += w;
					return w;
				}
			}
		}
		return 0;
	}
	lint match(int src, int sink){
		lint ret = 0;
		while(bfs(src, sink)){
			int r;
			while((r = dfs(src, sink, 2e9))) ret += r;
		}
		return ret;
	}
}



bitset<555> chk[555];

vector<int> XV, YV;
int SX[55], SY[55], EX[55], EY[55];

int N, K, XL, YL;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> N >> K;
	for(int i = 1; i <= K; i++) {
		cin >> SX[i] >> SY[i] >> EX[i] >> EY[i];
		XV.eb(SX[i]); XV.eb(EX[i]);
		if(1 < SX[i]) XV.eb(SX[i]-1);
		if(EX[i] < N) XV.eb(EX[i]+1);

		YV.eb(SY[i]); YV.eb(EY[i]);
		if(1 < SY[i]) YV.eb(SY[i]-1);
		if(EY[i] < N) YV.eb(EY[i]+1);
	}
	XV.eb(1); XV.eb(N); YV.eb(1); YV.eb(N);

	sorv(XV); univ(XV);
	sorv(YV); univ(YV);

	XL = sz(XV); YL = sz(YV);
	STWG :: init(2 + XL + YL);
	XV.eb(N+1); YV.eb(N+1);

	ll Sum = 0;
	for(int i = 0; i < XL; i++) {
		DINIC :: add(1, 2+i, XV[i+1]-XV[i]);
		Sum += XV[i+1] - XV[i];
	}
	for(int i = 0; i < YL; i++) {
		DINIC :: add(2+XL+i, 2+XL+YL, YV[i+1]-YV[i]);
		Sum += YV[i+1] - YV[i];
	}

	for(int i = 1; i <= K; i++) {
		for(int j = 0; j < XL; j++) {
			// [XV[j], XV[j+1])
			if(XV[j+1] <= SX[i] || EX[i] < XV[j]) continue;
			for(int k = 0; k < YL; k++) {
				if(YV[k+1] <= SY[i] || EY[i] < YV[k]) continue;
				chk[j][k] = true;
			}
		}
	}

	for(int i = 0; i < XL; i++) for(int j = 0; j < YL; j++) {
		if(chk[i][j]) {
			DINIC :: add(2+i, 2+XL+j, INF);
		}
	}

	ll Ans = DINIC :: match(1, 2 + XL + YL);

	cout << Ans << endl;
	return 0;
}