#include <iostream>
#include <vector>
#include <string>

#define ll long long

using namespace std;

int main() {
	ll n;
	cin >> n;
	string s;
	cin >> s;
	int cnt = 0;
	vector <ll> a;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '1') {
			a.push_back(cnt);
			cnt = 0;
		}
		else
			cnt++;
	}
	a.push_back(cnt);
	ll ans = 0;
	if (n >= a.size()) {
		cout << 0;
		return 0;
	}
	if (n == 0)
		for (int i = 0; i < a.size(); i++)
			ans += (a[i] + 1) * a[i] / 2;
	else
		for (int i = 0; i < a.size() - n; i++)
			ans += (a[i] + 1) * (a[i + n] + 1);
	cout << ans;
	return 0;
}