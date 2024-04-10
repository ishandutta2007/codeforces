#include <bits/stdc++.h>
//#define DEBUG
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define rrep(i, a, b) for(int i = (a-1); i >= (b); --i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

ll get_rand() {
	return ll(((rand()%10000)*200000+(rand()%100000))-1e9);
}

void solve() {
	int n, m;
#ifdef DEBUG
	n = (rand()%200000)+1;
	m = (rand()%200000)+1;
#else
	cin >> n >> m;
#endif
	vector<ll> a(n);
	rep(i,0,n)
#ifdef DEBUG
		a[i] = get_rand();
#else
		cin >> a[i];
#endif
	vector<pair<ll, ll>> seg(m);
	rep(i,0,m) {
#ifdef DEBUG
		seg[i].first = 1;
		while (seg[i].first > seg[i].second) {
			seg[i].first = get_rand();
			seg[i].second = get_rand();
		}
#else
		cin >> seg[i].first >> seg[i].second;
#endif
	}
	sort(all(a));
	vector<pair<ll, ll>> new_segs;
	set<pair<ll, ll>> already_added;
	for (auto s : seg) {
		if (already_added.count(s))
			continue;
		already_added.insert(s);
		auto it = upper_bound(all(a), s.first);
		bool covered = false;
		if (it != a.begin()) {
			--it;
			if (*it >= s.second)
				covered = true;
		}
		if (!covered)
			new_segs.push_back(s);
	}
	seg = new_segs;
	m = sz(seg);
	sort(all(seg));
	vector<ll> cheap_cost;
	vector<ll> expensive_cost;
	vector<ll> dp(m+1, 1e10);
	dp[0] = 0;
	rep(i,0,n) {
		set<pair<ll, ll>> in_between_segs;
		auto it = lower_bound(all(seg), make_pair(a[i], 0LL));
		if (it != seg.begin()) {
			--it;
			while (!i || it->first > a[i-1]) {
				in_between_segs.insert(make_pair(it->second, it->first));
				if (it == seg.begin())
					break;
				--it;
			}
		}
		cheap_cost.push_back(1e10);
		expensive_cost.push_back(1e10);
		if (sz(in_between_segs) == 0) {
			if (i) {
				cheap_cost[i] = cheap_cost[i-1];
				expensive_cost[i] = expensive_cost[i-1];
			} else {
				cheap_cost[i] = 0;
				expensive_cost[i] = 0;
			}
		}
		if (it != seg.end() && i && it->first <= a[i-1]) {
			++it;
		}
		while (it != seg.end()) {
			ll dis = 0;
			if (sz(in_between_segs))
				dis = max(0LL, a[i]-(in_between_segs.begin()->first));
			//assert(dis >= 0);
			ll prev_val = dp[it-seg.begin()];
			ll new_cheap_cost = prev_val + dis;
			ll new_expensive_cost = prev_val + 2*dis;
			cheap_cost[i] = min(cheap_cost[i], new_cheap_cost);
			expensive_cost[i] = min(expensive_cost[i], new_expensive_cost);
			in_between_segs.erase(make_pair(it->second, it->first));
			if (it->first >= a[i])
				break;
			++it;
		}
		//assert(sz(in_between_segs) == 0);
		dp[it-seg.begin()] = min(dp[it-seg.begin()], cheap_cost[i]);
		while (it != seg.end() && (i+1 == n || it->first <= a[i+1])) {
			ll dis = it->first - a[i];
			//assert(dis >= 0);
			dp[it-seg.begin()+1] = min(dp[it-seg.begin()+1], cheap_cost[i] + dis * 2);
			dp[it-seg.begin()+1] = min(dp[it-seg.begin()+1], expensive_cost[i] + dis);
			it++;
		}
	}
	cout << dp[m] << endl;
}

int main() {
#ifdef DEBUG
	while (true)
		solve();
#endif
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	int T;
	cin >> T;
	while (T--)
		solve();
}