#include<bits/stdc++.h>
#define ll long long
using namespace std;
char gc(){static char buf[1<<16],*s,*t;if(s==t){t=(s=buf)+fread(buf,1,1<<16,stdin);if(s==t)return EOF;}return *s++;}
//#define getchar gc
int read()
{
	char c;
	int w=1;
	while((c=getchar())>'9'||c<'0')if(c=='-')w=-1;
	int ans=c-'0';
	while((c=getchar())>='0'&&c<='9')ans=(ans<<1)+(ans<<3)+c-'0';
	return ans*w;
}
void pc(char c,int op)
{
	static char buf[1<<16],*s=buf,*t=buf+(1<<16);
	(op||((*s++=c)&&s==t))&&(fwrite(buf,1,s-buf,stdout),s=buf);
}
void wt(int x)
{
	if(x>9)wt(x/10);
	pc('0'+x%10,0);
}
void wts(int x,char op)
{
	if(x<0)pc('-',0),x=-x;
	wt(x);pc(op,0);
}
namespace zhs
{
	const int xx=5e5+5,mod=998244353;
	ll jiec[xx],ni[xx];
	ll ksm(ll a,ll b)
	{
		ll ans=1;
		while(b)
		{
			if(b&1)ans*=a,ans%=mod;
			a*=a,a%=mod,b>>=1;
		}
		return ans;
	}
	ll C(ll n,ll m){return jiec[n]*ni[m]%mod*ni[n-m]%mod;}
	void pre()
	{
		jiec[0]=1;
		for(int i=1;i<xx;i++)jiec[i]=jiec[i-1]*i%mod;
		ni[xx-1]=ksm(jiec[xx-1],mod-2);
		for(int i=xx-2;i>=0;i--)ni[i]=ni[i+1]*(i+1)%mod;
	}
}
namespace pr
{
	const int xx=5e5+5,mod=998244353;
	int prim[xx],vis[xx],cnt;
	void pre(int n)
	{
		for(int i=2;i<=n;i++)
		{
			if(!vis[i])prim[++cnt]=i;
			for(int j=1;j<=cnt;j++)
			{
				if(prim[j]*i>n)break;
				vis[i*prim[j]]=1;
				if(i%prim[j]==0)break;
			}
		}
	}
}
const int xx=5e5+5,mod=998244353;
ll ksm(ll a,ll b)
{
	ll ans=1;
	while(b)
	{
		if(b&1)ans*=a,ans%=mod;
		a*=a,a%=mod,b>>=1;
	}
	return ans;
}
int n,m,k,q,ans,a[xx],t[xx];
char s[xx];
int vs[xx],sum[xx];
bool check(int a)
{
//	cerr<<sum[n]<<"!@#$\n";
	for(int i=a;i<=n;i++)
		if((sum[i]-sum[i-a])*2-n>=k)return 1;
	return 0;
}
int X,Y;
void get(int a)
{
	for(int i=a;i<=n;i++)
		if((sum[i]-sum[i-a])*2-n>=k)
		{
			X=i-a+1,Y=i;
			return ;
		}
	return ;
}
int main(){
	int T=read();
	while(T--)
	{
		n=read();k=read();
		for(int i=1;i<=n;i++)t[i]=0;
		for(int i=1;i<=n;i++)a[i]=read(),t[a[i]]++;
		for(int i=1;i<=n;i++)sum[i]=sum[i-1]+t[i];
		int l=1,r=n;
		ans=0;
		while(l<=r)
		{
			int mid=l+r>>1;
			if(check(mid))ans=mid,r=mid-1;
			else l=mid+1;
		}
//		cout<<check(n)<<"!!\n";
//		cout<<ans<<"!!\n";
		get(ans);
		cout<<X<<" "<<Y<<"\n";
		int last=1,S=0;
		if(k==1)
		{
			cout<<1<<" "<<n<<"\n";
			continue;
		}
		for(int i=1;i<=n;i++)
		{
			if(X<=a[i]&&a[i]<=Y)
			{
				S++;
				if(S==1)
				{
					cout<<last<<" "<<i<<"\n";
					k--;
					last=i+1;
					if(k==1)break;
					S=0;
				}
			}
			else S--;
		}
		cout<<last<<" "<<n<<"\n";
	}
	pc('1',1);
	return 0;
}