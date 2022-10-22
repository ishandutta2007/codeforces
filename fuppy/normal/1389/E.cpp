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

// ll inter(pii lr1, pii lr2) {
//     if (lr2 < lr1) swap(lr1, lr2);
//     if (lr1.second <= lr2.first) return 0;
//     else {
//         int l = max(lr1.first, lr2.first);
//         int r = min(lr1.second, lr2.second);
//         return r - l;
//     }
// }

// void solve() {
//     ll n, k;
//     cin >> n >> k;
//     vector<pii> lr(2);
//     rep (i, 2) {
//         cin >> lr[i].first >> lr[i].second;
//     }
//     if (lr[0] > lr[1]) swap(lr[0], lr[1]);

//     ll ans = 0, score = inter(lr[0], lr[1]) * n;
//     if (score >= k) {
//         cout << 0 << '\n';
//         return;
//     }
//     ll pre = 0;
//     if (inter(lr[0], lr[1]) == 0) {
//         ans += lr[1].first - lr[0].second;
//         pre = lr[1].first - lr[0].second;
//     }
//     ll gain = max(lr[0].second, lr[1].second) - min(lr[0].first, lr[1].first) - inter(lr[0], lr[1]);

//     if (score + gain >= k) {
//         ll rem = k - score;
//         cout << ans + rem << '\n';
//         return;
//     }
//     score += gain;
//     ans += gain;
//     rep1 (_, n - 1) {
//         if (score >= k) break;
//         ll rem = k - score;
//         ll gain2 = min(gain, rem);
//         if (gain2 <= pre) break;
//         else {
//             score += gain2;
//             ans += pre + gain2;
//         }
//     }

//     if (score < k) {
//         ll rem = k - score;
//         ans += 2 * rem;
//     }
//     cout << ans << '\n';
// }

ll gcd(ll a, ll b) {
  if (b > a) {
    swap(a, b);
  }
//   if (b == 0) return a;
  ll r = a%b;
  while (r != 0) {
    a = b;
    b = r;
    r = a%b;
  }
  return b;
}

ll lcm(ll a, ll b) {
  return (a / gcd(a, b))*b;
}


void solve() {
    ll m, d, w;
    cin >> m >> d >> w;
    ll z = d % w;
    ll k = min(d, m);
    if ((z - 1 + w) % w == 0) {
        cout << k * (k - 1) / 2 << endl;
        return;
    }
    ll g = gcd((z - 1 + w) % w, w);
    ll h = w / g;
    ll fi;
    if (k % h == 0) fi = k / h - 1;
    else fi = k / h;

    ll ans = k * fi - h * fi * (fi + 1) / 2;

    // for (ll x = 0; x < k; x++) {
    //     for (ll y = x + h; y < k; y += h) {
    //         ans++;
    //     }
    //     // ll temp;
    //     // if ((k - x) % h == 0) temp = (k - x) / h;
    //     // else temp = (k - x) / h + 1;
    //     // ans += temp;
    // }
    cout << ans << endl;
}

signed main() {
    fio();
    int t = 1;
    cin >> t;
    while (t--) solve();
}