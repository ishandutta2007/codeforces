#include <bits/stdc++.h>

using namespace std;

int r, g, b, flag;

int main() {
	scanf("%d %d %d", &r, &g, &b);
	if(r % 3 == 0 && r >= 3 && g % 3 == 2 && b % 3 == 2) flag = 1;
	if(g % 3 == 0 && g >= 3 && r % 3 == 2 && b % 3 == 2) flag = 1;
	if(b % 3 == 0 && b >= 3 && g % 3 == 2 && r % 3 == 2) flag = 1;
	
	printf("%d\n", r/3 + g/3 + b/3 + min(r%3, min(g%3, b%3)) + flag);
}