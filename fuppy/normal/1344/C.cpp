#include <bits/stdc++.h>
 
using namespace std;
 
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

int n, m; //_
#define N 200100
vii H(N, vi()); //OtXg\
vii rH(N, vi()); //tOt
vi vr; //A
vector<bool> used(N); //
vi cmp(N); //Ag|WJ

void add_edge(int from, int to) {
	H[from].push_back(to);
	rH[to].push_back(from);
}

void dfs(int v) {
	used[v] = true;
	for (int i = 0; i < H[v].size(); i++) {
		if (!used[H[v][i]]) {
			dfs(H[v][i]);
		}
	}
	vr.push_back(v);
}

void rdfs(int v, int k) {
	used[v] = true;
	cmp[v] = k;
	for (int i = 0; i < rH[v].size(); i++) {
		if (!used[rH[v][i]]) {
			rdfs(rH[v][i], k);
		}
	}
}


int scc() {
	fill(used.begin(), used.end(), false);
	vr.clear();
	for (int v = 0; v < n; v++) {
		if (!used[v]) dfs(v);
	}
	fill(used.begin(), used.end(), false);
	int k = 0;
	for (int i = vr.size() - 1; i >= 0; i--) {
		if (!used[vr[i]]) rdfs(vr[i], k++);
	}
	return k;
}

vector<vii> G(2);
vii visited(2);

void dfs(int i, int now) {
    visited[i][now] = true;
    for (int v: G[i][now]) {
        if (not visited[i][v]) dfs(i, v);
    }
}

void solve() {
    cin >> n >> m;

    rep (i, 2) {
        G[i].resize(n);
        visited[i].resize(n);
    }

    rep (i, m) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        G[0][u].push_back(v);
        G[1][v].push_back(u);
        add_edge(u, v);
    }

    int num = scc();
    if (num != n) {
        cout << -1 << endl;
        return;
    }

    string ans;
    int cnt = 0;
    rep (i, n) {
        if (not visited[0][i] and not visited[1][i]) {
            cnt++;
            ans += 'A';
        }
        else {
            ans += 'E';
        }
        if (not visited[0][i]) dfs(0, i);
        if (not visited[1][i]) dfs(1, i);
    }
    cout << cnt << endl;
    cout << ans << endl;
}


signed main() {
    fio();

    int t;
    // cin >> t;
    t = 1;
    while (t--) {
        solve();
    }
}