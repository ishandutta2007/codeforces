#include<bits/stdc++.h>
#define ll long long
#define dd double
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
const int mod=998244353,base=117,xx=2e5+5;
int n,m;
char s[xx],t[xx];
int e[27][xx],f[27][xx];
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
ll pw[xx],ni[xx];
ll an[27],re[27],fi[27],to[27];
signed main(){
	pw[0]=1;
	for(int i=1;i<xx;i++)pw[i]=pw[i-1]*base%mod;
	ni[0]=1;
	ni[1]=ksm(base,mod-2);
	for(int i=2;i<xx;i++)ni[i]=ni[i-1]*ni[1]%mod;
	n=read(),m=read();
	scanf("%s",s+1);
	scanf("%s",t+1);
	for(int i=1;i<=n;i++)e[s[i]-'a'][i]=1;
	for(int i=1;i<=m;i++)f[t[i]-'a'][i]=1;
	for(int i=1;i<=m;i++)if(!fi[t[i]-'a'])fi[t[i]-'a']=i;
	for(int j=0;j<26;j++)
		for(int i=1;i<=m;i++)
			re[j]+=pw[i-1]*f[j][i]%mod,re[j]%=mod;
	for(int j=0;j<26;j++)
		for(int i=1;i<=m;i++)
			an[j]+=pw[i-1]*e[j][i]%mod,an[j]%=mod;
	vector<int>ans;
	for(int i=1;i<=n-m+1;i++)
	{
		for(int j=0;j<26;j++)
		{
			if(fi[j])
				to[j]=s[i+fi[j]-1]-'a';
		}
		int vs=1;
		for(int j=0;j<26;j++)
		{
			if(fi[j])
			{
//				if(i==5)
//				{
//					cout<<j<<" "<<an[to[j]]<<" "<<re[j]<<" "<<to[to[j]]<<" "<<to[j]<<"\n";
//				}
				if(an[to[j]]!=re[j])vs=0;
				if(fi[to[j]]&&to[to[j]]!=j)vs=0;
			}
		}
		if(vs)ans.push_back(i);
		if(i!=n-m+1)
		{
			for(int j=0;j<26;j++)an[j]+=mod-e[j][i],an[j]%=mod;
			for(int j=0;j<26;j++)an[j]=an[j]*ni[1]%mod;
			for(int j=0;j<26;j++)an[j]+=e[j][i+m]*pw[m-1]%mod,an[j]%=mod;
		}
	}
	cout<<ans.size()<<"\n";
	for(auto it:ans)cout<<it<<" ";
	puts("");
	return 0;
}