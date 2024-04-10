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
// const ll MOD = 1000000007;
const ll MOD = 998244353;
// #define mp make_pair
//#define endl '\n'


signed main() {
    int n ;
    cin >> n;
    vi a(n);
    rep (i, n) cin >> a[i];

    int mi = inf;
    int ma = -1;
    int sum = 0;
    rep (i, n) {
        chmin(mi, a[i]);
        chmax(ma, a[i]);
        sum += a[i];
    }

    if (n == 2) {
        if (a[0] == a[1]) {
            cout << a[0] << endl;
            cout << 0 << endl;
        }
        else {
            cout << 0 << endl;
            cout << ma << endl;
            rep (i, ma) {
                cout << "11" << endl;
            }
        }
        return 0;
    }

    for (int x = mi; x >= 0; x--) {
        int oo = ma - x;
        int nn = sum - ma - (n - 1) * x;
        if (x != 0 and oo > nn) continue;
        vi over(n);
        rep (i, n) over[i] = a[i] - x;
        vector<string> res;
        while (true) {
            set<pii, greater<pii>> pq;
            rep (i, n) {
                if (over[i] == 0) continue;
                pq.insert(pii(over[i], i));
                if (pq.size() > 4) {
                    auto itr = pq.end();
                    itr--;
                    pq.erase(itr);
                }
            }
            // DEBUG_VEC(over);
            if (pq.size() == 0) break;
            int num = 2;
            if (pq.size() == 3) {
                if (pq.begin()->first == 1) num = 3;
            }

            string ans(n, '0');
            while (num) {
                if (pq.size() == 0) {
                    rep (i, n) {
                        if (ans[i] != '1') {
                            ans[i] = '1';
                            break;
                        }
                    }
                    num--;
                }
                else {
                    auto itr = pq.begin();
                    ans[itr->second] = '1';
                    over[itr->second]--;
                    pq.erase(itr);
                    num--;
                }
            }
            res.push_back(ans);
        }
        cout << x << endl;
        cout << res.size() << endl;
        rep (i, res.size()) {
            cout << res[i] << endl;
        }
        return 0;

    }
}