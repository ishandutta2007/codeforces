#include<bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int N, K; cin >> N >> K;
	map<pair<int, int>, vector<double>> dists;
	for (int i = 0; i < N; i++) {
		int x, y; cin >> x >> y;
		double d = hypot(double(x), double(y));
		int g = gcd(abs(x), abs(y));
		if (!g) {
			g = 1;
		}
		dists[{x/g, y/g}].push_back(d);
	}
	vector<double> vals; vals.reserve(N);
	for (auto& it : dists) {
		sort(it.second.begin(), it.second.end());
		for (int z = 0; z <= (K-1)/2 && !it.second.empty(); z++) {
			vals.push_back(it.second.back() * (K-1 - 2 * z));
			it.second.pop_back();
		}
		if (!it.second.empty()) {
			int z = (K-1) / 2 + 1;
			int v0 = K-1 - 2 * z;
			double cur_val = 0;
			for (int i = 0; i < int(it.second.size()); i++) {
				vals.push_back(v0 * it.second[i] + cur_val);
				cur_val -= 2 * it.second[i];
			}
		}
	}
	nth_element(vals.begin(), vals.begin()+K, vals.end(), std::greater<>());
	double ans = accumulate(vals.begin(), vals.begin()+K, double(0));
	cout << fixed << setprecision(20) << ans << '\n';

	return 0;
}