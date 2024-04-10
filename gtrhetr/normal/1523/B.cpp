#include<bits/stdc++.h>
using namespace std;

int num[1010],t,n;

inline int rd()
{
	int x=0;char ch=getchar();
	for (;ch<'0'||ch>'9';ch=getchar());
	for (;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-'0';
	return x;
}

inline void work()
{	
	n=rd();
	for (int i=1;i<=n;i++) num[i]=rd();
	printf("%d\n",n/2*6);
	for (int i=1;i<=n;i+=2)
	{
		printf("2 %d %d\n",i,i+1);
		printf("1 %d %d\n",i,i+1);
		printf("2 %d %d\n",i,i+1);
		printf("2 %d %d\n",i,i+1);
		printf("1 %d %d\n",i,i+1);
		printf("2 %d %d\n",i,i+1);
	}
}

int main()
{
	t=rd();
	while (t--) work();
	return 0;
}