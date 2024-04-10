#include<bits/stdc++.h>
using namespace std;

int t[1005*1005];

int main() {
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) {
		scanf("%d", &t[i]);
	}
	int x = t[1];
	for(int i = 2; i <= n; ++i)
		x = __gcd(x, t[i]);
	while(x % 2 == 0) x /= 2;
	while(x % 3 == 0) x /= 3;
	for(int i = 1; i <= n; ++i) {
		int two = 1, three = 1;
		while(t[i] % (two * 2) == 0) two *= 2;
		while(t[i] % (three * 3) == 0) three *= 3;
		if(x * two * three != t[i]) {
			puts("No");
			return 0;
		}
	}
	puts("Yes");
	return 0;
}