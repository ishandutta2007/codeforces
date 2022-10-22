//#pragma GCC optimize("O3")
//#pragma GCC target("sse4,avx2,abm,fma")
#include <bits/stdc++.h>
using namespace std;
#define _USE_MATH_DEFINES

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

typedef long long ll;
typedef long double ld;
typedef complex<ld> pt;

const char nl = '\n';
const ll INF = 0x3f3f3f3f;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 1e9+7;
const ld EPS = 1e-9;
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());



int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cout << fixed << setprecision(10);

	int n, m;
	cin >> n >> m;
	int a[n+1];
	for(int i=1; i<=n; i++) {
		cin >> a[i];
	}

	vector<tuple<int,int,int,int>> ranges(n+1);
	vector<tuple<int,int,int>> threes(n+1);

	vector<int> top, bot;
	vector<bool> intop(n+1), inbot(n+1);
	set<int> middle;

	for(int i=1; i<=n; i++) {
		// remove from stacks
		while(!top.empty() && a[i] > a[top.back()]) {
			int j = top.back();
			intop[j] = false;
			if(!inbot[j]) {
				middle.insert(j);
			}
			top.pop_back();
		}
		while(!bot.empty() && a[i] < a[bot.back()]) {
			int j = bot.back();
			inbot[j] = false;
			if(!intop[j]) {
				middle.insert(j);
			}
			bot.pop_back();
		}

		top.push_back(i);
		bot.push_back(i);
		intop[i] = inbot[i] = true;
		if(middle.empty()) continue;

		auto up = lower_bound(top.begin(), top.end(), a[i],
				[&] (int j, int v) { return a[j] > v; });
		auto down = lower_bound(bot.begin(), bot.end(), a[i],
				[&] (int j, int v) { return a[j] < v; });
		if(up == top.begin() || down == bot.begin()) continue;
		--up;
		--down;
		auto mid = middle.lower_bound(min(*up, *down));
		if(mid == middle.begin()) continue;
		--mid;
		up = lower_bound(top.begin(), top.end(), *mid);
		down = lower_bound(bot.begin(), bot.end(), *mid);
		ranges[i] = make_tuple(*mid, min(*up, *down), max(*up, *down), i);
	}

	vector<tuple<int,int,int>> reduced; // value, l, r
	for(int i=1, first=1; i<=n; i++) {
		if(i == n || a[i] != a[i+1]) {
			reduced.push_back(make_tuple(a[i], first, i));
			first = i+1;
		}
	}
	for(int i=1; i+1<reduced.size(); i++) {
		const auto& [pre, _1, l] = reduced[i-1];
		const auto& [nxt, r, _2] = reduced[i+1];
		const auto& [cur, j, _3] = reduced[i];
		if(cur < min(pre, nxt) || cur > max(pre, nxt)) {
			threes[r] = make_tuple(l, j, r);
		}
	}

	for(int i=1; i<=n; i++) {
		ranges[i] = max(ranges[i], ranges[i-1]);
		threes[i] = max(threes[i], threes[i-1]);
	}

	for(int i=0; i<m; i++) {
		int l, r;
		cin >> l >> r;
		if(get<0>(ranges[r]) >= l) {
			const auto& [A, b, c, d] = ranges[r];
			cout << 4 << nl;
			cout << A << " " << b << " " << c << " " << d << nl;
		} else if(get<0>(threes[r]) >= l) {
			const auto& [A, b, c] = threes[r];
			cout << 3 << nl;
			cout << A << " " << b << " " << c << nl;
		} else {
			cout << 0 << nl;
			cout << nl;
		}
	}

	return 0;
}