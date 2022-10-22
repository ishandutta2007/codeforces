#include <bits/stdc++.h>
#define MOD 1000000007
typedef long long LL;

int main(){
	int n, m;
	scanf("%d%d", &n, &m);
	if(n == 1 && m == 1)
		printf("1\n");
	else
		printf("%.7lf\n", 1.0/n+((m-1)*(n-1)+0.0)/((n*m-1.0)*n+0.0));
}