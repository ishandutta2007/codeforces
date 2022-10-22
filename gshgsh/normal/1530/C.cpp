#include<algorithm>
#include<iostream>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define MAXN 100001
int T,N,a[MAXN],b[MAXN],c[MAXN*3],d[MAXN*3];
int get(){int x=0;char c=getchar();while(c<'0'||c>'9')c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x;}
bool check(int x)
{
	For(i,1,N)c[i]=a[i],d[i]=b[i];For(i,N+1,N+x)c[i]=100,d[i]=0;
	sort(c+1,c+N+x+1);sort(d+1,d+N+x+1);
	int sum1=0,sum2=0;For(i,(N+x)/4+1,N+x)sum1+=c[i],sum2+=d[i];return sum1>=sum2;
}
int main()
{
	T=get();
	while(T--)
	{
		N=get();For(i,1,N)a[i]=get();For(i,1,N)b[i]=get();
		int l=0,r=N,ans=0;while(l<=r){int mid=l+r>>1;check(mid)?ans=mid,r=mid-1:l=mid+1;}
		cout<<ans<<endl;
	}
}