//*
#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
//*/
 
#include <bits/stdc++.h>
 
// #include <atcoder/all>
 
using namespace std;
// using namespace atcoder;
 
#define DEBUG(x) cerr<<#x<<": "<<x<<endl;
#define DEBUG_VEC(v) cerr<<#v<<":";for(int i=0;i<v.size();i++) cerr<<" "<<v[i]; cerr<<endl;
#define DEBUG_MAT(v) cerr<<#v<<endl;for(int i=0;i<v.size();i++){for(int j=0;j<v[i].size();j++) {cerr<<v[i][j]<<" ";}cerr<<endl;}
typedef long long ll;
// #define int ll
 
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
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rep1(i,n) for(int i=1;i<=(int)(n);i++)
#define rrep(i,n) for(int i=(int)(n)-1;i>=0;i--)
#define rrep1(i,n) for(int i=(int)(n);i>0;i--)
#define REP(i,a,b) for(int i=a;i<b;i++)
#define in(x, a, b) (a <= x && x < b)
#define all(c) c.begin(),c.end()
void YES(bool t=true) {cout<<(t?"YES":"NO")<<endl;}
void Yes(bool t=true) {cout<<(t?"Yes":"No")<<endl;}
void yes(bool t=true) {cout<<(t?"yes":"no")<<endl;}
void NO(bool t=true) {cout<<(t?"NO":"YES")<<endl;}
void No(bool t=true) {cout<<(t?"No":"Yes")<<endl;}
void no(bool t=true) {cout<<(t?"no":"yes")<<endl;}
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a = b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a = b; return 1; } return 0; }
#define UNIQUE(v) v.erase(std::unique(v.begin(), v.end()), v.end());
const ll inf = 1000000001;
const ll INF = (ll)1e18 + 1;
const long double pi = 3.1415926535897932384626433832795028841971L;
int popcount(ll t) { return __builtin_popcountll(t); }
// int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
// int dx2[8] = { 1,1,0,-1,-1,-1,0,1 }, dy2[8] = { 0,1,1,1,0,-1,-1,-1 };
vi dx = {0, 1, 0, -1}, dy = {-1, 0, 1, 0};
// vi dx2 = { 1,1,0,-1,-1,-1,0,1 }, dy2 = { 0,1,1,1,0,-1,-1,-1 };
struct Setup_io {
    Setup_io() {
        ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
        cout << fixed << setprecision(25);
    }
} setup_io;
// const ll MOD = 1000000007;
const ll MOD = 998244353;
// #define mp make_pair
//#define endl '\n'


vl dijkstra(int s, int n, vector<vector<pll>>& G){
	priority_queue<pll, vector<pll>, greater<pll> > pq;
	int i;
	vl d(n, INF);
	d[s]=0;
	pq.push(make_pair(0,s));
	
	while(!pq.empty()){
		pll f=pq.top();
		pq.pop();
		int u=f.second;
		if(d[u]<f.first){
			continue;
		}
		for (i = 0; i < G[u].size(); i++) {
			int v=G[u][i].second;
			if (d[v] > d[u] + G[u][i].first) {
				d[v] = d[u] + G[u][i].first;
				pq.push(make_pair(d[v], v));
			}
		}
	}
	return d;
}


// vector<pll> tu[601][601];
vll ma(601, vl(601, -1));

void solve() {
    int n, m;
    cin >> n >> m;

    vector<vector<pll>> G(n);
    vll dist(n, vl(n, INF));
    rep (i, m) {
        int u, v, w;
        cin >> u >> v >> w;
        u--; v--;
        G[u].push_back(pll(w, v));
        G[v].push_back(pll(w, u));
        dist[u][v] = dist[v][u] = w;
    }
    rep (i, n) dist[i][i] = 0;
    rep (k, n) rep (i, n) rep (j, n) {
        chmin(dist[i][j], dist[i][k] + dist[k][j]);
    }

    // rep (i, n) {
    //     dist[i] = dijkstra(i, n, G);
    // }

    int q;
    cin >> q;
    using P = pair<ll, pii>;
    vector<P> tri(q);
    rep (i, q) {
        int u, v, w;
        cin >> u >> v >> w;
        u--; v--;
        tri[i] = P(w, pii(u, v));
    }


    for (auto temp: tri) {
        ll M = temp.first;
        int s = temp.second.first, t = temp.second.second;
        rep (u, n) {
            ll now = dist[s][u];
            ll rem = M - now;
            if (rem < 0) continue;
            chmax(ma[t][u], rem);
        }
    }


    // rep (t, n) {
    //     rep (u, n) {
    //         for (pll temp: G[u]) {
    //             int v = temp.second;
    //             ll d = temp.first + dist[t][v];
    //             tu[t][u].push_back(pll(d, v));
    //         }
    //     }
    // }

    vii used(n, vi(n));
    rep (t, n) {
        rep (u, n) {
            for (pll temp: G[u]) {
                int v = temp.second;
                ll d = temp.first + dist[t][v];
                if (d <= ma[t][u]) {
                    used[u][v] = used[v][u] = true;
                }
            }
        }
    }

    int ans = 0;
    rep (i, n) rep (j, n) ans += used[i][j];
    ans /= 2;

    cout << ans << endl;
}



signed main() {
    int t = 1;
    // cin >> t;
    while (t--) solve();
}