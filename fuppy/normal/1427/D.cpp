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


void solve() {
    int n;
    cin >> n;
    vi a(n);
    rep (i, n) {
        cin >> a[i];
        a[i]--;
    }
    vector<pii> p;
    rep (i, n) {
        if (p.size() == 0) {
            p.push_back(pii(a[i], a[i] + 1));
        }
        else {
            if (p.back().second == a[i]) p.back().second++;
            else p.push_back(pii(a[i], a[i] + 1));
        }
    }
    bool flag = true;
    vii res;
    while (flag) {
        // DEBUG_VEC(p);
        flag = false;
        rep (i, p.size()) {
            for (int j = i + 1; j < p.size(); j++) {
                if (p[i].first == p[j].second) {
                    // DEBUG(pii(i, j));
                    vector<vector<pii>> temp(1);
                    for (int k = 0; k < i; k++) temp[0].push_back(p[k]);
                    temp.push_back(vector<pii>(0));
                    for (int k = i; k < j; k++) temp[1].push_back(p[k]);
                    temp.push_back(vector<pii>(1, p[j]));
                    temp.push_back(vector<pii>(0));
                    for (int k = j + 1; k < p.size(); k++) temp[3].push_back(p[k]);

                    rrep (i, temp.size()) {
                        if (temp[i].size() == 0) temp.erase(temp.begin() + i);
                    }

                    res.push_back(vi(0));
                    res.back().push_back(temp.size());
                    // cout << temp.size() << " ";
                    rep (i, temp.size()) {
                        int su = 0;
                        rep (j, temp[i].size()) su += temp[i][j].second - temp[i][j].first;
                        res.back().push_back(su);
                        // cout << su << " ";
                    }
                    // cout << endl;
                    reverse(all(temp));

                    vector<pii> p2;
                    rep (i, temp.size()) {
                        rep (j, temp[i].size()) {
                            pii p = temp[i][j];
                            if (p2.size() == 0) p2.push_back(p);
                            else {
                                if (p2.back().second == p.first) p2.back().second = p.second;
                                else p2.push_back(p);
                            }
                        }
                    }
                    swap(p, p2);

                    flag = true;
                    break;
                }
            }
            if (flag) break;
        }
    }
    cout << res.size() << endl;
    rep (i, res.size()) {
        rep (j, res[i].size()) {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
}

signed main() {
    fio();
    int t = 1;
    // cin >> t;
    while (t--) solve();
}