#include <bits/stdc++.h>

using namespace std;

int powers[42];
int need[42];
int log(long long n) {
	int p = 0;
	while (n != 1)
	{
		p++;
		n /= 2;
	}
	return p;
}
vector<int> ans;
int main() {
	//freopen(".in", "r", stdin);
	//freopen(".out", "w", stdout);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		long long x;
		cin >> x;
		if ((x & (x - 1)) == 0)
			powers[log(x)]++;
		else
			need[log(x)]++;
	}
	for (int j = 0; j <= 41; j++)
	{
		if (powers[j] < powers[j + 1]) {
			need[j] += powers[j + 1] - powers[j];
			powers[j + 1] = powers[j];
		}
	}
	for (int i = powers[0]; i > 0; i--) {
		for (int j = 0; j <= 41; j++)
		{
			need[max(j - 1, 0)] += max(0, powers[j] - i);
			powers[j] = min(powers[j], i);
		}
		int curpow = 0;
		int sumneed = 0;
		for (int j = 41; j >= 0; j--) {
			curpow = powers[j];
			sumneed += need[j];
			if (sumneed > curpow)
				break;
		}
		if (sumneed <= curpow) {
			ans.push_back(i);
		}
	}
	reverse(ans.begin(), ans.end());
	if (ans.size() == 0)
		cout << -1 << endl;
	for (int i = 0; i < ans.size(); i++)
		cout << ans[i] << " ";
	return 0;
}