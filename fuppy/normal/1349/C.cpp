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
//const ll MOD = 1000000007;
const ll MOD = 998244353;
// #define mp make_pair
//#define endl '\n'


signed main() {
    fio();
    int h, w, t;
    cin >> h >> w >> t;
    vector<string> a(h);
    rep (i, h) {
        cin >> a[i];
    }
    
    vll first_time(h, vl(w, INF));
    queue<pii> qu;
    rep (i, h) {
        rep (j, w) {
            bool flag = false;
            rep (k, 4) {
                int ni = i + dy[k], nj = j + dx[k];
                if (not in(ni, 0, h) or not in(nj, 0, w)) continue;
                if (a[i][j] == a[ni][nj]) {
                    flag = true;
                }
            }
            if (flag) {
                first_time[i][j] = 1;
                qu.push(pii(i, j));
            }
        }
    }

    for (int T = 1; T <= INF; T++) {
        if (qu.size() == 0) break;
        queue<pii> nqu;
        while (qu.size()) {
            pii temp = qu.front();
            qu.pop();
            int i = temp.first, j = temp.second;
            rep (k, 4) {
                int ni = i + dy[k], nj = j + dx[k];
                if (not in(ni, 0, h) or not in(nj, 0, w)) continue;
                if (first_time[ni][nj] == INF) {
                    first_time[ni][nj] = T + 1;
                    nqu.push(pii(ni, nj));
                }
            }
        }
        swap(qu, nqu);
    }

    while (t--) {
        ll i, j, p;
        cin >> i >> j >> p;
        i--; j--;
        if (first_time[i][j] > p) {
            cout << a[i][j] << '\n';
            continue;
        }

        ll turn = (p - first_time[i][j] + 1) % 2;
        if (turn == 0) {
            cout << a[i][j] << '\n';
        }
        else {
            if (a[i][j] == '1') {
                cout << '0' << '\n';
            }
            else {
                cout << '1' << '\n';
            }
        }
    }
}