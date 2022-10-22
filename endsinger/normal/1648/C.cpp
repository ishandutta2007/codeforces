#include<bits/stdc++.h>
using namespace std;
const int N=200005,mx=200000,mod=998244353;
int n,m,a[N],b[N],c[N],fc[N],iv[N],t[N],d[N],ans,z,r;
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
int rd()
{
	char c=getchar();int x=0;
	while(!(c>='0'&&c<='9'))
		c=getchar();
	while(c>='0'&&c<='9')
	{
		x=x*10+(c-'0');
		c=getchar();
	}
	return x;
}
void add(int x,int v)
{
	for(int i=x;i<=mx;i+=i&(-i))
		t[i]=(t[i]+v)%mod;
}
int ask(int x)
{
	int v=0;
	for(int i=x;i;i-=i&(-i))
		v=(v+t[i])%mod;
	return v;
}
int main()
{
	n=rd(),m=rd();
	fc[0]=1;
	for(int i=1;i<=mx;i++)
		fc[i]=1ll*fc[i-1]*i%mod;
	iv[mx]=qp(fc[mx],mod-2);
	for(int i=mx-1;i>=0;i--)
		iv[i]=1ll*iv[i+1]*(i+1)%mod;
	for(int i=1;i<=n;i++)
		a[i]=rd(),c[a[i]]++;
	for(int i=1;i<=m;i++)
		b[i]=rd();
	z=fc[n];
	for(int i=1;i<=mx;i++)
		z=1ll*z*iv[c[i]]%mod;
	for(int i=1;i<=mx;i++)
	{
		if(c[i])
		{
			d[i]=1ll*iv[c[i]-1]*fc[c[i]]%mod;
			add(i,d[i]);
		}
	}
	r=n;
	for(int i=1;i<=m;i++)
	{
		if(i>n)
		{
			ans=(ans+1)%mod;
			break;
		}
		int g=ask(b[i]-1);
		ans=(ans+1ll*z*g%mod*fc[r-1]%mod*iv[r]%mod)%mod;
		int w=b[i];
		if(!c[w])
			break;
		z=1ll*z*d[w]%mod*iv[r]%mod*fc[r-1]%mod;
		r--;
		add(w,(mod-d[w])%mod);
		c[w]--;
		if(c[w])
		{
			d[w]=1ll*iv[c[w]-1]*fc[c[w]]%mod;
			add(w,d[w]);
		}
	}
	printf("%d\n",ans);
	return 0;
}