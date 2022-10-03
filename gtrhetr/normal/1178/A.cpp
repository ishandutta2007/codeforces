#include<bits/stdc++.h>
using namespace std;
#define ll long long

int num[110],n,sum;

inline int rd()
{
	int x=0;char ch=getchar();
	for (;ch<'0'||ch>'9';ch=getchar());
	for (;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-'0';
	return x;
}

int main()
{
	n=rd();
	for (int i=1;i<=n;i++) sum+=num[i]=rd();
	int s=num[1],s1=0;
	for (int i=2;i<=n;i++) if (num[i]*2<=num[1]) s+=num[i],s1++;
	if (s*2>sum)
	{
		printf("%d\n",s1+1);
		printf("1 ");
		for (int i=2;i<=n;i++) if (num[i]*2<=num[1]) printf("%d ",i);
		return 0;
	}
	puts("0");
	return 0;
}