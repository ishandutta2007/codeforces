#include <bits/stdc++.h>

using namespace std;
 
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


signed main() {
    int n, k;
    cin >> n >> k;
    vl c(n);
    rep (i, n) cin >> c[i];
    sort(all(c));
    reverse(all(c));

    ll sum = 0;
    rep (i, n) sum += c[i];

    ll low, high;
    if (sum % n == 0) low = high = sum / n;
    else {
        low = sum / n;
        high = low + 1;
    }

    ll ok = c[0], ng = high - 1;
    while (ng + 1 < ok) {
        ll mid = (ok + ng) / 2;
        ll need = 0;
        rep (i, n) {
            if (c[i] > mid) need += c[i] - mid;
        }
        if (need <= k) ok = mid;
        else ng = mid;
    }

    ll p1 = ok;
    ok = c.back(); ng = low + 1;
    while (ok + 1 < ng) {
        ll mid = (ok + ng) / 2;
        ll need = 0;
        rep (i, n) {
            if (c[i] < mid) need += mid - c[i];
        }
        if (need <= k) ok = mid;
        else ng = mid;
    }
    ll p2 = ok;
    cout << p1 - p2 << endl;
}



// long double dist(pll xy1, pll xy2 = pll(0, 0)) {
//     return sqrtl((xy1.first - xy2.first) * (xy1.first - xy2.first) + (xy1.second - xy2.second) * (xy1.second - xy2.second));
// }

// signed main() {
//     fio();
//     pll a, b, c;
//     cin >> a.first >> a.second >> b.first >> b.second >> c.first >> c.second;
//     a = a - c;
//     b = b - c;
//     int n;
//     cin >> n;
//     vector<pll> xy(n);
//     rep (i, n) {
//         cin >> xy[i].first >> xy[i].second;
//         xy[i] = xy[i] - c;
//     }

//     if (n == 1) {
//         long double ans = min(dist(xy[0], a) + dist(xy[0]), dist(xy[0], b) + dist(xy[0]));
//         Sp(ans);
//         return 0;
//     }

//     long double ans = 0;
//     vector<pair<long double, int>> ai(n), bi(n);
//     rep (i, n) {
//         ans += 2 * dist(xy[i]);
//         ai[i].first = dist(xy[i], a) - dist(xy[i]);
//         bi[i].first = dist(xy[i], b) - dist(xy[i]);
//         ai[i].second = bi[i].second = i;
//     }

//     sort(all(ai));
//     sort(all(bi));

//     long double diff = INF;
//     rep (i, 3) {
//         rep (j, 3) {
//             if (i == 2 and j == 2) continue;
//             long double temp = 0;
//             if (i < 2 and j < 2) {
//                 if (ai[i].second == bi[j].second) continue;
//             }
//             if (i < 2) temp += ai[i].first;
//             if (j < 2) temp += bi[j].first;
//             chmin(diff, temp);
//         }
//     }
//     ans += diff;
//     Sp(ans);
// }