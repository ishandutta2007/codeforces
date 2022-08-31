#include<bits/stdc++.h>
using namespace std;

int main() {
	int a, b, c, d, e; cin >> a >> b >> c >> d >> e;
	int s = a + b + c + d + e;
	if(s > 0 && s % 5 == 0) cout << s / 5 << '\n';
	else cout << -1 << '\n';
	return 0;
}