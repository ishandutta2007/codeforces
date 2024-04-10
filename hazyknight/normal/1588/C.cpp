#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAXN = 300005;

int T,n;

ll ans;
ll a[MAXN];
ll b[MAXN];
ll MAX[MAXN << 2];
ll MIN[MAXN << 2];

vector<pair<ll,int> > q[MAXN];
map<ll,int> cnt;

void buildtree(int o,int l,int r)
{
	if (l == r)
	{
		MIN[o] = 1e18;
		MAX[o] = -1e18;
		if (l & 1)
			MAX[o] = b[l];
		else
			MIN[o] = b[l];
		return;
	}
	int mid = l + r >> 1;
	buildtree(o << 1,l,mid);
	buildtree(o << 1 | 1,mid + 1,r);
	MAX[o] = max(MAX[o << 1],MAX[o << 1 | 1]);
	MIN[o] = min(MIN[o << 1],MIN[o << 1 | 1]);
}

int query(int o,int l,int r,int p,ll v)
{
	if (l >= p)
	{
		if (MIN[o] >= v && MAX[o] <= v)
			return r;
		if (l == r)
			return r - 1;
		int mid = l + r >> 1;
		int ret = query(o << 1,l,mid,p,v);
		if (ret == mid)
			return query(o << 1 | 1,mid + 1,r,p,v);
		return ret;
	}
	int mid = l + r >> 1;
	if (mid < p)
		return query(o << 1 | 1,mid + 1,r,p,v);
	int ret = query(o << 1,l,mid,p,v);
	if (ret == mid)
		return query(o << 1 | 1,mid + 1,r,p,v);
	return ret;
}

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d",&n);
		for (int i = 1;i <= n;i++)
			scanf("%lld",&a[i]);
		for (int i = 1;i <= n;i++)
			q[i].clear();
		cnt.clear();
		ans = 0;
		for (int i = 1;i <= n;i++)
			b[i] = b[i - 1] + ((i & 1) ? -a[i] : a[i]);
		buildtree(1,1,n);
		for (int i = 1;i <= n;i++)
		{
			int r = query(1,1,n,i,b[i - 1]);
			q[r].push_back(make_pair(b[i - 1],1));
			q[i - 1].push_back(make_pair(b[i - 1],-1));
		}
		for (int i = 1;i <= n;i++)
		{
			cnt[b[i]]++;
			for (int j = 0;j < q[i].size();j++)
				ans += q[i][j].second * cnt[q[i][j].first];
		}
		printf("%lld\n",ans);
	}
	return 0;
}