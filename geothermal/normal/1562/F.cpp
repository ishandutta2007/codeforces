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


vi primes, leastFac;
void compPrimes(int N) {
	F0R(i, N) {
		leastFac.pb(0);
	}
	leastFac[0] = 1; leastFac[1] = 1;
	FOR(i, 2, N) {
		if (leastFac[i] == 0) {
			primes.pb(i);
			leastFac[i] = i;
		}
		for (int j = 0; j < sz(primes) && i*primes[j] < N && primes[j] <= leastFac[i]; j++) {
			leastFac[i*primes[j]] = primes[j];
		}
	}
}

ll query(int X, int Y) {
    cout << "? " << X+1 << " " << Y+1 << endl;
    ll res; cin >> res; return res;
}

void answer(vl res) {
    cout << "! ";
    trav(a, res) cout << a << " ";
    cout << endl;
}

const int CAP = 95;
const int NQ = 1200;

void solve() {
    int N; cin >> N;
    if (N < CAP) {
        vl ans(N); F0R(i, N) ans[i] = 0;
        F0R(i, N) {
            FOR(j, i+1, N) {
                ll res = query(i, j);
                if (ans[i] == 0) ans[i] = res;
                if (ans[j] == 0) ans[j] = res;
                ans[i] = gcd(ans[i], res);
                ans[j] = gcd(ans[j], res);
            }
        }
        if (N == 3) {
            int cnt = 0;
            F0R(i, N) if (ans[i]%2 == 0) cnt++;
            int hi = 0;
            F0R(i, N) if (ans[i] > ans[hi]) hi = i;
            if (cnt == 3) ans[hi] /= 2;
        }
        answer(ans);
    } else {
        ll prim = 0;
        pi pos;
        set<int> used;
        F0R(i, NQ) {
            if (sz(used) == N) break;
            int X = uid(0, N-1), Y = uid(0, N-1);
            while (used.count(X) || X == Y) {
                X = uid(0, N-1), Y = uid(0, N-1);
            }
            used.ins(X); used.ins(Y);
            ll val = query(X, Y);
            trav(a, primes) {
                if (val%a == 0 && a > prim) {
                    prim = a;
                    pos = {X, Y};
                }
                while (val%a == 0) val /= a;
            }
            assert(val==1);
        }
        dbg(prim, pos);
        int p = 0; while (pos.f == p || pos.s == p) p++;
        int v = pos.f;
        if (query(pos.f, p) % prim != 0) {
            v = pos.s;
        }
        vl ans(N);
        ans[v] = prim;
        F0R(i, N) {
            if (i == v) continue;
            ans[i] = query(i, v) / prim;
        }
        answer(ans);
    }

}
 
int main() {
    cin.tie(0)->sync_with_stdio(0); 
    cin.exceptions(cin.failbit);
    compPrimes(MX);
    int T = 1;
    cin >> T;
    while(T--) {
        solve();
    }

	return 0;
}