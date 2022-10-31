#include<cstdio>
int main()
{
	int a,b,c,x,y,z,tot=0;
	scanf("%d %d %d %d %d %d",&a,&b,&c,&x,&y,&z);
	if(a>=x) tot+=(a-x)>>1,a-=x,x=0;
	else x-=a;
	if(b>=y) tot+=(b-y)>>1,b-=y,y=0;
	else y-=b;
	if(c>=z) tot+=(c-z)>>1,c-=z,z=0;
	else z-=c;
	if(tot>=x+y+z) printf("Yes\n");
	else printf("No\n");
	return 0;
}