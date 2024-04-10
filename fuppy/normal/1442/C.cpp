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
void YES(bool t=true) {cout<<(t?"YES":"NO")<<endl;}
void Yes(bool t=true) {cout<<(t?"Yes":"No")<<endl;}
void yes(bool t=true) {cout<<(t?"yes":"no")<<endl;}
void NO(bool t=true) {cout<<(t?"NO":"YES")<<endl;}
void No(bool t=true) {cout<<(t?"No":"Yes")<<endl;}
void no(bool t=true) {cout<<(t?"no":"yes")<<endl;}
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a = b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a = b; return 1; } return 0; }
#define UNIQUE(v) v.erase(std::unique(v.begin(), v.end()), v.end());
const ll inf = 1000000001;
const ll INF = (ll)1e18 + 1;
const long double pi = 3.1415926535897932384626433832795028841971L;
#define Sp(p) cout<<setprecision(25)<< fixed<<p<<endl;
// int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
// int dx2[8] = { 1,1,0,-1,-1,-1,0,1 }, dy2[8] = { 0,1,1,1,0,-1,-1,-1 };
vi dx = {-1, 0, 1, 0}, dy = {0, -1, 0, 1};
// vi dx2 = { 1,1,0,-1,-1,-1,0,1 }, dy2 = { 0,1,1,1,0,-1,-1,-1 };
#define fio() cin.tie(0); ios::sync_with_stdio(false);
// const ll MOD = 1000000007;
const ll MOD = 998244353;
// #define mp make_pair
//#define endl '\n'

const int N = 211111;
vii G(N), rG(N);
int n, m;
vl power2(2 * N), sum2(2 * N);

ll solve1() {
    int K = 25;
    vll dist(n, vl(K, INF));
    dist[0][0] = 0;
    using P = pair<ll, pii>;
    priority_queue<P, vector<P>, greater<P>> pq;
    pq.push(P(0, pii(0, 0)));
    while (pq.size()) {
        P temp = pq.top();
        pq.pop();
        ll cost = temp.first;
        int i = temp.second.first, j = temp.second.second;
        if (dist[i][j] < cost) continue;
        if (j % 2 == 0) {
            for (int ni: G[i]) {
                int nj = j;
                ll ncost = cost + 1;
                if (dist[ni][nj] > ncost) {
                    dist[ni][nj] = ncost;
                    pq.push(P(ncost, pii(ni, nj)));
                }
            }
        }
        else {
            for (int ni: rG[i]) {
                int nj = j;
                ll ncost = cost + 1;
                if (dist[ni][nj] > ncost) {
                    dist[ni][nj] = ncost;
                    pq.push(P(ncost, pii(ni, nj)));
                }
            }
        }
        if (j + 1 < K) {
            int nj = j + 1;
            ll ncost = cost + power2[j];
            if (dist[i][nj] > ncost) {
                dist[i][nj] = ncost;
                pq.push(P(ncost, pii(i, nj)));
            }
        }
    }

    ll mi = INF;
    rep (i, K) {
        chmin(mi, dist[n - 1][i]);
    }
    return mi;
    // return INF;
}

ll solve2() {
    vll dist(n, vl(2, INF));
    dist[0][0] = 0;

    using P = pair<ll, pii>;
    priority_queue<P, vector<P>, greater<P>> pq1, pq2;
    pq1.push(P(0, pii(0, 0)));
    rep (turn, 2 * n + 10) {
        while (pq1.size()) {
            P temp = pq1.top();
            pq1.pop();
            ll cost = temp.first;
            int i = temp.second.first, j = temp.second.second;
            if (dist[i][j % 2] < cost) continue;
            if (j % 2 == 0) {
                for (int ni: G[i]) {
                    int nj = j;
                    ll ncost = (cost + 1) % MOD;
                    if (dist[ni][nj % 2] > ncost) {
                        dist[ni][nj % 2] = ncost;
                        pq1.push(P(ncost, pii(ni, nj)));
                    }
                }
            }
            else {
                for (int ni: rG[i]) {
                    int nj = j;
                    ll ncost = (cost + 1) % MOD;
                    if (dist[ni][nj % 2] > ncost) {
                        dist[ni][nj % 2] = ncost;
                        pq1.push(P(ncost, pii(ni, nj)));
                    }
                }
            }
            int nj = j + 1;
            ll ncost = cost;
            if (dist[i][nj % 2] > ncost) {
                dist[i][nj % 2] = ncost;
                pq2.push(P(ncost, pii(i, nj)));
            }
        }

        if (dist[n - 1][turn % 2] != INF) return (dist[n - 1][turn % 2] + sum2[turn]) % MOD;

        swap(pq1, pq2);
    }
    // DEBUG_MAT(dist);
    return INF;
}

signed main() {
    fio();
    cin >> n >> m;
    rep (i, m) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        G[u].push_back(v);
        rG[v].push_back(u);
    }
    power2[0] = 1;
    rep (i, 2 * n + 10) power2[i + 1] = power2[i] * 2 % MOD;
    rep (i, 2 * n + 9) sum2[i + 1] = (sum2[i] + power2[i]) % MOD;
    ll ans1 = solve1();
    if (ans1 != INF) {
        cout << ans1 << endl;
        return 0;
    }
    ll ans2 = solve2();
    cout << ans2 << endl;
}