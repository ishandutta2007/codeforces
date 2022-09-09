#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 5e5 + 5;
const int inf = 0x3f3f3f3f;

inline int read(void)
{
	int res=0;
	char c=getchar();
	while(c<'0'||c>'9') c=getchar();
	while(c>='0'&&c<='9') res=res*10+c-'0', c=getchar();
	return res;
}
inline void write(int x)
{
	if(x>=10) write(x/10);
	putchar(x%10 + '0');
}

/*
R = 0
B = 1
*/

struct Matrix
{
	int a[2][2];
	Matrix(void){}
//	const int* operator[] (int x) const { return a[x];}
//	int* operator [] (int x){ return a[x];}
};

Matrix operator * (const Matrix &a,const Matrix &b)
{
	Matrix res;
#define trans(i,j) res.a[i][j] = min(a.a[i][0] + b.a[0][j], a.a[i][1] + b.a[1][j])
	trans(0,0); trans(0,1); trans(1,0); trans(1,1);
#undef trans
	return res;
};

struct Node
{
	Matrix f[2];
	int u0, d0, len;
	bool tagf, tagd;
	Node(void){}
	Node(int _u0,int _d0,int _len,const Matrix &f0,const Matrix &f1)
		: u0(_u0), d0(_d0), len(_len), tagf(0), tagd(0)
	{
		f[0] = f0;
		f[1] = f1;
	}
	Node(int u,int d,int _len,int m)
		: u0(u == 0), d0(d == 0), len(_len), tagf(0), tagd(0)
	{
		for(int k=0; k<=1; ++k)
			for(int i=0; i<=1; ++i)
				for(int j=0; j<=1; ++j)
					f[k].a[i][j] = m * (i != j) + (i != u) + (i != (d ^ k));
	}
	void flipall(void)
	{
		swap(f[0].a[0][0], f[0].a[1][1]);
		swap(f[0].a[0][1], f[0].a[1][0]);
		swap(f[1].a[0][0], f[1].a[1][1]);
		swap(f[1].a[0][1], f[1].a[1][0]);
		u0 = len - u0;
		d0 = len - d0;
		tagf ^= 1;
	}
	void flipd(void)
	{
		swap(f[0], f[1]);
		d0 = len - d0;
		tagd ^= 1;
	}
};

Node operator + (const Node &p,const Node &q)
{
	return Node(
		p.u0 + q.u0,
		p.d0 + q.d0,
		p.len + q.len,
		q.f[0] * p.f[0],
		q.f[1] * p.f[1]
	);
}

struct Segment_Tree
{
	Node tree[MAXN<<2];
	#define ls(u) ((u)<<1)
	#define rs(u) ((u)<<1|1)
	#define lson(u) ls(u),l,mid
	#define rson(u) rs(u),mid+1,r
	inline void push_up(int u)
	{
		tree[u] = tree[ls(u)] + tree[rs(u)];
	}
	inline void push_down(int u)
	{
		if(tree[u].tagf)
		{
			tree[ls(u)].flipall();
			tree[rs(u)].flipall();
			tree[u].tagf = 0;
		}
		if(tree[u].tagd)
		{
			tree[ls(u)].flipd();
			tree[rs(u)].flipd();
			tree[u].tagd = 0;
		}
	}
	void build(int u,int l,int r,char U[],char D[])
	{
		if(l == r)
		{
			tree[u] = Node(U[l] == 'B', D[l] == 'B', 1, m);
			return;
		}
		int mid = (l+r)>>1;
		build(lson(u),U,D); build(rson(u),U,D);
		push_up(u);
	}
	void update(int u,int l,int r,int ql,int qr,bool isu)
	{
		if(ql<=l && r<=qr)
		{
			if(isu) tree[u].flipall();
			tree[u].flipd();
			return;
		}
		push_down(u);
		int mid = (l+r)>>1;
		if(ql<=mid) update(lson(u),ql,qr,isu);
		if(mid<qr) update(rson(u),ql,qr,isu);
		push_up(u);
	}
	
	int n,m;
	void build(int _n,int _m,char U[],char D[])
	{
		n = _n; m = _m;
		build(1,1,n,U,D);
	}
	void update(int ql,int qr,bool isu)
	{
		update(1,1,n,ql,qr,isu);
	}
	int query_all(int l0,int r0)
	{
		int res = inf;
		for(int i=0; i<=1; ++i)
			for(int j=0; j<=1; ++j)
			{
				int cur = tree[1].f[0].a[j][i];
				cur += i == 0? m - l0: l0;
				cur += j == 0? m - r0: r0;
				res = min(res, cur);
			}
		return res;
	}
}R, C;

char tU[MAXN], tD[MAXN], tL[MAXN], tR[MAXN];

int main(void)
{
	int n = read(), m = read(), Q = read();
	scanf("%s%s%s%s",tL+1,tR+1,tU+1,tD+1);
	
	R.build(n, m, tL, tR);
	C.build(m, n, tU, tD);
	
	auto query_all = [&] (void) -> int
	{
		return min(
			C.query_all(R.tree[1].u0, R.tree[1].d0),
			R.query_all(C.tree[1].u0, C.tree[1].d0)
		);
	};
	
	write(query_all()); putchar('\n');
	while(Q--)
	{
		static char op[10];
		scanf("%s",op);
		int l = read(), r = read();
		if(op[0] == 'U' || op[0] == 'D')
			C.update(l, r, op[0] == 'U');
		else
			R.update(l, r, op[0] == 'L');
		write(query_all()); putchar('\n');
	}
	return 0;
}