#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 2e5 + 10;

struct Segment_Tree
{
	int sum[MAXN<<2];
	pii mn[MAXN<<2];
	#define ls(u) ((u)<<1)
	#define rs(u) ((u)<<1|1)
	#define lson(u) ls(u),l,mid
	#define rson(u) rs(u),mid+1,r
	inline void push_up(int u)
	{
		sum[u] = sum[ls(u)] + sum[rs(u)];
		pii t = mn[rs(u)]; t.first += sum[ls(u)];
		mn[u] = min(mn[ls(u)], t);
	}
	void set(int u,int l,int r,int q,int k)
	{
		if(l == r){ sum[u] = k; mn[u] = {k,l}; return;}
		int mid = (l+r)>>1;
		if(q<=mid) set(lson(u),q,k);
		else set(rson(u),q,k);
		push_up(u);
	}
	int getsum(int u,int l,int r,int ql,int qr)
	{
		if(ql<=l && r<=qr) return sum[u];
		int mid = (l+r)>>1;
		if(ql<=mid && mid<qr)
			return getsum(lson(u),ql,qr) + getsum(rson(u),ql,qr);
		else
			return ql<=mid? getsum(lson(u),ql,qr): getsum(rson(u),ql,qr);
	}
	
	int n;
	void set(int q,int k){ set(1,0,n,q,k);}
	int getsum(int ql,int qr){ return getsum(1,0,n,ql,qr);}
}tree;

int p[MAXN];

int main(void)
{
	int n,Q;
	scanf("%d%d",&n,&Q);
	for(int i=1; i<=2*n+1; ++i) scanf("%d",&p[i]);
	
	auto getval = [&] (int u)
	{
		return u < n+1? -1: u == n+1? 0: 1;
	};
	
	static int pos[MAXN];
	ll suml = 0, sumr = 0;
	auto calc = [&] (int u,int ml,int mr) -> int
	{
		int l = u-1, r = u+1;
		if(l < ml) l += n+1;
		if(r > mr) r -= n+1;
		
		auto trim = [&] (int t)
		{
			return t >= 0? t: t + 2*n+1;
		};
		return trim(pos[u] - pos[l]) + trim(pos[r] - pos[u]);
	};
	auto upd = [&] (int u,int k)
	{
		if(u <= n+1) suml -= calc(u, 1,n+1);
		if(u >= n+1) sumr -= calc(u, n+1,2*n+1);
		p[k] = u; pos[u] = k;
		tree.set(k, getval(u));
		if(u <= n+1) suml += calc(u, 1,n+1);
		if(u >= n+1) sumr += calc(u, n+1,2*n+1);
	};
	
	tree.n = 2*n+1;
	for(int i=1; i<=2*n+1; ++i)
	{
		upd(p[i], i);
		tree.set(i, getval(p[i]));
	}
	
	while(Q--)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		int px = p[x], py = p[y];
		upd(px, y); upd(py, x);
		
		int k = tree.mn[1].second;
		int cursum = pos[n+1] <= k? tree.getsum(pos[n+1], k): tree.getsum(k+1, pos[n+1]);
		if(cursum != 0)
		{
			printf("%d\n",k);
		}
		else if(suml != 2*n+1)
		{
			printf("%d\n",pos[n+1] == 2*n+1? 0: pos[n+1]);
		}
		else if(sumr != 2*n+1)
		{
			printf("%d\n",pos[n+1]-1);
		}
		else
		{
			printf("-1\n");
		}
	}
	return 0;
}