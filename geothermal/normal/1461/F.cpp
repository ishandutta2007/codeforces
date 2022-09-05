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

string solve(vi &A) {
    int c1 = -1, c2 = 0;
    int N = sz(A);
    F0R(i, N) {
        if (A[i] != 1) {
            c1 = i; break;
        }
    }
    string res;
    if (c1 == -1) {
        
        F0R(i, N-1) {
            res += "1+";
        }
        res += '1'; return res;
    }
    F0Rd(i, N) {
        if (A[i] != 1) {
            c2 = N-1-i; break;
        }
    }

    int cc = 0;
    int cgood = 0;
    vi cur;
    FOR(i, c1, N-c2) {
        if (A[i] == 1) {
            cc++;
        } else {
            cgood++;
            if (cc != 0) {
                cur.pb(-cc); cc = 0;
            }
            cur.pb(A[i]);
        }
    }
    N = sz(cur);
    if (cgood < 20) {
        ll dp[N+1];
        ll lst[N+1];
        F0R(i, N+1) dp[i] = 0;
        F0R(i, N+1) lst[i] = 0;
        F0R(i, N+1) {
            if (dp[i] > 1000000) {
                goto done;
            }
            ll pr = 1;
            FOR(j, i+1, N+1) {
                if (cur[j-1] > 0) pr *= cur[j-1];
                if (pr >= 1000000) goto done;
                if (ckmax(dp[j], dp[i] + pr)) {
                    lst[j] = i;
                }
            }
            if (i < N && ckmax(dp[i+1], dp[i] + abs(cur[i]))) {
                lst[i+1] = i;
            }
        }
/*        F0R(i, N+1) {

            cout << dp[i] << " " << lst[i] << nl;
        }
        F0R(i, N) {
            cout << cur[i] << " ";
        }
        cout << nl;*/
        int val = N;
        while (val > 0) {
            int L = lst[val];
            if (L == val-1) {
                val--;
                if (cur[val] > 0) {
                    res += '0' + cur[val];
                    res += '+';
                } else {
                    F0R(i, -cur[val]) {
                        res += "1+";
                    }
                }
                continue;
            }
            while (val > L) {
                val--;
                if (cur[val] > 0) {
                    res += '0' + cur[val];
                    res += "*";
                } else {
                    F0R(i, -cur[val]) {
                        res += "1*";
                    }
                }
            }
            res.pop_back(); res += "+";
        }
        res.pop_back(); reverse(all(res)); 
    }
    done:
    ;
    if (sz(res) == 0) {
        F0R(i, N) {
            if (cur[i] > 0) {

                res += '0' + cur[i];
                res += '*';
            } else {
                F0R(j, -cur[i]) res += "1*";
            }
        }
        res.pop_back();
    }
    string val; F0R(i, c1) val += "1+";
    val += res;
    F0R(i, c2) val += "+1";
    return val;
}
 
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);    
	
    int N; cin >> N;
    int A[N]; F0R(i, N) cin >> A[i];
    string S; cin >> S;
    bool ok[3]; F0R(i, 3) ok[i] = false;
    F0R(i, sz(S)) {
        if (S[i] == '*') {
            ok[0] = true;
        } 
        if (S[i] == '+') {
            ok[1] = true;
        }
        if (S[i] == '-') {
            ok[2] = true;
        }
    }

    if (!ok[0]) {
        if (ok[1]) {
            F0R(i, N-1) {
                cout << A[i] << '+';
            }
            cout << A[N-1] << nl;
        } else {
            F0R(i, N-1) {
                cout << A[i] << '-';
            }
            cout << A[N-1] << nl;
        }
    } else {
        if (!ok[1]) {
            if (!ok[2]) {
                F0R(i, N-1) {
                    cout << A[i] << '*';
                }
                cout << A[N-1] << nl;
                return 0;
            } else {
                F0R(i, N-1) {
                    cout << A[i];
                    if (A[i+1] == 0) {
                        cout << '-';
                    } else {
                        cout << '*';
                    }
                }
                cout << A[N-1] << nl;
                return 0;
            }
        }
        //and now, the actual hard case
        string ans;
        vi cur;
        F0R(i, N) {
            if (A[i] == 0) {
                if (sz(cur) != 0) ans += solve(cur) + '+';
                cur.clear();
                ans += '0'; 
                if (i != N-1) ans += '+';
            }  else {
                cur.pb(A[i]);
            }
        }
        if (sz(cur) != 0) ans += solve(cur);
        cout << ans << nl;
    }
	
	return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343