#include<bits/stdc++.h>
#define y0 y000
#define y1 y111
#define y2 y222
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXP = 2e4 * 10 * 2 + 5;

vector<int> g[MAXP];

int dfn[MAXP], low[MAXP], curdfn;
int clr[MAXP], ccnt = 0;
void tarjan(int u)
{
	static stack<int> sta;
	static bool insta[MAXP];
	dfn[u] = low[u] = ++curdfn;
	sta.push(u); insta[u] = 1;
	for(int v: g[u])
	{
		if(!dfn[v]) tarjan(v), low[u] = min(low[u], low[v]);
		else if(insta[v]) low[u] = min(low[u], dfn[v]);
	}
	if(dfn[u] == low[u])
	{
		++ccnt;
		int v; do
		{
			v = sta.top(); sta.pop();
			insta[v] = 0; clr[v] = ccnt;
		}while(v != u);
	}
}

void solve(void)
{
	int n,m,d;
	scanf("%d%d%d",&n,&m,&d);
	
	int pcnt = n * d * 2;
	for(int i=1; i<=pcnt; ++i) g[i].clear();
	
	auto inco = [&] (int x,int y,int z)
	{
		return ((x-1) * d + (y-1)) * 2 + z + 1;
	};
	auto getoth = [&] (int u)
	{
		return u&1? u+1: u-1;
	};
	auto addthen = [&] (int u,int v)
	{
		g[u].emplace_back(v);
		g[getoth(v)].emplace_back(getoth(u));
	};
	auto addfob = [&] (int u)
	{
		g[u].emplace_back(getoth(u));
	};
	
	for(int i=1; i<=n; ++i)
	{
		addfob(inco(i,d,0));
		for(int j=1; j<=d; ++j)
		{
			if(j+1<=d) addthen(inco(i,j,1), inco(i,j+1,1));
			if(i-1>=1) addthen(inco(i,j,1), inco(i-1,j,1));
		}
	}
	
	while(m--)
	{
		int type;
		scanf("%d",&type);
		if(type == 1)
		{
			int i,x;
			scanf("%d%d",&i,&x);
			if(x == 1) addfob(inco(i,x,1));
			else addthen(inco(i,x,1), inco(i,x-1,1));
		}
		else if(type == 2)
		{
			int i,j,x;
			scanf("%d%d%d",&i,&j,&x);
			for(int T=1; T<=2; ++T, swap(i,j))
			{
				for(int k=1; k<d; ++k)// a[i] > k
				{
					int kk = x-k-1;// a[j] <= kk
					if(kk < 1)
						addfob(inco(i,k,0));
					else if(kk <= d)
						addthen(inco(i,k,0), inco(j,kk,1));
				}
			}
		}
		else if(type == 3)
		{
			int i,j,x;
			scanf("%d%d%d",&i,&j,&x);
			for(int T=1; T<=2; ++T, swap(i,j))
			{
				for(int k=1; k<=d; ++k)// a[i] <= k
				{
					int kk = x-k-1;// a[j] > kk
					if(kk >= d)
						addfob(inco(i,k,1));
					else if(kk >= 1)
						addthen(inco(i,k,1), inco(j,kk,0));
				}
			}
		}
	}
	
	curdfn = ccnt = 0;
	for(int i=1; i<=pcnt; ++i) dfn[i] = low[i] = clr[i] = 0;
	for(int i=1; i<=pcnt; ++i) if(!dfn[i])
		tarjan(i);
	
	for(int i=1; i<=pcnt; i+=2)
		if(clr[i] == clr[i+1])
		{
			printf("-1\n");
			return;
		}
	
	for(int i=1; i<=n; ++i)
	{
		for(int j=1; j<=d; ++j)
			if(clr[inco(i,j,1)] < clr[inco(i,j,0)])
			{
				printf("%d ",j);
				break;
			}
	}
	printf("\n");
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}