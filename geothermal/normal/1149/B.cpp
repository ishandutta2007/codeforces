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
const int MX = 100011; //check the limits, dummy
int N, Q;
string S;
int nxt[MX][26];
int dp[251][251][251];
string T[3];

void update(int X, int Y, int Z) {
    int A[3]; A[0] = X; A[1] = Y; A[2] = Z;
    if (dp[A[0]][A[1]][A[2]] >= N) return;
    F0R(i, 3) {
        if (A[i] != sz(T[i])) {
            int B[3]; F0R(j, 3) B[j] = A[j];
            B[i]++;
            ckmin(dp[B[0]][B[1]][B[2]], nxt[dp[A[0]][A[1]][A[2]]][T[i][A[i]]-'a']+1);
        }
    }
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);    
	
    cin >> N >> Q;
    cin >> S;
    F0R(i, 26) nxt[N-1][i] = N;
    nxt[N-1][S[N-1]-'a'] = N-1;
    F0Rd(i, N-1) {
        F0R(j, 26) nxt[i][j] = nxt[i+1][j];
        nxt[i][S[i] - 'a'] = i;
    }

    F0R(i, 251) F0R(j, 251) F0R(k, 251) dp[i][j][k] = N+1;
    dp[0][0][0] = 0;

    while(Q--) {
        char C; cin >> C;
        int W; cin >> W; W--;
        if (C == '+') {
            cin >> C;
            T[W].pb(C);
            int L[3], R[3];
            F0R(i, 3) {
                L[i] = 0;
                R[i] = sz(T[i]) + 1;
            }
            L[W] = sz(T[W]) - 1;
            FOR(i, L[0], R[0]) {
                FOR(j, L[1], R[1]) {
                    FOR(k, L[2], R[2]) {
                        update(i, j, k);
                    }
                }
            }
        } else {
            int L[3], R[3];
            F0R(i, 3) {
                L[i] = 0;
                R[i] = sz(T[i]) + 1;
            }
            L[W] = sz(T[W]);
            FOR(i, L[0], R[0]) {
                FOR(j, L[1], R[1]) {
                    FOR(k, L[2], R[2]) {
                        dp[i][j][k] = N+1;
                    }
                }
            }
            T[W].pop_back();
        }

        cout << (dp[sz(T[0])][sz(T[1])][sz(T[2])]<=N?"YES":"NO") << nl;

/*        cout << "After " << Q << nl;
        F0R(i, sz(T[0]) + 1) {
            F0R(j, sz(T[1]) + 1) {
                F0R(k, sz(T[2]) + 1) {
                    cout << i << " " << j << " " << k << ": " << dp[i][j][k] << nl;
                }
            }
        }*/
    }
	
	return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343