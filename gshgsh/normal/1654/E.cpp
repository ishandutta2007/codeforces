#include<algorithm>
#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define MAXN 100001
#define B 670
int N,a[MAXN],val[MAXN];
int get(){int x=0,f=1;char c=getchar();while(c<'0'||c>'9')c=='-'&&(f=-1),c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x*f;}
int main()
{
	N=get();For(i,1,N)a[i]=get();if(N<=2){cout<<0<<'\n';return 0;}int ans=2;
	For(t,-150,150)
	{
		For(i,1,N)val[i]=a[i]+i*t;sort(val+1,val+N+1);
		int cnt=1;For(i,2,N)if(val[i]!=val[i-1])ans=max(ans,cnt),cnt=1;else cnt++;ans=max(ans,cnt);
	}
	For(i,1,N)
	{
		int M=0;For(j,i+1,min(i+B,N))if((a[j]-a[i])%(j-i)==0)val[++M]=(a[j]-a[i])/(j-i);sort(val+1,val+M+1);
		int cnt=1;For(j,2,M)if(val[j]!=val[j-1])ans=max(ans,cnt+1),cnt=1;else cnt++;ans=max(ans,cnt+1);
	}
	cout<<N-ans<<'\n';
}