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
// int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
// int dx2[8] = { 1,1,0,-1,-1,-1,0,1 }, dy2[8] = { 0,1,1,1,0,-1,-1,-1 };
vi dx = {1, 0, -1, 0}, dy = {0, 1, 0, -1};
// vi dx2 = { 1,1,0,-1,-1,-1,0,1 }, dy2 = { 0,1,1,1,0,-1,-1,-1 };
#define fio() cin.tie(0); ios::sync_with_stdio(false);
const ll MOD = 1000000007;
// const ll MOD = 998244353;
// #define mp make_pair
//#define endl '\n'


struct dice {
  mt19937 mt;
  dice() : mt(chrono::steady_clock::now().time_since_epoch().count()) {}
  // [0, x)
  ll operator()(ll x) { return this->operator()(0, x); }
  // [x, y)
  ll operator()(ll x, ll y) {
    uniform_int_distribution<ll> dist(x, y - 1);
    return dist(mt);
  }
  vl operator()(int n, ll x, ll y) {
    vl res(n);
    for (int i = 0; i < n; i++) res[i] = this->operator()(x, y);
    return res;
  }
} rnd;

std::random_device seed_gen;
std::mt19937 engine(seed_gen());

void solve() {
    int n;
    cin >> n;
    vl a(n);
    set<pii> st;
    rep (i, n) {
        cin >> a[i];
        st.insert(pii(a[i], i));
    }
    map<pii, int> mp;
    int ma = 0;
    for (auto itr = st.begin(); itr != st.end(); itr++) {
        mp[*itr] = ma++;
    }
    rep (i, n) a[i] = mp[pii(a[i], i)];

    vi pos(ma);
    rep (i, n) {
        pos[a[i]] = i;
    }

    vector<pii> b;
    set<pii> op;
    rep (i, n) {
        for (int j = i + 1; j < n; j++) {
            if (a[i] > a[j]) {
                b.push_back(pii(i, j));
                op.insert(pii(i, j));
            }
        }
    }
    sort(all(b));


    vector<bool> used(b.size());
    vector<pii> ans;
    int cnt = 0;

    while (cnt < b.size()) {
        queue<int> qu;
        while (true) {
            while (qu.size() > 0) {
                int u = qu.front();
                qu.pop();
                rep (_, 2) {
                    if (0 <= u and u < n - 1) {
                        int v = u + 1;
                        int j = pos[u], i = pos[v];
                        if (i < j and op.count(pii(i, j))) {
                            op.erase(pii(i, j));
                            ans.push_back(pii(i, j));
                            a[i] = u; a[j] = v;
                            pos[u] = i; pos[v] = j;
                            cnt++;
                            if (cnt == b.size()) break;
                            qu.push(u);
                            qu.push(v);
                        }
                    }
                    u--;
                }
                if (cnt == b.size()) break;
            }
            if (cnt == b.size()) break;

            rep (i, n) qu.push(i);
        }
    }

    cout << ans.size() << '\n';
    rep (i, ans.size()) {
        cout << ans[i].first + 1 << " " << ans[i].second + 1 << '\n';
    }
}

signed main() {
    // fio();
    int t = 1;
    // cin >> t;    
    while (t--) {
        solve();
    }
}