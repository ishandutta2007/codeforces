#include<cstdio>
#include<iostream>
using namespace std;
const int N=1000010;
typedef long long LL;
int n,m;
int a[N],b[N],c[N],s[N];
LL d[N];
int main()
{
	scanf("%d",&m);
	LL now=0;
	int p=0;
	for (int i=1;i<=m;i++)
	{
		scanf("%d",&a[i]);
		if (a[i]==1) 
		{
			scanf("%d",&b[i]);
			now++;
			s[++p]=b[i];
		}
		else 
		{
			scanf("%d%d",&b[i],&c[i]);
			int p1=1,p2=1;
			while (p<=1000000)
			{
				s[++p]=s[p2];
				p2++;
				if (p2==b[i]+1) p2=1,p1++;
				if (p1==c[i]+1) break;
			}
			now+=1LL*b[i]*c[i];
		}
		d[i]=now;
	}
	scanf("%d",&n);
	int i=1;
	while (n--)
	{
		LL x;
		scanf("%I64d",&x);
		while (x>d[i]) i++;
		if (a[i]==1) printf("%d ",b[i]);
		else printf("%d ",s[(x-d[i-1]-1)%b[i]+1]);
	}
	printf("\n");
	return 0;
}