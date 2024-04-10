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
    map<char, int> M; M['A'] = 0; M['N'] = 1; M['T'] = 2; M['O'] = 3;
    map<int, char> Mi; Mi[0] = 'A'; Mi[1] = 'N'; Mi[2] = 'T'; Mi[3] = 'O';
    vl pos[4];
    string S; cin >> S;
    F0R(i, sz(S)) {
        pos[M[S[i]]].pb(i);
    }
    string ans; ll res = -1;
    vi perm = {0, 1, 2, 3};
    do {
        string T; 
        ll cur = 0;
        bool found[4]; F0R(i, 4) found[i] = false;
        F0R(i, 4) {
            int p = 0;
            ll fl = 0;
            F0R(j, sz(pos[perm[i]])) {
                while (p < pos[perm[i]][j]) {
                    if (!found[M[S[p]]]) {
                        fl++;
                    }
                    p++;
                }
                p++;
                //cur += abs(sz(T)-pos[perm[i]][j]);
                cur += fl;
                T += Mi[perm[i]];
            }
            found[perm[i]] = true;
        }
        if (ckmax(res, cur)) ans = T;
    } while (next_permutation(all(perm)));
    cout << ans << nl;
    //cout << res << nl;

}
 
int main() {
    cin.tie(0)->sync_with_stdio(0); 
    cin.exceptions(cin.failbit);

    int T = 1;
    cin >> T;
    while(T--) {
        solve();
    }

	return 0;
}