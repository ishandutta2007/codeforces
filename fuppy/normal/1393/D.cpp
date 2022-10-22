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
// int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
// int dx2[8] = { 1,1,0,-1,-1,-1,0,1 }, dy2[8] = { 0,1,1,1,0,-1,-1,-1 };
vi dx = {1, 0, -1, 0}, dy = {0, 1, 0, -1};
// vi dx2 = { 1,1,0,-1,-1,-1,0,1 }, dy2 = { 0,1,1,1,0,-1,-1,-1 };
#define fio() cin.tie(0); ios::sync_with_stdio(false);
const ll MOD = 1000000007;
// const ll MOD = 998244353;
// #define mp make_pair
//#define endl '\n'


ll solve(int h, int w, vector<string> s) {
    vii left(h, vi(w)), right(h, vi(w)), up(h, vi(w)), down(h, vi(w));
    rep (i, h) {
        char pre = '?';
        int cnt = 1;
        rep (j, w) {
            if (s[i][j] != pre) {
                left[i][j] = 0;
                pre = s[i][j];
                cnt = 1;
            }
            else {
                left[i][j] = cnt;
                cnt++;
            }
        }
    }
    rep (i, h) {
        char pre = '?';
        int cnt = 1;
        rrep (j, w) {
            if (s[i][j] != pre) {
                right[i][j] = 0;
                pre = s[i][j];
                cnt = 1;
            }
            else {
                right[i][j] = cnt;
                cnt++;
            }
        }
    }

    rep (j, w) {
        char pre = '?';
        int cnt = 1;
        rep (i, h) {
            if (s[i][j] != pre) {
                up[i][j] = 0;
                pre = s[i][j];
                cnt = 1;
            }
            else {
                up[i][j] = cnt;
                cnt++;
            }
        }
    }

    rep (j, w) {
        char pre = '?';
        int cnt = 1;
        rrep (i, h) {
            if (s[i][j] != pre) {
                down[i][j] = 0;
                pre = s[i][j];
                cnt = 1;
            }
            else {
                down[i][j] = cnt;
                cnt++;
            }
        }
    }

    vii ue(h, vi(w)), sita(h, vi(w));
    rep (i, h) {
        rep (j, w) {
            if (i == 0) ue[i][j] = 1;
            else if (s[i][j] != s[i - 1][j]) ue[i][j] = 1;
            else {
                int mi = min({ue[i - 1][j], right[i][j], left[i][j]});
                ue[i][j] = mi + 1;
            }
        }
    }
    rrep (i, h) {
        rep (j, w) {
            if (i == h - 1) sita[i][j] = 1;
            else if (s[i][j] != s[i + 1][j]) sita[i][j] = 1;
            else {
                int mi = min({sita[i + 1][j], right[i][j], left[i][j]});
                sita[i][j] = mi + 1;
            }
        }
    }

    ll ans = 0;
    rep (i, h) {
        rep (j, w) {
            int mi = min(ue[i][j], sita[i][j]);
            ans += mi;
        }
    }
    cout << ans << endl;
    return ans;


    // using P = pair<int, pii>;
    // priority_queue<P, vector<P>, greater<P>> pq;
    // rep (i, h) {
    //     rep (j, w) {
    //         pq.push(P(
    //             min({up[i][j], down[i][j], left[i][j], right[i][j]}),
    //             pii(i, j)
    //         ));
    //     }
    // }

    // vii dist(h, vi(w));
    // ll ans = 0;
    // while (pq.size() > 0) {
    //     P temp = pq.top();
    //     pq.pop();
    //     int x = temp.first;
    //     int i = temp.second.first, j = temp.second.second;
    //     if (x == 0) {
    //         dist[i][j] = 1;
    //         ans += 1;
    //         continue;
    //     }
    //     int mi = inf;
    //     rep (k, 4) {
    //         int ni = i + dy[k], nj = j + dx[k];
    //         if (dist[ni][nj] == 0) continue;
    //         chmin(mi, dist[ni][nj]);
    //     }
    //     assert(mi != inf);
    //     dist[i][j] = mi + 2;
    //     ans += (dist[i][j] + 1) / 2;
    // }
    // // DEBUG_MAT(dist);
    // cout << ans << endl;
    // return ans;
}

signed main() {
    fio();
    int t = 1;
    // cin >> t;
    while (t--) {
        int h, w;
        cin >> h >> w;
        vector<string> s(h);
        rep (i, h) cin >> s[i];
        ll ans1 = solve(h, w, s);
        // ll ans2 = solve2(h, w, s);
    }
}