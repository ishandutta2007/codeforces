#include<bits/stdc++.h>
using namespace std;
const int N=100005;
int n,a,b,p[N];
void sol()
{
	scanf("%d%d%d",&n,&a,&b);
	if(a+b>n-2||abs(a-b)>1)
	{
		puts("-1");
		return;
	}
	if(a==b)
	{
		for(int i=1;i<=n;i++)
			p[i]=i;
		for(int i=2,j=1;j<=a;i+=2,j++)
			swap(p[i],p[i+1]);
	}
	if(a<b)
	{
		for(int i=1;i<=n;i++)
			p[i]=n-i+1;
		for(int i=n,j=1;j<=b;i-=2,j++)
			swap(p[i],p[i-1]);
	}
	if(a>b)
	{
		for(int i=1;i<=n;i++)
			p[i]=i;
		for(int i=n,j=1;j<=a;i-=2,j++)
			swap(p[i],p[i-1]);
	}
	for(int i=1;i<=n;i++)
		printf("%d ",p[i]);
	puts("");
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
		sol();
	return 0;
}