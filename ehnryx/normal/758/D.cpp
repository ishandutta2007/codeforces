#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

// normal
ll convert(string n, int i, int curr) {
	ll ans = 0;
	for (int j = i; j < curr; j++) {
		ans = 10*ans + n[j] - '0';
		if (ans < 0)
			return -1;
	}
	return ans;
}

int main() {
	ll ans[61]; 
	memset(ans, -1, sizeof(ans));
	ans[0] = 0;
	ll base, temp, sz;
	string num;
	cin >> base;
	cin >> num; sz = num.size();
	for (int i = 1; i <= sz; i++) {
		for (int j = i; j > 0; j--) {
			if (num[j-1] == '0') {
				if (i == j)
					temp = 0;
				else
					continue;
			}
			else {
				temp = convert(num, j-1, i);
			}
			if (temp < 0)
				continue;
			if (temp >= base)
				break;
			temp += base*ans[j-1];
			if (ans[i] < 0 || temp < ans[i])
				ans[i] = temp;
		}
		/*for (int k = 0; k < sz; k++)
			cout << " " << ans[k];
		cout << endl;
		*/
	}
	cout << ans[sz] << endl;
	return 0;
}