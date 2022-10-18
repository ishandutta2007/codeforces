#include <bits/stdc++.h>

int main() {
	int y, b, r;
	scanf("%d %d %d", &y, &b, &r);
	for (int i=y;i>=0;--i) {
		if (i+1<=b&&i+2<=r) {printf("%d", i+i+i+3);return 0;}
	}
	return 0;
}