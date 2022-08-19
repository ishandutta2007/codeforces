#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <set>
#define maxn 100005
#define ll long long
using namespace std;
struct edge
{
	ll u, v;
	edge *next;
}pool[maxn << 3], *h[maxn];
ll cnt = 0;
void addedge(ll u, ll v)
{
	edge *new1 = &pool[cnt++];
	new1->u = u, new1->v = v, new1->next = h[u], h[u] = new1;
}
ll fr[maxn], dp[2][maxn], dep[maxn], mxdep[maxn], mxdis[maxn];
ll mx = 0, mpl = 0;
void dfs(ll a, ll fa)
{
	mxdep[a] = dep[a], dp[0][a] = dp[1][a] = 0;
	if(dep[a] > mx) mx = dep[a], mpl = a;
	for(edge *p = h[a]; p; p = p->next)
	{
		if(p->v == fa) continue;
		dep[p->v] = dep[a] + 1, dfs(p->v, a);
		mxdep[a] = max(mxdep[a], mxdep[p->v]);
		if(mxdep[p->v] >= mxdep[dp[0][a]]) dp[1][a] = dp[0][a], dp[0][a] = p->v;
		else if(mxdep[p->v] > mxdep[dp[1][a]]) dp[1][a] = p->v; 
	}

}
void frdfs(ll a, ll fa)
{
	if(fa) 
	{
		fr[a] = fr[fa] + 1;
		if(dp[0][fa] == a) fr[a] = max(fr[a], 1 + mxdep[dp[1][fa]] - dep[fa]);
		else fr[a] = max(fr[a], 1 + mxdep[dp[0][fa]] - dep[fa]);
	}
	else fr[a] = 0;	
	mxdis[a] = max(fr[a], mxdep[dp[0][a]] - dep[a]);
	for(edge *p = h[a]; p; p = p->next)
		if(p->v != fa) frdfs(p->v, a);
}
struct q
{
	ll a, b;
	double ans;
	bool operator < (const q &x)const
	{
		if(a != x.a) return a < x.a;
		return b < x.b;
	}
};
set <q> ans;
ll bl[maxn];
ll num[maxn];
ll sum[maxn];
ll nmcnt = 0;
struct tree
{
	edge *th;
	ll size, len;
	ll bg, ed; 
	void push(ll u, ll fa, ll id)
	{
		size++;
		bl[u] = id;
		edge *new1 = &pool[cnt++];
		new1->v = u, new1->u = id, new1->next = th, th = new1;
		for(edge *p = h[u]; p; p = p->next)
			if(p->v == fa) continue;
			else push(p->v, u, id);
	}
	void init()
	{
		mx = mpl = fr[th->v] = 0, dep[th->v] = 1;
		dfs(th->v, 0);
		ll rt = mpl;
		fr[rt] = mx = mpl = 0, dep[rt] = 1;
		dfs(rt, 0);
		frdfs(rt, 0);
		len = mx - 1;
		bg = nmcnt; 
		for(edge *p = th; p; p = p->next)
			num[nmcnt++] = mxdis[p->v];	
		ed = nmcnt;
		sort(num + bg, num + ed);
		sum[ed - 1] = num[ed - 1];
		for(ll i = ed - 2; i >= bg; i--)
			sum[i] = sum[i + 1] + num[i];
		
	}
}t[maxn];
ll tid = 0;
int main()
{
	ll n, m, qs;
	scanf("%I64d%I64d%I64d", &n, &m, &qs);
	for(ll i = 0; i < m; i++)
	{
		ll u, v;
		scanf("%I64d%I64d", &u, &v);
		addedge(u, v), addedge(v, u);
	}
	memset(bl, -1, sizeof(bl));
	for(ll i = 1; i <= n; i++)
		if(bl[i] != -1) continue;
		else t[tid].push(i, 0, tid), tid++;
	for(ll i = 0; i < tid; i++) t[i].init();
	for(ll i = 1; i <= qs; i++)
	{
		ll a, b;
		scanf("%I64d%I64d", &a, &b);
		a = bl[a], b = bl[b];
		if(a == b) printf("-1\n");
		else 
		{
			if(a > b) 
				swap(a, b);
			q new1; 
			new1.a = a, new1.b = b, new1.ans = 0;
			set <q> :: iterator it = ans.find(new1);
			if(it != ans.end()) 
			{
				printf("%.7lf\n", (*it).ans);
				continue;
			}
			new1.ans = 0;
			ll nans = 0;
			if(t[a].size > t[b].size) swap(a, b);
			ll len = max(t[a].len, t[b].len);
			ll l = t[b].bg, r = t[b].ed - 1;
			for(ll i = t[a].bg; i < t[a].ed; i++)
			{
				l = t[b].bg;
				while(l < r)
				{
					//find the lst l where num[l] + num[i] + 1 <= len
					ll mid = (l + r) >> 1;
					if(num[mid + 1] + num[i] + 1 <= len) l = mid + 1;
					else r = mid;
				}
				if(l == t[b].bg && num[l] + num[i] + 1 > len) l--;
				if(l != t[b].ed - 1) nans += (ll)(num[i] + 1) * (ll)(t[b].ed - (l + 1)) + sum[l + 1];
				nans += (ll)len * (ll)(l - t[b].bg + 1);

			}
			new1.ans = 1.0 * nans / (t[a].size * t[b].size);
			
			ans.insert(new1);
			printf("%.7lf\n", new1.ans);
		}
	}
	return 0;
 }