#include "bits/stdc++.h"
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef complex<ld> cd;
 
typedef pair<int, int> pi;
typedef pair<ll,ll> pl;
typedef pair<ld,ld> pd;
 
typedef vector<int> vi;
typedef vector<ld> vd;
typedef vector<ll> vl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<cd> vcd;

template<class T> using pq = priority_queue<T>;
template<class T> using pqg = priority_queue<T, vector<T>, greater<T>>;
 
#define FOR(i, a, b) for (int i=a; i<(b); i++)
#define F0R(i, a) for (int i=0; i<(a); i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)
#define trav(a,x) for (auto& a : x)
#define uid(a, b) uniform_int_distribution<int>(a, b)(rng)
 
#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
#define ins insert

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ", "; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? ", " : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifdef DEBUG
#define dbg(x...) cerr << "\e[91m"<<__func__<<":"<<__LINE__<<" [" << #x << "] = ["; _print(x); cerr << "\e[39m" << endl;
#else
#define dbg(x...)
#endif


const int MOD = 1000000007;
const char nl = '\n';
const int MX = 200001; 
const int K = 100;
const int SZ = 262144;

ll sum[2*SZ][K];

ll qsum(int l, int r, int T) {
    ll resL = 0, resR = 0; r++;
    for (l += SZ, r += SZ; l < r; l >>= 1, r >>= 1) {
        if (l&1) resL = resL+sum[l++][T];
        if (r&1) resR = sum[--r][T]+resR;
    }
    return resL + resR;
}


int flar(int l, int r, int T, ll H, int L = 0, int R = SZ-1, int ind = 1) {
    //dbg(l, r, T, H, L, R, ind, sum[ind][T]);
    if (L > r || l > R) return -1;
    if (L == R) {
        return H <= sum[ind][T] ? L : -1;
    }
    int M = (L+R)/2;
    if (sum[ind*2][T] >= H) {
        int val = flar(l, r, T, H, L, M, ind*2);
        if (val != -1) return val;
    } 
    return flar(l, r, T, H - sum[ind*2][T], M+1, R, ind*2+1);
}

void solve() {
    int N; cin >> N;
    ll C[N], R[N];
    F0R(i, N) cin >> C[i] >> R[i];
    F0R(i, N) {
        F0R(j, K) {
            sum[i+SZ][j] = min(C[i], R[i] * j);
        }
    }
    FORd(i, 1, SZ) {
        F0R(j, K) {
            sum[i][j] = sum[2*i][j] + sum[2*i+1][j];
        }
    }

    set<pair<int, pl>> ev;
    F0R(i, N) {
        ev.ins({i, {-MX, C[i]}});
    }

    ll H[MX];
    F0R(i, MX) H[i] = 0;
    int Q; cin >> Q;
    while(Q--) {
        int T; cin >> T;
        cin >> H[T];
    }

    ll ans = 0;
    F0R(t, MX) {
        int p = 0;
        while (!ev.empty()) {
            pair<int, pl> cur = *ev.begin();
            if (t - cur.s.f >= K) {
                ll gap = t - cur.s.f;
                FOR(i, p, cur.f) {
                    ll V = min(R[i] * gap, C[i]);
                    if (V >= H[t]) {
                        ev.ins({i, {t, V - H[t]}});
                        goto done;
                    }
                    H[t] -= V;
                }
            } else if (p < cur.f) {
                ll S = qsum(p, cur.f - 1, t - cur.s.f);
                if (S < H[t]) {
                    H[t] -= S;
                } else {
                    int pos = flar(p, cur.f - 1, t - cur.s.f, H[t] + qsum(0, p-1, t - cur.s.f));
                    if (p < pos) H[t] -= qsum(p, pos - 1, t - cur.s.f);
                    ll V = min(R[pos] * (t - cur.s.f), C[pos]);
                    ev.ins({pos, {t, V - H[t]}});
                    goto done;
                }

            }
            ll V = min(cur.s.s + R[cur.f] * (t - cur.s.f), C[cur.f]);
            if (V >= H[t]) {
                ev.erase(ev.begin());
                cur.s.s = V - H[t];
                cur.s.f = t;
                ev.ins(cur);
                goto done;
            }
            H[t] -= V;
            p = cur.f + 1;
            ev.erase(ev.begin());

        }
        ans += H[t];
        //dbg(t, H[t]);
        ev.ins({N-1, {t, 0}});
        done:
        ;
        /*if (t < 11) {
            dbg(t, ev);
        }*/
    }

    cout << ans << nl;

}
 
int main() {
    cin.tie(0)->sync_with_stdio(0); 
    cin.exceptions(cin.failbit);

    int T = 1;
//    cin >> T;
    while(T--) {
        solve();
    }

	return 0;
}