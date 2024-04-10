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
	
	int N, M; cin >> N >> M;
	
	int K; cin >> K;
	set<int> oN[N], oM[M];
	F0R(i, K) {
		int A, B; cin >> A >> B; A--; B--;
		oN[A].insert(B);
		oM[B].insert(A);
	}
	
	int lX = 0, lY = 0, hX = N-1, hY = M-1;
	int X = 0, Y = 0;
	
	//start with increasing Y
	ll count = 1;
	int dir = 0;
	bool first = true;
	while (true) {
		if (dir == 0) {
			int oY = Y;
			Y = max(hY, Y);
			if (oN[X].upper_bound(oY) != oN[X].end()) {
				Y = min(Y, *oN[X].upper_bound(oY) - 1);
			}
			count += Y - oY;
			if (Y == oY && !first) break;
			lX = X+1;
			first = false;
		} else if (dir == 1) { //inc X
			int oX = X;
			X = max(X, hX);
			if (oM[Y].upper_bound(oX) != oM[Y].end()) {
				X = min(X, *oM[Y].upper_bound(oX) - 1);
			}
			count += X - oX;
			if (X == oX) break;
			hY = Y - 1;
		} else if (dir == 2) {
			int oY = Y;
			Y = min(Y, lY);
			if (sz(oN[X]) > 0 && oN[X].upper_bound(oY) != oN[X].begin()) {
				Y = max(Y, *(--oN[X].upper_bound(oY)) + 1);
			}
			count += oY - Y;
			if (Y == oY) break;
			hX = X - 1;
		} else {
			int oX = X;
			X = min(X, lX);
			if (sz(oM[Y]) > 0 && oM[Y].upper_bound(oX) != oM[Y].begin()) {
				X = max(X, *(--oM[Y].upper_bound(oX)) + 1);
			}
			count += oX - X;
			if (X == oX) break;
			lY = Y+1;
		}
		
		//cout << X << " " << Y << " " << count << " pos" << endl;
		//cout << lX << " " << lY << " " << hX << " " << hY << " bounds" << endl;
		
		
		dir++; dir %= 4;
	}
	ll area = N; area *= M; area -= K;
	cout << (count == area ? "Yes" : "No") << endl;
	

    return 0;
}

// read the question correctly (ll vs int)
// template by bqi343
// license: https://github.com/bqi343/USACO/blob/master/LICENSE