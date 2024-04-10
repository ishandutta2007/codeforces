#include <iostream>
#include <vector>

#define ll long long

using namespace std;

int main() {
	ll n;
	cin >> n;
	if (n % 4 == 1 || n % 4 == 2)
		cout << 1 << endl;
	else
		cout << 0 << endl;
	ll sum = (n + 1) * n / 4;
	ll cnt = n;
	vector <ll> ans;
	while (sum > 0) {
		if (cnt <= sum) {
			sum -= cnt;
			ans.push_back(cnt);
		}
		cnt--;
	}
	cout << ans.size() << " ";
	for (auto now : ans)
		cout << now << " ";
	return 0;
}