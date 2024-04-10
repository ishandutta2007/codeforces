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
#define Sp(p) cout<<setprecision(25)<< fixed<<p<<endl;
// int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
// int dx2[8] = { 1,1,0,-1,-1,-1,0,1 }, dy2[8] = { 0,1,1,1,0,-1,-1,-1 };
vi dx = {0, 1, 0, -1}, dy = {-1, 0, 1, 0};
vi dx2 = { 1,1,0,-1,-1,-1,0,1 }, dy2 = { 0,1,1,1,0,-1,-1,-1 };
#define fio() cin.tie(0); ios::sync_with_stdio(false);
const ll MOD = 1000000007;
// const ll MOD = 998244353;
// #define mp make_pair
//#define endl '\n'


const int N = 200;
vii G(N, vi());
vi match(N);
vector<bool> used(N);
int n, m;
vi color(N, -1);

bool bipartite() {
	stack<int> st;
	color[0] = 0;
	st.push(0);
	int i, j;
	while (!st.empty()) {
		i = st.top();
		st.pop();
		for (j = 0; j < G[i].size(); j++) {
			if (color[G[i][j]] == color[i]) {
				//cout << "NO" << endl;
				return false;
			}
			else {
				if (color[G[i][j]] == -1) {
					color[G[i][j]] = 1 - color[i];
					st.push(G[i][j]);
				}
			}
		}
	}
	//cout << "YES" << endl;
	return true;
}

signed main() {
    fio();
    cin >> n >> m;

    vii dist(n, vi(n, inf));
    rep (i, n) dist[i][i] = 0;
    rep (i, m) {
        int u, v, c;
        cin >> u >> v >> c;
        u--; v--;
        G[u].push_back(v);
        G[v].push_back(u);

        if (c == 0) {
            chmin(dist[v][u], 1);
            chmin(dist[u][v], 1);
        }
        else {
            chmin(dist[u][v], 1);
            chmin(dist[v][u], -1);
        }
    }

    if (not bipartite()) {
        NO();
        return 0;
    }

    rep (k, n) {
        rep (i, n) {
            rep (j, n) {
                if (dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
    DEBUG_MAT(dist);
    rep (i, n) {
        if (dist[i][i] != 0) {
            NO();
            return 0;
        }
    }

    using P = pair<int, pii>;
    P ma(-inf, pii(0, 0));
    rep (i, n) {
        rep (j, n) {
            chmax(ma, P(dist[i][j], pii(i, j)));
        }
    }
    DEBUG(ma);
    vi ans;
    int u = ma.second.first;
    if (ma.first < 0) {
        NO();
        return 0;
    }

    YES();
    cout << ma.first << endl;
    int mi = inf;
    rep (i, n) {
        ans.push_back(dist[u][i]);
        chmin(mi, dist[u][i]);
    }
    rep (i, n) ans[i] -= mi;
    rep (i, n) {
        cout << ans[i] << " ";
    }
    cout << endl;
}