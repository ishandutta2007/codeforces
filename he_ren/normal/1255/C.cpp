#include<cstdio>
#include<vector>
#include<set>
using namespace std;
typedef unsigned int uint;
const int MAXN = 1e5 + 5;

set<int> g[MAXN],h[MAXN];
inline void add(int u,int v)
{
	g[u].insert(v);
	h[v].insert(u);
}

int p[MAXN];

int main(void)
{
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n-2; ++i)
	{
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		add(x,i); add(y,i); add(z,i);
	}
	
	int u,v;
	for(int i=1; i<=n; ++i)
		if(g[i].size()==1){ u=i; break;}
	for(int i=n; i>=1; --i)
		if(g[i].size()==1){ v=i; break;}
	p[1]=u; p[n]=v;
	
	int l=2, r=n-1;
	while(l<r)
	{
		int i=*g[u].begin(), j=*g[v].begin();
		h[i].erase(u); h[j].erase(v);
		
		set<int>::iterator it;
		if(r-l == 2)
		{
			for(it=h[i].begin(); it!=h[i].end(); ++it)
			{
				if(g[*it].size()==2) p[l]=*it;
				if(g[*it].size()==3) p[l+1]=*it;
			}
			for(it=h[j].begin(); it!=h[j].end(); ++it)
				if(g[*it].size()==2) p[r]=*it;
			break;
		}
		if(r-l == 3)
		{
			for(it=h[i].begin(); it!=h[i].end(); ++it)
			{
				if(g[*it].size()==2) p[l]=*it;
				if(g[*it].size()==3) p[l+1]=*it;
			}
			for(it=h[j].begin(); it!=h[j].end(); ++it)
			{
				if(g[*it].size()==2) p[r]=*it;
				if(g[*it].size()==3) p[r-1]=*it;
			}
			break;
		}
		
		for(it=h[i].begin(); it!=h[i].end(); ++it)
		{
			g[*it].erase(i);
			if(g[*it].size()==1)
				u=*it;
		}
		for(it=h[j].begin(); it!=h[j].end(); ++it)
		{
			g[*it].erase(j);
			if(g[*it].size()==1)
				v=*it;
		}
		
		p[l]=u; p[r]=v;
		++l; --r;
	}
	for(int i=1; i<=n; ++i) printf("%d ",p[i]);
	putchar('\n');
	return 0;
}