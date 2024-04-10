#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 1e5 + 5;
const ll linf = 0x3f3f3f3f3f3f3f3f;

inline void chk_min(ll &a,ll b){ if(a>b) a=b;}

pii operator + (const pii &a,const pii &b)
{
	return {a.first + b.first, a.second + b.second};
}
int dist(const pii &a,const pii &b)
{
	return abs(a.first - b.first) + abs(a.second - b.second);
}
void read(pii &a)
{
	scanf("%d%d",&a.first,&a.second);
}

pii pt[MAXN][2], qt[MAXN][2];
int near[MAXN][2][2];

int getnear(int i,int j,pii oth)
{
	return dist(qt[i][j], oth) + 1;
}

struct Data
{
	int l, r; ll f[2][2];
	Data(void){}
	Data(int i)
	{
		l = r = i;
		f[0][0] = f[1][1] = 0;
		f[0][1] = f[1][0] = dist(pt[i][0], pt[i][1]);
	}
};

Data operator + (const Data &a,const Data &b)
{
	Data res; res.l = a.l; res.r = b.r;
	memset(res.f, 0x3f, sizeof(res.f));
	for(int i=0; i<=1; ++i)
		for(int j=0; j<=1; ++j)
			for(int x=0; x<=1; ++x)
				for(int y=0; y<=1; ++y)
					chk_min(res.f[i][j], a.f[i][x] + b.f[y][j] + near[a.r][x][y]);
	return res;
}

struct Segment_Tree
{
	Data tree[MAXN<<2];
	#define ls(u) ((u)<<1)
	#define rs(u) ((u)<<1|1)
	#define lson(u) ls(u),l,mid
	#define rson(u) rs(u),mid+1,r
	void build(int u,int l,int r)
	{
		if(l == r)
		{
			tree[u] = Data(l);
			return;
		}
		int mid = (l+r)>>1;
		build(lson(u)); build(rson(u));
		tree[u] = tree[ls(u)] + tree[rs(u)];
	}
	Data query(int u,int l,int r,int ql,int qr)
	{
		if(ql<=l && r<=qr) return tree[u];
		int mid = (l+r)>>1;
		if(ql<=mid && mid<qr)
			return query(lson(u),ql,qr) + query(rson(u),ql,qr);
		else
			return ql<=mid? query(lson(u),ql,qr): query(rson(u),ql,qr);
	}
}tree;

int main(void)
{
	int n;
	scanf("%d",&n);
	--n;
	for(int i=1; i<=n; ++i)
		for(int j=0; j<=1; ++j)
		{
			read(pt[i][j]);
			qt[i][j] = pt[i][j] + (j == 0? pii(1,0): pii(0,1));
		}
	
	for(int i=1; i+1<=n; ++i)
		for(int x=0; x<=1; ++x)
			for(int y=0; y<=1; ++y)
				near[i][x][y] = getnear(i, x, pt[i+1][y]);
	
	tree.build(1,1,n);
	
	int Q;
	scanf("%d",&Q);
	while(Q--)
	{
		pii a,b;
		read(a); read(b);
		
		int l = max(a.first, a.second);
		int r = max(b.first, b.second);
		if(l == r)
		{
			printf("%d\n",dist(a,b));
			continue;
		}
		
		if(l > r) swap(l,r), swap(a,b);
		--r;
		Data cur = tree.query(1,1,n,l,r);
		
		ll ans = linf;
		for(int x=0; x<=1; ++x)
			for(int y=0; y<=1; ++y)
				ans = min(ans, dist(a,pt[l][x]) + getnear(r, y, b) + cur.f[x][y]);
		printf("%lld\n",ans);
	}
	return 0;
}