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
bool solve(vector<pair<int, pair<int, int> > > events, vpi data) {
    sort(all(events));
    multiset<int> starts, ends;
    int N = sz(data);
    F0R(i, 2*N) {
        int pos = events[i].s.s;
//        cout << pos << " " << data[pos].f << " " << data[pos].s << endl;
        if (events[i].s.f == 1) {
            int lo = data[pos].f, hi = data[pos].s;
            starts.erase(starts.find(lo));
            ends.erase(ends.find(hi));
        } else {
            int lo = data[pos].f, hi = data[pos].s;
            if (sz(starts) > 0 && (lo > *ends.begin() || hi < *starts.rbegin())) {
                return false;
            }
            starts.insert(lo); ends.insert(hi);
            
        }
    }
    return true;
}

bool solveSlow(vector<pair<pi, pi> > data) {
    int N = sz(data);
    F0R(i, N) {
        FOR(j, i+1, N) {
            int cnt = 0;
            if (max(data[i].f.f, data[j].f.f) <= min(data[i].f.s, data[j].f.s)) cnt++;
            if (max(data[i].s.f, data[j].s.f) <= min(data[i].s.s, data[j].s.s)) cnt++;
            if (cnt == 1) return false;
        }
    }
    return true;
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);    
	
//    while (true) {
    int N = 5; cin >> N;
    vector<pair<int, pair<int, int> > > events1, events2;
    vpi data1(N), data2(N);
    vector<pair<pi, pi> > data;
    F0R(i, N) {
        int A, B, C, D; cin >> A >> B >> C >> D;
/*        A = uniform_int_distribution<int>(0, 10)(rng);
        B = uniform_int_distribution<int>(A, 12)(rng);
        C = uniform_int_distribution<int>(0, 10)(rng);
        D = uniform_int_distribution<int>(C, 12)(rng);*/;

        events1.pb({A, {0, i}});
        events1.pb({B, {1, i}});
        data1[i] = {C, D};
        events2.pb({C, {0, i}});
        events2.pb({D, {1, i}});
        data2[i] = {A, B};
//        data.pb({{A, B}, {C, D}});
    }

/*    bool ans1 = solve(events1, data1) && solve(events2, data2);
    bool ans2 = solveSlow(data);
    if (ans1 != ans2) {
        cout << N << endl;
        F0R(i, N) {
            cout << data[i].f.f << " " << data[i].f.s << " " << data[i].s.f << " " << data[i].s.s << endl;
        }
        cout << "FAST " << ans1 << endl;
        cout << "SLOW " << ans2 << endl;
        return 0;
    }
    }*/

    cout << (solve(events1, data1) && solve(events2, data2) ? "YES" : "NO") << endl;


	
	return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343