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
const int MX = 1005; //check the limits, dummy
int N;
int A[MX];
bool ans[MX][MX];
int block[MX];
int bs[MX];
int bc = 1;
queue<int> ab;
bool poss(int K, int cnt) {
    F0R(i, bc) {
        cnt -= max(0, bs[i] - K);
    }
    return cnt >= 0;
}

void assign(int p) {
    int bp[MX]; F0R(i, MX) bp[i] = -1;
    int ns[MX]; 
    int op = A[p];
//    cout << p << " " << A[p] << " " << K << nl;
    bool found = false;
    F0R(i, MX) {
        if (!found) {
            if (bs[i] > 1) {
                ns[i] = max(bs[i]-A[p], 1);
                found = true;
            } else {
                ns[i] = bs[i];
                if (bs[i] == 1 && A[p] > 1) {
                    ns[i] = 0;
                }
            }
        } else {
            ns[i] = max(bs[i] - A[p], 0);
        }
        A[p] -= bs[i] - ns[i];
    }

    if (A[p] > 0) {
        A[p] = op;
        F0R(i, MX) {
            ns[i] = bs[i];
            if (bs[i] == 1 && A[p] > 0) {
                ns[i] = 0; A[p]--;
            }
        }
    }

    F0R(i, MX) {
        if (bs[i] == ns[i]) continue;
        if (ns[i] == 0) {
            bp[i] = i;
        } else {
            bp[i] = bc; bc++;
        }
    }
    F0R(i, N+1) {
        if (bs[block[i]] > ns[block[i]]) {
            if (bp[block[i]] == block[i]) {
                ans[p][i] = !ans[p][i];
                ns[block[i]]++;
            } else {
                bs[block[i]]--;
                ans[p][i] = !ans[p][i];
                block[i] = bp[block[i]];
                bs[block[i]]++;
            }
        }
    }


}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);    
	
    cin >> N;
    F0R(i, N) {
        cin >> A[i];
    }
    F0R(i, MX) bs[i] = 0;
    F0R(i, N) block[i] = 0;
    F0R(i, N+1) F0R(j, N) ans[j][i] = false;
    bs[0] = N+1;
    FOR(i, 1, MX) {
        ab.push(i);
    }
    F0R(x, N) {
/*        int lo = 0, hi = 0;
        if (A[x] * 2 > N) {
            A[x] = N + 1 - A[x];
            F0R(i, N+1) ans[x][i] = true;
        }
        F0R(i, bc) {
            ckmax(hi, bs[i]);
            ckmax(lo, (bs[i]+1)/2);
        }
        while (lo < hi) {
            int mid = (lo+hi)/2;
            if (poss(mid, A[x])) {
                hi = mid;
            } else lo = mid+1;
        }*/
        assign(x);
    }
    cout << N+1 << nl;
    F0R(j, N+1) {
        F0R(i, N) {
            cout << (ans[i][j]?1:0);
        }
        cout << nl;
    }
	
	return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343