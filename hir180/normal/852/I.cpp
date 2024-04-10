#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
#define LOG 20
#define SIZE 100000
ll now[100000][2];
vector<int>pat[100000];
int par[LOG][SIZE];
#define B 500
#define NB 500
int pal[100000], dat[100000];
ll ret = 0;
ll ans[100000];
int ord[200000],palo[200000];
int ordpt = 0;
int tos[100000];
bool flag[100000];
int dep[100000];
void dfs(int node, int d)
{
	if (flag[node])return;
	flag[node] = true;
	ord[ordpt] = node, palo[ordpt] = 1;
	ordpt++;
	dep[node] = d;
	tos[node] = ordpt;
	for (int i = 0; i < pat[node].size(); i++)
	{
		if (!flag[pat[node][i]])
		{
			dfs(pat[node][i], d + 1);
			par[0][pat[node][i]] = node;
		}
	}
	ord[ordpt] = node, palo[ordpt] = -1;
	ordpt++;	
}
void lcainit(int num)
{
	for (int i = 1; i < LOG; i++)
	{
		for (int j = 0; j < num; j++)
		{
			par[i][j] = par[i - 1][par[i - 1][j]];
		}
	}
}
int lca(int a, int b)
{
	if (dep[a] > dep[b])swap(a, b);
	int maxi = 0;
	for (int i = LOG - 1; i >= 0; i--)
	{
		if (dep[a] + (1 << i) <= dep[b])
		{
			b = par[i][b];
		}
	}
	if (a == b)return a;
	for (int i = LOG - 1; i >= 0; i--)
	{
		if (par[i][a] != par[i][b])
		{
			a = par[i][a];
			b = par[i][b];
		}
	}
	return par[0][a];
}
typedef pair<int, int>pii;
typedef pair<pii, int>pi3;
vector<pi3>bag[NB];
void add(int a, int b)
{
	ret -= now[dat[a]][0] * now[dat[a]][1];
	now[dat[a]][pal[a]] += b;
	flag[a] = flag[a] ^ 1;
	ret += now[dat[a]][0] * now[dat[a]][1];
}
int main()
{
	int num;
	scanf("%d", &num);
	vector<int>zv;
	for (int i = 0; i < num; i++)scanf("%d", &pal[i]);
	for (int i = 0; i < num; i++)scanf("%d", &dat[i]), zv.push_back(dat[i]);
	sort(zv.begin(), zv.end());
	for (int i = 0; i < num; i++)dat[i] = lower_bound(zv.begin(), zv.end(), dat[i]) - zv.begin();
	for (int i = 0; i < num - 1; i++)
	{
		int za, zb;
		scanf("%d%d", &za, &zb);
		za--, zb--;
		pat[za].push_back(zb);
		pat[zb].push_back(za);
	}
	dfs(0, 0);
	lcainit(num);
	//for (int i = 0; i < num + num; i++)printf("%d %d\n", ord[i], palo[i]);
	int query;
	scanf("%d", &query);
	for (int p = 0; p < query; p++)
	{
		int za, zb;
		scanf("%d%d", &za, &zb);
		za--, zb--;
		bag[min(tos[za], tos[zb]) / B].push_back(make_pair(make_pair(max(tos[za], tos[zb]) - 1, min(tos[za], tos[zb])),p));
	}
	for (int i = 0; i < NB; i++)
	{
		sort(bag[i].begin(), bag[i].end());
		int lb = i*B, ub = i*B - 1;
		for (int j = 0; j < num; j++)now[j][0] = now[j][1] = 0;
		ret = 0;
		fill(flag, flag + num, false);
		for (int j = 0; j < bag[i].size(); j++)
		{
			int s = bag[i][j].first.second, t = bag[i][j].first.first;
			//printf("%d %d\n", s, t);
			for (;;)
			{
				if (ub == t)break;
				if (!flag[ord[ub + 1]])add(ord[ub + 1], 1);
				else add(ord[ub + 1], -1);
				ub++;
			}
			if (s < lb)
			{
				for (;;)
				{
					if (s == lb)break;
					if (!flag[ord[lb - 1]])add(ord[lb - 1], 1);
					else add(ord[lb - 1], -1);
					lb--;
				}
			}
			else
			{
				for (;;)
				{
					if (s == lb)break;
					if (!flag[ord[lb]])add(ord[lb], 1);
					else add(ord[lb], -1);
					lb++;
				}
			}
			int l = lca(ord[s - 1], ord[t]);
			ll pl = -now[dat[l]][0] * now[dat[l]][1];
			now[dat[l]][pal[l]]++;
			pl += now[dat[l]][0] * now[dat[l]][1];
			ans[bag[i][j].second] = ret + pl;
			now[dat[l]][pal[l]]--;
		}
	}
	for (int i = 0; i < query; i++)printf("%I64d\n", ans[i]);
}