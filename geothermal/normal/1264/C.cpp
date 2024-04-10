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
 
const int MOD = 998244353;
const ll INF = 1e18;
const int MX = 200011; //check the limits, dummy


ll modExp(ll base, ll power) {
    if (power == 0) {
        return 1;
    } else {
        ll cur = modExp(base, power / 2); cur = cur * cur; cur = cur % MOD;
        if (power % 2 == 1) cur = cur * base;
        cur = cur % MOD;
        return cur;
    }
}

ll inv(ll base) {
    int g = MOD, r = base, x = 0, y = 1;
    while (r != 0) {
        int q = g / r;
        g %= r; swap(g, r);
        x -= q * y; swap(x, y);
    }
    return x < 0 ? x+MOD : x;
}

ll mul(ll A, ll B) {
	return (A*B)%MOD;
}

ll add(ll A, ll B) {
	return (A+B)%MOD;
}

ll dvd(ll A, ll B) {
    return mul(A, inv(B));
}

ll sub(ll A, ll B) {
    return (A-B+MOD)%MOD;
}
const int K = 20;
ll st[MX][K+1];
ll queryVals(int L, int R) {
    ll ans = 1;
    for(int j = 20; j >= 0; j--) {
        if ((1 << j) <= R-L+1) {
            ans *= st[L][j];
            ans %= MOD;
            L += 1 << j;
        }
    }
    return ans;
}
 
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);    
	
    ll oneInv = inv(100);

    int N, Q; cin >> N >> Q;
    ll data[N]; F0R(i, N) {
        cin >> data[i];
        data[i] *= oneInv;
        data[i] %= MOD;
    }
    F0R(i, N) st[i][0] = data[i];
    for (int j = 1; j <= K; j++)
        for (int i = 0; i + (1 << j) <= N; i++)
            st[i][j] = (st[i][j-1] * st[i + (1 << (j - 1))][j - 1]) % MOD;

    vl partAns(N+1), eDist(N+1), curDist(N+1);

    set<int> curCheck;
    F0R(i, N+1) partAns[i] = 0;
    eDist[N] = 0;
    F0Rd(i, N) {
        eDist[i] = data[i] * (1 + eDist[i+1]);
        eDist[i] %= MOD;
    }
    F0R(i, N+1) curDist[i] = eDist[i];

    partAns[0] = mul(eDist[0] + 1 + MOD - queryVals(0, N-1), inv(queryVals(0, N-1)));
    ll ans = partAns[0]; 
    curCheck.insert(0); curCheck.insert(N);
    F0R(query, Q) {
        int P; cin >> P;
        P--;
        if (!curCheck.count(P)) {
            curCheck.insert(P);
            int nextCheck = *(curCheck.upper_bound(P));
            int lastCheck = *(--(curCheck.find(P)));
            //compute value of new check
            curDist[P] = eDist[P] - mul(eDist[nextCheck], queryVals(P, nextCheck-1));
            curDist[P] += MOD; curDist[P] %= MOD;
            partAns[P] = mul(curDist[P] + 1 + MOD - queryVals(P, nextCheck-1), inv(queryVals(P, nextCheck-1)));
            ans += partAns[P]; ans %= MOD;
            ans += MOD - partAns[lastCheck]; ans %= MOD;
            curDist[lastCheck] = eDist[lastCheck] - mul(eDist[P], queryVals(lastCheck, P-1));
            curDist[lastCheck] += MOD; curDist[lastCheck] %= MOD;
            partAns[lastCheck] = mul(curDist[lastCheck] + 1 + MOD - queryVals(lastCheck, P-1), inv(queryVals(lastCheck, P-1)));
            ans += partAns[lastCheck]; ans %= MOD;
        } else {
            int nextCheck = *(curCheck.upper_bound(P));
            int lastCheck = *(--(curCheck.find(P)));
            ans += MOD - partAns[P]; ans %= MOD;
            curCheck.erase(P);
            ans += MOD - partAns[lastCheck]; ans %= MOD;
            curDist[lastCheck] = eDist[lastCheck] - mul(eDist[nextCheck], queryVals(lastCheck, nextCheck-1)) + MOD;
            curDist[lastCheck] %= MOD;
            partAns[lastCheck] = mul(curDist[lastCheck] + 1 + MOD - queryVals(lastCheck, nextCheck-1), inv(queryVals(lastCheck, nextCheck-1)));
            ans += partAns[lastCheck]; ans %= MOD;
        }
        cout << ans << endl;
    }

	
	return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343