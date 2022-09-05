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
const int MX = 100001; //check the limits, dummy
 
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);    
	
    int T; cin >> T;
    while(T--) {
        int A[3], B[3], C[8];
        F0Rd(i, 3) cin >> A[i];
        F0Rd(i, 3) cin >> B[i];
        FORd(i, 1, 8) cin >> C[i];
        
        F0R(i, 3) {
            int space = A[i] + B[i];
            FOR(j, 1, 8) {
                if (j & (1 << i)) space -= C[j];
            }
            if (space < 0) {
                cout << -1 << nl; goto done;
            }
        }
        F0R(i, C[7] + 1) {
            F0R(j, C[6] + 1) {
                int lof = C[7] + C[6] + C[5] - i - j - B[2]; // range for 5
                int hif = A[2] - i - j;
                hif = min(hif, C[5]);
                lof = max(lof, 0);
                if (hif < lof) continue;
                int hit = A[1] - i - j; // range for 3
                int lot = C[7] + C[6] + C[3] - i - j - B[1];
                hit = min(hit, C[3]);
                lot = max(lot, 0);

                if (hit < lot) continue;
                int los = C[7] + C[5] + C[3] - i - B[0];
                int his = A[0] - i;
                /*if (j == 610) {
                    cout << "TEST " << i << " " << j << nl;
                    cout << lof << " " << hif << nl;
                    cout << lot << " " << hit << nl;
                    cout << los << " " << his << nl;
                }*/
                if (his < lof + lot || los > hit + hif) {
                    continue;
                }
/*                cout << "TEST " << i << " " << j << nl;
                cout << lof << " " << hif << nl;
                cout << lot << " " << hit << nl;
                cout << los << " " << his << nl;*/
                FOR(a, lof, hif+1) {
                    FOR(b, lot, hit+1) {
                        if (a+b >= los && a+b <= his) {
                            int one = min(C[1], A[0] - i - a - b);
                            int two = min(C[2], A[1] - i - j - b);
                            int four = min(C[4], A[2] - i - j - a);
                            cout << i << " " << j << " " << a << " " << four << " " << b << " " << two << " " << one << nl;
                            goto done;
                        }
                    }
                }
            }
        }
        cout << -1 << nl;
        done:
        ;
    }
	
	return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343