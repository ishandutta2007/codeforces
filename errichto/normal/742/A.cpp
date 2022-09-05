#include <bits/stdc++.h>
using namespace std;
int main() {
	int n;
	scanf("%d", &n);
	if(n) {
		n %= 4;
		n += 4;
	}
	int r = 1;
	while(n--) r *= 8;
	printf("%d\n", r % 10);
}