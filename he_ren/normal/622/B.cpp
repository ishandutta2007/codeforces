#include<cstdio>

int main(void)
{
	int h,m,a;
	scanf("%d:%d\n%d",&h,&m,&a);
	m+=a;
	h += m/60;
	m%=60;
	h%=24;
	printf("%02d:%02d",h,m);
	return 0;
}