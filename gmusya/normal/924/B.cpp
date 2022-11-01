#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>

#define ll long long
#define dl double long
#define eps 1e-12
#define fsp fixed << setprecision(13)

using namespace std;

int main() {
	ll n, u;
	cin >> n >> u;
	vector <ll> a(n);
	for (ll i = 0; i < n; i++)
		cin >> a[i];
	dl ans = 0;
	ll uki = 0, ukk = 2;
	while (ukk < n && uki < n) {
		while (ukk < n && (uki + 2 >= ukk || a[ukk] - a[uki] <= u))
			ukk++;
		ukk--;
		if (ukk - uki > 1 && a[ukk] - a[uki] <= u + eps)
			ans = max(ans, ((dl) a[ukk] - (dl) a[uki + 1]) / ((dl)a[ukk] - (dl)a[uki]));
		uki++;
	}
	if (ans < eps) {
		cout << "-1";
		return 0;
	}
	cout << fsp << ans;
	return 0;
}