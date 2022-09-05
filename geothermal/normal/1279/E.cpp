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
const int MX = 52; //check the limits, dummy
 
ll* facs = new ll[MX];


void initFacs() {
	facs[0] = 1;
	FOR(i, 1, MX) {
		facs[i] = (facs[i-1] * i) ;
	}
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);    
    int T; cin >> T;
	while(T--) {
    int N; ll K; cin >> N >> K;
    vi ans;
    F0R(i, N-22) {
        ans.pb(i+1);
    }
    ll cnts[MX];
    cnts[0] = 1;
    cnts[1] = 1;
    initFacs();
    FOR(i, 2, MX) {
        cnts[i] = 0;
        F0R(j, i) {
            ll val = cnts[j];
            if (i-j > 2) {
                val *= facs[i-j-2];
            }
            cnts[i] += val;
        }
    }
    if (N <= 22 && cnts[N] < K) {
        cout << -1 << endl; continue;
    }
    bool used[N+1]; F0R(i, N) used[i] = false;
    F0R(i, sz(ans)) used[ans[i]] = true;
    int active = -1;
    int offset = -1;
    int nxtVal = -1;
//    cout << cnts[29] << endl;
    FOR(i, max(0, N-22), N) {
        if (active == -1) {
            FOR(j, 1, N-i+1) {//use j next
                ll curFac = cnts[N-i-j];
                if (j > 2) curFac *= facs[j-2];
//                cout << curFac << endl;
//                cout << i << " " << j << " " << curFac << " " << K << endl;;
                if (curFac < K) {
                    K -= curFac;
                } else {
                    active = j;//count of elements
                    offset = i;//0-indexed start
                    ans.pb(i+j);
                    used[i+j] = true;
                    nxtVal = N-i-j;
                    if (j == 1) {
                        active = -1;
                    }
                    break;
                }
            }
        } else {

            FOR(j, offset+1, offset+active) {
                int pos = j;
                bool bad = false;
                F0R(k, 52) {
                    if (pos > i+1) break;
                    if (pos == i+1) { bad = true; break; }
                    pos = ans[pos-1];
                }
                
                if ((bad && i != offset+active-1) || i+1 == j || used[j]) continue;
                ll curFac = cnts[nxtVal];
                if (offset + active - i > 2) {
                    curFac *= facs[offset+active-i-2];
                }

                if (curFac < K) {
                    K-=curFac;
                } else {
                    ans.pb(j);
                    used[j] = true;
                    break;
                }


                if (j == offset+active-1) {
                    cout << "BAD" << i << " " << K << endl;
                }
            }

            if (i == active+offset-1) {
                active = -1;
            }
        }
    }
    

    F0R(i, N) {
        cout << ans[i] << " ";
    }
    cout << endl;

    }

    /*F0R(i, MX) {
        cout << i << " " << cnts[i] << endl;
    }*/
	return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343