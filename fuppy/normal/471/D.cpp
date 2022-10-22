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


// S  S[i:|S|-1]  A  O(|S|) 
vi z_algorithm(vi s) {
    int n = s.size();
    vi a(n);
    int c = 0;
    for (int i = 1; i < n; i++){
    if (i+a[i-c] < c+a[c]) {
        a[i] = a[i-c];
    } else {
        int j = max(0, c+a[c]-i);
        while (i+j < n && s[j] == s[i+j]) ++j;
            a[i] = j;
            c = i;
        }
    }
    a[0] = n;
    return a;
}


signed main() {
    fio();
    int n, w;
    cin >> n >> w;
    vi a(n), b(w);
    rep (i, n) cin >> a[i];
    rep (i, w) cin >> b[i];
    vector<int> a2(n - 1), b2(w - 1);
    rep (i, n - 1) {
        a2[i] = a[i + 1] - a[i];
        a2[i] += inf;
    }
    rep (i, w - 1) {
        b2[i] = b[i + 1] - b[i];
        b2[i] += inf;
    }
    if (n < w) {
        cout << 0 << endl;
        return 0;
    }
    if (w == 1) {
        cout << n << endl;
        return 0;
    }
    // DEBUG_VEC(b2);
    rep (i, a2.size()) {
        b2.push_back(a2[i]);
    }

    vi common = z_algorithm(b2);

    int cnt = 0;
    for (int i = w - 1; i < b2.size(); i++) {
        if (common[i] >= w - 1) cnt++;
    }
    cout << cnt << endl;
}