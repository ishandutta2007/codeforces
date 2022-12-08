#include <cstdio>
#include <cstring>
#include <algorithm>

template<typename T> bool ckmin(T& a, T b){return b<a?a=b,1:0;}
template<typename T> bool ckmax(T& a, T b){return a<b?a=b,1:0;}

const int INF = 0x1f1f1f1f;
const int MN = 1e5+10;

struct dat
{
	int v[2][4];//[0=normal,1=flip top/right][0:left=blue, 1:right=blue]
	int z;//bitmask: 0 = flip top/right, 1 = flip bottom/left
	dat()
	{
		memset(v, 0x1f, sizeof v);
		z=0;
	}
	void tog(int z)
	{
		if(z&2) for(int i=0;i<2;++i) std::swap(v[i][0], v[i][3]), std::swap(v[i][1], v[i][2]);//red <-> blue, this op is equivalent to z^=3
		if(z&1^z>>1) for(int i=0;i<4;++i) std::swap(v[0][i], v[1][i]);//this op is equivalent to z^=1
		this->z^=z;
	}
};
struct ST
{
	dat v[1<<18];
	int C;//cost of switching color = length of orthagonal segment
	dat merge(const dat& l, const dat& r)
	{
		dat n;
		for(int i=0;i<2;++i)
			for(int j=0;j<4;++j)
				for(int k=0;k<4;++k)
					ckmin(n.v[i][j&1|k&2], l.v[i][j] + r.v[i][k] + (j>>1^k&1)*C);
		return n;
	}
	void down(int n)
	{
		if(v[n].z)
			v[n<<1].tog(v[n].z), v[n<<1|1].tog(v[n].z), v[n].z=0;
	}
	void build(int n, int l, int r, char *a, char *b)
	{
		if(r-l>1)
		{
			int m=l+(r-l)/2;
			build(n<<1, l, m, a, b);
			build(n<<1|1, m, r, a, b);
			v[n]=merge(v[n<<1], v[n<<1|1]);
			//printf("%d %d %d %d %d %d\n", l, r, v[n].v[0][0], v[n].v[0][1], v[n].v[0][2], v[n].v[0][3]);
		}
		else
		{
			for(int j=0;j<2;++j)
				v[n].v[0][j*3] = (a[l]!="RB"[j])+(b[l]!="RB"[j]);
			for(int j=0;j<2;++j)
				v[n].v[1][j*3] = (a[l]!="RB"[j])+(b[l]!="BR"[j]);//b = top/right
		}
	}
	void upd(int n, int l, int r, int ql, int qr, int z)
	{
		if(ql <= l&&r <= qr) v[n].tog(z);
		else
		{
			int m=l+(r-l)/2;
			down(n);
			if(ql < m) upd(n<<1, l, m, ql, qr, z);
			if(m < qr) upd(n<<1|1, m, r, ql, qr, z);
			v[n] = merge(v[n<<1], v[n<<1|1]);
		}
	}
} H, V;
struct ST2
{
public:
	int v[1<<18];
	bool z[1<<18];
	void build(int n, int l, int r, char *s)
	{
		if(r-l>1)
		{
			int m=l+(r-l)/2;
			build(n<<1, l, m, s);
			build(n<<1|1, m, r, s);
			v[n]=v[n<<1]+v[n<<1|1];
		}
		else
			v[n]=s[l]=='R';
	}
	void upd(int n, int l, int r)
	{
		z[n]^=1;
		v[n]=r-l-v[n];
	}
	void down(int n, int l, int r)
	{
		int m=l+(r-l)/2;
		if(z[n])
		{
			upd(n<<1, l, m);
			upd(n<<1|1, m, r);
			z[n]=0;
		}
	}
	void upd(int n, int l, int r, int ql, int qr)
	{
		if(ql <= l&&r <= qr) upd(n, l, r);
		else
		{
			int m=l+(r-l)/2;
			down(n, l, r);
			if(ql<m) upd(n<<1, l, m, ql, qr);
			if(m<qr) upd(n<<1|1, m, r, ql, qr);
			v[n]=v[n<<1]+v[n<<1|1];
		}
	}
} ll,rr,dd,uu;

int N, M, Q;
char l[MN], r[MN], u[MN], d[MN], t;

void ans()
{
	int f=INF;
	{
		int c[2]={ll.v[1], rr.v[1]};//counts # of reds
		for(int i=0;i<4;++i)
			ckmin(f, H.v[1].v[0][i]+(i&1?c[0]:N-c[0])+(i&2?c[1]:N-c[1]));//if blue, count reds & vice versa
	}
	{
		int c[2]={uu.v[1], dd.v[1]};//counts # of reds
		for(int i=0;i<4;++i)
			ckmin(f, V.v[1].v[0][i]+(i&1?c[0]:M-c[0])+(i&2?c[1]:M-c[1]));//if blue, count reds & vice versa
	}
	printf("%d\n", f);
}
int main()
{
	scanf("%d%d%d", &N, &M, &Q);
	scanf(" %s %s %s %s", l, r, u, d);
	ll.build(1, 0, N, l);
	rr.build(1, 0, N, r);
	dd.build(1, 0, M, d);
	uu.build(1, 0, M, u);
	H.C = N; H.build(1, 0, M, d, u);
	V.C = M; V.build(1, 0, N, l, r);
	ans();
	for(int i=0,x,y;i<Q;++i)
	{
		scanf(" %c%d%d", &t, &x, &y), --x;
		if(t=='L')
		{
			ll.upd(1, 0, N, x, y);
			V.upd(1, 0, N, x, y, 2);
		}
		else if(t=='R')
		{
			rr.upd(1, 0, N, x, y);
			V.upd(1, 0, N, x, y, 1);
		}
		else if(t=='U')
		{
			uu.upd(1, 0, M, x, y);
			H.upd(1, 0, M, x, y, 1);
		}
		else if(t=='D')
		{
			dd.upd(1, 0, M, x, y);
			H.upd(1, 0, M, x, y, 2);
		}
		ans();
	}
	return 0;
}