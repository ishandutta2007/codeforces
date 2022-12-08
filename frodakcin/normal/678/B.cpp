#include <cstdio>

bool leap(int a)
{
	if(a%400==0) return 1;
	if(a%4==0 && a%100) return 1;
	return 0;
}
int n,m;
bool l0;
int main()
{
	scanf("%d", &n);
	l0 = leap(n);
	for(;;)
	{
		m+=365+leap(n);
		m%=7;
		++n;
		if(!m && l0 == leap(n)) break;
	}
	printf("%d\n", n);
}