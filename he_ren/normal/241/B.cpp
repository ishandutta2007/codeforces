#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 5e4 + 5;
const int lb = 30;
const int MAXP = MAXN * lb;
const int mod = 1e9 + 7;

#define bbit(i) (1<<(i))
#define bdig(x,i) (((x)>>(i))&1)

int son[MAXP][2], siz[MAXP], pcnt = 1;
void insert(int x)
{
	int u = 1; ++siz[u];
	for(int i=lb-1; i>=0; --i)
	{
		int &v = son[u][bdig(x,i)];
		if(!v) v = ++pcnt;
		u = v; ++siz[u];
	}
}

int tmpbak[MAXN * 2][lb], *bak[MAXP], curbak = 0;
void dfs_bak(int u,int dep,int x)
{
	if(dep < 0)
	{
		bak[u] = tmpbak[curbak++];
		for(int i=0; i<lb; ++i) if(bdig(x, i))
			bak[u][i] += siz[u];
	}
	else
	{
		int l = son[u][0], r = son[u][1];
		if(l) dfs_bak(l, dep-1, x << 1);
		if(r) dfs_bak(r, dep-1, x << 1 | 1);
		
		if(l && r)
		{
			bak[u] = tmpbak[curbak++];
			for(int i=0; i<lb; ++i)
				bak[u][i] = bak[l][i] + bak[r][i];
		}
		else bak[u] = bak[l | r];
	}
}

int main(void)
{
	int n; ll m;
	scanf("%d%lld",&n,&m);
	for(int i=1; i<=n; ++i)
	{
		int x;
		scanf("%d",&x);
		insert(x);
	}
	
	dfs_bak(1, lb-1, 0);
	
	static pii p[2][MAXN];
	static int len[2];
	int now = 0; p[now][++len[now]] = {1,1};
	
	ll ans = 0;
	for(int k=lb-1; k>=0 && m>0; --k)
	{
		len[now^1] = 0;
		
		auto push = [&] (int u,int v)
		{
			if(u && v) p[now^1][++len[now^1]] = {u, v};
		};
		auto updans = [&] (int u,int v)
		{
			if(!u || !v) return;
			for(int i=0; i<=k; ++i)
				ans += ((ll)bak[u][i] * (siz[v] - bak[v][i])
					+ (ll)bak[v][i] * (siz[u] - bak[u][i])) << i;
		};
		
		ll totdif = 0;
		for(int i=1; i<=len[now]; ++i)
		{
			int u = p[now][i].first, v = p[now][i].second;
			
			totdif += (ll)siz[son[u][0]] * siz[son[v][1]];
			if(u != v) totdif += (ll)siz[son[u][1]] * siz[son[v][0]];
		}
		
		if(m > totdif)
		{
			m -= totdif;
			for(int i=1; i<=len[now]; ++i)
			{
				int u = p[now][i].first, v = p[now][i].second;
				
				updans(son[u][0], son[v][1]);
				if(u != v) updans(son[u][1], son[v][0]);
				push(son[u][0], son[v][0]); push(son[u][1], son[v][1]);
			}
		}
		else
		{
			ans += (ll)m << k;
			for(int i=1; i<=len[now]; ++i)
			{
				int u = p[now][i].first, v = p[now][i].second;
				
				push(son[u][0], son[v][1]);
				if(u != v) push(son[u][1], son[v][0]);
			}
		}
		
		now ^= 1;
	}
	
	ans %= mod;
	printf("%lld\n",ans);
	return 0;
}