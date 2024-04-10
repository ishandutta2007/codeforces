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
 
ll SZ = 2048;
ll* seg = new ll[2*SZ]; //segtree implementation by bqi343's Github


ll combine(ll a, ll b) { return max(a, b); }

void build() { F0Rd(i,SZ) seg[i] = combine(seg[2*i],seg[2*i+1]); }

void update(int p, ll value) {  
    for (seg[p += SZ] = value; p > 1; p >>= 1)
        seg[p>>1] = combine(seg[(p|1)^1], seg[p|1]);
}

ll query(int l, int r) {  // sum on interval [l, r]
    ll resL = 0, resR = 0; r++;
    for (l += SZ, r += SZ; l < r; l >>= 1, r >>= 1) {
        if (l&1) resL = combine(resL,seg[l++]);
        if (r&1) resR = combine(seg[--r],resR);
    }
    return combine(resL,resR);
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);    
	
    int N; cin >> N;
    int data[N]; F0R(i, N) cin >> data[i];
    int pref[N+1]; pref[0] = 0;
    F0R(i, N) {
        pref[i+1] = pref[i] + data[i];
    }

    map<int, vector<pi> > sums;
    F0R(i, N+1) {
        FOR(j, i+1, N+1) {
            sums[pref[j]-pref[i]].pb({j-1, i}); 
        }
    }
    int best = -2000000000;
    int pos = -2000000000;
    F0R(i, 2*SZ) seg[i] = 0;
    for (auto it = sums.begin(); it != sums.end(); it++) {
        vpi cur = it->s;
        sort(all(cur));
        F0R(i, sz(cur)) {
            pi X = cur[i];
            update(cur[i].f, max(query(cur[i].f, cur[i].f), query(0, cur[i].s-1) + 1));
        }
        int ans = query(0, 2047);
        if (ans > best) {
            best = ans;
            pos = it->f;
        }
        F0R(i, sz(cur)) {
            update(cur[i].f, 0);
        }
    }

    cout << best << endl;

    vpi cur = sums[pos];
    int lastRange[N+2]; F0R(i, N+2) lastRange[i] = -1;
    F0R(i, sz(cur)) {
        lastRange[cur[i].f+1] = max(lastRange[cur[i].f+1], cur[i].s+1);
    }
    int dp[N+2]; F0R(i, N+2) dp[i] = 0;
    int last[N+2]; F0R(i, N+1) last[i] = -1;
    F0R(i, N+2) {
        if (lastRange[i] > -1) {
            int hi = -1;
            pos = -1;
            F0R(j, lastRange[i]) {
                if (dp[j] > hi) {
                    hi = dp[j];
                    pos = j;
                }
            }
            dp[i] = hi+1;
            last[i] = pos;
        } 
    }

    best = -1, pos = -1;
    F0R(i, N+2) {
        if (dp[i] > best) {
            best = dp[i]; pos = i;
        }
    }

    while (last[pos] != -1) {
        cout << lastRange[pos] << " " << pos << endl;
        pos = last[pos];
    }
	
	return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343