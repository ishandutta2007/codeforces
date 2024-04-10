#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll read()
{
	char c;
	ll w=1;
	while((c=getchar())>'9'||c<'0')if(c=='-')w=-1;
	ll ans=c-'0';
	while((c=getchar())>='0'&&c<='9')ans=(ans<<1)+(ans<<3)+c-'0';
	return ans*w;
}
int n,m,t;
const int xx=2e5+5;
struct node
{
	int x,y;
	bool operator<(const node&w)const{return x==w.x?y<w.y:x<w.x;}
}e[xx];
const int mod=1e9+7;
ll jiec[xx],ni[xx],f[xx];
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
ll C(int n,int m)
{
	if(n<m)return 0;
	return jiec[n]*ni[m]%mod*ni[n-m]%mod;
}
signed main(){
	n=read(),m=read(),t=read();
	for(int i=1;i<=t;i++)e[i].x=read(),e[i].y=read();
	e[++t].x=n,e[t].y=m;
	sort(e+1,e+t+1);
	jiec[0]=1;
	for(int i=1;i<xx;i++)jiec[i]=jiec[i-1]*i%mod;
	ni[xx-1]=ksm(jiec[xx-1],mod-2);
	for(int i=xx-2;i>=0;i--)ni[i]=ni[i+1]*(i+1)%mod;
	for(int i=1;i<=t;i++)
	{
		f[i]=C(e[i].x-1+e[i].y-1,e[i].y-1);
		for(int j=1;j<i;j++)
		{
			if(e[j].x<=e[i].x&&e[j].y<=e[i].y)
			{
				f[i]-=f[j]*C(e[i].x-e[j].x+e[i].y-e[j].y,e[i].y-e[j].y)%mod;
				f[i]+=mod,f[i]%=mod;
			}
		}
	}
	cout<<f[t]<<'\n';
	return 0;
}