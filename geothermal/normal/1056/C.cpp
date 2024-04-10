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

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);	
	
	int N; cin >> N; N *= 2; int M; cin >> M;
	
	int powers[N]; F0R(i, N) cin >> powers[i];
	
	set<pi> heroes; F0R(i, N) heroes.insert(mp(powers[i], i));
	
	int match[N]; F0R(i, N) match[i] = -1;
	F0R(i, M) {
		int A, B; cin >> A >> B;
		A--; B--;
		match[A] = B;
		match[B] = A;
	}
	
	int T; cin >> T;
	
	int last = -1;
	
	if (T == 2) {
		int X; cin >> X; X--;
		if (X == -1) return 0;
		heroes.erase(mp(powers[X], X));
		last = X;
	}
	
	
	
	F0R(i, N/2) {
		int C = -1;
		if (last >= 0 && match[last] != -1 && heroes.count(mp(powers[match[last]], match[last]))) {
			C = match[last];
			
		} else {
			F0R(i, N) {
				if (heroes.count(mp(powers[i], i)) && match[i] != -1 && heroes.count(mp(powers[match[i]], match[i]))) {
					C = i;
					if (powers[match[i]] > powers[i]) C = match[i];
				}
			}
			auto it = heroes.rbegin();
			if (C == -1) C = it->s;
		}
		cout << C+1 << endl;
		heroes.erase(mp(powers[C], C));
		if (i == N/2-1) return 0;
		int X; cin >> X; X--;
		if (X == -1) return 0;
		heroes.erase(mp(powers[X], X));
		last = X;
	}
	
	

    return 0;
}

// read the question correctly (ll vs int)
// template by bqi343
// license: https://github.com/bqi343/USACO/blob/master/LICENSE