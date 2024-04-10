#include <iostream>
#include <cstdio>

using namespace std;

int n,t,tot;

int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++) {
		scanf("%d",&t);
		tot = (tot + t - 1) % 2;
		if (tot % 2 == 0) printf("2\n"); else printf("1\n");
	}
	return 0;
}