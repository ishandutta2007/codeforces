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
 
const ll identity = 0;
const ll SZ = 131072*2;

ll sum[2*SZ], lazy[2*SZ];

ll combine(ll A, ll B) {
    return max(A, B);
}

ll combineUpd(ll A, ll B) {
    return A+B;
}

void push(int index, ll L, ll R) {
    sum[index] = combineUpd(sum[index], lazy[index]);
    if (L != R) lazy[2*index] = combineUpd(lazy[2*index], lazy[index]), lazy[2*index+1] = combineUpd(lazy[2*index+1], lazy[index]);
    lazy[index] = identity;
}

void pull(int index) {
    sum[index] = combine(sum[2*index], sum[2*index+1]);
}

bool checkCondition(int index, int val) {
    //FILL THIS IN
//    cout << "Sum at " << index << " equals " << sum[index] << endl;
    return sum[index] >= val;
}
ll last = -1;
ll query(int val, int lo = 0, int hi = SZ-1, int index = 1, ll L = 0, ll R = SZ-1) { //returns first node satisfying con
    push(index, L, R);
    if (lo > R || L > hi) return -1;
    if (L == R) {
        bool condition = checkCondition(index, val);
        return (condition ? L : -1);
    }
    int M = (L+R) / 2;
    push(2*index, L, M);
    push(2*index+1, M+1, R);
    if (!checkCondition(2*index, val)) {
        return query(val, lo, hi, 2*index+1, M+1, R);
    }
    return query(val, lo, hi, 2*index, L, M); 
}

void update(int lo, int hi, ll increase, int index = 1, ll L = 0, ll R = SZ-1) {
    push(index, L, R);
    if (hi < L || R < lo) return;
    if (lo <= L && R <= hi) {
        lazy[index] = increase;
        push(index, L, R);
        return;
    }

    int M = (L+R) / 2;
    update(lo, hi, increase, 2*index, L, M); update(lo, hi, increase, 2*index+1, M+1, R);
    pull(index);
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);    
    int N; cin >> N;
    vi preData(N); F0R(i, N) cin >> preData[i];
    vpi data;
    F0R(i, N) {
        data.pb({preData[i], -1*i});
    }
    sort(all(data));
    reverse(all(data));
    F0R(i, N) data[i].s *= -1;
    int M; cin >> M;
    vector<pair<pi, int> > queries(M);
    int ans[M];
    F0R(i, M) {
        int A, B; cin >> A >> B; queries[i] = {{A, B}, i};
    }
    sort(all(queries));
    int cur = 0;
    F0R(q, M) {
        FOR(i, cur, queries[q].f.f) {
            update(data[i].s, SZ-1, 1);
//            cout << sum[1] << " " << lazy[1] << " i " << i << endl;
        }
        cur = queries[q].f.f;
        ans[queries[q].s] = query(queries[q].f.s);
//        cout << sum[1] << " " << lazy[1] << " " << q << endl;

    }

    F0R(i, M) {
        assert(ans[i] < N && ans[i] >= 0);
        cout << preData[ans[i]] << endl;
    }
	
	return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343