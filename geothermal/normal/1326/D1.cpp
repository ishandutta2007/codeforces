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
 
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);    
	
    int T; cin >> T;
    while(T--) {
        string S; cin >> S; int N = sz(S);
        string s = S;

        //Manacher's algorithm code from cp-algorithms
        int n = N;
        vector<int> d1(n);
        for (int i = 0, l = 0, r = -1; i < n; i++) {
            int k = (i > r) ? 1 : min(d1[l + r - i], r - i + 1);
            while (0 <= i - k && i + k < n && s[i - k] == s[i + k]) {
                k++;
            }
            d1[i] = k--;
            if (i + k > r) {
                l = i - k;
                r = i + k;
            }
        }

        vector<int> d2(n);
        for (int i = 0, l = 0, r = -1; i < n; i++) {
            int k = (i > r) ? 0 : min(d2[l + r - i + 1], r - i + 1);
            while (0 <= i - k - 1 && i + k < n && s[i - k - 1] == s[i + k]) {
                k++;
            }
            d2[i] = k--;
            if (i + k > r) {
                l = i - k - 1;
                r = i + k ;
            }
        }

        int val = 0;
        F0R(i, N/2) {
            if (S[i] == S[N-i-1]) {
                val++;
            } else break;
        }

        int bestPre = 0;

        int bestPost = 0;

        FOR(i, val, N-val) {
            if (d2[i] >= i-val) {
                if (val+(i-val)*2 - 1 < N-val) bestPre = max(bestPre, (i-val)*2);
            }
            if (d1[i] >= i-val+1) {
                if (val + (i-val)*2 < N-val) bestPre = max(bestPre, (i-val)*2+1);
            }
            if (d2[i] >= N-val-i) {
                if (N-val - (N-i-val)*2 >= val) bestPost = max(bestPost, (N-i-val)*2);
            }
            if (d1[i] >= N-val-i) {
                if (N-val - (N-i-val)*2 + 1 >= val) bestPost = max(bestPost, (N-i-val-1)*2+1);
            }
        }

//        cout << bestPre << " " << bestPost << " " << val << endl;

        F0R(i, val) {
            cout << S[i];
        }

        if (bestPre > bestPost) {
            FOR(i, val, bestPre+val) {
                cout << S[i];
            }
        } else {
            FOR(i, N-val-bestPost, N-val) {
                cout << S[i];
            }
        }

        FOR(i, N-val, N) {
            cout << S[i];
        }
        cout << endl;
    }
	
	return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343