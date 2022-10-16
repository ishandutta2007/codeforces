#include<bits/stdc++.h>
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
int n,m;
const int xx=155;
struct node
{
	int x,y,z;
	bool operator<(const node&w)const
	{
		return z<w.z;
	}
}s[xx];
bitset<xx>hang[xx];
bitset<xx>lie[xx];
struct Matrix
{
	int a[xx][xx];
	void clear()
	{
		memset(a,0,sizeof(a));
	}
	void operator*(const Matrix&w)
	{
		Matrix s;
		s.clear();
		for(int i=1;i<=n;i++)
		{
			hang[i].reset();
			for(int j=1;j<=n;j++)hang[i][j]=a[i][j];
		}
		for(int i=1;i<=n;i++)
		{
			lie[i].reset();
			for(int j=1;j<=n;j++)lie[i][j]=w.a[j][i];
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)s.a[i][j]=(hang[i]&lie[j]).any();
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)a[i][j]=s.a[i][j];
		}
	}
}ans,zy,ls;
void ksm(int x)
{
	ls=zy;
	while(x)
	{
		if(x&1)ans*ls;
		ls*ls;
		x>>=1;
	}
}
struct nod
{
	int next,to;
}e[xx];
int h[xx];
int cnt;
void add(int x,int y)
{
	cnt++;
	e[cnt].next=h[x];
	h[x]=cnt;
	e[cnt].to=y;
}
int vis[xx];
int last;
int res=2147483647;
void bfs()
{
	memset(vis,-1,sizeof(vis));
	queue<int>q;
	for(int i=1;i<=n;i++)
	{
		if(ans.a[1][i])vis[i]=last,q.push(i);
	}
	while(!q.empty())
	{
		int x=q.front();
		q.pop();
		for(int i=h[x];i;i=e[i].next)if(vis[e[i].to]==-1)vis[e[i].to]=vis[x]+1,q.push(e[i].to);
	}
	if(vis[n]!=-1)res=min(res,vis[n]);
}
int main(){
	n=read();
	m=read();
	for(int i=1;i<=m;i++)
	{
		s[i].x=read();
		s[i].y=read();
		s[i].z=read();
	}
	sort(s+1,s+m+1);
	ans.a[1][1]=1;
	for(int i=1;i<=m;i++)
	{
		ksm(s[i].z-last);
		last=s[i].z;
		add(s[i].x,s[i].y);
		zy.a[s[i].x][s[i].y]=1;
		bfs();
	}
	if(res==2147483647)puts("Impossible");
	else cout<<res<<endl;
	return 0;
}