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
	
    string S; cin >> S;
    int N = sz(S);
    int C[26]; F0R(i, 26) C[i] = 0;
    F0R(i, N) {
        C[S[i] - 'a']++;
    }

    F0R(i, 26) {
        F0Rd(j, 26) {
            if (C[i] % 2 && C[j] % 2) {
                C[j]--; C[i]++;
            }
        }
    }

    string A, B;
    F0R(i, 26) {
        F0R(j, C[i] / 2) {
            A += 'a' + i;
            B += 'a' + i;
        }
    }
    F0R(i, 26) {
        if (C[i] % 2) A += 'a' + i;
    }
    cout << A;
    reverse(all(B));
    cout << B << nl;
	
	return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343