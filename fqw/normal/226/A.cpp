#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
using namespace std;

typedef long long LL;

int main() {
	int n, m; scanf("%d%d", &n, &m);
	LL ans=1, p=3;
	for(; n>0; n>>=1, p=p*p%m)
		if(n&1) ans=ans*p%m;
	ans=(ans-1+m)%m;
	printf("%d\n", (int)ans);
	return 0;
}