#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 2e5 + 5;

char s[MAXN];
int ls[MAXN], rs[MAXN], anc[MAXN], firlef[MAXN];

int dep[MAXN], dfn[MAXN], seq[MAXN], cur_dfn = 0;
void dfs_tree(int u)
{
	firlef[ls[u]] = firlef[u];
	firlef[rs[u]] = u;
	for(int v: {ls[u], u, rs[u]}) if(v)
	{
		if(v == u)
		{
			dfn[u] = ++cur_dfn;
			seq[cur_dfn] = u;
			continue;
		}
		anc[v] = u;
		dep[v] = dep[u] + 1;
		dfs_tree(v);
	}
}

int f[MAXN];

int main(void)
{
	int n,d;
	scanf("%d%d%s",&n,&d,s+1);
	for(int i=1; i<=n; ++i) scanf("%d%d",&ls[i],&rs[i]);
	
	dfs_tree(1);
	
	for(int i=1,j=1; i<=n; i=j)
	{
		while(j<=n && s[seq[i]] == s[seq[j]]) ++j;
		f[seq[i]] = j>n || s[seq[j]] < s[seq[i]]? 0: 1;
		for(int k=i+1; k<j; ++k) f[seq[k]] = f[seq[i]];
	}
	
	int has = 0;
	static int res[MAXN];
	function<void(int)> set0 = [&] (int u)
	{
		if(u == 0 || res[u] != -1) return;
		res[u] = 0;
		if(ls[u]) set0(ls[u]);
		if(rs[u]) set0(rs[u]);
	};
	function<void(int)> set1 = [&] (int u)
	{
		if(u == 0 || res[u] != -1) return;
		res[u] = 1; ++has;
		if(anc[u]) set1(anc[u]);
	};
	
	memset(res, -1, sizeof(res));
	for(int k=1; k<=n; ++k)
	{
		int u = seq[k];
		if(res[u] != -1) continue;
		if(f[u] == 0){ set0(u); continue;}
		
		int cnt = firlef[u]? dep[u] - dep[firlef[u]]: dep[u] + 1;
		if(has + cnt <= d) set1(u);
		else set0(u);
	}
	
	for(int i=1; i<=n; ++i)
	{
		int u = seq[i];
		putchar(s[u]);
		if(res[u]) putchar(s[u]);
	}
	return 0;
}