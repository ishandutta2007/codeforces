#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

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

template <class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;

#define FOR(i, a, b) for (int i=a; i<(b); i++)
#define F0R(i, a) for (int i=0; i<(a); i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)

#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()

const int MOD = 1000000007;
const ll INF = 1e18;
const int MX = 100001;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    string C, S, T; cin >> C >> S >> T;

    int N = C.size();
    int Sz = S.size(), Tz = T.size();
    int tranS[Sz+1][26], tranT[Tz+1][26];
    F0R(i, Sz+1) {
        F0R(j, 26) {
            vector<char> newStr;
            F0R(k, i) newStr.pb(S[k]);
            newStr.pb('a' + j);
            int best = 0;
            F0R(l, Sz+1) {
                int start = sz(newStr)-l;
                if (start < 0) goto done;
                F0R(pos, l) {
                    if (newStr[pos+start] != S[pos]) goto done;
                }

                best = l;
                done:;
            }
            tranS[i][j] = best;
        }
    }

    F0R(i, Tz+1) {
        F0R(j, 26) {
            vector<char> newStr;
            F0R(k, i) newStr.pb(T[k]);
            newStr.pb('a' + j);
            int best = 0;
            F0R(l, Tz+1) {
                int start = sz(newStr)-l;
                if (start < 0) goto done2;
                F0R(pos, l) {
                    if (newStr[pos+start] != T[pos]) goto done2;
                }

                best = l;
                done2:;
            }
            tranT[i][j] = best;
        }
    }

    int dp[N+1][Sz+1][Tz+1]; // cur, longest S-prefix, longest T-prefix


    F0R(i, Sz+1) {
        F0R(j, Tz+1) {
            F0R(k, N+1) {
                dp[k][i][j] = -1000000;
            }
        }
    }

    dp[0][0][0] = 0;
    F0R(i, N) {
        F0R(j, Sz+1) {
            F0R(k, Tz+1) {
                if (C[i] != '*') {
                    int nxt = C[i] - 'a';
                    int nxtS = tranS[j][nxt];
                    int nxtT = tranT[k][nxt];
                    int nxtVal = dp[i][j][k];
                    if (nxtS == Sz) nxtVal++;
                    if (nxtT == Tz) nxtVal--;
                    dp[i + 1][nxtS][nxtT] = max(dp[i + 1][nxtS][nxtT], nxtVal);
                } else {
                    F0R(nxt, 26) {
                        int nxtS = tranS[j][nxt];
                        int nxtT = tranT[k][nxt];
                        int nxtVal = dp[i][j][k];
                        if (nxtS == Sz) nxtVal++;
                        if (nxtT == Tz) nxtVal--;
                        dp[i + 1][nxtS][nxtT] = max(dp[i + 1][nxtS][nxtT], nxtVal);
                    }
                }
            }
        }
    }

    int ans = -100000;
    F0R(i, Sz+1) {
        F0R(j, Tz+1) {
            ans = max(ans, dp[N][i][j]);
        }
    }
    cout << ans << endl;


    return 0;
}

// read the question correctly (ll vs int)
// template by bqi343