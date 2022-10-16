#include<bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;
//char gc(){static char buf[1<<16],*s,*t;if(s==t){t=(s=buf)+fread(buf,1,1<<16,stdin);if(s==t)return EOF;}return*s++;}
int read()
{
	char c;
	int w=1;
	while((c=getchar())>'9'||c<'0')if(c=='-')w=-1;
	int ans=c-'0';
	while((c=getchar())>='0'&&c<='9')ans=(ans<<1)+(ans<<3)+c-'0';
	return ans*w;
}
int n,m;
const int xx=2e5+5;
struct node{int next,to;}e[xx<<1];
int cnt=1,h[xx];
void add(int x,int y)
{
	cnt++;
	e[cnt].next=h[x];
	h[x]=cnt;
	e[cnt].to=y;
}
int id[xx],low[xx],dfn[xx],cst,sum[xx];
char to[xx];
multiset<int>S[xx];
int num[2][xx];//0s 1t
void ins(multiset<int>&a,int id,int op,int x)//0s1t ,idset 
{
	if(a.find(x)!=a.end())num[op^1][id]--,a.erase(a.find(x));
	else a.insert(x),num[op][id]++;
}
void merge(multiset<int>&a,multiset<int>&b,int ida,int idb)
{
	num[0][ida]+=num[0][idb];num[1][ida]+=num[1][idb];
	if(a.size()<b.size())swap(a,b);
	for(auto it:b)if(a.find(it)!=a.end())num[0][ida]--,num[1][ida]--,a.erase(a.find(it));else a.insert(it);
	b.clear();
}
vector<pair<int,int> >v[xx];
int bel[xx],TT;
void dfs(int x)
{
	bel[x]=TT;
	for(int i=h[x];i;i=e[i].next)if(!bel[e[i].to])dfs(e[i].to);
}
void tj(int x,int y)
{
	dfn[x]=low[x]=++cst;
	for(int i=h[x];i;i=e[i].next)
	{
		if(!dfn[e[i].to])
		{
			tj(e[i].to,i);low[x]=min(low[x],low[e[i].to]);sum[x]+=sum[e[i].to];
			if(low[e[i].to]>dfn[x])
			{
				if(num[0][e[i].to]&&num[1][e[i].to]){puts("No"),exit(0);}
			}
			merge(S[x],S[e[i].to],x,e[i].to);
		}
		else if(i!=(y^1))low[x]=min(low[x],dfn[e[i].to]);
	}
	for(auto it:v[x])ins(S[x],x,it.second,it.first);
}
int main(){
	n=read(),m=read();
	int q=read();
	for(int i=1;i<=m;i++)
	{
		int a=read(),b=read();
		add(a,b);add(b,a);
		id[i]=cnt;
	}
	for(int i=1;i<=n;i++)if(!bel[i])TT++,dfs(i);
	for(int i=1;i<=q;i++)
	{
		int a=read(),b=read();
		if(bel[a]!=bel[b]){puts("No"),exit(0);}
		v[a].push_back(make_pair(i,0));
		v[b].push_back(make_pair(i,1));
	}
	for(int i=1;i<=n;i++)if(!dfn[i])tj(i,0);
	puts("Yes");
	return 0;
}