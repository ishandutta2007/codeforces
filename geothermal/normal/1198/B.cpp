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

const int MOD = 1000000007;
const ll INF = 1e18;
const int MX = 100001; //check the limits, dummy

ll sum[524288], lazy[524288]; //Lazy segtree implementation inspired by bqi343's Github contributions



void push(int index, ll L, ll R) {
    sum[index] = max(lazy[index], sum[index]);
    if (L != R) lazy[2*index] = max(lazy[2*index], lazy[index]), lazy[2*index+1] = max(lazy[2*index+1], lazy[index]);
    lazy[index] = 0;
}

void pull(int index) {
    sum[index] = max(sum[2*index], sum[2*index+1]);
}

ll query(int lo, int hi, int index = 1, ll L = 0, ll R = 262143) {
    push(index, L, R);
    if (lo > R || L > hi) return 0;
    if (lo <= L && R <= hi) return sum[index];

    int M = (L+R) / 2;
    return max(query(lo, hi, 2*index, L, M), query(lo, hi, 2*index+1, M+1, R));
}

void update(int lo, int hi, ll increase, int index = 1, ll L = 0, ll R = 262143) {
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

void updatePoint(int lo, int hi, ll increase, int index = 1, ll L = 0, ll R = 262143) {
    push(index, L, R);
    if (hi < L || R < lo) return;
    if (lo <= L && R <= hi) {
        lazy[index] = 0;
        sum[index] = increase;
        //cout << sum[index] << endl;
        push(index, L, R);
        //cout << sum[index] << endl;
        return;
    }

    int M = (L+R) / 2;
    updatePoint(lo, hi, increase, 2*index, L, M); updatePoint(lo, hi, increase, 2*index+1, M+1, R);
    pull(index);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int N; cin >> N;
    F0R(i, 524288) {
        sum[i] = 0;
        lazy[i] = 0;
    }

    F0R(i, N) {
        int cur; cin >> cur;
        updatePoint(i, i, cur);
    }

    int Q; cin >> Q;
    F0R(i, Q) {
        int type; cin >> type;
        if (type == 1) {
            int P, X; cin >> P >> X;
            updatePoint(P-1, P-1, X);
        } else {
            int X; cin >> X;
            update(0, N, X);
        }
        /*cout << "After " << i << endl;
        F0R(i, N) {
            cout << query(i,i) << " ";
        }
        cout << endl;*/
    }

    F0R(i, N) {
        cout << query(i,i) << " ";
    }
    cout << endl;

    return 0;
}

// read the question correctly (ll vs int)
// template by bqi343
// license: https://github.com/bqi343/USACO/blob/master/LICENSE