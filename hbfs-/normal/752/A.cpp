#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
	int n,m,q;
	scanf("%d%d%d",&n,&m,&q);
	int t1 = (q-1)/(m*2) + 1;
	q -= (t1-1) * (m*2);
	int t2 = (q-1) / 2 + 1;
	q -= (t2-1) * 2;
	printf("%d %d ",t1,t2);
	if (q==2) printf("R\n"); else printf("L\n");
	return 0;
}