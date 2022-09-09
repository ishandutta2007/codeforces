#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 1e5 + 5;
const int MAXQ = 1e5 + 5;
const int MAXA = 1e5 + 5;

struct BIT
{
	int tree[MAXN], n;
	#define lowbit(x) ((x)&-(x))
	inline void update(int x,int k)
	{
		while(x<=n)
			tree[x] += k,
			x += lowbit(x);
	}
	inline int query(int x)
	{
		int res=0;
		while(x)
			res += tree[x],
			x ^= lowbit(x);
		return res;
	}
	inline int query(int l,int r){ return query(r) - query(l-1);}
}tlst, tval;

int a[MAXN];
array<int,3> qs[MAXQ];
int res[MAXQ];

int main(void)
{
	int n,Q;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
	scanf("%d",&Q);
	for(int i=1; i<=Q; ++i)
	{
		int l,r;
		scanf("%d%d",&l,&r);
		qs[i] = {r, l, i};
	}
	sort(qs+1,qs+Q+1);
	
	tlst.n = tval.n = n;
	static int lst[MAXA], pre[MAXN], val[MAXN], pos[MAXN];
	val[0] = -1;
	for(int i=1, j=1; i<=n && j<=Q; ++i)
	{
		pre[i] = lst[a[i]]; lst[a[i]] = i;
		val[i] = pre[i]? i - pre[i]: -1;
		
		if(val[pre[i]] == -1) pos[i] = 0;
		else if(val[pre[i]] != val[i]) pos[i] = pre[pre[i]];
		else pos[i] = pos[pre[i]];
		
		if(pre[i]) tlst.update(pre[i], -1);
		tlst.update(i, 1);
		
		if(pos[pre[i]]) tval.update(pos[pre[i]], -1);
		if(pos[i]) tval.update(pos[i], 1);
		
		for(; j<=Q && qs[j][0] <= i; ++j)
		{
			int l = qs[j][1], r = qs[j][0], id = qs[j][2];
			int x = tlst.query(l, r);
			int y = tval.query(l, r);
			res[id] = x == y? x + 1: x;
		}
	}
	
	for(int i=1; i<=Q; ++i) printf("%d\n",res[i]);
	return 0;
}