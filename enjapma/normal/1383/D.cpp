#include <bits/stdc++.h>
#include <unistd.h>
#include <sys/time.h>
#include <stdlib.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> P;
typedef pair<P, ll> T;
typedef pair<long double , ll> Ps;
typedef pair<ll, bool> Pb;

const ll INF = 1e18;
const ll fact_table = 3200008;
long double Pi = 3.1415926535897932384626;

priority_queue <ll> pql;
priority_queue <P> pqp;
priority_queue <P> bag;
//big priority queue
priority_queue <ll, vector<ll>, greater<ll> > pqls;
priority_queue <P, vector<P>, greater<P> > pqps;
//small priority queue
//top pop

ll dx[8] = {1, 0, -1, 0, 1, 1, -1, -1};
ll dy[8] = {0, 1, 0, -1, 1, -1, -1, 1};
char dir[] = "DRUL";
//,,,

/*
#define endl "\n"
#ifdef ENJAPMA
#undef endl
#endif
*/
#define p(x) cout<<x<<endl;
#define el cout<<endl;
#define pe(x) cout<<x<<" ";
#define ps(x) cout<<fixed<<setprecision(25)<<x<<endl;
#define pu(x) cout<<(x);
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define CLEAR(a) a = decltype(a)();
#define pc(x) cout << x << ",";
#define rep(i, n) for (ll i = 0; i < (n); i ++)

// const ll mod = 998244353ll;
const ll mod = 1000000007ll;

ll mypow(ll a, ll b, ll mod) {ll x = 1; while (b) {while (!(b & 1)) {(a *= a) %= mod; b >>= 1;}(x *= a) %= mod; b--;} return x;}
void YES(bool cond) { if (cond) { p("YES");} else { p("NO");} return;}
void Yes(bool cond) { if (cond) { p("Yes");} else { p("No");} return;}
void line() { p("--------------------"); return;}

/*
ll fact[fact_table + 5], rfact[fact_table + 5];

void c3_init() {
    fact[0] = rfact[0] = 1;
    for (ll i = 1; i <= fact_table; i++) {
        fact[i] = (fact[i - 1] * i) % mod;
    }
    rfact[fact_table] = mypow(fact[fact_table], mod - 2, mod);
    for (ll i = fact_table; i >= 1; i--) {
        rfact[i - 1] = rfact[i] * i;
        rfact[i - 1] %= mod;
    }
    return;
}
ll c3(ll n, ll r) {
    return (((fact[n] * rfact[r]) % mod ) * rfact[n - r]) % mod;
}
*/
struct Timer {
    int64_t start;
    const int64_t CYCLES_PER_SEC = 2800000000;
    Timer() { reset(); }
    void reset() { start = getCycle(); }
    inline double get() { return (double)(getCycle() - start) / CYCLES_PER_SEC; }
    inline int64_t getCycle() {
        uint32_t low, high;
        __asm__ volatile ("rdtsc" : "=a" (low), "=d" (high));
        return ((int64_t)low) | ((int64_t)high << 32);
    }
};

Timer timer;

bool multicase = false;

ll n, m, k, w, num, a, b, d, e, h, q, ans, sum, l;

typedef vector<ll> vec;
typedef vector<vector<ll>> mat;

string s, t;

ll A[255][255], B[255][255], C[255][255];
ll r[500], c[500];
ll p1[500], p2[500];
bool used[5005][5005];
ll v_id = 0;

void safe(ll ri, ll li, vector<P> &v) {
    for (int i = ri; i >= 0; i--) {
        if (B[i][li] == 0 && !used[i][li]) {
            v.push_back(P(i, li));
            used[i][li] = true;
        }
    }
    for (int j = li; j >= 0; j--) {
        if (B[ri][j] == 0 && !used[ri][j]) {
            v.push_back(P(ri, j));
            used[ri][j] = true;
        }
    }
    return;
}

void solve() {
    cin >> h >> w;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cin >> A[i][j];
        }
    }
    for (int i = 0; i < h; i++) {
        ll maxi = -INF;
        for (int j = 0; j < w; j++) {
            maxi = max(maxi, A[i][j]);
        }
        r[i] = maxi;
    }
    for (int j = 0; j < w; j++) {
        ll maxi = -INF;
        for (int i = 0; i < h; i++) {
            maxi = max(maxi, A[i][j]);
        }
        c[j] = maxi;
    }
    sort(r, r + h);
    reverse(r, r + h);
    sort(c, c + w);
    reverse(c, c + w);
    int ri = 0, li = 0;
    int put = h * w;
    vector<P> safety;
    while (true) {
        if (r[ri] == put && c[li] == put) {
            B[ri][li] = put;
            safe(ri, li, safety);
            ri ++;
            li ++;
        } else if (r[ri] == put && c[li] != put) {
            B[ri][li - 1] = put;
            safe(ri, li - 1, safety);
            ri++;
        } else if (r[ri] != put && c[li] == put) {
            B[ri - 1][li] = put;
            safe(ri - 1, li, safety);
            li++;
        } else {
            // 
            P pos = safety[v_id++];
            B[pos.first][pos.second] = put;
        }
        put --;
        if (put == 0) break;
    }
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            pe(B[i][j]);
        }
        el;
    }

    return;
}

int main() {
    // init();
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll q, testcase = 1;
    if (multicase) {
        cin >> q;
    } else {
        q = 1;
    }
    while (q--) {
        // pu("Case ");pu("#");pu(testcase);pu(": ");
        solve();
        testcase++;
    }
    // solve();
    return 0;
}