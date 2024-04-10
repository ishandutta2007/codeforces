#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector <long long> a(n);
		for (int i = 0; i < n; i++)
			cin >> a[i];
		long long sum = 0;
		for (int i = 0; i < n; i += 2)
			sum += a[i];
		vector <long long> b, c;
		for (int i = 0; 2 * i + 1 < n; i++)
			b.push_back(a[2 * i + 1] - a[2 * i]);
		for (int i = 0; 2 * i + 2 < n; i++)
			c.push_back(a[2 * i + 1] - a[2 * i + 2]);
		long long ans = 0;
		long long cur_sum = 0;
		for (int i = 0; i < b.size(); i++) {
			cur_sum += b[i];
			cur_sum = max(0ll, cur_sum);
			ans = max(ans, cur_sum);			
		}
		cur_sum = 0;
		for (int i = 0; i < c.size(); i++) {
			cur_sum += c[i];
			cur_sum = max(0ll, cur_sum);
			ans = max(ans, cur_sum);
		}
		cout << sum + ans << '\n';
	}
	return 0;
	}