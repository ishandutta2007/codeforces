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
vi dx = {-1, 0, 1, 0}, dy = {0, -1, 0, 1};
// vi dx2 = { 1,1,0,-1,-1,-1,0,1 }, dy2 = { 0,1,1,1,0,-1,-1,-1 };
#define fio() cin.tie(0); ios::sync_with_stdio(false);
// const ll MOD = 1000000007;
const ll MOD = 998244353;
// #define mp make_pair
//#define endl '\n'

void solve() {
    int n, k;
    cin >> n >> k;
    vi a(n), b(k);
    rep (i, n) {
        cin >> a[i];
        a[i]--;
    }
    set<int> alive;
    rep (i, k) {
        cin >> b[i];
        b[i]--;
        alive.insert(b[i]);
    }
    alive.insert(-1);

    vi left(n, -1), right(n, -1);
    rep (i, n) {
        if (i > 0) {
            left[a[i]] = a[i - 1];
        }
        if (i < n - 1) {
            right[a[i]] = a[i + 1];
        }
    }
    // DEBUG_VEC(left);
    // DEBUG_VEC(right);

    ll ans = 1;
    rep (i, k) {
        int x = b[i];
        int cnt = 0;
        if (alive.count(left[x]) == 0) cnt++;
        if (alive.count(right[x]) == 0) cnt++;
        if (cnt == 0) {
            cout << 0 << endl;
            return;
        }
        // DEBUG(cnt);
        if (cnt == 1) {
            if (alive.count(left[x]) == 0) {
                int l2 = left[left[x]];
                left[x] = l2;
                if (l2 != -1) {
                    right[l2] = x;
                }
            }
            else {
                int r2 = right[right[x]];
                right[x] = r2;
                if (r2 != -1) {
                    left[r2] = x;
                }
            }
        }
        else {
            (ans *= 2) %= MOD;
            int l2 = left[left[x]];
            left[x] = l2;
            if (l2 != -1) {
                right[l2] = x;
            }
        }
        alive.erase(x);
    }
    cout << ans << '\n';
}

signed main() {
    fio();
    int t = 1;
    cin >> t;
    while (t--) solve();
}