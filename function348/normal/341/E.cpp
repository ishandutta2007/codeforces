#include<cstdio>
#include<iostream>
#define MP make_pair
using namespace std;
typedef pair<int,int> PII;
const int N=1010;
int n,num;
int a[N];
PII ans[N*N];
void work(int i,int j,int k)
{
	while (1)
	{
		if (a[i]>a[j]) swap(i,j);
		if (a[j]>a[k]) swap(j,k);
		if (a[i]>a[j]) swap(i,j);
		if (a[i]==0) return;
		while (a[i]<=a[j])
		if ((a[j]/a[i])&1) 
		{
			ans[++num]=MP(i,j);
			a[j]-=a[i];
			a[i]<<=1;
		}
		else
		{
			ans[++num]=MP(i,k);
			a[k]-=a[i];
			a[i]<<=1;
		}
	}
}
int main()
{
	scanf("%d",&n);
	int cnt=0;
	for (int i=1;i<=n;i++) 
	{
		scanf("%d",&a[i]);
		if (a[i]) cnt++;
	}
	if (cnt<=1) { printf("-1\n");return 0;}
	if (cnt==2) { printf("0\n");return 0;}
	int k1=0,k2=0;
	num=0;
	for (int i=1;i<=n;i++)
	if (a[i])
	{
		if (!k1) k1=i;else
		if (!k2) k2=i;else 
		{
			work(k1,k2,i);
			if (a[k1]==0) k1=i;
			if (a[k2]==0) k2=i;
		}
	}
	printf("%d\n",num);
	for (int i=1;i<=num;i++) printf("%d %d\n",ans[i].first,ans[i].second);
	return 0;
}