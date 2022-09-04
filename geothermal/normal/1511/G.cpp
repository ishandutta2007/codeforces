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
const int MX = 200001; 

const int K = 512;
void solve() {
    int M, N; cin >> M >> N;
    int chip[N]; F0R(i, N) chip[i] = 0;
    F0R(i, M) {
        int X; cin >> X; X--;
        chip[X] = 1-chip[X];
    }
    int pc1[N], pc2[N]; //pc1: Next 512 & 511.  pc2: sum
    F0R(i, N) {
        pc1[i] = 0; pc2[i] = 0;
        F0R(j, K) {
            if (i+j >= N) break;
            if (!chip[i+j]) continue;
            pc1[i] ^= j & (K-1);
            pc2[i] = 1 - pc2[i];
        }
    }

    int Q; cin >> Q;
    while(Q--) {
        int L, R; cin >> L >> R;
        L--; 
        int nim = 0;
        int oL = L;
        while (L < R) {
            if (L+K <= R) {
                nim ^= pc1[L];
                if (pc2[L]) nim ^= L-oL;
                L += K;
            } else  {
                if (chip[L]) nim ^= L - oL;
                L++;
            }
        }
        cout << (nim==0?"B":"A");
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