#include<bits/stdc++.h>
#define int long long
using namespace std;
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
int a[1000003],b[1000003];
int c[1000003],d[1000003];
int A,B;
int pre[1000003];
int ef(int l,int r,int x)
{
	int ans=l;
	while(l<=r)
	{
		int mid=(l+r)>>1;
		if(d[mid]>=x)
		{
			ans=mid;
			r=mid-1;
		}
		else l=mid+1;
	}
	return ans;
}
int solve()
{
	if(A==0||B==0) return 0;
	pre[0]=0;
	int ans=0;
	for(int i=A,j=B,cur=0; i>=1;) 
	{
		while(c[i]>d[j]&&i>0)
		{
			--i;
		}
		//printf("%lld %lld %lld\n",i,j,cur);
		if(i==0) 
		{
			ans=max(ans,cur);
			return ans;
		}		
		if(c[i]==d[j])
		{
			++cur;
			--i,--j;
			ans=max(ans,cur);
			continue;
		}
		//case 1: ALL
		//printf(">%lld %lld %lld\n",j,d[j]-i+1,ef(1,B,d[j]-i+1));
		ans=max(ans,cur+(j-ef(1,B,d[j]-i+1)+1));
		--j;
	}
	return ans;
}
signed main()
{
	int T=read();
	while(T--)
	{
		int n=read(),m=read();
		for(int i=1; i<=n; i++) a[i]=read();
		for(int i=1; i<=m; i++) b[i]=read();
		int ans=0;
		A=0,B=0;
		for(int i=1; i<=n; i++) if(a[i]>0) c[++A]=a[i];
		for(int i=1; i<=m; i++) if(b[i]>0) d[++B]=b[i];
		//printf("%lld\n",solve());
		ans+=solve();
		//printf("%lld\n",ans);
		A=0,B=0;
		for(int i=n; i>=1; i--) if(a[i]<0) c[++A]=-a[i];
		for(int i=m; i>=1; i--) if(b[i]<0) d[++B]=-b[i];
		ans+=solve();
		printf("%lld\n",ans);
	}
	return 0;
}