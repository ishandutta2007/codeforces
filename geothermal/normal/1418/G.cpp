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
 

const ll SZ = 131072*4;

pl sum[2*SZ]; ll lazy[2*SZ];

pl combine(pl a, pl b) {
    if (a.f == b.f) {
        return {a.f, a.s+b.s};
    } else if (a.f > b.f) {
        return a;
    } else {
        return b;
    }
}

pl combineUpd(pl A, ll B) {
    return {A.f+B, A.s};
}

void push(int index, ll L, ll R) {
    sum[index] = combineUpd(sum[index], lazy[index]);
    if (L != R) lazy[2*index] += lazy[index], lazy[2*index+1] += lazy[index];
    lazy[index] = 0;
}

void pull(int index) {
    sum[index] = combine(sum[2*index], sum[2*index+1]);
}

pl query(int lo, int hi, int index = 1, ll L = 0, ll R = SZ-1) {
    push(index, L, R);
    if (lo > R || L > hi) return {0, 0};
    if (lo <= L && R <= hi) return sum[index];

    int M = (L+R) / 2;
    return combine(query(lo, hi, 2*index, L, M), query(lo, hi, 2*index+1, M+1, R));
}

void update(int lo, int hi, ll increase, int index = 1, ll L = 0, ll R = SZ-1) {
    if (lo > hi) return;
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
    F0R(i, SZ) sum[i+SZ] = {0, 1};
    F0Rd(i, SZ) pull(i);
    int A[N]; F0R(i, N) cin >> A[i];
    F0R(i, N) A[i]--;
    vi pos[N]; F0R(i, N) pos[A[i]].pb(i);
    ll ans = 0;
    F0R(i, N) F0R(j, 4) pos[i].pb(N);
    F0R(i, N) {
        update(0, pos[i][0] - 1, 1);
        update(pos[i][2], pos[i][3] - 1, 1);
    }
    F0R(i, N) {
        pl res = query(i, N-1);
        if (res.f == N) {
            ans += res.s;
        }
/*        cout << "Start " << i << nl;
        FOR(j, i, N+1) cout << query(j, j).f << " ";
        cout << nl;*/
        int p = lb(all(pos[A[i]]), i) - pos[A[i]].begin();
//        cout << "position " <<p << nl;
        if (p == 0) {
            update(0, pos[A[i]][p] - 1, -1);
        } else {
            update(pos[A[i]][p-1], pos[A[i]][p]-1, -1);
        }
        update(pos[A[i]][p+2], pos[A[i]][p+3]-1, -1);

        update(pos[A[i]][p], pos[A[i]][p+1]-1, 1);
        update(pos[A[i]][p+3], pos[A[i]][p+4]-1, 1);
    }
    cout << ans << nl;
	return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343