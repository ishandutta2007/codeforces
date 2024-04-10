//#pragma GCC optimize("O3")
//#pragma GCC target("sse4,avx2,abm,fma,tune=native")
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
const ll MOD = 998244353;
const ld EPS = 1e-9;
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

ll dist2(const pair<int,int>& v) {
	return (ll)v.first*v.first + (ll)v.second*v.second;
}

// TODO
// double-check correctness
// read limits carefully
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cout << fixed << setprecision(10);

	int n, k;
	cin >> n >> k;

	map<pair<int,int>,vector<pair<int,int>>> lines;
	for(int i=0; i<n; i++) {
		int x, y;
		cin >> x >> y;
		if(x == 0 && y == 0) continue;
		int g = abs(__gcd(x, y));
		pair<int,int> slope(x/g, y/g);
		lines[slope].emplace_back(x, y);
	}

	vector<ld> val;
	pair<int,int> large(INF, INF);
	map<pair<int,int>,ld> sum;
	ld total = 0;
	for(auto& [slope, line] : lines) {
		sort(line.begin(), line.end(), [](const auto& a, const auto& b) {
			return dist2(a) > dist2(b);
		});
		if(n - (int)line.size() <= k/2) {
			large = slope;
		}
		for(int i=0; i<line.size(); i++) {
			ld d = sqrt((ld)dist2(line[i]));
			ll weight = (ll)(i+1) * (k-(i+1)) - (ll)i * (k-i);
			ld cur = weight * d;
			val.push_back(cur);
			sum[slope] += cur;
			total += cur;
		}
	}

	if(large.first == INF) {
		sort(val.begin(), val.end(), greater<ld>());
		ld ans = accumulate(val.begin(), val.begin()+k, (ld)0);
		cout << ans << nl;
		return 0;
	}

	const auto& line = lines[large];
	ld ans = total - sum[large];
	int other = n - (int)line.size();

	ld big = 0;
	for(int i=0; i<other; i++) {
		ld d = sqrt((ld)dist2(line[i]));
		ans += other*d + (big - i*d);
		big += d;
	}

	ld small = 0;
	for(int i=2*other; i<k; i++) {
		int j = i%2 == 0 ? i/2 : (int)line.size() - (i/2-other) - 1;
		ld d = sqrt((ld)dist2(line[j]));
		ans += ((i/2)*d - small) + (big - ((i+1)/2)*d);
		(i%2 == 0 ? big : small) += d;
	}

	cout << ans << nl;

	return 0;
}