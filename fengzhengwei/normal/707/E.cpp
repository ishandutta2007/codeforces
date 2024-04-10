#include<bits/stdc++.h>
#define ll long long
using namespace std;
int read()
{
	char c;
	int w=1;
	while((c=getchar())>'9'||c<'0')if(c=='-')w=-1;
	int ans=c-'0';
	while((c=getchar())>='0'&&c<='9')ans=(ans<<1)+(ans<<3)+c-'0';
	return ans*w;
}
int n,m,k;
vector<pair<int,int> >v[10005];
int val[2005][2005];
char c[20];
int op[2005];
ll ans[2005];
int res[2005][2005];
struct qy
{
	int a,b,c,d;
}e[2005];
ll sum[2005][2005];
int lb(int x)
{
	return x&(-x);
}
void add(int x,int y,int z)
{
	for(;x<=n;x+=lb(x))
		for(int o=y;o<=m;o+=lb(o))sum[x][o]+=z;
}
ll ask(int x,int y)
{
	ll ans=0;
	for(;x;x-=lb(x))
		for(int o=y;o;o-=lb(o))ans+=sum[x][o];
	return ans;
}
ll ask(int a,int b,int c,int d)
{
	return ask(c,d)+ask(a-1,b-1)-ask(a-1,d)-ask(c,b-1);
}
int main(){
	n=read();
	m=read();
	k=read();
	for(int i=1;i<=k;i++)
	{
		op[i]=1;
		int t=read();
		for(int j=1;j<=t;j++)
		{
			int x,y;
			x=read();
			y=read();
			v[i].push_back(make_pair(x,y));
			val[x][y]=read();
		}
	}
	int q=read();
	int tot=0;
	while(q--)
	{
		scanf("%s",c);
		if(c[0]=='S')
		{
			int a=read();
			op[a]^=1;
		}
		else 
		{
			++tot;
			e[tot].a=read();
			e[tot].b=read();
			e[tot].c=read();
			e[tot].d=read();
			for(int j=1;j<=k;j++)res[tot][j]=op[j];
		}
	}
	for(int i=1;i<=k;i++)
	{
		for(int j=0;j<v[i].size();j++)add(v[i][j].first,v[i][j].second,val[v[i][j].first][v[i][j].second]);
		for(int j=1;j<=tot;j++)
		{
			if(res[j][i])ans[j]+=ask(e[j].a,e[j].b,e[j].c,e[j].d);
		}
		for(int j=0;j<v[i].size();j++)add(v[i][j].first,v[i][j].second,-val[v[i][j].first][v[i][j].second]);
	}
	for(int j=1;j<=tot;j++)cout<<ans[j]<<"\n";
	return 0;
}