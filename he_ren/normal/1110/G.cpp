#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 1e6 + 5;

inline void memset0(int a[],int n){ memset(a,0,(n+1)<<2);}

struct Edge
{
	int next,to;
}e[MAXN<<1];
int head[MAXN],etot=0, deg[MAXN];
inline void add(int u,int v)
{
	e[++etot] = (Edge){ head[u],v};
	head[u] = etot;
	++deg[v];
}
inline void add_edge(int u,int v){ add(u,v); add(v,u);}

char s[MAXN];

#define Win { printf("White\n"); return;}
#define Tie { printf("Draw\n"); return;}

void solve(void)
{
	int n;
	scanf("%d",&n);
	etot = 0;
	memset0(head, n * 2); memset0(deg, n * 2);
	for(int i=1; i<n; ++i)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		add_edge(u,v);
	}
	scanf("%s",s+1);
	
	int odn = n;
	for(int i=1; i<=odn; ++i)
		if(s[i] == 'W')
			add_edge(i, ++n), deg[n] += 2;
	
	for(int u=1; u<=odn; ++u)
	{
		if(deg[u] >= 4) Win;
		if(deg[u] < 3) continue;
		
		int cnt = 0;
		for(int i=head[u]; i; i=e[i].next)
			if(deg[e[i].to] >= 2)
				++cnt;
		if(cnt >= 2) Win;
	}
	
	int t = count(deg+1, deg+n+1, 3);
	if(t >= 2 && (n - 2) % 2){ Win;}
	else{ Tie;}
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}