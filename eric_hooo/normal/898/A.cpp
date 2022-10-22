#include <bits/stdc++.h>
using namespace std;
int main(){
	int n;
	scanf("%d", &n);
	if (n % 10 <= 5) n -= n % 10;
	else n += 10 - n % 10;
	printf("%d\n", n);
	return 0;
}