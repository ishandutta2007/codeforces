#include<algorithm>
#include<iostream>
#include<random>
#include<vector>
#include<cstdio>
using namespace std;
#define ll long long
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define MAXN 200001
int N,a[MAXN];ll s[MAXN];
int get(){int x=0,f=1;char c=getchar();while(c<'0'||c>'9')c=='-'&&(f=-1),c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x*f;}
int main()
{
	N=get();For(i,1,N)a[i]=get();sort(a+1,a+N+1);For(i,1,N)s[i]=s[i-1]+a[i];long double ans=0;int x=1,cnt=0;
	For(i,2,N)
	{
		int l=1,r=min(i-1,N-i),t=0;long double mx=0;
		while(l<=r)
		{
			int mid=l+r>>1;long double val=(long double)(s[N]-s[N-mid+1]+s[i]-s[i-mid])/(mid*2-1)-a[i],val1=(long double)(s[N]-s[N-mid]+s[i]-s[i-mid-1])/(mid*2+1)-a[i];
			if(val1>val)val1>mx&&(mx=val1,t=mid),l=mid+1;else r=mid-1;
		}
		if(mx>ans)ans=mx,x=i,cnt=t;
	}
	cout<<cnt*2+1<<'\n';For(i,x-cnt,x)cout<<a[i]<<' ';For(i,N-cnt+1,N)cout<<a[i]<<' ';cout<<'\n';
}