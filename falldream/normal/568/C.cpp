#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
#define MN 400
#define mod 1000000007
using namespace std;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
pair<int,int> rule[MN*MN+5];
vector<int> v[MN+5],V[MN+5];
int vis[MN+5],n,L,m,q[MN+5],top,mark[MN+5],yes1=0,yes2=0,Vis[MN+5],num;
char res[MN+5],st[MN+5],vc[MN+5],a1[20],a2[20];
inline int Rev(int x){return x>n?x-n:x+n;}
inline void ins(int f,int t)
{
	v[f].push_back(t);
	V[t].push_back(f);	
	v[Rev(t)].push_back(Rev(f));
	V[Rev(f)].push_back(Rev(t));
}
void dfs(int x)
{
	vis[x]=1;
	for(int i=0;i<v[x].size();++i)
		if(!vis[v[x][i]]) dfs(v[x][i]);
	q[++top]=x;
}
void rdfs(int x)
{
	vis[x]=1;mark[x]=num;
	for(int i=0;i<V[x].size();++i)
		if(!vis[V[x][i]]) rdfs(V[x][i]);	
}
bool Solve(int p)
{
	top=num=0;
	for(int i=1;i<=n<<1;++i) v[i].clear(),V[i].clear(),vis[i]=mark[i]=0;
	for(int i=1;i<=p;++i)
	{
		if(vc[res[i]-'a'+1]=='V') ins(i+n,i);
		else ins(i,i+n);
	}
	for(int i=p+1;i<=n;++i)
	{
		if(!yes1) ins(i,i+n);
		if(!yes2) ins(i+n,i);	
	}
	for(int i=1;i<=m;++i) ins(rule[i].first,rule[i].second);
	for(int i=1;i<=n<<1;++i) if(!vis[i]) dfs(i);
	memset(vis,0,sizeof(vis));
	for(int i=top;i;--i) if(!vis[q[i]]) ++num,rdfs(q[i]);
	for(int i=1;i<=n;++i) if(mark[i]==mark[i+n]) return false;
	return true;
}

int main()
{
	scanf("%s",vc+1);L=strlen(vc+1);
	for(int i=1;i<=L;++i) yes1|=vc[i]=='V',yes2|=vc[i]=='C';
	n=read();m=read();
	for(int i=1;i<=m;++i)
	{
		int x=read();scanf("%s",a1+1);	
		int y=read();scanf("%s",a2+1);
		x=x+n*(a1[1]=='C');
		y=y+n*(a2[1]=='C');
		rule[i]=make_pair(x,y); 
	}
	scanf("%s",st+1);
	for(int i=1;i<=n;++i) res[i]=st[i];
	if(Solve(n)) return 0*printf("%s",res+1);
	for(int i=n;i;--i) 
		for(int j=st[i]-'a'+2;j<=L;++j) if(Vis[vc[j]]!=i)
		{
			Vis[vc[j]]=i;res[i]=j+'a'-1;
			if(Solve(i)) 
			{
				for(int j=i+1;j<=n;++j)
				{
					res[j]='a';
					if(!Solve(j))
						while(vc[res[j]-'a'+1]==vc[1]) ++res[j];
				}
				printf("%s",res+1);
				return 0;	
			}
		}
	puts("-1");
	return 0;
}