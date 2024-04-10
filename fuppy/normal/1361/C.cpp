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
// const ll MOD = 998244353;
// #define mp make_pair
//#define endl '\n'
 
int n;
vector<pii> edges;
int m = 1 << 20;
vi num(m);
 

class UnionFind {
public:
  int n;
  vi par; //e
  vi ran; //[
  vi num; //vf
  int g; // group
 
  UnionFind(int _n) {
    n = _n;
    g = n;
    par.resize(n); ran.resize(n); num.resize(n);
    for (int i = 0; i < n; i++) {
      par[i] = i; ran[i] = 0; num[i] = 1;
    }
  }
 
  //
  int find(int x) {
    if (par[x] == x) {
      return x;
    }
    else {
      return par[x] = find(par[x]);
    }
  }
 
  //xyW
  void unite(int x, int y) {
    x = find(x); y = find(y);
    int numsum = num[x] + num[y];
    if (x == y) {
      return;
    }
    if (ran[x]<ran[y]) {
      par[x] = y;
    }
    else {
      par[y] = x;
      if (ran[x] == ran[y]) {
        ran[x]++;
      }
    }
    num[x] = num[y] = numsum;
    g--;
  }
 
  //xyW
  bool same(int x, int y) {
    return find(x) == find(y);
  }
 
};
 
 
bool judge(int mask) {
    UnionFind uf(mask + 1);
    fill(all(num), 0);
    rep (i, edges.size()) {
        int u = edges[i].first & mask, v = edges[i].second & mask;
        uf.unite(u, v);
        num[u]++;
        num[v]++;
    }
 
    set<int> st;
    rep (i, mask + 1) {
        if (num[i] % 2 == 1) return false;
        if (num[i] > 0) {
            st.insert(uf.find(i));
        }
    }
    return st.size() == 1;
}
 
 
using P = pair<int, pii>;
vector<set<P>> G;
vector<vector<P>> nex;
queue<int> qu;
using P2 = pair<pii, pii>;
vector<P2> temp;
 
void dfs(int now, int par, int i_now, int i_par) {
    qu.push(now);
    while (G[now].size() > 0) {
        auto itr = G[now].begin();
        int u = now, v = itr->first;
        int i1 = itr->second.first, i2 = itr->second.second;
        // temp.push_back({pii(u, v), pii(i1, i2)});
        nex[u].push_back(P(v, pii(i1, i2)));
        // DEBUG(make_pair(pii(u, v), pii(i1, i2)));
        assert(G[v].count(P(u, pii(i2, i1))));
        G[v].erase(P(u, pii(i2, i1)));
        G[u].erase(itr);
        dfs(v, now, i2, i1);
    }
    temp.push_back(P2(pii(now, par), pii(i_now, i_par)));
}
 
void solve(int mask) {
    nex.resize(mask + 1);
    G.resize(mask + 1);
    int start;
    rep (i, edges.size()) {
        int u = edges[i].first, v = edges[i].second;
        u = u & mask; v = v & mask;
        start = u;
        if (qu.size() == 0) qu.push(u);
        G[u].insert(P(v, pii(2 * i + 1, 2 * i + 2)));
        G[v].insert(P(u, pii(2 * i + 2, 2 * i + 1)));
    }
 
    dfs(start, -1, -1, -1);
    // DEBUG_VEC(temp);

    // int now = -1;
    // while (qu.size() > 0) {
    //     int i = qu.front();
    //     qu.pop();
    //     if (G[i].size() == 0) continue;
    //     dfs(i);
    //     if (now == -1) now = i;
    //     // DEBUG_VEC(temp);
    //     rrep (j, temp.size()) {
    //         int u = temp[j].first.first, v = temp[j].first.second;
    //         pii ij = temp[j].second;
    //         nex[u].push_back(P(v, ij));
    //     }
    //     temp.clear();
    // }
    // DEBUG_MAT(nex);
    
    // int now = start;
    // vi ans;
    // while (nex[now].size() > 0) {
    //     ans.push_back(nex[now].back().second.first);
    //     ans.push_back(nex[now].back().second.second);
    //     int nn = nex[now].back().first;
    //     nex[now].pop_back();
    //     now = nn;
    // }
    // assert(ans.size() == 2 * n);
    // rep (i, ans.size()) {
    //     cout << ans[i] << " ";
    // }
    // cout << endl;
    rep (i, temp.size() - 1) {
      cout << temp[i].second.first << " " <<  temp[i].second.second << " ";
    }
    cout << endl;
}
 
signed main() {
    fio();
    cin >> n;
    rep (i, n) {
        int u, v;
        cin >> u >> v;
        edges.push_back(pii(u, v));
    }
 
    ll ans = 0;
    for (int i = 20; i >= 1; i--) {
        int mask = (1 << i) - 1;
        if (judge(mask)) {
            ans = i;
            break;
        }
    }
    cout << ans << endl;
 
    if (ans == 0) {
        rep1 (i, 2 * n) {
            cout << i << " ";
        }
        cout << endl;
        return 0;
    }
 
    solve((1 << ans) - 1);
}