#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, m, a, b;
	cin >> n >> m >> a >> b;
	int total = 0;
	while(n) {
		if(b <= a*min(n, m)) total += b;
		else total += a*min(n, m);
		n -= min(n, m);
	}
	cout << total << '\n';
}