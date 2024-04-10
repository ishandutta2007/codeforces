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
 
 
vector<pii> calc(vl a) {
    set<pll> st;
    vector<pii> res;
    ll sum = 0;
    st.insert(pll(sum, 0));
    rep (i, a.size()) {
        sum += a[i];
        auto itr = st.lower_bound(pll(sum, -1));
        if (itr != st.end() and itr->first == sum) {
            int l = itr->second;
            int r = i + 1;
            res.push_back(pii(l, r));
            st.erase(itr);
        }
        st.insert(pll(sum, i + 1));
    }
    sort(all(res));
 
    priority_queue<pii> pq;
    rep (i, res.size()) {
        while (pq.size()) {
            pii ri = pq.top();
            if (ri.first >= res[i].second) pq.pop();
            else break;
        }
        pq.push(pii(res[i].second, i));
    }
 
    vector<pii> res2;
    while (pq.size()) {
        int i = pq.top().second;
        pq.pop();
        res2.push_back(res[i]);
    }
    sort(all(res2));
    return res2;
}
 
vii doubling(vector<pii> a) {
    int m = 20;
    int n = a.size();
    vii res(n, vi(m));
 
    rep (i, n) {
        res[i][0] = i;
    }
 
    for (int j = 0; j < m - 1; j++) {
        rep (i, n) {
            int ni = res[i][j];
            ni++;
            if (ni == n) {
                res[i][j + 1] = n;
            }
            res[i][j + 1] = res[ni][j];
        }
    }
    return res;
}
 
signed main() {
    fio();
    int n;
    cin >> n;
    
    vll t(2, vl(n));
    rep (i, 2) {
        rep (j, n) {
            cin >> t[i][j];
        }
    }
    
    vector<vector<pii>> a(2);
    rep (i, 2) a[i] = calc(t[i]);

    vii b(2, vi(n, -1));
    rep (i, 2) {
        rep (j, a[i].size()) {
            b[i][a[i][j].first] = a[i][j].second;
        }
    }
 
    vl temp(n);
    rep (i, n) temp[i] = t[0][i] + t[1][i];
    vector<pii> both = calc(temp);

    vi both_b(n, -1);
    rep (i, both.size()) {
        both_b[both[i].first] = both[i].second;
    }

    vi next(n + 1);
    rep (j, n + 1) {
        auto itr0 = lower_bound(all(a[0]), pii(j + 1, -inf));
        auto itr1 = lower_bound(all(a[1]), pii(j + 1, -inf));
        auto itr2 = lower_bound(all(both), pii(j + 1, -inf));
        int l0, l1, l2;
        if (itr0 == a[0].end()) l0 = n;
        else l0 = itr0->first;
        if (itr1 == a[1].end()) l1 = n;
        else l1 = itr1->first;
        if (itr2 == both.end()) l2 = n;
        else l2 = itr2->first;
        next[j] = min({l0, l1, l2});
    }
    // if (n == 300000) {
    //     cout << a[0].size() + a[1].size() + both.size() << endl;
    //     return 0;
    // }
 
    vector<map<int, int>> dp(n + 1);
    dp[0][0] = 0;
    // vector<set<int>> qu(n + 1);
    // qu[0].insert(0);
    int ans = 0;
    rep (i, n + 1) {
        while (dp[i].size()) {
            pii jc = *dp[i].begin();
            dp[i].erase(dp[i].begin());
            int j = jc.first;
            int now = jc.second;
            chmax(ans, now);
            if (i <= j and i != n) {
                int ni = next[i];
                // int ni = i + 1;
                if (dp[ni].count(j) == 0 or dp[ni][j] < now) {
                    dp[ni][j] = now;
                }

                if (b[0][i] != -1) {
                    int ni = b[0][i];
                    if (dp[ni].count(j) == 0 or dp[ni][j] < now + 1) {
                        dp[ni][j] = now + 1;
                    }
                }
            }
            if (j <= i and j != n) {
                int nj = next[j];
                // int nj = j + 1;
                if (dp[i].count(nj) == 0 or dp[i][nj] < now) {
                    dp[i][nj] = now;
                }

                if (b[1][j] != -1) {
                    int nj = b[1][j];
                    if (dp[i].count(nj) == 0 or dp[i][nj] < now + 1) {
                        dp[i][nj] = now + 1;
                    }
                }
            }
            if (i == j and i != n) {
                if (both_b[i] != -1) {
                    int ni = both_b[i];
                    int nj = both_b[i];
                    if (dp[ni].count(nj) == 0 or dp[ni][nj] < now + 1) {
                        dp[ni][nj] = now + 1;
                    }
                }
            }
        }
    }

    cout << ans << endl;
}