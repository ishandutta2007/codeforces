#include<algorithm>
#include<iostream>
#include<cstdio>
#define MN 100000
#define ll long long 
using namespace std;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
ll ans=-1;
int n,A,cf,cm,from,Res,a[MN+5],rk[MN+5],c[MN+5],Ans[MN+5];ll m,s[MN+5];
bool cmp(int x,int y){return a[x]>a[y];}
int main()
{
	n=read();A=read();cf=read();cm=read();scanf("%lld",&m);
	for(int i=1;i<=n;++i) a[i]=read(),rk[i]=i;
	sort(rk+1,rk+n+1,cmp);
	for(int i=1;i<=n;++i) s[i]=s[i-1]+(c[n-i+1]=a[rk[i]]);
	for(int i=0;i<=n;++i) if(1LL*i*A-s[i]<=m)
	{
		if(i==n) 
		{
			ll pow=1LL*n*cf+1LL*A*cm;
			if(pow>ans) ans=pow,from=i;
			continue;
		}	
		ll left=m-1LL*i*A+s[i];
		int l=0,r=A,mid,res;
		while(l<=r)
		{
			mid=l+r>>1;
			int pos=lower_bound(c+1,c+n+1-i,mid)-c;
			if(1LL*(pos-1)*mid-(s[n]-s[n-pos+1])<=left) res=mid,l=mid+1;
			else r=mid-1;
		}	
		ll pow=1LL*i*cf+1LL*res*cm;
		if(pow>ans) ans=pow,from=i,Res=res;
	}
	printf("%lld\n",ans);
	for(int i=1;i<=from;++i) Ans[rk[i]]=A;
	for(int i=from+1;i<=n;++i) Ans[rk[i]]=max(a[rk[i]],Res);
	for(int i=1;i<=n;++i) printf("%d ",Ans[i]);
	return 0;
}