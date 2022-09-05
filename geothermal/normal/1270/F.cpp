#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
 
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
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
const int MOD = 1000000007;
const ll INF = 1e18;
const int MX = 100001; //check the limits, dummy

ll solveSlow(string S) {
    int N = sz(S);
    ll ans = 0;
    F0R(i, N) {
        FOR(j, i+1, N+1) {
            int cnt = 0;
            FOR(k, i, j) {
                cnt += S[k] - '0';
            }
            if (cnt > 0 && (j-i) % cnt == 0) {
                ans++;
            }
        }
    }
    return ans;
}

ll solve(string S) {
    int N = sz(S);
    int T = 450;

    vi oneLocs;
    oneLocs.pb(-1); oneLocs.pb(N);
    F0R(i, N) {
        if (S[i] == '1') oneLocs.pb(i);
    }
    sort(all(oneLocs));
//    cout << "TEST" << endl;
    ll ans = 0;
    for (ll len = 1; len < T+1; len++) {    
        FOR(i, len, sz(oneLocs) - 1) {
            int lo = oneLocs[i-len+1];
            int hi = oneLocs[i];
            int thisLen = hi-lo+1;
            //Need total to be 0 mod len
            //count ways to sum--can do this on O(T)
            //or math bash.  say mar1 = X * len + Y, mar2 = A * len + B.  X*A*len + Y*A + B*X + count from A, B

            //THIS IS WRONG--need to add one to margins I think
            int mar1 = oneLocs[i-len+1] - oneLocs[i-len];
            int mar2 = oneLocs[i+1] - oneLocs[i]; //possible values are now from 0 to mar1 - 1
            ll X = mar1 / len; ll Y = mar1 - X * len;
            ll A = mar2 / len; ll B = mar2 - A * len;
//            if (len == 5) cout << mar1 << " " << mar2 << " " << X << " " << Y << " " << A << " " << B << endl;
            ll cnt = X * A * len;
            cnt += Y * A;
            cnt += B * X;
            int goal = thisLen % len;
            goal = len - goal; goal %= len;
//            if (len == 5) cout << goal << endl;
            //min value for 0..mar1 - 1, 0..mar2 - 1.  loPos = 
            if (Y > 0 && B > 0) {
                F0R(useless, 2) {
                    int loPos = max(0ll, goal-B+1);
                    int hiPos = min(Y-1, (ll) goal);
                    cnt += max(0ll, (ll) hiPos-loPos+1);
                    goal += len;
                }
            }
            ans += cnt;
//            cout << len << " " << i << " " << ans << endl;
        }
    }

//    cout << ans << endl;
    vector<int> counts(N*(T+4)); F0R(i, N*(T+4)) counts[i] = 0;
    int offset = N*2;
    FOR(mult, 1, T+1) {
        //at least T+1 1's
        //len = mult * 1's
        int prefSums[N+1];
        prefSums[0] = 0;
        F0R(i, N) {
            prefSums[i+1] = prefSums[i];
            if (S[i] == '1') prefSums[i+1] += mult-1;
            if (S[i] == '0') prefSums[i+1]--;
        }

        int countOnes = 0;
        F0R(i, N) {
            //if this is a 1, and it is at least the T+1's 1... add everything before the (i-T)'th 1.
            if (i == oneLocs[countOnes+1]) {
                countOnes++;
                if (countOnes >= T+1) {
                    FOR(j, oneLocs[countOnes-T-1], oneLocs[countOnes-T]) {
                        counts[prefSums[j+1]+offset]++;
                    }
                }
            }
            ans += counts[prefSums[i+1]+offset];
        }
        F0R(i, N+1) {
            counts[prefSums[i]+offset] = 0;
        }
    }
    return ans;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);    
	
    string S; cin >> S;


    cout << solve(S) << endl;

/*    int N = 20;

    F0R(it, (1 << N)) {
        string S;
        F0R(i, N) {
            if (it & (1 << i)) {
                S.pb('1');
            } else {
                S.pb('0');
            }
        }
        int wrong = solve(S);
        int slow = solveSlow(S);
        if (wrong != slow) {
            cout << "FOUND" << endl;
            cout << S << endl;
            cout << "Wrong " << wrong << endl;
            cout << "Slow " << slow << endl;
            return 0;
        }
    }*/


//    S += '0';
//    F0R(i, 200000) {
//        S += '1';
//    }
//    S += '0';
//    F0R(i, 100000) S += '1';
//    S += '0';
	return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343