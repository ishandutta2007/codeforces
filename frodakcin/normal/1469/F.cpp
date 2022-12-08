#include <cstdio>
#include <cassert>
#include <vector>
#include <algorithm>
#include <functional>

template<typename T> bool ckmax(T& a, const T& b) {return b>a?a=b,1:0;}
template<typename T> bool ckmin(T& a, const T& b) {return b<a?a=b,1:0;}

using ll = long long;

const int MN = 2e5+10;
const int MK = 1e9+10;
const int INF = 0x3f3f3f3f;

struct ST
{
	public:
		int S;
		std::vector<ll> v, z;
		ST(int _S=0): S(_S)
		{
			int l;
			if(S<=1) l=-1;
			else l=31-__builtin_clz(S-1);
			v.assign(1<<l+2, 0);
			z.assign(1<<l+2, 0);
		}
		
		void upd(int n, int l, int r, ll x) {v[n]+=x*(r-l), z[n]+=x;}
		void up(int n) {v[n]=v[n<<1]+v[n<<1|1];}
		void down(int n, int l, int r)
		{
			if(z[n])
			{
				int m=l+(r-l)/2;
				upd(n<<1, l, m, z[n]);
				upd(n<<1|1, m, r, z[n]);
				z[n]=0;
			}
		}

		void upd(int n, int l, int r, int ql, int qr, ll x)
		{
			if(ql <= l && r <= qr) upd(n, l, r, x);
			else
			{
				down(n, l, r);
				int m=l+(r-l)/2;
				if(ql < m) upd(n<<1, l, m, ql, qr, x);
				if(m < qr) upd(n<<1|1, m, r, ql, qr, x);
				up(n);
			}
		}
		void upd(int ql, int qr, ll x) {upd(1, 0, S, ql, qr, x);}

		int get(int n, int l, int r, ll k) // max x such that qry(0, x) < K
		{
			if(v[n] < k) return r;
			if(r-l>1)
			{
				down(n, l, r);
				int m=l+(r-l)/2;
				if(v[n<<1] >= k) return get(n<<1, l, m, k);
				else return get(n<<1|1, m, r, k-v[n<<1]);
			}
			else
				return l;
		}
		int get(ll k) {return get(1, 0, S, k);}
};

int N, K, l[MN];
ST st;

int main()
{
	scanf("%d%d", &N, &K);
	for(int i=0;i<N;++i) scanf("%d", l+i);
	std::sort(l, l+N, std::greater<int>());
	st = ST(MN*2);

	st.upd(1, 2, 1);

	int ans=INF;
	for(int i=0;i<N;++i)
	{
		int d = st.get(1);
		st.upd(d, d+1, -1);
		st.upd(d+2, d+l[i]/2+2, 1);
		st.upd(d+2, d+(l[i]-1)/2+2, 1);

		if(st.v[1] >= K)
			ckmin(ans, st.get(K));
	}

	if(ans == INF) printf("-1\n");
	else
		printf("%d\n", ans-1);
	return 0;
}