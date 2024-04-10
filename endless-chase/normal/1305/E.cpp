#include<bits/stdc++.h>
#define Accepted 0
using namespace std;
const int maxn=15000;
int n,ans[5555],m,arr[5555],pos,cnt,cur;
void recycle(int l)
{
	cur=100000000;
	for (int i=l;i<=n;i++)
	{
		ans[i]=cur;
		cur+=maxn;
	}
}
void Out()
{
	for (int i=1;i<=n;i++) printf("%d ",ans[i]);
	printf("\n"); 
}
int main()
{
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++)
	{
		arr[i]=(i*(i-1)/2-(i/2))/2;
	}
	if (m>arr[n])
	{
		printf("-1\n");
		return 0;
	}
	pos=n+1;
	for (int i=0;i<=n;i++)
	{
		if (arr[i]>m)
		{
			pos=i;
			break;
		}
	}
	pos--;
	for (int i=1;i<=pos;i++) ans[i]=i;
	if (m==arr[pos])
	{
		recycle(pos+1);
		Out();
		return 0;
	}
	for (int i=pos+1;i<=maxn;i++)
	{
		cnt=0;
		for (int j=1;j<=pos;j++)
		{
			if (i-j<j) cnt++;
		}
		if (cnt+arr[pos]==m)
		{
			ans[pos+1]=i;
			break;
		}
	}
	recycle(pos+2);
	Out();
	return Accepted;
}