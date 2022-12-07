#include<map>
#include<set>
#include<queue>
#include<stack>
#include<cmath>
#include<ctime>
#include<bitset>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<complex>
#include<iostream>
#include<algorithm>
#define LL long long
#define add_edge(u,v) nxt[++cnt]=head[u],head[u]=cnt,to[cnt]=v
#define open(x) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
char ch;bool fs;void re(int& x)
{
	while(ch=getchar(),ch<33);
	if(ch=='-')fs=1,x=0;else fs=0,x=ch-48;
	while(ch=getchar(),ch>33)x=x*10+ch-48;
	if(fs)x=-x;	
}
using namespace std;
int n,m;
bool fin;
bool use[100001];
int w[100001]; 
bool check(int i,int j)
{
	if(i+m==j)return 0;
	if(i-m==j)return 0;
	if(i%m!=1 && i-1==j)return 0;
	if(i%m && i+1==j)return 0;
	return 1;
}
void dfs(int i,int j)
{
	if(i>n)
	{
		fin=1;
		return;
	}
	int id=(i-1)*m+j;
	for(int k=max(1,id-10);k<=min(n*m,id+10);++k)
		if(!use[k])
		{
			if(i!=1 && !check(w[id-m],k))continue;
			if(j!=1 && !check(w[id-1],k))continue;
			w[id]=k;
			use[k]=1;
			dfs(i+j/m,j%m+1);
			if(fin)return;
			use[k]=0;
		}
}
int main()
{
	re(n),re(m);
	dfs(1,1);
	if(fin)
	{
		puts("YES");
		for(int i=1;i<=n;++i,puts(""))
			for(int j=1;j<=m;++j)
				printf("%d ",w[(i-1)*m+j]);
	}
	else puts("NO");
}