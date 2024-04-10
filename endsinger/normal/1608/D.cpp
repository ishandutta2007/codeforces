#include<bits/stdc++.h>
using namespace std;
const int N=100005,mod=998244353;
int n,a[N],b[N],x,y,v,fc[N],iv[N],ans,fl,z=1;
char s[10],mp[300];
int qp(int a,int b)
{
	int ans=1;
	while(b)
	{
		if(b&1)
			ans=1ll*ans*a%mod;
		a=1ll*a*a%mod;
		b>>=1;
	}
	return ans;
}
int c(int n,int m){return 1ll*fc[n]*iv[m]%mod*iv[n-m]%mod;}
int main()
{
	mp['B']=0,mp['W']=1,mp['?']=2;
	scanf("%d",&n);
	fc[0]=iv[0]=1;
	for(int i=1;i<=n;i++)
		fc[i]=1ll*fc[i-1]*i%mod,iv[i]=qp(fc[i],mod-2);
	for(int i=1;i<=n;i++)
	{
		scanf("%s",s);
		a[i]=mp[s[0]];
		b[i]=mp[s[1]];
		if(a[i]==0)
			v++;
		if(a[i]==2)
			x++;
		if(b[i]==1)
			v--;
		if(b[i]==2)
			y++;
	}
	for(int i=0;i<=x;i++)
	{
		int j=v+i;
		if(j>=0&&j<=y)
		{
			int w=1ll*c(x,i)*c(y,j)%mod;
			ans=(ans+w)%mod;
		}
	}
	fl=1;
	for(int i=1;i<=n;i++)
		if(a[i]==1||b[i]==0)
			fl=0;
	ans=(ans+fl)%mod;
	fl=1;
	for(int i=1;i<=n;i++)
		if(a[i]==0||b[i]==1)
			fl=0;
	ans=(ans+fl)%mod;
	for(int i=1;i<=n;i++)
	{
		int zz=0;
		for(int x=0;x<=1;x++)
		{
			if(a[i]!=x&&a[i]!=2)
				continue;
			for(int y=0;y<=1;y++)
			{
				if(b[i]!=y&&b[i]!=2)
					continue;
				if(x!=y)
					zz++;
			}
		}
		z=1ll*z*zz%mod;
	}
	ans=(ans+mod-z)%mod;
	printf("%d\n",ans);
	return 0;
}