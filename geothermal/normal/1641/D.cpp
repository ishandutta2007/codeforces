#include "bits/stdc++.h"
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

struct chash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

template<typename T> using pb_set = gp_hash_table<T, null_type, chash>;
template<typename T, typename U> using pb_map = gp_hash_table<T, U, chash>;

 
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
const int MX = 100001; 

ll base;

ll hsh(vi &A) {
    ll h1 = 0, h2 = 0;
    trav(a, A) {
        h1 *= base; h2 *= base;
        h1 *= MOD; h2 %= MOD+2;
        h1 += a; h2 += a;
        h1 %= MOD; h2 %= MOD+2;
    }
    return h2*MOD+h1;
}

void solve() {
    base = uid(10, MOD-10);
    int N, M; cin >> N >> M;
    vpl hshes[6];
    F0R(i, N) {
        vi X(M); F0R(j, M) cin >> X[j];
        sort(all(X));
        int W; cin >> W;
        F0R(j, M) {
            FOR(k, j+1, M) {
                if (X[j] == X[k]) goto done;
            }
        }
        F0R(j, 1 << M) {
            vi Y;
            F0R(k, M) {
                if (j & (1 << k)) {
                    Y.pb(X[k]);
                }
            }
            hshes[sz(Y)].pb({hsh(Y), W});
        }
        done:
        ;
    }

    vector<vi> vals[M+1];
    F0R(i, M+1) {
        vi cur;
        sort(all(hshes[i]));
        F0R(j, sz(hshes[i])) {
            cur.pb(hshes[i][j].s);
            if (j == sz(hshes[i]) - 1 || hshes[i][j].f != hshes[i][j+1].f) {
                vals[i].pb(cur);
                cur.clear();
            }
        }
    }
    /*dbg(vals[0]);
    dbg(vals[1]);
    dbg(vals[2]);*/
    ll lo = 2, hi = 2e9 + 10;
    while (lo < hi) {
        ll mid = (lo+hi)/2;
        ll res = 0;
        //dbg(mid, "GOGOGO");
        F0R(it, M+1) {
            trav(a, vals[it]) {
                //dbg(a, it, res);
                int p = sz(a) - 1;
                F0R(i, sz(a)) {
                    while (p >= 0 && a[p] + a[i] > mid) {
                        p--;
                    }
                    //dbg(i, p);
                    if (p < 0) break;
                    res += (p+1)*(it%2?-1:1);
                }
                //dbg(res);
            }
        }
        //dbg(res);
        if (res > 0) {
            hi = mid;
        } else lo = mid+1;
    }
    if (lo > 2e9 + 5) {
        cout << -1 << nl; return;
    }
    cout << lo << nl;

}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int T = 1;
    //cin >> T;
    while(T--) {
        solve();
    }

	return 0;
}