#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#define ll long long
#define maxn 2000005
using namespace std;
int fa[maxn];
int gfa(int a)
{
	if(fa[a] == a) return a;
	return fa[a] = gfa(fa[a]);
}
int ns[maxn], nid[maxn]; 
char inp[maxn];
int bg[maxn];
vector<int> pls[maxn];
int ls[maxn];
int n;
int main()
{
	scanf("%d", &n);
	int len = 0;
	bg[1] = 0;
	for(int i = 0; i < maxn; i++)
		fa[i] = i;
	for(int i = 1; i <= n; i++)
	{
		scanf("%s", inp + bg[i]);
		int l = strlen(inp + bg[i]);
		ls[i] = l;
		bg[i + 1] = bg[i] + l;
		int k;
		scanf("%d", &k);
		pls[i].push_back(0);
		for(int j = 1; j <= k; j++)
		{
			int npl;
			scanf("%d", &npl);
			pls[i].push_back(npl);
			int pl = npl;
			while(pl < npl + l)
			{
				pl = gfa(pl);
				if(pl >= npl + l) break;
				ns[pl] = i, nid[pl] = j;
				fa[pl] = pl + 1;
				pl++;
			}
			len = max(len, npl + l - 1);
		}
	}
	for(int i = 1; i <= len; i++)
	{
		if(fa[i] == i) printf("a");
		else
		{
			int lpl = pls[ns[i]][nid[i]];
			int ch = i - lpl;
			printf("%c", inp[bg[ns[i]] + ch]);
		}
	}
	printf("\n");
	return 0;	
}