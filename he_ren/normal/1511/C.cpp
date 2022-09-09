#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 3e5 + 5;
const int MAXQ = 3e5 + 5;
const int MAXA = 50 + 5;

struct BIT
{
	int tree[MAXN + MAXQ], n;
	#define lowbit(x) ((x)&-(x))
	inline void update(int x,int k)
	{
		while(x<=n)
			tree[x] += k,
			x += lowbit(x);
	}
	inline int query(int x)
	{
		int res = 0;
		while(x)
			res += tree[x],
			x ^= lowbit(x);
		return res;
	}
	inline int query(int l,int r){ return query(r) - query(l-1);}
}tree;

int fir[MAXA];

int main(void)
{
	int n,Q;
	scanf("%d%d",&n,&Q);
	tree.n = n + Q;
	for(int i=1; i<=n; ++i)
	{
		int x;
		scanf("%d",&x);
		if(!fir[x]) fir[x] = i + Q;
		tree.update(i + Q, 1);
	}
	
	int cur = Q + 1;
	while(Q--)
	{
		int x;
		scanf("%d",&x);
		printf("%d ",tree.query(fir[x]));
		tree.update(fir[x], -1);
		fir[x] = --cur;
		tree.update(fir[x], 1);
	}
	return 0;
}