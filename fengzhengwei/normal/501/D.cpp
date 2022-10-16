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
const int xx=2e5+5;
int n,a[xx],b[xx],sum[xx];
int lb(int x){return x&-x;}
void add(int x,int y){for(;x<=n;x+=lb(x))sum[x]+=y;}
int ask(int x){int ans=0;for(;x;x-=lb(x))ans+=sum[x];return ans;}
int ef(int x)
{
	int s=0,v=0;
//	cout<<x<<"sss\n";
	for(int i=17;i>=0;i--)if(s+(1<<i)<=n&&v+sum[s+(1<<i)]<x)s+=(1<<i),v+=sum[s];
//	cout<<sum[1]<<" "<<s<<" "<<v<<"ss \n";
	return s+1;
}
int now[xx];
int main(){
	n=read();
	for(int i=1;i<=n;i++)a[i]=read()+1;
	for(int i=1;i<=n;i++)b[i]=read()+1;
	memset(sum,0,sizeof(sum));
	for(int i=n;i>=1;i--)
	{
		add(a[i],1);
		now[i]+=ask(a[i]-1);
		now[i-1]+=now[i]/(n-i+1);
		now[i]%=(n-i+1);
	}
	memset(sum,0,sizeof(sum));
	for(int i=n;i>=1;i--)
	{
		add(b[i],1);
		now[i]+=ask(b[i]-1);
		now[i-1]+=now[i]/(n-i+1);
		now[i]%=(n-i+1);
	}
	memset(sum,0,sizeof(sum));
	for(int i=1;i<=n;i++)add(i,1);
	for(int i=1;i<=n;i++)
	{
		int id=ef(now[i]+1);
		add(id,-1);
		cout<<id-1<<" \n"[i==n];
	}
	return 0;
}