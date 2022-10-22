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


void solve() {
    int n, m;
    cin >> n >> m;
    vector<pii> ab(n), cd(m);
    rep (i, n) cin >> ab[i].first >> ab[i].second;
    sort(all(ab));
    rep (i, m) {
        cin >> cd[i].first >> cd[i].second;
    }
    sort(all(cd));

    vector<pii> cd2;
    rep (i, m) {
        while (cd2.size() > 0 and cd2.back().second <= cd[i].second) cd2.pop_back();
        cd2.push_back(cd[i]);
    }
    swap(cd, cd2);
    cd.push_back(pii(inf, -inf));
    // DEBUG_VEC(cd);
    m = cd.size();

    set<pii> st;
    using P = pair<int, pii>;
    vi dist(n, -inf);
    vector<P> events;
    rep (i, n) {
        bool flag = true;
        rep (j, m) {
            if (ab[i].first <= cd[j].first) {
                P temp;
                temp.first = cd[j].first - ab[i].first + 1;
                temp.second = pii(i, j);
                events.push_back(temp);
                if (flag) {
                    int dis = cd[j].second - ab[i].second + 1;
                    if (dis > 0) {
                        dist[i] = dis;
                        st.insert(pii(dis, i));
                    }
                    flag = false;
                }
            }
        }
    }
    sort(all(events));

    if (st.size() == 0) {
        cout << 0 << endl;
        return;
    }
    auto itr = st.end();
    itr--;
    int ans = itr->first;
    

    // for (auto itr = st.begin(); itr != st.end(); itr++) DEBUG(*itr);
    // DEBUG_VEC(dist);

    for (P event: events) {
        // DEBUG(event);
        int temp = event.first;
        int i = event.second.first, j = event.second.second;
        int dis = dist[i];
        if (st.count(pii(dis, i))) {
            st.erase(pii(dis, i));
            int nj = j + 1;
            int dis2 = cd[nj].second - ab[i].second + 1;
            if (dis2 > 0) {
                dist[i] = dis2;
                st.insert(pii(dis2, i));
            }
        }
        // DEBUG(st.size());
        if (st.size() == 0) {
            chmin(ans, temp);
        }
        else {
            auto itr = st.end();
            itr--;
            chmin(ans, itr->first + temp);
        }
    }

    cout << ans << endl;
}

signed main() {
    fio();
    int t = 1;
    // cin >> t;
    while (t--) solve();
}