#include<cstdio>

int main(void)
{
	int a,b,c,d;
	scanf("%d%d%d%d",&a,&b,&c,&d);
	if(a==b+c+d || b==a+c+d || c==a+b+d || d==a+b+c || a+b==c+d || a+c==b+d || a+d==b+c) printf("YES");
	else printf("NO");
	return 0;
}