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
    
    int N; cin >> N;
    int data[N];
    int hiVal = -1, loVal = 1000000001;
    F0R(i, N) {
		cin >> data[i];
		loVal = min(loVal, data[i]);
		hiVal = max(hiVal, data[i]);
		
	}
	
	if (loVal * 2 >= hiVal) {
		F0R(i, N) cout << -1 << " ";
		cout << endl;
		return 0;
	}
	
	int prevVals[2*N];
	int nxt[3*N];
	
	set<pi> pos;
	
	int minSF = 1000000001;
	F0R(i, N) {
		if (data[i] < minSF) {
			pos.insert(mp(data[i], i+N));
			minSF = data[i];
		}
	}
	
	F0Rd(i, N) {
		if (pos.begin()->f * 2 >= data[i]) {
			nxt[i] = 4*N;
		} else {
			/*int lo = i+1;
			int hi = 2*N-1;
			F0R(j, 20) {
				int mid = (lo+hi)/2;
				if (prevVals[mid] * 2 >= data[i]) {
					lo = mid+1;
				} else {
					hi = mid;
				}
			}
			
			if (prevVals[min(lo, hi)] * 2 < data[i]) {
				nxt[i] = min(lo, hi);
			} else {
				nxt[i] = max(lo, hi);
			}*/
			int needVal = data[i] / 2;
			if (data[i] % 2 == 0) needVal--; //needs to be at most needVal
			auto it = pos.upper_bound(mp(needVal, 2*N+1));
			it--;
			nxt[i] = it->s;
		}
		
		pos.insert(mp(data[i], i));
		pos.erase(pos.upper_bound(mp(data[i], i)), pos.end());
		
		nxt[i+N] = nxt[i] + N;
		nxt[i+2*N] = nxt[i] + 2*N;
	}
	
	F0Rd(i, 3*N-1) {
		//cout << i << " " << nxt[i] << endl;
		nxt[i] = min(nxt[i], nxt[i+1]);
	}
	

	
	F0R(i, N) {
		cout << nxt[i] - i << " ";
	}
	
	cout << endl;
	

    return 0;
}

// read the question correctly (ll vs int)
// template by bqi343
// license: https://github.com/bqi343/USACO/blob/master/LICENSE