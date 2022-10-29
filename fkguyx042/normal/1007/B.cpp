#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#include<cstring>
#include<string>
#include<cmath>
#include<ctime>
#include<set>
#include<vector>
#include<map>
#include<queue>

#define N 300005
#define M 8000005

#define ls (t<<1)
#define rs ((t<<1)|1)
#define mid ((l+r)>>1)

#define mk make_pair
#define pb push_back
#define fi first
#define se second

using namespace std;

int i,j,m,n,p,k,c[8],g[8],A[5],f[8],cnt;

struct Node{
		int a[3],b[3];
}type[N];

void check()
{
		int i,j,k;
		memset(f,0,sizeof(f));
		memset(g,0,sizeof(g));
		f[0]=1; 
		for (i=1;i<=3;++i)
		{
			for (j=0;j<8;++j) g[j]=f[j];
			for (j=0;j<3;++j)
				if (A[i]&(1<<j))
				{
						for (k=0;k<8;++k)
							g[k|(1<<j)]|=f[k];		
				}
			for (j=0;j<8;++j) f[j]=g[j];
		} 
		if (f[7])
		{
				++cnt;
				memset(g,0,sizeof(g));
				for(i=1;i<=3;++i) g[A[i]]++;
				int tot=0;
				for(i=1;i<8;++i) if (g[i]) type[cnt].a[tot]=i,type[cnt].b[tot]=g[i],++tot;
		}
}

void dfs(int x,int y)
{
		if (y>4) return;
		if (x>7)
		{
				if (y==4) check();
		}
		else
		{
				A[y]=x;
				dfs(x,y+1);
				dfs(x+1,y);
		}
}

vector<int>v[100005];

void pre()
{	
		dfs(1,1);
		for (i=1;i<=100000;++i)
			for (j=i;j<=100000;j+=i) v[j].pb(i);
}

int t[1005],R[3];

long long ww[8];

long long Count(long long x,int y)
{
		if (y==1) return x;
		if (y==2) return x*(x+1)/2;
		if (y==3) return x*(x-1)*(x-2)/6+x*(x-1)+x;
}

int main()
{
		pre(); int T;
		scanf("%d",&T);
		for (;T--;)
		{
				long long ans=0;
				scanf("%d%d%d",&R[0],&R[1],&R[2]);
				t[0]=0;
				for (i=0;i<3;++i) 
				{
						for (j=0;j<(int)v[R[i]].size();++j) t[++t[0]]=v[R[i]][j];
				}
				sort(t+1,t+t[0]+1);
				t[0]=unique(t+1,t+t[0]+1)-(t+1);
				memset(ww,0,sizeof(ww));
				for (i=1;i<=t[0];++i)
				{
						int w=0;
						for (j=0;j<3;++j) if (R[j]%t[i]==0) w|=(1<<j);
						ww[w]++;
				}
				for (i=1;i<=cnt;++i)
				{
						long long s=1;
						for (j=0;j<3;++j) if (type[i].b[j]) s*=Count(ww[type[i].a[j]],type[i].b[j]);
						ans+=s;
				}
				printf("%I64d\n",ans);
		}
}