#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
 
#include <bits/stdc++.h>
 
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

const int MOD = 1000000007;
const char nl = '\n';
const int MX = 100001; 

int base;

struct hsh  {
    ll base, p1, p2;

    ll val1, val2;
    ll inv1, inv2;

	ll modExp(ll power, ll prime) {
        if (power == 0) {
            return 1;
        } else {
            ll cur = modExp(power / 2, prime); cur = cur * cur; cur = cur % prime;
            if (power % 2 == 1) cur = cur * base;
            cur = cur % prime;
            return cur;
        }
    }

    hsh() {
    }

    hsh(ll b, string S) {
        p1 = 1000000007;
        p2 = 1000000009;
        base = b;
        val1 = 0;
        val2 = 0;

        inv2 = modExp(p2-2, p2);
        inv1 = modExp(p1-2, p1);
        F0R(i, sz(S)) {
            push_back(S[i] - 'a');
        }
    }

    void push_back(ll v) {
        val1 *= base;
        val1 %= p1;
        val1 += v;
        val1 %= p1;
        val2 *= base;
        val2 %= p2;
        val2 += v;
        val2 %= p2;
    }

    ll get() {
        return val1 * p2 + val2;
    }
};

void prepHash() {
   base = uniform_int_distribution<int>(1000, MOD-2)(rng);
}

ll solveOne(vector<string> &A) {
    int N = sz(A);
    int M = sz(A[0]);
    int ni[N][M];
    F0R(i, N) {
        ni[i][M-1] = M-1;
        F0Rd(j, M-1) {
            ni[i][j] = ni[i][j+1];
            if (A[i][j] > A[i][j+1]) ni[i][j] = j;
        }
    }
    ll ans = N; ans *= N-1;
    F0R(i, N) {
        F0R(j, i) {
            int p1 = 0;
            while (A[i][p1] == A[j][p1]) p1++;
            int p2 = M-1;
            while (A[i][p2] == A[j][p2]) p2--;
            if (max(ni[i][p1], ni[j][p1]) >= p2) ans--;
        }
    }
    return ans;
}


ll solveTwo(vector<string> &A) {
    int N = sz(A);
    int M = sz(A[0]);
    int ni[N][M]; 
    F0R(i, N) {
        ni[i][M-1] = M-1;
        F0Rd(j, M-1) {
            ni[i][j] = ni[i][j+1];
            if (A[i][j] > A[i][j+1]) ni[i][j] = j;
        }
    }

    pb_map<ll, int> nums[M][M];
    int cnt[N][M][M];
    F0R(i, N) F0R(j, M) F0R(k, M) cnt[i][j][k] = 1;
    F0R(i, N) {
        hsh h1(base, "");
        F0R(j, M) {
            if (j > 0) {
                h1.pb(A[i][j-1]-'a');
            }
            hsh h2 = h1;
            F0R(k, M-j) {
                if (k > 0) {
                    h2.pb(A[i][M-k]-'a');
                }
                nums[j][k][h2.get()]++;
            }
        }
    }

    F0R(i, N) {
        hsh h1(base, "");
        F0R(j, M) {
            if (j > 0) {
                h1.pb(A[i][j-1]-'a');
            }
            hsh h2 = h1;
            F0R(k, M-j) {
                if (k > 0) {
                    h2.pb(A[i][M-k]-'a');
                }
                cnt[i][j][k] = nums[j][k][h2.get()];
            }
        }
    }

    ll ans = N; ans *= (N-1);
    F0R(i, N) {
        F0R(j, M) {
            F0R(k, M-j) {
                if (ni[i][j] >= M-1-k) {
                    ans -= cnt[i][j][k];
                    if (j < M-1) {
                        ans += cnt[i][j+1][k];
                    } else ans++;
                    if (k < M-1) {
                        ans += cnt[i][j][k+1];
                        if (j < M-1) {
                            ans -= cnt[i][j+1][k+1];
                        } else ans--;
                    }
                }
            }
        }
    }

    return ans;
}

void solve() {
    prepHash();
    int N; cin >> N;
    map<string, vector<string>> data;
    F0R(i, N) {
        string S; cin >> S;
        string T = S; sort(all(T)); data[T].pb(S);
    }
    ll ans = 0;
    trav(a, data) {
        N -= sz(a.s); ll cur = sz(a.s); cur *= N; ans += cur * 1337;
        if (sz(a.s) < sz(a.f) * 100 ) { 
            ans += solveOne(a.s);
        } else {
            ans += solveTwo(a.s);
        }
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