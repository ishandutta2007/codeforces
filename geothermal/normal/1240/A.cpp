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
const int MX = 200001; //check the limits, dummy
 
int N;
ll req;
ll X, A, Y, B;
vl P;

bool poss(int C) {
	ll lcm = A*B / __gcd(A, B);
	ll countBoth = C / lcm;
	ll countA = C / A - countBoth;
	ll countB = C / B - countBoth;
	ll val = 0;
	F0R(i, countBoth) {
		val += (X+Y) * P[i];
	}
	FOR(i, countBoth, countBoth+countA) {
		val += X*P[i];
	}
	FOR(i, countBoth+countA, countBoth+countA+countB) {
		val += Y*P[i];
	}
	//cout << val << " found" << endl;
	return val >= req;
}
 
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);    
	int Q; cin >> Q;
	F0R(testCase, Q) {
		cin >> N;
		P = vl(N);
		F0R(i, N) cin >> P[i];
		F0R(i, N) P[i] /= 100;
		sort(all(P));
		reverse(all(P));
		cin >> X >> A >> Y >> B >> req;
		if (X < Y) {
			swap(X, Y);
			swap(A, B);
		}
		
		if (!poss(N)) {
			cout << -1 << endl;
		} else {
			int lo = 1;
			int hi = N;
			F0R(i, 20) {
				int mid = (lo+hi)/2;
				if (poss(mid)) {
					hi = mid;
				} else {
					lo = mid+1;
				}
			}
			cout << lo << endl;
		}
	}
	
	return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343