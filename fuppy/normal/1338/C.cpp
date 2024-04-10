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
//int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
//int dx2[8] = { 1,1,0,-1,-1,-1,0,1 }, dy2[8] = { 0,1,1,1,0,-1,-1,-1 };
vi dx = {1, 0, -1, 0}, dy = {0, 1, 0, -1};
vi dx2 = { 1,1,0,-1,-1,-1,0,1 }, dy2 = { 0,1,1,1,0,-1,-1,-1 };
#define fio() cin.tie(0); ios::sync_with_stdio(false);
const ll MOD = 1000000007;
//const ll MOD = 998244353;
// #define mp make_pair
//#define endl '\n'

ll ori_n;
ll n;

ll solve() {
    cin >> n;
    ori_n = n;
    n--;
    vi perm;
    if (n % 3 == 0) perm = {0, 1, 2, 3};
    else if (n % 3 == 1) perm = {0, 2, 3, 1};
    else perm = {0, 3, 1, 2};

    int zou = 0;
    ll mask = 1;
    while ((mask << 2) <= (n + 1)) {
        mask <<= 2;
        zou += 2;
    }

    ll add_mask;
    if (n % 3 == 0) add_mask = mask;
    else if (n % 3 == 1) add_mask = (mask << 1);
    else add_mask = mask + (mask << 1);
    //DEBUG(add_mask);

    n++;
    n -= mask;
    n /= 3;
    //DEBUG(n);
    mask >>= 2;
    zou -= 2;

    ll ans = add_mask;
    while (mask > 0) {
        ll mask2 = mask + (mask << 1);
        //DEBUG(mask2);
        ll m = n & mask2;
        m >>= zou;
        ans += perm[m] * mask;

        mask >>= 2;
        zou -= 2;
    }
    cout << ans << endl;
    return ans;
}

signed main() {
    fio();

    // set<int> st;
    // vl a;
    // rep1 (i, 1270) {
    //     if (st.count(i)) continue;
    //     for (int j = i + 1; j <= 10000; j++) {
    //         int k = i ^ j;
    //         if (st.count(j) or st.count(k)) continue;
    //         //cout << i << " " << j << " " << k << endl;
    //         st.insert(i);
    //         st.insert(j);
    //         st.insert(k);
    //         a.push_back(i);
    //         a.push_back(j);
    //         a.push_back(k);
    //         break;
    //     }
    // }

    // int cnt = 1;
    // int i = 0;
    // ll mask = 1;
    // while (i < a.size()) {
    //     int cnt2 = 0;
    //     while (cnt2 < cnt) {
    //         cout << (a[i] - mask) << " " << (a[i + 1] - (mask << 1)) << " " << (a[i + 2] - mask - (mask << 1)) << endl;
    //         cnt2++;
    //         i += 3;
    //     }
    //     mask <<= 2;
    //     cout << endl;
    //     cnt *= 4;
    // }
    // DEBUG_VEC(a);


    int t;
    cin >> t;
    while (t--) {
        ll res = solve();
        //DEBUG(pll(res, a[ori_n - 1]));
    }
}