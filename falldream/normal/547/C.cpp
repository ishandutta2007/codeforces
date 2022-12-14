#include<iostream>
#include<cstdio>
#include<vector> 
#define MN 500000
using namespace std;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
vector<int> v[MN+5];
int n,m,a[MN+5],mu[MN+5],num[MN+5],b[MN+5];
long long ans=0;
int main()
{
	n=read();m=read();mu[1]=1;
	for(int i=1;i<=n;++i) a[i]=read();
	for(int i=1;i<=MN;++i) for(int j=i;j<=MN;j+=i) v[j].push_back(i);
	for(int i=2,t,pre;i<=MN;++i)
		for(mu[t=i]=1,pre=0;t>1;pre=v[t][1],t/=v[t][1],mu[i]*=-1)
			if(v[t][1]==pre) mu[i]=0;
	for(int i=1,n=0;i<=m;++i)
	{
		int x=read();b[x]^=1;
		for(int j=0;j<v[a[x]].size();++j) 
			if(b[x]) ans+=mu[v[a[x]][j]]*(num[v[a[x]][j]]++);
			else ans-=mu[v[a[x]][j]]*(--num[v[a[x]][j]]);
		printf("%lld\n",ans);
	}
	return 0;
}