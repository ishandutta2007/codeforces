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

bool inc(pii a, pii b) {
    if (b.first <= a.first and a.second <= b.second) return true;
    else return false;
}


signed main() {
    int n ;
    cin >> n;
    using P = pair<pii, int>;
    vector<P> lr(n);
    rep (i, n) {
        cin >> lr[i].first.first >> lr[i].first.second;
        lr[i].first.second++;
        lr[i].second = i;
    }
    sort(all(lr), [](P a, P b) {
        if (a.first.first != b.first.first) return a < b;
        else {
            if (a.first.second != b.first.second) {
                return a.first.second > b.first.second;
            }
            else return a < b;
        }
    });

    vector<pii> left(n + 1), right(n + 1, pii(inf, inf));
    rep (i, n) {
        if (left[i].second < lr[i].first.first) {
            left[i + 1] = lr[i].first;
        }
        else {
            left[i + 1].first = left[i].first;
            left[i + 1].second = max(left[i].second, lr[i].first.second);
        }
    }
    rep (i, n) {
        if (lr[n - 1 - i].first.second < right[i].first) {
            right[i + 1] = lr[n - 1 - i].first;
        }
        else {
            right[i + 1].first = min(lr[n - 1 - i].first.first, right[i].first);
            right[i + 1].second = min(lr[n - 1 - i].first.second, right[i].second);
        }
    }
    // DEBUG_VEC(left);
    // DEBUG_VEC(right);
    rep (i, n) {
        pii le = left[i], ri = right[n - 1 - i];
        if (inc(lr[i].first, le) or inc(lr[i].first, ri)) {
            cout << lr[i].second + 1 << endl;
            return 0;
        }
        if (le.second >= ri.first) {
            pii ne(min(le.first, ri.first), max(le.second, ri.second));
            if (inc(lr[i].first, ne)) {
                cout << lr[i].second + 1 << endl;
                return 0;
            }
        }
    }
    cout << -1 << endl;
}