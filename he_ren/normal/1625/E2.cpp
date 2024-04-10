#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 3e5 + 5;

struct BIT
{
	vector<ll> tree;
	#define lowbit(x) ((x)&-(x))
	inline void init(int n){ tree.resize(n+1);}
	inline void update(int x,ll k)
	{
		while(x<(int)tree.size())
			tree[x] += k,
			x += lowbit(x);
	}
	inline ll query(int x)
	{
		ll res = 0;
		while(x)
			res += tree[x],
			x ^= lowbit(x);
		return res;
	}
	inline ll query(int l,int r){ return query(r) - query(l-1);}
};

char s[MAXN];
int to[MAXN], dep[MAXN], idx[MAXN];
int anc[MAXN];

inline ll calc(ll len){ return len * (len + 1) / 2;}

vector<int> pt[MAXN];
BIT cnt[MAXN], sumf;

inline ll get(int k,int l,int r)
{
	return calc(cnt[k].query(l, r));
}

int main(void)
{
	int n,Q;
	scanf("%d%d%s",&n,&Q,s+1);
	
	stack<int> sta;
	int mxd = 0;
	for(int i=1; i<=n; ++i) pt[i].push_back(0);
	for(int i=1; i<=n; ++i)
	{
		if(s[i] == '(') sta.push(i);
		else
		{
			if(!sta.size()) continue;
			int j = sta.top(); sta.pop();
			to[i] = j; to[j] = i;
			dep[i] = dep[j] = (int)sta.size() + 1;
			mxd = max(mxd, dep[i]);
			
			if(dep[j] != 1)
			{
				if(s[j-1] == '(') anc[i] = anc[j] = j-1;
				else anc[i] = anc[j] = anc[j-1];
			}
			
			idx[i] = idx[j] = (int)pt[dep[j]].size();
			pt[dep[j]].push_back(j);
		}
	}
	
	sumf.init(n);
	for(int k=mxd; k>=1; --k)
	{
		cnt[k].init((int)pt[k].size() - 1);
		for(int i=1; i<(int)pt[k].size(); ++i)
		{
			int l = pt[k][i], r = to[l];
			if(l+1 <= r-1)
				sumf.update(l, get(k+1, idx[l+1], idx[r-1]));
			cnt[k].update(i, 1);
		}
	}
	
	while(Q--)
	{
		int t,l,r;
		scanf("%d%d%d",&t,&l,&r);
		if(t == 2)
			printf("%lld\n",sumf.query(l,r) + get(dep[l], idx[l], idx[r]));
		else
		{
			cnt[dep[l]].update(idx[l], -1);
			int u = anc[l];
			if(!u || !dep[u]) continue;
			
			int v = to[u];
			int k = cnt[dep[u]+1].query(idx[u+1], idx[v-1]);
			sumf.update(u, -calc(k+1) + calc(k));
		}
	}
	return 0;
}