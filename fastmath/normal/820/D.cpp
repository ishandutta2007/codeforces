#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <random>


using namespace std;


#define int long long
mt19937 rnd(rand());
int inf = 1e9;
int mod = 1e9 + 7;
int big_inf = 1e18;


signed main() {
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	vector <int> a(n);

	set <pair <int, int> > s1;
	int s2_size = 0;
	vector <int> set_val(n);
	int my_sum = 0;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		int r = i + 1 - a[i];
		set_val[i] = r;
		if (r < 0)
			s1.insert({ r, i });
		else
			s2_size++;

		my_sum += abs(i + 1 - a[i]);
	}

	int j = n - 1;
	int ans = my_sum;
	int ans_num = 0;
	for (int i = 0; i < n - 1; ++i) {
		my_sum -= abs(n - a[j]);
		my_sum += abs(1 - a[j]);

		my_sum -= s1.size();
		my_sum += s2_size - 1;

		if (my_sum < ans) {
			ans = my_sum;
			ans_num = i + 1;
		}

		while (s1.size() && s1.rbegin()->first + i + 1 == 0) {
			s2_size++;
			s1.erase(*s1.rbegin());
		}

		if (a[j] > 1) {
			s2_size--;
			s1.insert({ 1 - a[j] - i - 1, j });
		}

		--j;
	}

	cout << ans << " " << ans_num;
	return 0;
}