#include<cstdio>

int x,y,z,a,b,c;

int main()
{
	scanf("%d%d%d%d%d%d",&x,&y,&z,&a,&b,&c);
	if(a>=x&&a+b-x>=y&&a+b+c-x-y>=z)
		printf("YES");
	else printf("NO");
	return 0;
}