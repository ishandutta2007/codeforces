#include<bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	string s; cin >> s;
	ll num1 = 0, num2 = 0, num3 = 0;
	for (int i = 0; i+1 < int(s.size()); i++) {
		if (s[i] == 'v' && s[i+1] == 'v') {
			num3 += num2;
			num1 ++;
		} else if (s[i] == 'o') {
			num2 += num1;
		}
	}
	cout << num3 << '\n';

	return 0;
}