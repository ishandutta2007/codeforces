#include <cstdio>
#include <algorithm>
#include <cassert>

const int MN = 3e5 + 100;

struct segtree
{
public:
	int m[1<<20], z[1<<20];
	void down(int n)
	{
		if(z[n])
		{
			m[n<<1] += z[n], z[n<<1] += z[n];
			m[n<<1|1] += z[n], z[n<<1|1] += z[n];
			z[n] = 0;
		}
	}
	void up(int n) {m[n] = std::max(m[n<<1], m[n<<1|1]);}
	void upd(int n, int l, int r, int ql, int qr, int v)
	{
		if(ql <= l && r <= qr)
			m[n] += v, z[n] += v;
		else
		{
			int m = l + (r-l)/2;
			down(n);
			if(ql < m) upd(n<<1, l, m, ql, qr, v);
			if(m < qr) upd(n<<1|1, m, r, ql, qr, v);
			up(n);
		}
	}
	int qry(int n, int l, int r, int ql, int qr)
	{
		if(ql <= l && r <= qr) return m[n];
		int m = l + (r-l)/2, a = -MN;
		down(n);
		if(ql < m) a = std::max(a, qry(n<<1, l, m, ql, qr));
		if(m < qr) a = std::max(a, qry(n<<1|1, m, r, ql, qr));
		return a;
	}
};

segtree pos; // suffix sum, greater - bombs
segtree neg; // prefix sum, bombs - greater
// both inclusive psums

int N, NN, p[MN], ip[MN], q[MN];
int M;
int main(void)
{
	NN = 1 << 19;
	scanf("%d", &N);
	for(int i = 0;i < N;++i)
		scanf("%d", p+i), ip[--p[i]] = i;
	for(int i = 0;i < N;++i)
		scanf("%d", q+i), --q[i];

	printf("%d ", N);
	M = N-1;
	for(int i = 0;i < N-1;++i)
	{
		pos.upd(1, 0, NN, 0, q[i]+1, -1);
		neg.upd(1, 0, NN, q[i], N, 1);
		//printf("DBGP %d %d\n", pos.qry(1, 0, NN, 0, ip[M]+1), pos.qry(1, 0, NN, ip[M], ip[M]+1));
		//printf("DBGN %d %d\n", neg.qry(1, 0, NN, ip[M], N), (ip[M]?neg.qry(1, 0, NN, ip[M]-1, ip[M]):0));
		for(;
				  (pos.qry(1, 0, NN, 0, ip[M]+1)-pos.qry(1, 0, NN, ip[M], ip[M]+1))
				< (neg.qry(1, 0, NN, ip[M], N) - (ip[M]?neg.qry(1, 0, NN, ip[M]-1, ip[M]):0))
				;)
		{
			pos.upd(1, 0, NN, 0, ip[M]+1, 1);
			neg.upd(1, 0, NN, ip[M], N, -1);
			--M;
			assert(M >= -1);
		}
		printf("%d ", M+1);
	}
	printf("\n");
	return 0;
}