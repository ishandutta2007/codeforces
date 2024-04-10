#include<iostream>
#include<cstdio>
#include<vector>
#define MN 200000
#define pa pair<int,int>
#define mod 1000000007 
using namespace std;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
vector<int> v[MN+5];
int n;pa f[MN+5],g[MN+5],p[MN+5];
pa C(pa x){return x.second+=x.first,x;}
pa operator*(pa a,pa b){return make_pair(1LL*a.first*b.first%mod,(1LL*a.first*b.second+1LL*a.second*b.second+1LL*a.second*b.first)%mod);}
void dfs(int x)
{
	f[x].first=1;
	for(int i=0;i<v[x].size();++i) dfs(v[x][i]),f[x]=f[x]*C(f[v[x][i]]);
}
void Solve(int x)
{
	for(int i=0;i<v[x].size();++i)
		p[i]=(i?p[i-1]*C(f[v[x][i]]):C(f[v[x][i]]));
	pa suf=g[x];
	for(int i=v[x].size()-1;i>=0;--i) g[v[x][i]]=C(i?p[i-1]*suf:suf),suf=suf*C(f[v[x][i]]);
	for(int i=0;i<v[x].size();++i) Solve(v[x][i]);
}
int main()
{
	n=read();
	for(int i=2;i<=n;++i) v[read()].push_back(i);
	dfs(1);g[1].first=1;Solve(1);pa ans;
	for(int i=1;i<=n;++i) ans=f[i]*g[i],printf("%d ",(ans.first+ans.second)%mod);
	return 0;
}