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
#define uid(a, b) uniform_int_distribution<int>(a, b)(rng)
 
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


/*ll SZ = 262144*2; //set this to power of two
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
}*/


const ll identity = -10000000000;;
const ll SZ = 131072*4;

ll sum[2*SZ], add[2*SZ], lazy[2*SZ];


void push(int index, ll L, ll R) {
    if (lazy[index] == identity) return;
    sum[index] = lazy[index] + add[index];
    //cout << "TEST" << sum[index] << " " << lazy[index] << L << " " << R << nl;
    if (L != R) lazy[2*index] = lazy[index], lazy[2*index+1] = lazy[index];
    lazy[index] = identity;
}

void pull(int index) {
    sum[index] = max(sum[2*index], sum[2*index+1]);
}

ll query(int lo, int hi, int index = 1, ll L = 0, ll R = SZ-1) {
    push(index, L, R);
    if (lo > R || L > hi) return -1e18;
    if (lo <= L && R <= hi) return sum[index];

    int M = (L+R) / 2;
    return max(query(lo, hi, 2*index, L, M), query(lo, hi, 2*index+1, M+1, R));
}

void update(int lo, int hi, ll increase, int index = 1, ll L = 0, ll R = SZ-1) {
    //cout << index << " " << L << " " << R << nl;
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

void upd2(int p, ll val) {
    p += SZ;
    add[p] = val;
    while (p > 1) {
        p /= 2;
        ckmax(add[p], val);
    }
}


void solve() {

    int N; cin >> N;
    int H[N]; F0R(i, N) cin >> H[i];
    ll B[N]; F0R(i, N) cin >> B[i];
    /*update(N-1, B[N-1]);
    stack<int> st; st.push(N); st.push(N-1);
    multiset<ll> vals;
    vals.ins(B[N-1]);
    ll cur[N]; 
    cur[N-1] = B[N-1];
    F0Rd(i, N-1) {
        while (st.top() != N && A[i] < A[st.top()]) {
            int x = st.top();
            vals.erase(cur[x]);
            st.pop();
        }
        ll num = query(i, st.top()-1) + B[i];
        vals.ins(num);
        cur[i] = num;
        if (st.top() != N) {
            int x = st.top(); st.pop();
            vals.erase(cur[x]);
            cur[x] = query(x, st.top() - 1)
        }
    }
    cout << query(0, 0) << nl;*/
    F0R(i, 2*SZ) lazy[i] = identity;
    F0R(i, 2*SZ) {
        sum[i] = -1e18; add[i] = -1e18;
    }
    upd2(N, 0);
    update(N, N, 0);
    stack<int> st; st.push(N); st.push(N);
    F0Rd(i, N) {
        while (st.top() != N && H[i] < H[st.top()]) {
            st.pop();
        }
        update(i+1, st.top(), B[i]);
        st.push(i);
        ll val = query(i+1, N);
        //cout << val << nl;
        if (i == 0) cout << val << nl;
        upd2(i, val);
    }

}
 
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);    

    int T = 1;
//    cin >> T;
    while(T--) {
        solve();
    }

	return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343