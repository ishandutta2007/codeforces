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
const int MX = 200001; //check the limits, dummy
int ans[MX]; 
ll res = 0;
vl datas;
int N, M; 


/*bool try(ll dist) {
    int nxt = 0;
    ll maxUsed = -4000000000;
    F0R(i, N) {
        FOR(gap, 1, 1+dist) {
            ll pos = data[i] - gap;
            if (pos > maxUsed) {
            ans[nxt] = pos;
            nxt++;
            res += gap;
            if (nxt == M) return true;
            }
            pos = data[i] + gap;
            ans[nxt] = pos;
            nxt++;
            res += gap;
            if (nxt == M) 

        }
        maxUsed = data[i] + dist;
        
    }

    return false;
}*/

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);    
	
    cin >> N >> M;
    F0R(i, N) {
        int cur; cin >> cur;
        datas.pb(cur);
        
    }
    sort(all(datas));

    /*ll lo = 1, hi = 2000000000;
    F0R(iter, 63) {
        ll mid = (lo+hi)/2;
        if (try(mid)) {
            hi = mid;
        } else {
            lo = mid+1;
        }
    }
    ll best = min(lo, hi);
    if (!try(min(lo, hi))) {
        best = max(lo, hi);
    }
    
    F0R(i, M) {
        cout << ans[i] << " ";
    }*/
    set<pair<int, bool> > viableTrees;
    F0R(i, N) {
        viableTrees.insert({i, true});
        viableTrees.insert({i, false});
    }
    set<ll> used;
    F0R(i, N) used.insert(datas[i]);
    FOR(gap, 1, M+1) {
        set<pair<int, bool> > tbr;
        for (auto it = viableTrees.begin(); it != viableTrees.end(); it++) {
            int tree = it->f;
            bool neg = it->s;
            ll pos = datas[tree];
            if (neg) {
                pos += gap;
            } else pos -= gap;
            if (used.count(pos)) {
                tbr.insert(*it);
            } else {
                used.insert(pos);
                res += gap;
            }
            if (sz(used) >= M+N) goto done;
        }
        for (auto it = tbr.begin(); it != tbr.end(); it++) {
            viableTrees.erase(*it);
        }
    }
    done:;
         F0R(i, N) used.erase(datas[i]);
    cout << res << endl;
    for (auto it = used.begin(); it != used.end(); it++) {
        cout << *it << " ";
    }

    cout << endl;

	return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343