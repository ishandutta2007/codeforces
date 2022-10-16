#include <bits/stdc++.h>
#define ll long long
using namespace std;
int read()
{
	char c;
	int w=1;
	while((c=getchar())>'9'||c<'0')if(c=='-')w=-1;
	int ans=c-'0';
	while((c=getchar())>='0'&&c<='9')ans=(ans*10)+c-'0';
	return ans*w;
}
int n,m;
struct trie
{
	int to[4];
	int fail;
	int maxx;
}e[1000005];
char c[1000005];
int has[10005];
int cst;
void insert()
{
	int p=strlen(c+1);
	int last=0;
	for(int i=1;i<=p;i++)
	{
		if(!e[last].to[has[c[i]]])e[last].to[has[c[i]]]=++cst;
		last=e[last].to[has[c[i]]];
	}
	e[last].maxx=max(e[last].maxx,p);
}
void getfail()
{
	queue<int>q;
	for(int i=0;i<4;i++)if(e[0].to[i])q.push(e[0].to[i]);
	while(!q.empty())
	{
		int x=q.front();
		q.pop();
		for(int i=0;i<4;i++)
		{
			if(!e[x].to[i])
			{
				e[x].to[i]=e[e[x].fail].to[i];
				continue; 
			}
			e[e[x].to[i]].fail=e[e[x].fail].to[i];
			q.push(e[x].to[i]);
		}
	}
}
int vis[1000005];
void js(int x)
{
	if(!vis[e[x].fail])js(e[x].fail);
	e[x].maxx=max(e[x].maxx,e[e[x].fail].maxx);
	vis[x]=1;
}
int f[1005][1005][12];//xyz 
const int mod=1e9+9;
int main(){
	has['A']=0;
	has['T']=1;
	has['G']=2;
	has['C']=3;
	n=read();
	m=read();
	for(int i=1;i<=m;i++)
	{
		scanf("%s",c+1);
		insert();
	}
//	cout<<"qweqe"<<endl;
	getfail();
//	cout<<"qweqe"<<endl;
	vis[0]=1;
	for(int i=1;i<=cst;i++)
	{
		if(!vis[i])js(i);
	}
	f[0][0][0]=1;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<=cst;j++)
		{
			for(int k=0;k<=10;k++)
			{
				if(!f[i][j][k])continue;
				for(int s=0;s<=3;s++)
				{
					int p=k+1;
					int t=e[j].to[s];
					if(e[t].maxx>=p)p=0;
					if(p>10)continue;
					f[i+1][t][p]+=f[i][j][k];
					if(f[i+1][t][p]>=mod)f[i+1][t][p]-=mod;
				}
			}
		}
	}
	int ans=0;
	for(int i=0;i<=cst;i++)ans+=f[n][i][0],ans%=mod;
	cout<<ans<<endl;
	return 0;
}