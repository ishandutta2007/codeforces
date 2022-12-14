#include<algorithm>
#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
int n,L,num=0,lim;
long long ans=1e18,c[35];
pair<int,long long> S[1<<15];
void dfs1(int x,int s,long long v)
{
	if(x>lim){S[++num]=make_pair(s,v);return;}
	dfs1(x+1,s|(1<<x-1),v+c[x]);
	dfs1(x+1,s,v);	
}
void dfs2(int x,int s,long long v)
{
	if(x==lim)
	{
		int pos=lower_bound(S+1,S+num+1,make_pair(L-s,0LL))-S;
		if(pos<=num)ans=min(ans,S[pos].second+v);
		return;	
	}
	dfs2(x-1,s|(1<<x-1),v+c[x]);
	dfs2(x-1,s,v);
}
int main()
{
	n=read();L=read();
	for(int i=1;i<=n;++i) c[i]=read();
	for(int i=n+1;i<=31;++i) c[i]=c[i-1]*2;
	for(int i=31;--i;) c[i]=min(c[i],c[i+1]);
	for(int i=2;i<=31;++i) c[i]=min(c[i],c[i-1]*2);
	lim=15;
	dfs1(1,0,0);
	sort(S+1,S+num+1);
	for(int i=num;--i;) S[i].second=min(S[i].second,S[i+1].second);
	dfs2(31,0,0);
	cout<<ans;
	return 0;
}