#include<cstdio>
using namespace std;
int n,m;
int main()
{
	scanf("%d%d",&n,&m);
	if(n==m) printf("%d1 %d2\n",n,m);
	else if(n==m-1) printf("%d9 %d0\n",n,m);
	else if(n==9 && m==1) printf("9 10\n");
	else printf("-1\n");
	return 0;
}