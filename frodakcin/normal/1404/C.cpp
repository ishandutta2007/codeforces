#include <cstdio>
#define NDEBUG
#include <cassert>
#include <vector>
#include <algorithm>

const int MN = 3e5+10;
const int MS = 1 << 20;
const int INF = 0x3f3f3f3f;

int ini[MN];
struct SegTree
{
	int v[MS], z[MS];
	void build(int n, int l, int r)// can be replaced by build
	{
		if(r-l>1)
		{
			int m=l+(r-l)/2;
			build(n<<1, l, m);
			build(n<<1|1, m, r);
			v[n]=std::min(v[n<<1], v[n<<1|1]);
			z[n]=0;
		}
		else
			v[n]=ini[l], z[n]=0;
	}
	void upd(int n, int d){v[n]+=d, z[n]+=d;}
	void down(int n) {if(z[n]) upd(n<<1, z[n]), upd(n<<1|1, z[n]), z[n]=0;}
	void upd(int n, int l, int r, int ql, int qr, int d)
	{
		if(ql <= l&&r <= qr) upd(n, d);
		else
		{
			int m=l+(r-l)/2;
			down(n);
			if(ql < m) upd(n<<1, l, m, ql, qr, d);
			if(m < qr) upd(n<<1|1, m, r, ql, qr, d);
			v[n]=std::min(v[n<<1], v[n<<1|1]);
		}
	}
	int qry(int n, int l, int r)
	{
		if(v[n]>0) return -1;
		if(r-l>1)
		{
			int m=l+(r-l)/2;
			down(n);
			if(v[n<<1|1]==0) return qry(n<<1|1, m, r);
			if(v[n<<1]==0) return qry(n<<1, l, m);
			assert(0);
		}
		else
			return l;
	}
} st;

int N, Q, a[MN], ans;
std::vector<int> val[MS];

void build(int n, int l, int r)
{
	val[n].reserve(r-l);
	for(int i=l;i<r;++i)
		ini[i-l]=i-a[i];
	int L = r-l;
	st.build(1, 0, L);
	for(int x,c=0;;)
	{
		assert(st.v[1] >= 0);
		if(st.v[1] <= N)
		{
			if(st.v[1])
			{
				c += st.v[1];
				st.upd(1, 0, L, 0, L, -st.v[1]);
			}
		}
		else
			break;
		x=st.qry(1, 0, L);
		assert(~x);
		st.upd(1, 0, L, x, x+1, INF);
		if(x+1<L) st.upd(1, 0, L, x+1, L, -1);
		val[n].push_back(c);
	}
	if(r-l>1)
	{
		int m=l+(r-l)/2;
		build(n<<1, l, m);
		build(n<<1|1, m, r);
	}
}
void query(int n, int l, int r, int ql, int qr)
{
	if(ql <= l&&r <= qr)
		ans += std::distance(val[n].begin(), std::upper_bound(val[n].begin(), val[n].end(), ans));
	else
	{
		int m=l+(r-l)/2;
		if(ql < m) query(n<<1, l, m, ql, qr);
		if(m < qr) query(n<<1|1, m, r, ql, qr);
	}
}

int main()
{
	scanf("%d%d", &N, &Q);
	for(int i=0;i<N;++i)
	{
		scanf("%d", a+i), --a[i];
		if(a[i]>i) a[i]=-INF;//some placeholder
	}
	build(1, 0, N);
	for(int i=0,x,y;i<Q;++i)
	{
		scanf("%d%d", &x, &y);
		ans=0;
		query(1, 0, N, x, N-y);
		printf("%d\n", ans);
	}
	return 0;
}