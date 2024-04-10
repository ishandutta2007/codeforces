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
#define ins insert
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
const int MOD = 1000000007;
const ll INF = 1e18;
const int MX = 100001; //check the limits, dummy
 
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);    
	
    int N, K; cin >> N >> K;
    vi A(N);
    F0R(i, N) {
        char C; cin >> C;
        if (C == 'R') {
            A[i] = 1;
        } else {
            A[i] = 0;
        }
    }

    vector<vi> moves;
    while (true) {
        vi cur;
        F0R(i, N-1) {
            if (A[i] == 1 && A[i+1] == 0) {
                cur.pb(i);
            }
        }
        F0R(i, sz(cur)) {
            swap(A[cur[i]], A[cur[i]+1]);
        }
        if (sz(cur) == 0) break;
        moves.pb(cur);
    }
    int lo = sz(moves);
    int hi = 0; F0R(i, sz(moves)) hi += sz(moves[i]);
    if (K < lo || K > hi) {
        cout << -1 << endl; return 0;
    }
    int cur = 0;
    int pos = 0;
    while (K > sz(moves) - cur) {
        cout << "1 " << moves[cur][pos]+1 << '\n';
        pos++;
        if (pos == sz(moves[cur])) {
            cur++; pos = 0;
        }
        K--;
    }

    while (cur < sz(moves)) {
        cout << sz(moves[cur]) - pos << " ";
        FOR(i, pos, sz(moves[cur])) {
            cout << moves[cur][i]+1 << " ";
        }
        cout << '\n';
        pos = 0; cur++;
    }


/*    int lo = 0, cur = 0;
    ll hi = 0;
    F0R(i, N) {
        if (A[i]) cur++;
        if (!A[i]) lo = cur, hi += cur;
    }
    if (K < lo || K > hi) {
        cout << -1 << endl;
    }

    cur = -1, goal = -1;
    while (K > lo) {
        if (cur == -1) {
            bool found = false;
            int cnt = 0;
            F0R(i, N) {
                if (!A[i]) {
                    if (found) {
                        cur = i; goal = cnt;
                    } else {
                        cnt++;
                    }
                } else {
                    found = true;
                }
            }
        }

        cout << "1 " <<  cur << '\n';
        cur--;
        swap(A[cur-1], A[cur]);
        if (cur == goal) cur = -1;
        K--;
    }

    while(K--) {
        vi res;
        F0R(i, N) {
            
        }
    }*/
	
	return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343