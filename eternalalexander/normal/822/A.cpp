#include <bits/stdc++.h>

int main() {
	int a,b;int ans = 1;
	scanf("%d%d",&a,&b);
	a = std::min(a,b);
	for (int i = 1; i <= a; ++ i) ans *= i;
	printf("%d",ans); 
	return 0;
}