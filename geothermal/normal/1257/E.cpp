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

const ll identity = 1000000;
const ll SZ = 262144;

ll sum[2*SZ], lazy[2*SZ];

ll combine(ll A, ll B) {
    return min(A, B);
}

ll combineUpd(ll A, ll B) {
    return A+B;
}

void push(int index, ll L, ll R) {
    sum[index] = combineUpd(sum[index], lazy[index]);
    if (L != R) lazy[2*index] = combineUpd(lazy[2*index], lazy[index]), lazy[2*index+1] = combineUpd(lazy[2*index+1], lazy[index]);
    lazy[index] = 0;
}

void pull(int index) {
    sum[index] = combine(sum[2*index], sum[2*index+1]);
}

ll query(int lo, int hi, int index = 1, ll L = 0, ll R = SZ-1) {
    push(index, L, R);
    if (lo > R || L > hi) return 1000000;
    if (lo <= L && R <= hi) return sum[index];

    int M = (L+R) / 2;
    return combine(query(lo, hi, 2*index, L, M), query(lo, hi, 2*index+1, M+1, R));
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
	
	int X, Y, Z; cin >> X >> Y >> Z;
	int N = X+Y+Z;
	bool A[N], B[N], C[N];
	F0R(i, N) {
		A[i] = false; B[i] = false; C[i] = false;
	}
	F0R(i, X) {
		int K; cin >> K; K--;
		A[K] = true;
	}
	F0R(i, Y) {
		int K; cin >> K; K--;
		B[K] = true;
	}
	F0R(i, Z) {
		int K; cin >> K; K--;
		C[K] = true;
	}
	
	int lowerC[N+1]; //Number of cards less than this owned by C
	int higherB[N+1]; //Number of cards greater than or equal to this owned by B
	                  //cost of giving C the suffix starting with i is lowerC[i] + higherB[i]
	lowerC[0] = 0;
	FOR(i, 1, N+1) {
		lowerC[i] = lowerC[i-1];
		if (C[i-1]) lowerC[i]++;
	}
	higherB[N] = 0;
	F0Rd(i, N) {
		higherB[i] = higherB[i+1];
		if (B[i]) higherB[i]++;
	}
	
	F0R(i, 2*SZ) {
		sum[i] = 1000000, lazy[i] = 0;
	}
	
	F0R(i, N+1) {
		update(i, i, lowerC[i]+higherB[i]-1000000);
		//cout << i << " " << lowerC[i] << " " << higherB[i] << " test" << endl;
	}
	
	
	
	int aCost = X;
	int ans = 1000000;
	
	F0R(i, N+1) { //give a cards up to and excluding i
		
		if (i > 0 && A[i-1]) aCost--;
		if (i > 1 && (B[i-2] || C[i-2])) aCost++;
		if (i > 1 && C[i-2]) update(i, N+2, -1);
		ans = min(ans, aCost + (int) query(i, N+2));
		
		//cout << i << " " << aCost + (int) query(i, N+2) << " " << aCost << endl;
		
	}
	
	cout << ans << endl;
	
	
	return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343