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

set<string> used_name;

string new_name() {
    while (true) {
        string s;
        rep (i, 6) s += (char)('a' + rnd(26));
        if (used_name.count(s) == 0) {
            used_name.insert(s);
            return s;
        }
    }
}

signed main() {
    int n;
    cin >> n;
    vector<string> s(n);
    vi a(n);
    int e = 0;
    rep (i, n) {
        cin >> s[i] >> a[i];
        used_name.insert(s[i]);
        if (a[i] == 1) e++;
    }

    set<string> emp;
    set<string> ex, te;
    for (int i = 1; i <= e; i++) {
        ex.insert(to_string(i));
        emp.insert(to_string(i));
    }
    for (int i = e + 1; i <= n; i++) {
        te.insert(to_string(i));
        emp.insert(to_string(i));
    }

    rep (i, n) {
        emp.erase(s[i]);
    }

    vector<string> t;
    vi b;
    rep (i, n) {
        if (ex.count(s[i]) and a[i] == 1) continue;
        if (te.count(s[i]) and a[i] == 0) continue;
        t.push_back(s[i]);
        b.push_back(a[i]);
    }

    if (t.size() == 0) {
        cout << 0 << endl;
        return 0;
    }

    string last;
    vector<pair<string, string>> op;
    if (emp.size() == 0) {
        string temp = new_name();
        op.push_back({t[0], temp});
        emp.insert(t[0]);
        t[0] = temp;
        last = temp;
    }
    else {
        rep (i, t.size()) {
            if (ex.count(t[i]) == 0 and te.count(t[i]) == 0) {
                last = t[i];
                break;
            }
        }
    }

    vector<vector<string>> u(2);
    rep (i, t.size()) {
        u[b[i]].push_back(t[i]);
    }

    auto itr = emp.begin();
    while (u[0].size() + u[1].size() > 1) {
        // DEBUG_MAT(u);
        // DEBUG(last);
        string tar = *itr;
        itr++;
        // DEBUG(tar);
        int ba;
        if (te.count(tar)) ba = 0;
        else ba = 1;
        // DEBUG(ba);
        rrep (i, u[ba].size()) {
            if (u[ba][i] == last) continue;

            string ori = u[ba][i];
            op.push_back({ori, tar});
            emp.erase(tar);
            if (ex.count(ori) or te.count(ori)) {
                emp.insert(ori);
            }

            u[ba].erase(u[ba].begin() + i);
            itr = emp.begin();
            break;
        }
        // DEBUG_VEC(op);
    }
    // DEBUG_MAT(u);
    // DEBUG(last);
    // for (auto itr = emp.begin(); itr != emp.end(); itr++) {
    //     cout << *itr << " ";
    // }
    // cout << endl;
    // DEBUG_VEC(op);

    assert(emp.size() == 1);
    string rem = *emp.begin();
    op.push_back({last, rem});
    cout << op.size() << endl;
    rep (i, op.size()) {
        auto [u, v] = op[i];
        cout << "move " << u << " " << v << endl;
    }
}