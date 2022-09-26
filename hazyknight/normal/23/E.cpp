#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <vector>

using namespace std;

struct BigNumber
{
	int n[305];
	int len;
	void memNum()
	{
		memset(n,0,sizeof(n));
		len = 0;
	}
	void fixcarry()
	{
		for (int i = 0;i < len;i++)
		{
			n[i + 1] += n[i] / 10;
			n[i] %= 10;
		}
		while (n[len] > 0)
		{
			n[len + 1] += n[len] / 10;
			n[len] %= 10;
			len++;
		}
		while (len > 0 && n[len - 1] == 0)
			len--;
		if (len == 0)
			len = 1;
	}
	BigNumber(int v = 0)
	{
		memNum();
		n[len++] = v;
		fixcarry();
	}
	BigNumber operator + (const BigNumber & p)const
	{
		BigNumber ret;
		ret.len = max(len,p.len);
		for (int i = 0;i < ret.len;i++)
			ret.n[i] = n[i] + p.n[i];
		ret.fixcarry();
		return ret;
	}
	BigNumber operator * (const BigNumber & p)const
	{
		BigNumber ret;
		ret.len = len + p.len - 1;
		for (int i = 0;i < len;i++)
			for (int j = 0;j < p.len;j++)
				ret.n[i + j] += n[i] * p.n[j];
		ret.fixcarry();
		return ret;
	}
	void output()
	{
		for (int i = len - 1;i >= 0;i--)
			cout << n[i];
		cout << endl;
	}
	bool operator < (const BigNumber & p)const
	{
		if (len == p.len)
		{
			for (int i = len - 1;i >= 0;i--)
				if (n[i] != p.n[i])
					return n[i] < p.n[i];
			return false;
		}
		return len < p.len;
	}
	bool operator > (const BigNumber & p)const
	{
		if (len == p.len)
		{
			for (int i = len - 1;i >= 0;i--)
				if (n[i] != p.n[i])
					return n[i] > p.n[i];
			return false;
		}
		return len > p.len;
	}
};

typedef BigNumber ll;

const int MAXN = 705;

int n,id;
int size[MAXN];
int cnt[MAXN];

ll res,tmp,MAX;
ll f[MAXN];
ll g[MAXN];
ll h[MAXN];
ll pre[MAXN];
ll suf[MAXN];
ll dp[MAXN];
ll t[MAXN];

vector<int> edge[MAXN];

void addE(int u,int v)
{
	edge[u].push_back(v);
}

void dfs(int now,int fa)
{
	g[now] = ll(1);
	size[now] = cnt[now] = 1;
	for (int i = 0;i < edge[now].size();i++)
	{
		if (edge[now][i] == fa)
		{
			edge[now].erase(edge[now].begin() + i);
			i--;
		}
		else
		{
			dfs(edge[now][i],now);
			g[now] = g[now] * f[edge[now][i]];
			size[now] += size[edge[now][i]];
			cnt[now] += (size[edge[now][i]] == 1);
		}
	}
	f[now] = ll(size[now]);
	if (f[now] < (tmp = g[now] * ll(cnt[now])))
		f[now] = tmp;
	if (edge[now].size() == 0)
		return;
	dp[0] = ll(1);
	for (int i = 1;i <= edge[now].size();i++)
		dp[i] = ll(0);
	for (int i = 0;i < edge[now].size();i++)
	{
		for (int j = 0;j <= i + 1;j++)
			t[j] = dp[j];
		for (int j = 0;j <= i + 1;j++)
		{
			dp[j] = t[j] * f[edge[now][i]];
			if (j > 0 && (tmp = t[j - 1] * g[edge[now][i]]) > dp[j])
				dp[j] = tmp;
		}
	}
	for (int i = 0;i <= edge[now].size();i++)
		if ((tmp = dp[i] * ll(i + 1)) > f[now])
			f[now] = tmp;
	pre[0] = f[edge[now][0]];
	for (int i = 1;i < edge[now].size();i++)
		pre[i] = pre[i - 1] * f[edge[now][i]];
	suf[edge[now].size() - 1] = f[edge[now].back()];
	for (int i = edge[now].size() - 2;i >= 0;i--)
		suf[i] = suf[i + 1] * f[edge[now][i]];
	for (int i = 0;i < edge[now].size();i++)
	{
		if (size[edge[now][i]] == 1)
			continue;
		res = 1;
		if (i > 0)
			res = res * pre[i - 1];
		if (i < edge[now].size() - 1)
			res = res * suf[i + 1];
		MAX = g[edge[now][i]] * ll(cnt[now] + cnt[edge[now][i]]);
		if (MAX < (tmp = h[edge[now][i]] * ll(cnt[now] + cnt[edge[now][i]] + 1)))
			MAX = tmp;
		if (MAX < (tmp = ll(size[edge[now][i]] + cnt[now])))
			MAX = tmp;
		if (h[now] < (tmp = res * g[edge[now][i]]))
			h[now] = tmp;
		res = res * MAX;
		if (res > f[now])
			f[now] = res;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin >> n;
	for (int u,v,i = 1;i < n;i++)
	{
		cin >> u >> v;
		addE(u,v);
		addE(v,u);
	}
	dfs(1,0);
	f[1].output();
	return 0;
}