#include<bits/stdc++.h>
#define ll long long
#define dd double
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
const int xx=3e5+5;
int n,a[xx],t[xx];
int gcd(int a,int b){return !b?a:gcd(b,a%b);}
int bs[xx];// 
int prim[xx],vis[xx],mn[xx];
void pre(int n)
{
	int cnt=0;
	for(int i=2;i<=n;i++)
	{
		if(!vis[i])prim[++cnt]=i,mn[i]=i;
		for(int j=1;j<=cnt;j++)
		{
			if(prim[j]*i>n)break;
			//int 
			vis[i*prim[j]]=1;
			mn[i*prim[j]]=prim[j];
			if(i%prim[j]==0)break;
		}
//		if(i>46340)cerr<<i<<" "<<cnt<<"ss \n";
	}
//	cout<<mn[6]<<"ss \n";
}
int g[xx];//gcd=1 
int ct[xx];
int Ct(int x)
{
	int res=0;
	for(int i=0;i<10;i++)res+=x>>i&1;
	return res;
}
int js(vector<int>v)
{
	int sz=v.size();
	int res=0;
	for(int i=1;i<(1<<sz);i++)
	{
		int P=1;
		for(int j=0;j<sz;j++)
			if(i>>j&1)P*=v[j];
		if(ct[i]&1)res+=bs[P];
		else res-=bs[P];
//		cout<<P<<" "<<res<<" "<<bs[3]<<" "<<ct[i]<<"!!AD\n";
	}
	return n-res;
}
int calc(int x)
{
	if(g[x])return g[x];
	vector<int>pm;
	while(x!=1)
	{
		int u=mn[x];
		pm.push_back(u);
		while(x%u==0)x/=u;
	}
	int S=1;
	for(auto it:pm)S*=it;
	return g[x]=js(pm);
}
int f[129];
int G[129];
int solve(int x)
{
	vector<int>v;
	while(x!=1)
	{
		int u=mn[x];
		v.push_back(u);
//		cout<<u<<"\n";
		while(x%u==0)x/=u;
	}
//	exit(0);
	
	int sz=v.size();
	for(int i=0;i<(1<<sz);i++)f[i]=1e9;
	f[0]=1;
	for(int i=0;i<(1<<sz);i++)
	{
		int P=1;
		for(int j=0;j<sz;j++)
			if(i>>j&1)P*=v[j];
		G[i]=P;
	}
	for(int i=0;i<(1<<sz);i++)
	{
		for(int j=i;j;j=(j-1)&i)
			if(calc(G[j]))
			{
//				cout<<j<<" "<<G[j]<<"\n";
				f[i]=min(f[i],f[i^j]+1);
			}
	}
	return f[(1<<sz)-1];
}
int main(){
	pre(300000);
	for(int i=0;i<=(1<<9);i++)ct[i]=Ct(i);
	n=read();
	int ans=0;
	for(int i=1;i<=n;i++)a[i]=read(),ans=gcd(ans,a[i]),t[a[i]]++;
	if(ans!=1)
	{
		puts("-1");
		return 0;
	}
	int I=300000;
	for(int i=1;i<=I;i++)
		for(int j=i;j<=I;j+=i)bs[i]+=t[j];
	if(t[1])
	{
		puts("1");
		return 0;
	}
	ans=10;//7 
//	cout<<calc(15)<<"\n";
//	return 0;
	for(int i=2;i<=I;i++)
	{
		if(!t[i])continue;
//		cout<<i<<" "<<calc(i)<<"!!!\n";
		ans=min(ans,solve(i));
		if(ans==1)break;
	}
//	return 0;
	cout<<ans<<"\n";
	return 0;
}