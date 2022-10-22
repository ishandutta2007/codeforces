#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;
using ull = unsigned long long;
#define all(x) (x).begin(),(x).end()

#define int ll

int n, k, b, c;
vector<int> a;
const int INF = 1e18;
struct solver{
	multiset<int> have;
	int sum;
	int mod;
	int last;	
	void relax() {
		while ((int)have.size() > k) {
			sum -= *(--have.end()) + mod;
			have.erase(--have.end());
		}
	}
	solver() {
		have = {};
		sum = 0;
		mod = 0;
		last = INF;
	}
	void add(int cost) {
		have.insert(cost - mod);
		sum += cost;
		relax();
	}
	void upd(int newPos) {
		if (last == INF) {
			assert(have.empty() && sum == 0 && mod == 0);
			last = newPos;
			return;
		} 
		assert((newPos - last) % 5 == 0);
		sum += (newPos - last) / 5 * b * (ll)have.size();
		mod += (newPos - last) / 5 * b;
		last = newPos;
		relax();
	}
};



int getNxt(int val, int mod) {
	while (val % 5 != mod) val++;
	return val;
}

solver fans[5];
int ans;

signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cout.precision(20);
	cin >> n >> k >> b >> c;
	b = min(b, c * 5);
	a.resize(n);
	for (auto &i : a) {
		cin >> i;
		i += 1e9 + 228;
	}
	sort(all(a));
	ans = 1e18;
	//cout << n << " " << k << " " << b << " " << c << endl;
	//cout << "a = " << endl;
	//for (auto i : a) cout << i << " ";
	//cout << endl;
	for (auto i : a) {
		for (int mod = 0; mod < 5; mod++) {
			int myVal = getNxt(i, mod);
			fans[mod].upd(myVal);
			fans[mod].add((myVal - i) * c);
			if (fans[mod].have.size() == k) {
				ans = min(ans, fans[mod].sum);
			}
		}
	}
	cout << ans << endl;
	return 0;
}