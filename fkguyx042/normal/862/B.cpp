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

int i,j,m,n,p,k,col[N],sz[2];

vector<int>v[N]; 

void dfs(int x)
{
		int i;
		sz[col[x]]++;
		for (i=0;i<(int)v[x].size();++i)
			if (col[v[x][i]]==-1)
			{
					col[v[x][i]]=col[x]^1;
					dfs(v[x][i]);
			}
}

int main()
{
		scanf("%d",&n);
		for (i=1;i<=n;++i) col[i]=-1;
		for (i=1;i<n;++i)
		{
				int x,y;
				scanf("%d%d",&x,&y); 
				v[x].pb(y); v[y].pb(x);
		}
		col[1]=0;
		dfs(1);
		printf("%I64d\n",1ll*sz[0]*sz[1]-(n-1)); 
}