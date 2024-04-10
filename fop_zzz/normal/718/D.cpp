#include<bits/stdc++.h>
#define eps 1e-10
#define inf 1e9
#define For(i,j,k)	for(int i=j;i<=k;++i)
#define Dow(i,j,k)	for(int i=k;i>=j;--i)
#define ll long long
using namespace std;
inline ll read()
{
	ll t=0,f=1;char c=getchar();
	while(c<'0'||c>'9')	{if(c=='-')	f=-1;c=getchar();}
	while(c>='0'&&c<='9')	t=t*10+c-48,c=getchar();
	return t*f;
}
map<vector<int>,int> hav;
bool mp[2000001];
int n,deg[2000001],ans,x,y;
map<int,int> jy[200001];
int f[2000001],nxt[2000001],poi[2000001],cnt,tot;
inline void add(int x,int y){poi[++cnt]=y;nxt[cnt]=f[x];f[x]=cnt;}
inline int dfs(int x,int fa)
{
	if(jy[x][fa])	return jy[x][fa];	
	vector<int> tmp;
	for(int i=f[x];i;i=nxt[i])
	{
		if(poi[i]==fa)	continue;
		tmp.push_back(dfs(poi[i],x));
	}
	sort(tmp.begin(),tmp.end());
	if(!hav[tmp])	hav[tmp]=++tot;
	return jy[x][fa]=hav[tmp];
}
int main()
{
	scanf("%d",&n);
	For(i,1,n-1)
	{
		scanf("%d%d",&x,&y);
		add(x,y);add(y,x);
		deg[x]++;deg[y]++;
	}
	For(i,1,n)	if(deg[i]<4)	mp[dfs(i,0)]=1;
	For(i,1,tot)	if(mp[i])	ans++;
	printf("%d\n",ans);
}