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
const int MX = 100001; //check the limits, dummy

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    ll fact[60];
    fact[0] = 1;
    FOR(i, 1, 60) {
        fact[i] = fact[i-1] * i;
        fact[i] = fact[i] % MOD;
    }

    int N; cin >> N;
    int T; cin >> T;

    vi data[3];
    F0R(i, N) {
        int A, B; cin >> A >> B;
        data[B-1].pb(A);
    }
    int A = sz(data[0]); int B = sz(data[1]); int C = sz(data[2]);
    ll dp[T+1][A+1][B+1][C+1];

    F0R(i, T+1) {
        F0R(j, A+1) {
            F0R(k, B+1) {
                F0R(x, C+1) {
                    dp[i][j][k][x] = 0;
                }
            }
        }
    }

    dp[0][0][0][0] = 1;

    F0R(i, A) {
        F0Rd(j, i+1) {
            F0R(t, T+1-data[0][i]) {
                dp[t+data[0][i]][j+1][0][0] += dp[t][j][0][0];
                dp[t+data[0][i]][j+1][0][0] = dp[t+data[0][i]][j+1][0][0] % MOD;
            }
        }
    }

    F0R(i, B) {
        F0Rd(j, i+1) {
            F0R(sA, A+1) {
                F0R(t, T+1-data[1][i]) {
                    dp[t+data[1][i]][sA][j+1][0] += dp[t][sA][j][0];
                    dp[t+data[1][i]][sA][j+1][0] = dp[t+data[1][i]][sA][j+1][0] % MOD;
                }
            }
        }
    }

    F0R(i, C) {
        F0Rd(j, i+1) {
            F0R(sA, A+1) {
                F0R(sB, B+1) {
                    F0R(t, T+1-data[2][i]) {
                        dp[t+data[2][i]][sA][sB][j+1] += dp[t][sA][sB][j];
                        dp[t+data[2][i]][sA][sB][j+1] = dp[t+data[2][i]][sA][sB][j+1] % MOD;
                    }
                }
            }
        }
    }


    ll ans = 0;
    F0R(i, A+1) {
        F0R(j, B+1) {
            F0R(k, C+1) {
                if (dp[T][i][j][k] == 0) continue;
                ll dp2[i+1][j+1][k+1][3];
                F0R(i2, i+1) {
                    F0R(j2, j+1) {
                        F0R(k2, k+1) {
                            F0R(x, 3) {
                                dp2[i2][j2][k2][x] = 0;
                            }
                        }
                    }
                }
                if (i > 0) dp2[1][0][0][0] = 1;
                if (j > 0) dp2[0][1][0][1] = 1;
                if (k > 0) dp2[0][0][1][2] = 1;
                F0R(i2, i+1) {
                    F0R(j2, j+1) {
                        F0R(k2, k+1) {
                            F0R(x, 3) {
                                if (x != 0 && i2 != i) {
                                    dp2[i2+1][j2][k2][0] += dp2[i2][j2][k2][x];
                                    dp2[i2+1][j2][k2][0] = dp2[i2+1][j2][k2][0] % MOD;
                                }
                                if (x != 1 && j2 != j) {
                                    dp2[i2][j2+1][k2][1] += dp2[i2][j2][k2][x];
                                    dp2[i2][j2+1][k2][1] = dp2[i2][j2+1][k2][1] % MOD;
                                }
                                if (x != 2 && k2 != k) {
                                    dp2[i2][j2][k2+1][2] += dp2[i2][j2][k2][x];
                                    dp2[i2][j2][k2+1][2] = dp2[i2][j2][k2+1][2] % MOD;
                                }
                            }
                        }
                    }
                }
                ll sum = dp2[i][j][k][0] + dp2[i][j][k][1] + dp2[i][j][k][2]; sum = sum % MOD;
                sum = sum * fact[i]; sum = sum % MOD; sum = sum * fact[j]; sum = sum % MOD; sum = sum * fact[k]; sum = sum % MOD;
                ans += dp[T][i][j][k] * (sum);
                ans = ans % MOD;
            }
        }
    }
    cout << ans << endl;

    return 0;
}

// read the question correctly (ll vs int)
// template by bqi343