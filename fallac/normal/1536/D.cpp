/*
				---~;;;;:~--,
			  :;;;;;;;;;;;;;;;:
		   ,:;;;;;;;;;;;;;;;;;;;-
		  ~;;;;;;;;;;;;;;;;;;;;;;:.
		 ;;;;;;;;;;;;;;;;;;;;;;;;;;.
		:;;;;;;;;;;;;;;;;;;;;;;;;;;;.
	   ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;~
	 .:;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;,
	 ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
	,;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;-
   ,;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;~
   -;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;.
   ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;.
  ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;.
  ;;;;;;;;;;;;;;;:;:*;!;;;;;;;;:;;;;;;;~
 -;;;;;;;;;;;;;;;:==$$$;;;;;;;;=,;;;;;;~
 ~;;;;;;;;;;;;;;;;$$$$$;;;;;;;-$$=!;;;;~
 ~;;;;;;;;;;;;;;;!$$$$!;;;;;;;$$$$$-;;;,
.;;;;;;;;;;;;;;;;:*$$=!;;;;;;;;$$$$.;;;.
.;;;;;;;;;;;;;;;;;:**:;;;;;;;;~=$$*;;;;.
.;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;~~~;;;;:
,;;;;;;;;;;;;;;;;;;;;;;~:;;~;;;;;;;;;;~
-;;;;;;;;;;;;;;;;;;;;~===$$==:;;;;;;;;~
-;;;;;;;;;;;;;;;;;;;=$$$$$$$$$$:;;;;;;~
-;;;;;;;;;;;;;;;;;=$$$;!!!!:;$$$=:;;;;~
-;;;;;;;;;;;;;;;~$$$:;;;;;;;;~$$$=;;;;;.
.;;;;;;;;;;;;;;*$$;;;;;;;;;;;;;!==;;;;;.
.;;;;;;;;;;;;;!$$*;;;;;;;;;;;;;;,-;;;;;.
 :;;;;;;;;;;;;;!=;;;;;;;;;;;;;;;;;;;;;~
  ;;;;;;;;;;;;;:;;;;;;;;;;;;;;;;;;;;;;
   -;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;:,
	.,:;;;;;;;;;;;;;;;;;;;;;;;;;;:,
		~:;;;;;;;;;;;;;;;;;;;;:~
		   ,---~~;;;;;;~~---,

*/

#include <bits/stdc++.h>

#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,fma")

using namespace std;
typedef long long ll;

#define omode T=1
#define tmode cin>>T
#define cmode(c) T=c
#define bb ' '
#define ln '\n'

#define MAX 101010
#define MOD 100000009
#define INF 10000000000000

#define vv vector
#define pq priority_queue
#define pp pair<ll, ll>
#define ff first
#define ss second
#define yes "YES"
#define no "NO"

//var

//

struct segtree {
	vector<ll> tree, l, r;
	ll N = 0;
	ll leaf = 0;
	void init(ll loc = 1) {
		if (loc >= leaf) {
			l[loc] = r[loc] = loc - leaf + 1;
			return;
		}
		init(loc * 2);
		init(loc * 2 + 1);
		l[loc] = l[loc * 2];
		r[loc] = r[loc * 2 + 1];
		tree[loc] = tree[loc * 2] + tree[loc * 2 + 1];
	}
	void update(ll loc, ll x) {
		loc += leaf - 1;
		tree[loc] = x;
		while (loc != 1) loc /= 2, tree[loc] = tree[loc * 2] + tree[loc * 2 + 1];
	}
	ll query(ll low, ll high, ll loc = 1) {
		if (l[loc] == low && r[loc] == high) return tree[loc];
		if (high <= r[loc * 2]) return query(low, high, loc * 2);
		if (low >= l[loc * 2 + 1]) return query(low, high, loc * 2 + 1);
		return query(low, r[loc * 2], loc * 2) + query(l[loc * 2 + 1], high, loc * 2 + 1);
	}
	segtree(ll n) {
		N = n;
		leaf = 1LL << (ll)ceil(log2(N));
		tree.resize(leaf * 2 + 1);
		l.resize(leaf * 2 + 1);
		r.resize(leaf * 2 + 1);
		init();
	}
	segtree(vector<ll>& arr) {
		N = arr.size();
		leaf = 1LL << (ll)ceil(log2(N));
		tree.resize(leaf * 2 + 1);
		l.resize(leaf * 2 + 1);
		r.resize(leaf * 2 + 1);
		for (ll i = 0; i < N; i++) tree[i + leaf] = arr[i];
		init();
	}
};

void solve() {
	ll N;
	cin >> N;
	vector<ll> v, v1;
	ll i;
	v.resize(N + 1);
	for (i = 1; i <= N; i++) cin >> v[i], v1.push_back(v[i]);
	sort(v1.begin(), v1.end());
	v1.erase(unique(v1.begin(), v1.end()), v1.end());
	for (i = 1; i <= N; i++) v[i] = lower_bound(v1.begin(), v1.end(), v[i]) - v1.begin() + 1;
	segtree seg = segtree(N);
	seg.update(v[1], 1);
	for (i = 2; i <= N; i++) {
		seg.update(v[i], 1);
		ll ind1 = seg.query(1, v[i - 1]);
		ll ind2 = seg.query(1, v[i]);
		if (abs(ind2 - ind1) > 1) {
			cout << no << ln;
			return;
		}
	}
	cout << yes << ln;
}

void init() {

}

signed main() {
	ios::sync_with_stdio(false), cin.tie(0);
	ll T;
	tmode;
	while (T--) {
		init();
		solve();
	}
}