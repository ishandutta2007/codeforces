#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<set>
#include<map>
using namespace std;
int a[202020];
int sum[202020];
int n;
void add(int x,int v)
{
	for(;x<=n;x+=(x&-x))
		sum[x]+=v;
}
int query(int x)
{
	int ret=0;
	for(;x;x-=(x&-x))
		ret+=sum[x];
	return ret;
}
struct Data
{
	int id,v;
	bool operator <(const Data &r)const
	{
		return v<r.v;
	}
}data[202020];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		data[i].id=i;
		data[i].v=a[i];
		add(i,1);
	}
	sort(data+1,data+n+1);
	int p=1;
	long long ans=0;
	for(int i=1;i<=n;i++)
	{
		while(p<=n&&data[p].v<i)
		{
			add(data[p].id,-1);
			p++;
		}
		ans+=query(min(a[i],n));
		if(a[i]>=i)
			ans--;
	}
	printf("%I64d\n",ans/2);
	return 0;
}