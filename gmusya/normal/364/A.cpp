#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

int main() {
	int n;
	cin >> n;
	string s;
	cin >> s;
	int m = s.size();
	vector <int> a(m + 1);
	for (int i = 1; i <= m; i++)
		a[i] = s[i - 1] - '0';
	vector <int> pref(m + 1);
	for (int i = 1; i <= m; i++)
		pref[i] = pref[i - 1] + a[i];
	map <int, int> cnt;
	for (int L = 1; L <= m; L++)
		for (int R = L; R <= m; R++)
			cnt[pref[R] - pref[L - 1]]++;
	if (n == 0) {
		long long ans = 0;
		for (int L = 1; L <= m; L++)
			for (int R = L; R <= m; R++) {
				int val = pref[R] - pref[L - 1];
				if (val == 0) ans += m + m * (m - 1) / 2;
				else ans += cnt[0];
			}
		cout << ans;
		return 0;
	}
	long long ans = 0;
	for (int L = 1; L <= m; L++)
		for (int R = L; R <= m; R++) {
			int val = pref[R] - pref[L - 1];
			if (val == 0 || n % val) continue;
			ans += cnt[n / val];
		}
	cout << ans;
	return 0;
}