// Problem: C. Black Widow
// Contest: Codeforces - Codeforces Round #366 (Div. 1)
// URL: https://codeforces.com/contest/704/problem/C
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

//And in that light,I find deliverance.
#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
using namespace std;
#define int long long
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
const int p=1e9+7;
int n,m;
int val[100003][2],col[100003];
struct node{int v,a,b,id;};
vector<node> e[100003];
int cnt,xcnt,ecnt;
int deg[100003],f[100003][2][2];
void dfs1(int x,int st)
{
	++xcnt,col[x]=cnt;
	if(x==st) f[xcnt][0][val[x][0]]=f[xcnt][1][val[x][1]]=1;
	for(auto t:e[x]) if(!col[t.v])
	{
		for(int j=0; j<2; ++j)
			for(int k=0; k<2; ++k)
				for(int l=0; l<2; ++l)
					f[xcnt+1][l][k^((j^t.a)|(l^t.b))^val[t.v][l]]=
					(f[xcnt+1][l][k^((j^t.a)|(l^t.b))^val[t.v][l]]+f[xcnt][j][k])%p;
		dfs1(t.v,st);
	 } 
	 return ;
}
void init()
{
	for(int i=1; i<=xcnt; ++i)
		for(int j=0; j<2; ++j)
			for(int k=0; k<2; ++k)
				f[i][j][k]=0;
}
int vis[2][100003],g[100003][2];
void dfs2(int x,int st,int c)
{
	++xcnt;col[x]=cnt;
	if(x==st) f[xcnt][c][val[x][c]]=1;
    for(node t:e[x]) if(!vis[c][t.id])
    {
        vis[c][t.id]=1;
        if(t.v==st)
            for(int j=0; j<2; j++)
                for(int k=0; k<2; k++)
                    g[cnt][k^((j^t.a)|(c^t.b))]=
                    (g[cnt][k^((j^t.a)|(c^t.b))]+f[xcnt][j][k])%p;
        else
		{
            for(int j=0; j<2; j++)
            	for(int k=0; k<2; k++)
                	for(int l=0; l<2; l++)
                		f[xcnt+1][l][k^((j^t.a)|(l^t.b))^val[t.v][l]]=
                  		(f[xcnt+1][l][k^((j^t.a)|(l^t.b))^val[t.v][l]]+f[xcnt][j][k])%p; 
            dfs2(t.v,st,c);
        }
    }
}
int h[100003][2];
signed main()
{
	n=read(),m=read();
	for(int i=1,k,x,y; i<=n; ++i)
	{
		k=read(),x=read();
		if(k==1)
		{
			if(x<0)
				val[-x][0]^=1;
			else
				val[x][1]^=1;
		}
		else
		{
			y=read();
			if(abs(x)==abs(y))
			{
				if(x<0&&y<0)
					val[abs(x)][0]^=1;
				else if(x>0&&y>0)
					val[abs(x)][1]^=1;
				else
				{
					val[abs(x)][0]^=1;
					val[abs(x)][1]^=1;
				}
				continue;
			}
			++ecnt;
			e[abs(x)].push_back((node){abs(y),(x<0),(y<0),ecnt});
			e[abs(y)].push_back((node){abs(x),(y<0),(x<0),ecnt});
			++deg[abs(x)];++deg[abs(y)];
		}
	}
	
	for(int i=1;i<=m;++i) if(!col[i]&&deg[i]<=1)
		++cnt,xcnt=0,dfs1(i,i),
		g[cnt][0]=(f[xcnt][0][0]+f[xcnt][1][0])%p,
		g[cnt][1]=(f[xcnt][0][1]+f[xcnt][1][1])%p,
		init();
	for(int i=1; i<=m; ++i) if(!col[i])
		++cnt,xcnt=0,dfs2(i,i,0),init(),
		xcnt=0,dfs2(i,i,1),init();
	h[0][0]=1;
	for(int i=1; i<=cnt; ++i)
		for(int j=0; j<2; ++j)
			for(int k=0; k<2; ++k)	
				h[i][j]=(h[i][j]+h[i-1][k]*g[i][j^k])%p;
	printf("%lld\n",h[cnt][1]);
	return 0;
}