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
const char nl = '\n';
const int MX = 100001; //check the limits, dummy
vi ans;
vector<vi> data;
bool solve(bool param) {
    ans.clear();
    int N = sz(data)+1;
    bool act[N-1]; F0R(i, N-1) act[i] = true;

    bool used[N]; F0R(i, N) used[i] = false;
    int lst = -1;
    int pos[N-1];
    F0R(it, N-1) {
        int cnt[N]; F0R(i, N) cnt[i] = 0;
        F0R(i, N-1) {
            if (!act[i]) continue;
            F0R(j, sz(data[i])) {
                cnt[data[i][j]]++;
            }
        }
        int K = -1;
        F0R(i, N) {
            if (cnt[i] == 1 && !used[i]) {
                if (K == -1) {
                    K = i;
                } else if (param) {
                    lst = i; used[i] = true;
                } else {
                    lst = K; used[K] = true;
                    K = i;
                }
            }
        }
        if (K == -1) {
            return false;
        }
        F0R(i, N-1) {
            if (!act[i]) continue;
            F0R(j, sz(data[i])) {
                if (data[i][j] == K) {

                    act[i] = false;
                    pos[i] = it;
                }
            }
        }
        used[K] = true;
        ans.pb(K);
    }
    ans.pb(lst);
    set<int> vals[N-1]; 
    F0R(i, N-1) {
        F0R(j, sz(data[i])) {
            vals[i].ins(data[i][j]);
        }
    }
    F0R(i, N-1) {
        F0R(j, sz(data[i])) {
            if (!vals[i].count(ans[pos[i]+j])) return false; 
        }
    }
    reverse(all(ans));
    return true;
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);    
	
    int T; cin >> T;
    while(T--) {
        int N; cin >> N;
        data.clear();
        F0R(i, N-1) {
            int K; cin >> K;
            vi X; data.pb(X);
            F0R(j, K) {
                int A; cin >> A; A--;
                data[i].pb(A);
            }
        }
        if (!solve(false)) {
            assert(solve(true));
        }
        F0R(i, N) {
            cout << ans[i] + 1 << " ";
        }
        cout << nl;
    }
	
	return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343