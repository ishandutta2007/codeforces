#include <iostream>
#include <vector>

typedef long long ll;

using namespace std;

int main() {
	vector <ll> p2(40);
	p2[0] = 1;
	for (int i = 1; i < 40; i++)
		p2[i] = (p2[i - 1] * 2);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		ll sum = 0;
		for (int i = 1; i <= n / 2 - 1; i++)
			sum += p2[i];
		sum += p2[n];
		sum = abs((p2[n + 1] - 2 - sum) - sum);
		cout << sum << '\n';
	}
	return 0;
}