#include <bits/stdc++.h>

using namespace std;

int main() {
	//freopen("input.txt", "rt", stdin);
	//freopen("output.txt", "wt", stdout);
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int hh, mm;
	cin >> hh >> mm;
	int h, d, c, n;
	cin >> h >> d >> c >> n;
	//v 20:00
	double ans = 1e9;
	int start_minutes = hh * 60 + mm;
	int minutes_rest = 20 * 60;
	//go_to_rest
	int final_health = h + d * max(0, (minutes_rest - start_minutes));
	int have_to_buy = (final_health + n - 1) / n;
	ans = min(ans, 0.8 * have_to_buy * c);
	//at time
	have_to_buy = (h + n - 1) / n;
	ans = min(ans, 1.0 * have_to_buy * c);
	cout << setprecision(15) << fixed << ans << '\n';
	return 0;
}