#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ll citizens, temp, ans;
	ll cap = -1;
	vector<ll> welfare;
	cin >> citizens;
	for (int i = 0; i < citizens; i++) {
		cin >> temp;
		welfare.push_back(temp);
		if (cap < temp)
			cap = temp;
	}
	for (int i = ans = 0; i < citizens; i++) {
		ans += cap - welfare[i];
	}
	cout << ans << endl;
	return 0;
}