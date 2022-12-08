#include <cstdio>
#include <vector>

template<typename T> bool ckmax(T& a, const T& b) {return b>a?a=b,1:0;}
template<typename T> bool ckmin(T& a, const T& b) {return b<a?a=b,1:0;}

using ll = long long;

const int MN = 5e5+10;

int N, min;
ll f;
std::vector<int> occ[MN];

struct ST
{
	public:
		struct DAT
		{
			public:
				int c,v;
				DAT(int _c=0, int _v=0): c(_c), v(_v)
				{
					if(v)v=c=0;
				}
				DAT& operator += (const DAT& o)
				{
					if(o.v<v) c=o.c, v=o.v;
					else if(v==o.v) c+=o.c;
					return *this;
				}
				friend DAT operator + (DAT a, const DAT& b) {return a+=b;}
		};
		int c[1 << 20], v[1 << 20], z[1 << 20];
		void build(int n, int l, int r)
		{
			if(r-l>1)
			{
				int m=l+(r-l)/2;
				build(n<<1, l, m);
				build(n<<1|1, m, r);
			}
			c[n]=r-l, v[n]=0;
		}
		void down(int n)
		{
			if(z[n])
			{
				v[n<<1]+=z[n], z[n<<1]+=z[n];
				v[n<<1|1]+=z[n], z[n<<1|1]+=z[n];
				z[n]=0;
			}
		}
		void up(int n)
		{
			if(v[n<<1]<v[n<<1|1])
				v[n]=v[n<<1], c[n]=c[n<<1];
			else if(v[n<<1|1]<v[n<<1])
				v[n]=v[n<<1|1], c[n]=c[n<<1|1];
			else
				v[n]=v[n<<1], c[n]=c[n<<1]+c[n<<1|1];
		}
		void upd(int n, int l, int r, int ql, int qr, int x)
		{
			if(ql <= l&&r <= qr)
				v[n] += x, z[n] += x;
			else
			{
				int m=l+(r-l)/2;
				down(n);
				if(ql<m) upd(n<<1, l, m, ql, qr, x);
				if(m<qr) upd(n<<1|1, m, r, ql, qr, x);
				up(n);
			}
		}
		DAT qry(int n, int l, int r, int ql, int qr)
		{
			if(ql <= l&&r <= qr)
				return DAT(c[n], v[n]);
			else
			{
				int m=l+(r-l)/2;
				DAT f;
				down(n);
				if(ql<m) f+=qry(n<<1, l, m, ql, qr);
				if(m<qr) f+=qry(n<<1|1, m, r, ql, qr);
				return f;
			}
		}
};
ST st;

int main()
{
	scanf("%d", &N);
	st.build(1, 0, N);
	for(int i=0, a;i<N;++i)
	{
		scanf("%d", &a);
		if(occ[a].size())
		{
			int v=occ[a].size()>=3?occ[a][occ[a].size()-3]:-1;
			st.upd(1, 0, N, v+1, occ[a].back()+1, -1);
		}
		occ[a].push_back(i);
		int v=occ[a].size()>=3?occ[a][occ[a].size()-3]:-1;
		if(occ[a].size() >= 4)
			ckmax(min, occ[a][occ[a].size()-4]+1);
		st.upd(1, 0, N, v+1, i+1, 1);
		f += st.qry(1, 0, N, min, i+1).c;
	}
	printf("%lld\n", f);
	return 0;
}