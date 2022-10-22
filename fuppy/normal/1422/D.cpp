#include <bits/stdc++.h>
 
// #include <atcoder/all>
 
using namespace std;
// using namespace atcoder;
 
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
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rep1(i,n) for(int i=1;i<=(int)(n);i++)
#define rrep(i,n) for(int i=(int)(n)-1;i>=0;i--)
#define rrep1(i,n) for(int i=(int)(n);i>0;i--)
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
// int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
// int dx2[8] = { 1,1,0,-1,-1,-1,0,1 }, dy2[8] = { 0,1,1,1,0,-1,-1,-1 };
vi dx = {1, 0, -1, 0}, dy = {0, 1, 0, -1};
// vi dx2 = { 1,1,0,-1,-1,-1,0,1 }, dy2 = { 0,1,1,1,0,-1,-1,-1 };
#define fio() cin.tie(0); ios::sync_with_stdio(false);
const ll MOD = 1000000007;
// const ll MOD = 998244353;
// #define mp make_pair
//#define endl '\n'
 
const int N = 111111;
vector<vector<pll>> G(N);
 
vl dijkstra(int s, int n){
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
 
 
void solve() {
    ll n, m;
    cin >> n >> m;
    vector<pii> yx(m + 2);
    rep (i, m + 2) {
        cin >> yx[i].first >> yx[i].second;
        yx[i].first--;
        yx[i].second--;
    }
 
    using P = pair<pii, int>;    
    vector<P> yx1(m + 2), yx2(m + 2);
    rep (i, yx.size()) {
        yx1[i].first = yx[i];
        yx1[i].second = i;
    }
    yx2 = yx1;
    sort(all(yx1));
    sort(all(yx2), [](P& a, P& b) {
        return a.first.second < b.first.second;
    });
    // DEBUG_VEC(yx1);
    // DEBUG_VEC(yx2);
    
    rep (i, yx1.size()) {
        int idx = yx1[i].second;
        if (idx <= 1) continue;
        for (int d = -3; d <= 3; d++) {
            if (d == 0) continue;
            int ni = i + d;
            if (not in(ni, 0, yx1.size())) continue;
            int idx2 = yx1[ni].second;
            if (idx2 <= 1) continue;
            G[idx].push_back(pll(abs(yx1[i].first.first - yx1[ni].first.first), idx2));
        }
    }
 
    rep (i, yx2.size()) {
        int idx = yx2[i].second;
        if (idx <= 1) continue;
        for (int d = -3; d <= 3; d++) {
            if (d == 0) continue;
            int ni = i + d;
            if (not in(ni, 0, yx2.size())) continue;
            int idx2 = yx2[ni].second;
            if (idx2 <= 1) continue;
            G[idx].push_back(pll(abs(yx2[i].first.second - yx2[ni].first.second), idx2));
        }
    }
 
    // DEBUG_MAT(G);
    
    rep (i, 2) {
        pii yx1 = yx[i];
        REP (j, 2, yx.size()) {
            pii yx2 = yx[j];
            G[i].push_back(pll(min(abs(yx1.first - yx2.first), abs(yx1.second - yx2.second)), j));
            G[j].push_back(pll(abs(yx1.first - yx2.first) + abs(yx1.second - yx2.second), i));
        }
    }
 
    G[0].push_back(pll(abs(yx[0].first - yx[1].first) + abs(yx[0].second - yx[1].second), 1));
    G[1].push_back(pll(abs(yx[0].first - yx[1].first) + abs(yx[0].second - yx[1].second), 0));
 
    // DEBUG_MAT(G);
 
    vl d = dijkstra(0, yx.size());
    // DEBUG_VEC(d);
    cout << d[1] << endl;
}
 
signed main() {
    fio();
 
    int t = 1;
    // cin >> t;
    while (t--) solve();
}