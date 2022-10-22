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


signed main() {
    fio();

    int n;
    cin >> n;
    vector<set<int>> st(n);
    rep (i, n - 1) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        st[u].insert(v);
        st[v].insert(u);
    }

    queue<int> qu;
    rep (i, n) {
        if (st[i].size() == 2) qu.push(i);
    }

    set<pii> syuku;

    while (qu.size()) {
        int u = qu.front();
        qu.pop();
        if (st[u].size() != 2) continue;
        // assert(st[u].size() == 2);
        auto itr = st[u].begin();
        int v1 = *itr;
        itr++;
        int v2 = *itr;
        st[u].clear();

        st[v1].erase(u);
        st[v1].insert(v2);
        if (st[v1].size() == 2) qu.push(v1);
        st[v2].erase(u);
        st[v2].insert(v1);
        if (st[v2].size() == 2) qu.push(v2);

        syuku.insert(pii(v1, v2));
        syuku.insert(pii(v2, v1));
    }

    vi num3(n), num4(n);
    vector<bool> ul(n);
    rep (i, n) {
        for (auto itr = st[i].begin(); itr != st[i].end(); itr++) {
            int v = *itr;
            int si = st[v].size();
            if (si == 3) num3[i]++;
            else if (si >= 4) {
                num3[i]++;
                num4[i]++;
            }
        }
        if (num4[i] >= 3) {
            cout << "No" << endl;
            return 0;
        }
        if (num3[i] >= 2) ul[i] = true;
    }

    rep (i, n) {
        for (auto itr = st[i].begin(); itr != st[i].end(); itr++) {
            int v = *itr;
            int si = st[v].size();
            if (si == 3 and ul[v]) num4[i]++;
            else if (si == 3) {
                if (syuku.count(pii(i, v))) num4[i]++;
            }
        }
        if (num4[i] >= 3) {
            cout << "No" << endl;
            return 0;
        }
    }

    // rep (i, n) {
    //     if (st[i].size() >= 3) {
    //         int cnt1 = 0, cnt2 = 0;
    //         for (auto itr = st[i].begin(); itr != st[i].end(); itr++) {
    //             int v = *itr;
    //             if (ul[v]) cnt1++;
    //             else if (st[v].size() >= 3) cnt2++;
    //         }
    //         if (cnt1 > 0 and cnt1 + cnt2 >= 2) {
    //             cout << "No" << endl;
    //             return 0;
    //         }
    //     }
    // }
    cout << "Yes" << endl;
}