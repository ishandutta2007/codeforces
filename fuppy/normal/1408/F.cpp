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
// const ll MOD = 1000000007;
const ll MOD = 998244353;
// #define mp make_pair
//#define endl '\n'

vector<pii> op;

signed main() {
    fio();
    int n;
    cin >> n;
    vector<vii> a(n + 1);
    rep1 (i, n) {
        a[1].push_back(vi(1, i));
    }
    int syu = n, mi = 1, ma = 1;
    while (syu > 2) {
        // DEBUG(pii(mi, ma));
        // rep1 (i, n) {
        //     DEBUG(i);
        //     rep (j, a[i].size()) {
        //         cout << "(";
        //         rep (k, a[i][j].size()) {
        //             cout << a[i][j][k] << ", ";
        //         }
        //         cout << ")  ";
        //     }
        //     cout << endl;
        // }
        int idx = mi;
        for (int idx = mi; idx < inf; idx *= 2) {
            if (a[idx].size() <= 1) break;
            while (a[idx].size() > 1) {
                vi temp1, temp2;
                swap(temp1, a[idx].back());
                a[idx].pop_back();
                swap(temp2, a[idx].back());
                a[idx].pop_back();

                assert(temp1.size() == temp2.size());

                vi temp;
                while (temp1.size()) {
                    int u = temp1.back(), v = temp2.back();
                    temp1.pop_back();
                    temp2.pop_back();
                    op.push_back(pii(u, v));
                    temp.push_back(u);
                    temp.push_back(v);
                }
                a[temp.size()].push_back(temp);
                chmax(ma, (int)temp.size());
                syu--;
                if (syu == 2) break;
            }
            if (syu == 2) break;
        }
        while (a[mi].size() == 0) mi++;

        // rep1 (i, n) {
        //     DEBUG(i);
        //     rep (j, a[i].size()) {
        //         cout << "(";
        //         rep (k, a[i][j].size()) {
        //             cout << a[i][j][k] << ", ";
        //         }
        //         cout << ")  ";
        //     }
        //     cout << endl;
        // }

        if (syu == 2) break;

        int del_idx;
        vi temp;
        swap(temp, a[ma].back());
        a[ma].pop_back();
        vi temp2;
        rep (i, mi) {
            temp2.push_back(temp.back());
            temp.pop_back();
        }
        syu++;
        a[temp.size()].push_back(temp);
        a[temp2.size()].push_back(temp2);
        while (a[ma].size() == 0) ma--;
    }

    cout << op.size() << '\n';
    rep (i, op.size()) {
        cout << op[i].first << " " << op[i].second << '\n';
    }
}

// void solve() {
//     int m, n;
//     cin >> m >> n;
//     vl a(m), b(n);
//     rep (i, m) cin >> a[i];
//     rep (i, n) cin >> b[i];

//     vi num(n);
//     vector<set<int>> st(m);
//     using P = pair<ll, pii>;
//     priority_queue<P, vector<P>, greater<P>> pq;

//     rep (i, m) {
//         int s;
//         cin >> s;
//         if (s == 1) continue;
//         rep (j, s) {
//             int x;
//             cin >> x;
//             x--;
//             num[x]++;
//             st[i].insert(x);
//             pq.push(P(a[i] + b[x], pii(i, x)));
//         }
//     }



//     ll ans = 0;
//     while (pq.size()) {
//         P temp = pq.top();
//         pq.pop();
//         int score = temp.first;
//         int i = temp.second.first, x = temp.second.second;
//         if (st[i].size() == 1) {
//             num[x]--;
//             continue;
//         }
//         if (num[x] == 1) {
//             continue;
//         }

//     }
// }

// signed main() {
//     fio();
//     int t = 1;
//     // cin >> t;
//     while (t--) solve();
// }