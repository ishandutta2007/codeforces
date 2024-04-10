#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
long long f[7], n;
int main() {
	cin >> f[1] >> f[2] >> n;
	for (int i = 3; i <= 6; ++ i) f[i] = f[i - 1] - f[i - 2];
	return cout << (f[(n - 1) % 6 + 1] + mod + mod + mod) % mod, 0;
}