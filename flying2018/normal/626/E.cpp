#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define N 200010
#define ll long long
using namespace std;
int n;
ll v[N],sm[N];
double solve(int x,int len){return (sm[x]-sm[x-len-1])+(sm[n]-sm[n-len]);}
double check(int x,int len){return solve(x,len)*1.0/(len*2+1)-v[x];}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%lld",&v[i]);
	sort(v+1,v+n+1);
	for(int i=1;i<=n;i++) sm[i]=sm[i-1]+v[i];
	double ans=-1e9;
	int x=0,len=0;
	for(int i=1;i<=n;i++)
	{
		int l=0,r=min(i-1,n-i);
		while(l+3<r)
		{
			int ml=l+(r-l+1)/3,mr=r-(r-l+1)/3;
			if(check(i,ml)>check(i,mr)) r=mr;
			else l=ml;
		}
		for(int j=l;j<=r;j++)
		if(ans<check(i,j))
		{
			ans=check(i,j);
			x=i;
			len=j;
		}
	}
	printf("%d\n",len*2+1);
	for(int i=x-len;i<=x;i++) printf("%lld ",v[i]);
	for(int i=n-len+1;i<=n;i++) printf("%lld ",v[i]);
	return 0;
}