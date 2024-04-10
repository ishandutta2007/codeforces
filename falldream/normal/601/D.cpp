#include<iostream>
#include<cstdio>
#include<set>
#define MN 300000
using namespace std;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
int n,c[MN+5],ansnum=0,ans=0,cnt=0,head[MN+5],size[MN+5],mx[MN+5],id[MN+5],dep[MN+5];
unsigned long long ha[MN+5];
set<pair<unsigned long long,int> > s[MN+5];char st[MN+5];
struct edge{int to,next;}e[MN*2+5];

inline void ins(int f,int t)
{
	e[++cnt]=(edge){t,head[f]};head[f]=cnt;
	e[++cnt]=(edge){f,head[t]};head[t]=cnt;
}	

void Dfs(int x,int f)
{
	size[x]=1;mx[x]=0;
	for(int i=head[x];i;i=e[i].next)
		if(e[i].to!=f) 
		{
			ha[e[i].to]=(ha[x]*233333+st[e[i].to])%1000000000007LL;
			dep[e[i].to]=dep[x]+1;
			Dfs(e[i].to,x);	
			size[x]+=size[e[i].to];
			if(size[e[i].to]>size[mx[x]]) mx[x]=e[i].to;
		}
}
	
void Solve(int x,int f)
{
	if(mx[x]) Solve(mx[x],x),id[x]=id[mx[x]]; else id[x]=x;
	s[id[x]].insert(make_pair(ha[x],dep[x]));
	for(int i=head[x];i;i=e[i].next)	
		if(e[i].to!=f&&e[i].to!=mx[x]) 
		{
			Solve(e[i].to,x);	
			for(set<pair<unsigned long long,int> >::iterator it=s[id[e[i].to]].begin();it!=s[id[e[i].to]].end();++it)
				s[id[x]].insert(*it);
		}
	int res=c[x]+s[id[x]].size();
	if(res>ans) ans=res,ansnum=1;
	else if(res==ans) ++ansnum;
}

int main()
{
	n=read();
	for(int i=1;i<=n;++i) c[i]=read();
	scanf("%s",st+1);
	for(int i=1;i<n;++i) ins(read(),read());
	ha[1]=st[1];Dfs(1,0);Solve(1,0);
	printf("%d\n%d",ans,ansnum);
	return 0;
}