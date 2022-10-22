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


bool dfs(int i, vi& ans, vector<bool> used, int n) {
    if (i == n) return true;

    if (i == 0) {
        rep (j, n) {
            ans.push_back(j);
            used[j] = true;
            if (dfs(i + 1, ans, used, n)) return true;
            used[j] = false;
            ans.pop_back();
        }
        return false;
    }

    int last = ans.back();
    for (int add = -4; add <= 4; add++) {
        if (abs(add) <= 1) continue;
        int nlast = last + add;
        if (not in(nlast, 0, n)) continue;
        if (used[nlast]) continue;
        ans.push_back(nlast);
        used[nlast] = true;
        if (dfs(i + 1, ans, used, n)) return true;
        used[nlast] = false;
        ans.pop_back();
    }
    return false;
}

void solve() {
    int n;
    cin >> n;
    if (n <= 3) {
        cout << -1 << endl;
        return;
    }
    if (n <= 11) {
        vi ans;
        vector<bool> used(n);
        dfs(0, ans, used, n);
        rep (i, n) {
            cout << ans[i] + 1 << " ";
        }
        cout << endl;
        return;
    }

    vi ori1 = {1, 3, 0, 2};
    vi ori2 = {2, 0, 3, 1, 4};

    int off = 1;
    while (n > 0) {
        if (n % 5 == 0) {
            rep (i, 5) {
                cout << ori2[i] + off << " ";
            }
            off += 5;
            n -= 5;
        }
        else {
            rep (i, 4) {
                cout << ori1[i] + off << " ";
            }
            off += 4;
            n -= 4;
        }
    }
    cout << endl;

}



signed main() {
    fio();
    int t;
    cin >> t;
    while (t--) {
        solve();
    }   

}