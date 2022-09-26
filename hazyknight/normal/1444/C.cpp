#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll MAXN = 500005;

int n,m,k;
int c[MAXN];
int u[MAXN];
int v[MAXN];
int fa[MAXN];
int sz[MAXN];
int val[MAXN];

bool gg[MAXN];

ll ans;

map<int,vector<int> > e[MAXN];
vector<pair<int*,int> > rollback;

int getroot(int u)
{
	return u == fa[u] ? u : getroot(fa[u]);
}

int getval(int u)
{
	return u == fa[u] ? 0 : val[u] ^ getval(fa[u]);
}

void setv(int &u,int v)
{
	rollback.push_back(make_pair(&u,u));
	u = v;
}

int main()
{
	scanf("%d%d%d",&n,&m,&k);
	for (int i = 1;i <= n;i++)
		scanf("%d",&c[i]);
	ans = (ll)k * (k - 1) / 2;
	for (int i = 1;i <= n;i++)
	{
		fa[i] = i;
		sz[i] = 1;
		val[i] = 0;
	}
	for (int i = 1;i <= m;i++)
	{
		scanf("%d%d",&u[i],&v[i]);
		if (c[u[i]] == c[v[i]])
		{
			int ru = getroot(u[i]),rv = getroot(v[i]);
			if (ru != rv)
			{
				if (sz[ru] > sz[rv])
				{
					swap(u[i],v[i]);
					swap(ru,rv);
				}
				val[ru] = getval(u[i]) ^ getval(v[i]) ^ 1;
				fa[ru] = rv;
				sz[rv] += sz[ru];
			}
		}
		else if (c[u[i]] > c[v[i]])
			swap(u[i],v[i]);
	}
	int cnt = k - 1;
	for (int i = 1;i <= m;i++)
		if (c[u[i]] == c[v[i]] && !gg[c[u[i]]])
			if (getval(u[i]) ^ getval(v[i]) ^ 1)
			{
				ans -= cnt;
				cnt--;
				gg[c[u[i]]] = 1;
			}
	for (int i = 1;i <= m;i++)
		if (c[u[i]] != c[v[i]] && !gg[c[u[i]]] && !gg[c[v[i]]])
			e[c[u[i]]][c[v[i]]].push_back(i);
	for (int i = 1;i <= m;i++)
		if (c[u[i]] != c[v[i]] && !gg[c[u[i]]] && !gg[c[v[i]]] && e[c[u[i]]][c[v[i]]].size())
		{
			vector<int> &cur = e[c[u[i]]][c[v[i]]];
			bool ok = 1;
			for (int j = 0;j < cur.size();j++)
			{
				int t = cur[j];
				int ru = getroot(u[t]),rv = getroot(v[t]);
				if (ru == rv)
				{
					if (getval(u[t]) == getval(v[t]))
					{
						ok = 0;
						break;
					}
				}
				else
				{
					if (sz[u[t]] > sz[v[t]])
					{
						swap(u[t],v[t]);
						swap(ru,rv);
					}
					setv(val[ru],getval(u[t]) ^ getval(v[t]) ^ 1);
					setv(fa[ru],rv);
					setv(sz[rv],sz[rv] + sz[ru]);
				}
			}
			cur.clear();
			if (!ok)
				ans--;
			while (rollback.size())
			{
				*rollback.back().first = rollback.back().second;
				rollback.pop_back();
			}
		}
	printf("%lld\n",ans);
	return 0;
}