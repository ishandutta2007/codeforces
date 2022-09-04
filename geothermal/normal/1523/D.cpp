#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
 
#include <bits/stdc++.h>
 
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

const int MOD = 1000000007;
const char nl = '\n';
const int MX = 100001; 

void solve() {
    int N, M, P; cin >> N >> M >> P;
    ll V[N];
    F0R(x, N) {
        string S; cin >> S;
        ll cur = 0;
        F0R(i, sz(S)) {
            if (S[i] == '1') {
                cur += (1ll << i);
            }
        }
        V[x] = cur;
    }

    ll ans = 0;
    F0R(iter, 50) {
        int X = uid(0, N-1);
        vi pos;
        F0R(i, 60) {
            if (V[X] & (1ll << i)) {
                pos.pb(i);
            }
        }

        int K = sz(pos);
        int cnt[1 << K]; F0R(i, 1 << K) cnt[i] = 0;
        F0R(i, N) {
            int cur = 0;
            F0R(j, K) {
                if (V[i] & (1ll << pos[j])) {
                    cur += 1 << j;
                }
            }
            cnt[(1 << K) - 1 - cur]++;
            
        }
        F0R(i, K) {
            F0R(m, 1 << K) {
                if (m & (1 << i)) cnt[m] += cnt[m^(1<<i)];
            }
        }
        F0R(i, 1 << K) {
            ll cur = 0;
            F0R(j, K) {
                if ((i & (1 << j)) == 0) {
                    cur += 1ll << pos[j];
                }
            }
            if (cnt[i] < (N+1)/2) continue;
            if (__builtin_popcountll(cur) > __builtin_popcountll(ans)) ans = cur;

        }

    }

    F0R(i, M) {
        if (ans & (1ll << i)) {
            cout << 1;
        } else cout << 0;
    }
    cout << nl;


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