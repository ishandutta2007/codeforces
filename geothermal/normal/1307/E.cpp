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
const int MX = 5001; //check the limits, dummy
int N, M;
int S[MX];
vector<vi> datas(MX);
int L[MX], R[MX];
ll lC, rC;
pl compute(int bp) {
    F0R(i, N) L[i] = 0, R[i] = 0;
    F0R(i, N) {
        if (i <= bp) {
            L[S[i]]++;
        } else {
            R[S[i]]++;
        }
    }

    if (bp == -1) {
        goto ok;
    }
    F0R(i, sz(datas[S[bp]])) {
        if (datas[S[bp]][i] == L[S[bp]]) goto ok;
    }
    return {0, 0};
    ok:;
    ll ans = 1;
    int cnt = 1; if (bp == -1) cnt--;

    F0R(i, N) {
        lC = 0, rC = 0;
        F0R(j, sz(datas[i])) {
            int cur = datas[i][j];
            if (cur <= L[i]) lC++;
            if (cur <= R[i]) rC++;
        }
        if (bp == -1 || i != S[bp]) {
            if (max(lC, rC) == 0) continue;
            if (lC * rC - min(lC, rC) <= 0) {
                ans *= lC + rC; ans %= MOD;
                cnt++;
            } else {
                ans *= (lC * rC - min(lC, rC)); ans %= MOD;
                cnt+=2;
            }
        } else {
            if (R[i] >= L[i]) rC--;
            if (rC > 0) ans *= rC, cnt++;
            ans %= MOD;

        }
    }

    //cout << cnt << " " << ans << " " << bp << endl;
    return {(ll)cnt, ans};
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);    
	
    cin >> N >> M;
    F0R(i, N) cin >> S[i];
    F0R(i, N) S[i]--;
    F0R(i, M) {
        int A, B; cin >> A >> B;
        A--; 
        datas[A].pb(B);
    }
    F0R(i, N) sort(all(datas[i]));

    ll best = 0; ll cnt = 0;

    FOR(i, -1, N) {
        pl cur = compute(i);
        if (cur.f > best) {
            best = cur.f; cnt = 0;
        }
        if (best == cur.f) {
            cnt += cur.s; cnt %= MOD;
        }
    }

    cout << best << " " << cnt << endl;

	return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343