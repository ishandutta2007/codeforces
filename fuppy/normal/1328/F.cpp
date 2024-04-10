#include <bits/stdc++.h>
 
using namespace std;
 
#define DEBUG(x) cerr<<#x<<": "<<x<<endl;
#define DEBUG_VEC(v) cerr<<#v<<":";for(int i=0;i<v.size();i++) cerr<<" "<<v[i]; cerr<<endl;
#define DEBUG_MAT(v) cerr<<#v<<endl;for(int i=0;i<v.size();i++){for(int j=0;j<v[i].size();j++) {cerr<<v[i][j]<<" ";}cerr<<endl;}
typedef long long ll;
//#define int ll
 
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
#define rep(i,n) for(int i=0;i<(n);i++)
#define rep1(i,n) for(int i=1;i<=(n);i++)
#define rrep(i,n) for(int i=(n)-1;i>=0;i--)
#define rrep1(i,n) for(int i=(n);i>0;i--)
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

map<ll, pll> solve(vl a, bool rev) {
    ll num = 0;
    map<ll, pll> mp;
    int x = a[0] - 1;
    if (rev) x *= -1;
    mp[x] = pll(0, 0);
    num = 1;
    ll pre = 0;
    for (int i = 1; i < a.size(); i++) {
        int x = a[i] - 1;
        if (rev) x *= -1;
        if (a[i] == a[i - 1]) {
            num++;
            continue;
        }
        else {
            ll diff = (a[i] - 1) - a[i - 1];
            pre += diff * num;
            mp[x] = pll(pre, num);
            pre += num;
            num++;
        }
    }
    return mp;
}

signed main() {
    fio();
    int n, k;
    cin >> n >> k;
    vl a(n);
    rep (i, n) {
        cin >> a[i];
        //a[i]++;
    }

    sort(all(a));
    map<ll, pll> sm = solve(a, false);
    vl b(n);
    rep (i, n) b[i] = -a[i];
    sort(all(b));
    map<ll, pll> la = solve(b, true);

    // for (auto itr = sm.begin(); itr != sm.end(); itr++) {
    //     DEBUG(*itr);
    // }
    // for (auto itr = la.begin(); itr != la.end(); itr++) {
    //     DEBUG(*itr);
    // }

    map<ll, int> num;
    rep (i, n) num[a[i]]++;

    ll ans = INF;
    for (auto itr = num.begin(); itr != num.end(); itr++) {
        ll x = itr->first;
        ll y = itr->second;
        if (y >= k) {
            chmin(ans, 0LL);
            continue;
        }
        assert(sm.count(x - 1));
        assert(la.count(x + 1));

        ll add = INF;
        pll la_num = la[x + 1];
        if (la_num.second + num[x] >= k) {
            chmin(add, la_num.first + k - num[x]);
        }
        pll sm_num = sm[x - 1];
        if (sm_num.second + num[x] >= k) {
            chmin(add, sm_num.first + k - num[x]);
        }
        chmin(add, la_num.first + sm_num.first + k - num[x]);
        chmin(ans, add);
    }
    cout << ans << endl;
}