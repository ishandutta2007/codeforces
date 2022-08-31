#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <set>
#include <queue>
#define maxn 200005
using namespace std;
long long a[maxn];
long long n,k,x;
bool cg[maxn]; 
struct thing
{
	long long x;
	long long num;
	bool operator<(const thing &a)const
	{
		return num>a.num;
	}
};
priority_queue <thing> q;
int main()
{
	scanf("%I64d%I64d%I64d",&n,&k,&x);
	long long fss=0;
	for(long long i=0;i<n;i++)
	{
		scanf("%I64d",&a[i]);
		if(a[i]<0) fss++,cg[i]=true,a[i]=-a[i];
		else cg[i]=false;
	}
	if(fss%2)
	{
		for(long long i=0;i<n;i++)
		{
			thing now;now.x=i,now.num=a[i];q.push(now);
		}
		for(long long j=0;j<k;j++) 
		{
			thing n=q.top();
			q.pop();
			a[n.x]+=x;
			n.num+=x;q.push(n);
		}
	}
	else
	{
		long long mins=2147483647,minpl=-1;
		for(long long i=0;i<n;i++) if(mins>a[i]) mins=a[i],minpl=i;
		long long ntime=0;
		while(ntime<k && a[minpl]>0) ntime++,a[minpl]-=x;
		if(ntime<k)
		{
			cg[minpl]=!cg[minpl];
			a[minpl]=-a[minpl];
			for(long long i=0;i<n;i++)
			{
				thing now;now.x=i,now.num=a[i];q.push(now);
			}
			for(long long j=0;j<k-ntime;j++)
			{
				thing n=q.top();
				q.pop();
				a[n.x]+=x;
				n.num+=x;q.push(n);
			}
		}
	}
	for(long long i=0;i<n;i++)
	{
		if(cg[i]) a[i]=-a[i];		printf("%I64d ",a[i]);
	}
	return 0;
}