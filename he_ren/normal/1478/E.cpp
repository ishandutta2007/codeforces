#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 2e5 + 5;
const int MAXQ = 2e5 + 5;

struct Segment_Tree
{
	int sum[MAXN<<2], tag[MAXN<<2];
	#define ls(u) ((u)<<1)
	#define rs(u) ((u)<<1|1)
	#define lson(u) ls(u),l,mid
	#define rson(u) rs(u),mid+1,r
	inline void push_up(int u){ sum[u] = sum[ls(u)] + sum[rs(u)];}
	inline void push_down(int u,int l,int r)
	{
		if(~tag[u])
		{
			int mid = (l+r)>>1;
			tag[ls(u)] = tag[u]; sum[ls(u)] = tag[u] * (mid-l+1);
			tag[rs(u)] = tag[u]; sum[rs(u)] = tag[u] * (r-mid);
			tag[u] = -1;
		}
	}
	void update(int u,int l,int r,int ql,int qr,int k)
	{
		if(ql<=l && r<=qr){ tag[u] = k; sum[u] = k * (r-l+1); return;}
		push_down(u,l,r);
		int mid = (l+r)>>1;
		if(ql<=mid) update(lson(u),ql,qr,k);
		if(mid<qr) update(rson(u),ql,qr,k);
		push_up(u);
	}
	int query(int u,int l,int r,int ql,int qr)
	{
		if(ql<=l && r<=qr) return sum[u];
		push_down(u,l,r);
		int mid = (l+r)>>1, res = 0;
		if(ql<=mid) res += query(lson(u),ql,qr);
		if(mid<qr) res += query(rson(u),ql,qr);
		return res;
	}
}tree;

char s[MAXN], t[MAXN];
pii p[MAXQ];

void solve(void)
{
	int n,Q;
	scanf("%d%d%s%s",&n,&Q,s+1,t+1);
	for(int i=1; i<=Q; ++i) scanf("%d%d",&p[i].first,&p[i].second);
	
	for(int i=1; i<=n; ++i) tree.update(1,1,n, i,i, t[i] - '0');
	for(int k=Q; k>=1; --k)
	{
		int l = p[k].first, r = p[k].second;
		int num1 = tree.query(1,1,n, l,r), num0 = r-l+1 - num1;
		if(num0 == num1){ printf("NO\n"); return;}
		
		if(num0 < num1) tree.update(1,1,n, l,r, 1);
		else tree.update(1,1,n, l,r, 0);
	}
	
	for(int i=1; i<=n; ++i)
		if(tree.query(1,1,n, i,i) != s[i] - '0'){ printf("NO\n"); return;}
	printf("YES\n");
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}