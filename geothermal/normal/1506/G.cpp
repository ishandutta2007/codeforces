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
const int MX = 100001; //check the limits, dummy

void solve() {

    string S; cin >> S;
    bool need[26]; F0R(i, 26) need[i] = false;
    int nxt[26][sz(S)];
    F0R(i, 26) {
        nxt[i][sz(S)-1] = sz(S);
    }
    int N = sz(S);
    nxt[S[N-1]-'a'][N-1] = N-1;
    need[S[N-1]-'a'] = true;
    F0Rd(i, N-1) {
        F0R(j, 26) nxt[j][i] = nxt[j][i+1];
        nxt[S[i]-'a'][i] = i;
        need[S[i]-'a'] = true;
    }

    /*F0R(i, N) {
        F0R(j, 26) {
            cout << nxt[j][i] << " ";
        }
        cout << nl;
    }*/
    int lst[26];
    F0R(i, N) {
        lst[S[i]-'a'] = i;
    }
    string ans;
    int cn = 0; F0R(i, 26) if (need[i]) cn++;
    int p = 0;
    F0R(it, cn) {
        F0Rd(j, 26) {
            if (need[j]) {
                F0R(k, 26) {
                    if (need[k] && lst[k] < nxt[j][p]) {
                        goto bad;
                    }
                }
                //cout << p << " " << j << " " << nxt[j][p] << nl;
                p = nxt[j][p];
                need[j] = false;
                ans.pb('a'+j);
                goto done;
                bad:
                ;
            }
        }


        done:
        ;
    }
    cout << ans << nl;

}
 
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);    

    int T = 1;
    cin >> T;
    while(T--) {
        solve();
    }

	return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343