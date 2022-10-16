#include<bits/stdc++.h>
#define ll long long
using namespace std;
char gc(){static char buf[1<<16],*s,*t;if(s==t){t=(s=buf)+fread(buf,1,1<<16,stdin);if(s==t)return EOF;}return *s++;}
//#define getchar gc
ll read()
{
	char c;
	ll w=1;
	while((c=getchar())>'9'||c<'0')if(c=='-')w=-1;
	ll ans=c-'0';
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
const int xx=5005+5,mod=1e9+7;
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
int n,k;
int stl[xx][xx],c[xx][xx];
ll C(ll n,ll m)
{
	ll ans=1;
	for(int i=1;i<=m;i++)
		ans*=(n-i+1),ans%=mod;
	return ans*ni[m]%mod;
}
int main(){
	n=read(),k=read();
	stl[0][0]=c[0][0]=1;
	for(int i=1;i<xx;i++)stl[i][1]=i,c[i][0]=1;
	for(int i=1;i<xx;i++)
		for(int j=1;j<=i;j++)
			stl[i][j]=(stl[i-1][j-1]+1ll*stl[i-1][j]*j)%mod,c[i][j]=(c[i-1][j]+c[i-1][j-1])%mod;
	jiec[0]=1;
	for(int i=1;i<xx;i++)jiec[i]=jiec[i-1]*i%mod;
	ni[xx-1]=ksm(jiec[xx-1],mod-2);
	for(int i=xx-2;i>=0;i--)ni[i]=ni[i+1]*(i+1)%mod;
	ll ans=0;
	if(n<=5000)
	{
		for(int i=1;i<=n;i++)
		{
			ans+=ksm(i,k)*c[n][i]%mod;
			ans%=mod;
		}
		cout<<ans<<"\n";
		return 0;
	}
	for(int j=1;j<=k;j++)
	{
		ans+=jiec[j]*stl[k][j]%mod*C(n,j)%mod*ksm(2,n-j);
		ans%=mod;
	}
	cout<<ans<<"\n";
	pc('1',1);
	return 0;
}