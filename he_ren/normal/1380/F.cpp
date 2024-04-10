#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 5e5 + 5;
const int mod = 998244353;

int ways[105];

struct Segment_Tree
{
	int n, val[MAXN], f[MAXN<<2][2][2];
	#define ls(u) ((u)<<1)
	#define rs(u) ((u)<<1|1)
	#define lson(u) ls(u),l,mid
	#define rson(u) rs(u),mid+1,r
	inline void push_up(int u,int l,int r)
	{
		int mid = (l+r)>>1, x = ways[val[mid]*10 + val[mid+1]];
		
		f[u][1][1] = ((ll)x * f[ls(u)][1][0] %mod * f[rs(u)][0][1] + (ll)f[ls(u)][1][1] * f[rs(u)][1][1]) %mod;
		f[u][0][0] = ((ll)x * f[ls(u)][0][0] %mod * f[rs(u)][0][0] + (ll)f[ls(u)][0][1] * f[rs(u)][1][0]) %mod;
		
		f[u][0][1] = ((ll)x * f[ls(u)][0][0] %mod * f[rs(u)][0][1] + (ll)f[ls(u)][0][1] * f[rs(u)][1][1]) %mod;
		f[u][1][0] = ((ll)x * f[ls(u)][1][0] %mod * f[rs(u)][0][0] + (ll)f[ls(u)][1][1] * f[rs(u)][1][0]) %mod;
	}
	void build(char s[]){ for(n=1; s[n]; ++n) val[n] = s[n]-'0'; --n; build(1,1,n);}
	void build(int u,int l,int r)
	{
		if(l==r){ f[u][0][0]=0; f[u][0][1]=f[u][1][0]=1; f[u][1][1]=val[l]+1; return;}
		int mid = (l+r)>>1;
		build(lson(u)); build(rson(u));
		push_up(u,l,r);
	}
	void update(int q,int k){ update(1,1,n,q,k);}
	void update(int u,int l,int r,int q,int k)
	{
		if(l==r){ val[l]=k; f[u][1][1]=k+1; return;}
		int mid = (l+r)>>1;
		if(q<=mid) update(lson(u),q,k);
		else update(rson(u),q,k);
		push_up(u,l,r);
	}
	int query(void){ return f[1][1][1];}
};

char s[MAXN];

int main(void)
{
	for(int i=0; i<=9; ++i)
		for(int j=0; j<=9; ++j)
			if(i+j >= 10) ++ways[i+j];
	
	int n,Q;
	scanf("%d%d%s",&n,&Q,s+1);
	
	static Segment_Tree tree;
	tree.build(s);
	
	while(Q--)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		tree.update(a,b);
		printf("%d\n",tree.query());
	}
	return 0;
}