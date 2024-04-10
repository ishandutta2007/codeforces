#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath> 
#include <algorithm>
#include <vector>
#define maxn 30005
#define maxk 305
#define ll long long
using namespace std;
int fa[maxn];
int d[maxk][maxn];
int id[maxk];
vector <int> nx[maxn];
int n, k;
int dep[maxn];
void dfs(int a, int fa)
{
	for(int j = 0; j < nx[a].size(); j++)
	{
		int ns = nx[a][j];
		if(ns == fa) continue;
		dep[ns] = dep[a] + 1, dfs(ns, a);
	}
}
int tr[maxn];
bool check()
{
	bool flag = 1;
	for(int i = 1; i <= n; i++)
		if(fa[i]) nx[i].push_back(fa[i]), nx[fa[i]].push_back(i);
	for(int i = 1; i <= k; i++)
	{
		dep[tr[i]] = 0;
		dfs(tr[i], 0);
		for(int j = 1; j <= n; j++)
			if(dep[j] != d[i][j] || (!d[i][j] && j != tr[i])) flag = 0;
	}
	if(!flag) return 0;
	return 1;
}
int fas[maxk][maxn];
int npl[maxn];
struct th
{
	int id, dep;
	bool operator < (const th &a)const
	{
		return dep < a.dep;
	}
}p[maxn];
int nnod[maxn][2]; // 0 :  - 1 1 

bool hv[maxn];
int main()
{
	scanf("%d%d", &n, &k);
	for(int i = 1; i <= k; i++)
		for(int j = 1; j <= n; j++)
		{
			scanf("%d", &d[i][j]);
			if(!d[i][j]) tr[i] = j, hv[j] = 1;
		}
	int root = 1;
	for(int i = 2; i <= k; i++)
	{
		// build const
		for(int j = 1; j <= n; j++)
			if(d[1][j] + d[i][j] == d[1][tr[i]])
				npl[d[1][j]] = j;
		for(int j = 1; j <= d[1][tr[i]]; j++)
			fa[npl[j]] = npl[j - 1];//, cout<<"FA"<<npl[j]<<" "<<npl[j - 1]<<endl;
		for(int j = 1; j <= d[1][tr[i]]; j++)
			fas[i][j] = npl[d[1][tr[i]] - j];
		fas[i][0] = tr[i];
		
	}
//	cout<<"BUILD"<<endl;
	int ncnt = 0;
	for(int i = 1; i <= n; i++)
		if(fa[i] || i == tr[1]) continue;
		else p[ncnt].id = i, p[ncnt++].dep = d[1][i];
	sort(p, p + ncnt);
	for(int i = 0; i < ncnt; i++)
	{
	//	cout<<i<<endl;
		if(i && p[i].dep != p[i - 1].dep)
			for(int j = 1; j <= n; j++)
				nnod[j][0] = nnod[j][1], nnod[j][1] = 0; 
		int nd = p[i].dep, id = p[i].id;
		int pre = tr[1];
	//	cout<<"!!!"<<endl;
		for(int j = 2; j <= k; j++)
		{
			int dv = (d[j][id] + d[1][tr[j]] - d[1][id]) / 2;
		//	cout<<dv<<endl;
			int nfa = fas[j][(d[j][id] + d[1][tr[j]] - d[1][id]) / 2];
			if(d[1][nfa] > d[1][pre]) pre = nfa;
		}
		if(nnod[pre][0]) fa[id] = nnod[pre][0];
		else fa[id] = pre;
	//	cout<<"FA"<<id<<" "<<fa[id]<<endl;
		nnod[pre][1] = id;
	}
	if(check())
	{
		for(int i = 1; i <= n; i++)
			if(fa[i])
				printf("%d %d\n", i, fa[i]);
	}
	else
		printf("-1\n");
	return 0;
}