#include<bits/stdc++.h>
using namespace std;
const int N=105;
int n,a[N],s;
void sol()
{
	scanf("%d",&n);
	for(int i=1;i<=10;i++)
		a[i]=0;
	s=0;
	for(int i=1;i<=n;i++)
	{
		int b,d;
		scanf("%d%d",&b,&d);
		a[d]=max(a[d],b);
	}
	for(int i=1;i<=10;i++)
	{
		if(!a[i])
		{
			puts("MOREPROBLEMS");
			return;
		}
		s+=a[i];
	}
	printf("%d\n",s);
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
		sol();
	return 0;
}