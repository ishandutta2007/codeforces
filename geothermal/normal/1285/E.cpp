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
        int N; cin >> N;
        set<int> used;
        vpi data(N);
        F0R(i, N) {
            int A, B; cin >> A >> B; used.insert(A); used.insert(B);
            data[i] = {A, B};
        }
        map<int, int> comp;
        int curVal = 0;
        for (auto it = used.begin(); it != used.end(); it++) {
            comp.insert({*it, curVal});
            curVal++;
        }

        F0R(i, N) {
            data[i].f = comp[data[i].f];
            data[i].s = comp[data[i].s];
        }

        vpi events;
        F0R(i, N) {
            events.pb({data[i].f, i});
            events.pb({data[i].s, i});
        }
        sort(all(events));
        set<int> curUsed;
        int cnts[N]; F0R(i, N) cnts[i] = 0;
        int countZero = 0;
        events.pb({MOD, -1});
        int pos = 0;
        ll pointCovers[sz(used)];
        ll curCover = 0;
        F0R(i, sz(used)) {
            curCover = sz(curUsed);
            while (events[pos].f == i) {
//                cout << i << " " << events[pos].s << endl;
                if (curUsed.count(events[pos].s)) {
                    curUsed.erase(events[pos].s);
                } else {
                    curUsed.insert(events[pos].s);
                    curCover++;
                }
                pos++;
            }
            pointCovers[i] = 0;
            if (curCover == 1) pointCovers[i] = 1;
            if (i == sz(used) - 1) break;
            if (sz(curUsed) == 1) {
                cnts[*(curUsed.begin())]++;
            } else if (sz(curUsed) == 0) {
                countZero++;
            }
        }
        ll preCover[sz(used)+1]; preCover[0] = 0;
        F0R(i, sz(used)) {
            preCover[i+1] = preCover[i] + pointCovers[i];
        }
        F0R(i, N) {
            cnts[i] -= preCover[data[i].s+1] - preCover[data[i].f];
        }

        int best = -1;
        F0R(i, N) best = max(best, cnts[i]);

        cout << best+countZero+1 << endl;
    }
	
	return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343