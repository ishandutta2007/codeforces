#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 1e5 + 5;
const ll linf = 0x3f3f3f3f3f3f3f3f;

struct Mat
{
	int a[3][3];
	Mat(void){ memset(a,0x3f,sizeof(a));}
	inline int* operator [] (int x){ return a[x];}
	inline const int* operator [] (int x) const { return a[x];}
};

inline Mat operator * (const Mat &a,const Mat &b)
{
	Mat c;
	for(int k=0; k<3; ++k)
		for(int i=0; i<3; ++i)
			for(int j=0; j<3; ++j)
				c[i][j] = min(c[i][j], a[i][k] + b[k][j]);
	return c;
}

struct Segment_Tree
{
	Mat tree[MAXN<<2];
	#define ls(u) ((u)<<1)
	#define rs(u) ((u)<<1|1)
	#define lson(u) ls(u),l,mid
	#define rson(u) rs(u),mid+1,r
	inline void push_up(int u){ tree[u] = tree[rs(u)] * tree[ls(u)];}
	void update(int u,int l,int r,int q,Mat k)
	{
		if(l == r){ tree[u] = k; return;}
		int mid = (l+r)>>1;
		if(q<=mid) update(lson(u),q,k);
		else update(rson(u),q,k);
		push_up(u);
	}
	Mat get(void) const { return tree[1];}
}tree;

char s[MAXN];

void solve(void)
{
	int n,Q;
	scanf("%d%d%s",&n,&Q,s+1);
	
	Mat val[3];
	for(int k=1; k<=3; ++k)
	{
		Mat cur;
		for(int i=0; i<3; ++i) cur[i][i] = 0;
		cur[k-1][k-1] = 1;
		if(k < 3) cur[k][k-1] = 0;
		val[k-1] = cur;
	}
	
	for(int i=1; i<=n; ++i)
		tree.update(1,1,n, i, val[s[i] - 'a']);
	
	while(Q--)
	{
		int pos;
		static char t[10];
		scanf("%d%s",&pos,t+1);
		s[pos] = t[1];
		tree.update(1,1,n, pos, val[s[pos] - 'a']);
		
		Mat cur = tree.get();
		ll ans = linf;
		for(int i=0; i<3; ++i)
			ans = min(ans, (ll)cur[i][0]);
		printf("%lld\n",ans);
	}
}

int main(void)
{
	int T = 1;
	while(T--) solve();
	return 0;
}