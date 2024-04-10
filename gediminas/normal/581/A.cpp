#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	long long a, b;
	cin >> a >> b;
	cout << min(a, b) << " " << (a + b - 2 * min(a, b)) / 2;
}