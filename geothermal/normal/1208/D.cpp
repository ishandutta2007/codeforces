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
#define shandom_ruffle random_shuffle

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int MOD = 1000000007;
const ll INF = 1e18;
const int MX = 100001; //check the limits, dummy

template<class T, int SZ> struct LazySegTree {
    T sum[2*SZ], mn[2*SZ], lazy[2*SZ]; // set SZ to a power of 2

    LazySegTree() {
        memset (sum,0,sizeof sum);
        memset (mn,0,sizeof mn);
        memset (lazy,0,sizeof lazy);
    }

    void push(int ind, int L, int R) {
        sum[ind] += (R-L+1)*lazy[ind];
        mn[ind] += lazy[ind];
        if (L != R) lazy[2*ind] += lazy[ind], lazy[2*ind+1] += lazy[ind];
        lazy[ind] = 0;
    }

    void pull(int ind) {
        sum[ind] = sum[2*ind]+sum[2*ind+1];
        mn[ind] = min(mn[2*ind],mn[2*ind+1]);
    }

    void build() {
        FORd(i,1,SZ) pull(i);
    }

    T qsum(int lo, int hi, int ind = 1, int L = 0, int R = SZ-1) {
        push(ind,L,R);
        if (lo > R || L > hi) return 0;
        if (lo <= L && R <= hi) return sum[ind];

        int M = (L+R)/2;
        return qsum(lo,hi,2*ind,L,M) + qsum(lo,hi,2*ind+1,M+1,R);
    }

    T qmin(int lo, int hi, int ind = 1, int L = 0, int R = SZ-1) {
        push(ind,L,R);
        if (lo > R || L > hi) return -1;
        if (L == R) {
            if (mn[ind] == 0) return L;
            return -1;
        }
        int M = (L+R)/2;
        push(2*ind+1, M+1, R);
        if (mn[2*ind+1] == 0) return qmin(lo,hi,2*ind+1,M+1,R);
        //cout << 2*ind+1 << " doesn't work" << endl;
        return qmin(lo,hi,2*ind,L,M);
        //int M = (L+R)/2;
        //int X = qmin(lo,hi,2*ind+1,M+1,R);
        //if (X != -1) return X;
        //return qmin(lo,hi,2*ind,L,M);
        /*if (lo > R || L > hi) return 1000000000;
        if (lo <= L && R <= hi) return mn[ind];

        int M = (L+R)/2;
        return min(qmin(lo,hi,2*ind,L,M), qmin(lo,hi,2*ind+1,M+1,R));*/
    }

    void upd(int lo, int hi, ll inc, int ind = 1, int L = 0, int R = SZ-1) {
        push(ind,L,R);
        if (hi < L || R < lo) return;
        if (lo <= L && R <= hi) {
            lazy[ind] = inc;
            push(ind,L,R);
            return;
        }

        int M = (L+R)/2;
        upd(lo,hi,inc,2*ind,L,M); upd(lo,hi,inc,2*ind+1,M+1,R);
        pull(ind);
    }
};

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    LazySegTree<ll, 262144> seg;


    int N; cin >> N;
    F0R(i, N) {
        ll cur; cin >> cur;
        seg.upd(i, i, cur);
    }
    FOR(i, N, 262144) {
        seg.upd(i, i, 1000000000000);
    }

    //cout << seg.mn[262144] << " " << seg.mn[262145] << " " << seg.mn[262146] << " " << seg.mn[262147] << endl;

    //cout << seg.mn[0] << " " << seg.mn[1] << " " << seg.mn[2] << " " << seg.mn[3] << endl;
    int ans[N];
    FOR(i, 1, N+1) {

        /*int lo = 0;
        int hi = N-1;
        F0R(j, 20) {
            int mid = (lo+hi)/2;
            if (seg.qmin(mid, N+1) == 0) {
                lo = mid;
            } else {
                hi = mid-1;
            }
        }
        int pos;
        if (seg.qmin(hi, N+1) == 0) {
            pos = hi;
        }  else pos = lo;*/
        int pos = seg.qmin(0, 262143);
        //cout << pos << endl;

        //cout << pos << endl;
        //cout << seg.qmin(0, 0) << " " << seg.qmin(1, 1) << " " << seg.qmin(2, 2) << endl;
        ans[pos] = i;
        seg.upd(pos, pos, 1000000000000);
        seg.upd(pos+1, 262143, -1*i);
        //cout << seg.mn[262147] << endl;
    }

    F0R(i, N) {
        cout << ans[i] << " ";
    }
    cout << endl;


    return 0;
}

// read the question correctly (ll vs int)
// template by bqi343
// license: https://github.com/bqi343/USACO/blob/master/LICENSE