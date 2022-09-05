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
	
	int N, K; cin >> N >> K;
	
	bool odd[N];
	string S; cin >> S;
	set<pi> ranges;
	bool found = false;
	F0R(i, N) {
		odd[i] = false;
		if (S[i] != S[(i+1) % N] && S[i] != S[(i+N-1) % N]) { odd[i] = true; ranges.insert({i, i}); }
		if (!odd[i]) found = true;
		
	}
	
	if (!found) {
		if (K % 2 == 0) {
			cout << S << endl;
		} else {
			F0R(i, N) {
				cout << S[(i+1)%N];
			}
			cout << endl;
		}
		return 0;
	}
	
	if (sz(ranges) == 0) {
		cout << S << endl;
		return 0;
	}
	
	for (auto it = ++ranges.begin(); it != ranges.end(); it++) {
		auto lower = it; lower--;
		if (lower->s + 1 == it->f) {
			pi cur = {lower->f, it->s};
			ranges.erase(lower);
			ranges.erase(it);
			ranges.insert(cur);
			it = ranges.find(cur);
		}
	}
	
	if (ranges.rbegin()->s == N-1 && ranges.begin()->f == 0) {
		pi cur = {ranges.rbegin()->f, ranges.begin()->s + N};
		ranges.erase(--ranges.end());
		ranges.erase(ranges.begin());
		ranges.insert(cur);
	}
	
	F0R(i, min(N+10, K)) {
		for (auto it = ranges.begin(); it != ranges.end();) {
			
			int A = it->f;
			int B = it->s;
			
			S[A%N] = S[(A+N-1)%N];
			S[B%N] = S[(B+1)%N];
	
			pi cur = {(it->f + 1), (it->s - 1)};
			bool nxt = false;
			if (cur.f > cur.s) nxt = true;
			
			ranges.erase(it);
			if (!nxt) ranges.insert(cur);
			it = ranges.upper_bound(cur);
			
		}
		
	}
	//cout << "Test2" << endl;
	
	if (K % 2 == 1) {
		for (auto it = ranges.begin(); it != ranges.end(); it++) {
			//cout << it->f << " " << it->s << endl;
			FOR (i, it->f, it->s+1) {
				if (S[i%N] == 'W') {
					S[i%N] = 'B';
				} else S[i%N] = 'W';
			}
			
		}
		
	}
	
	cout << S << endl;
	

    return 0;
}

// read the question correctly (ll vs int)
// template by bqi343
// license: https://github.com/bqi343/USACO/blob/master/LICENSE