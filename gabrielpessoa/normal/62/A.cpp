#include <bits/stdc++.h>
using namespace std;

int main() {
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	if((d >= a-1 && d <= 2*a+2) || (c >= b - 1 && c <= 2*b+2)) {
		puts("YES");
	} else {
		puts("NO");
	}
	return 0;
}