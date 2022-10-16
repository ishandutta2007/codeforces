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
const int mod=1e9+7,xx=2e5+5;
ll jiec[xx],ni[xx];
ll ksm(ll x,ll y)
{
	ll ans=1;
	while(y)
	{
		if(y&1)ans*=x,ans%=mod;
		x*=x,x%=mod,y>>=1;
	}
	return ans;
}
struct nod{int a,op;};
vector<nod> v[xx<<1];
int lsh[xx<<1],s[xx][2];
ll C(int n,int m)
{
	if(n<m)return 0;
	return jiec[n]*ni[m]%mod*ni[n-m]%mod;
}
int w[2];
int main(){
	jiec[0]=1;
	for(int i=1;i<xx;i++)jiec[i]=jiec[i-1]*i%mod;
	ni[xx-1]=ksm(jiec[xx-1],mod-2);
	for(int i=xx-2;i>=0;i--)ni[i]=ni[i+1]*(i+1)%mod;
	int q=read();
	while(q--)
	{
		int n=read(),l=read(),r=read(),tt=0;
		for(int i=1;i<=n;i++)lsh[++tt]=i-l+1,lsh[++tt]=-(i-r)+1;//- 
		lsh[++tt]=1;
		sort(lsh+1,lsh+tt+1);
		tt=unique(lsh+1,lsh+tt+1)-lsh-1;
		ll ans=0;
		for(int i=1;i<=tt;i++)v[i].clear();
		for(int i=1;i<=n;i++)
		{
			v[lower_bound(lsh+1,lsh+tt+1,i-l+1)-lsh].push_back((nod){i,1});
			v[lower_bound(lsh+1,lsh+tt+1,-(i-r)+1)-lsh].push_back((nod){i,0});
		}
		for(int i=1;i<=n;i++)s[i][0]=s[i][1]=1;
		int v2=n,vs=0;
		w[0]=w[1]=0;
		for(int i=1;i<=tt;i++)
		{
			for(auto it:v[i])
			{
				s[it.a][it.op]=0;
				if(!s[it.a][it.op^1]){vs=1;break;}
				v2--,w[it.op^1]++;
			}
			if(vs)break;
			if(n&1)
			{
				ll res=(C(v2,n/2-w[0])+C(v2,(n-n/2)-w[0]))%mod*(lsh[i+1]-lsh[i])%mod;
				ans+=res;
				ans%=mod;
			}
			else 
			{
				ll res=C(v2,n/2-w[0])%mod*(lsh[i+1]-lsh[i])%mod;
//				cout<<lsh[i+1]<<" "<<lsh[i]<<"\n";
				ans+=res;
				ans%=mod;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}