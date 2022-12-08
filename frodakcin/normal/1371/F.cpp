#include <cstdio>
#include <algorithm>

template<typename T> bool ckmax(T& a, T b){return a<b?a=b,1:0;}

const int MN = 5e5+10;
int N, Q, cL;

char s[MN];
struct range
{
public:
	int l[2], m[2], r[2];
	bool z;
	void set(bool v)//true = facing right
	{
		m[0]=m[1]=1;
		if(v)
		{
			r[0]=1,l[0]=-1;
			l[1]=1,r[1]=-1;
		}
		else
		{
			l[0]=1,r[0]=-1;
			r[1]=1,l[1]=-1;
		}
		z=0;
	}
	void flip()
	{
		z^=1;
		std::swap(l[0], l[1]);
		std::swap(m[0], m[1]);
		std::swap(r[0], r[1]);
	}
} st[1<<20], cur;
range merge(const range& l, int L, const range& r, int R)
{
	range n;
	n.z=0;
	for(int i=0;i<2;++i)
	{
		if(l.l[i]>0) n.l[i]=l.l[i]+(l.l[i]==L&&r.l[i]>0?r.l[i]:0);
		else
		{
			n.l[i]=l.l[i];
			if(l.l[i]==-L)
				if(r.l[i]>0 || l.r[i]==L)
					n.l[i]-=std::abs(r.l[i]);
		}

		if(r.r[i]>0) n.r[i]=r.r[i]+(r.r[i]==R&&l.r[i]>0?l.r[i]:0);
		else
		{
			n.r[i]=r.r[i];
			if(r.r[i]==-R)
				if(l.r[i]>0 || r.l[i]==R)
					n.r[i]-=std::abs(l.r[i]);
		}

		n.m[i] = std::max(l.m[i], r.m[i]);
		if(l.r[i] > 0 || r.l[i] > 0) ckmax(n.m[i], std::abs(l.r[i])+std::abs(r.l[i]));
	}
	return n;
}
void down(int n)
{
	if(st[n].z)
	{
		st[n<<1].flip();
		st[n<<1|1].flip();
		st[n].z=0;
	}
}
void build(int n, int l, int r)
{
	if(r-l>1)
	{
		int m=l+(r-l)/2;
		down(n);
		build(n<<1, l, m);
		build(n<<1|1, m, r);
		st[n] = merge(st[n<<1], m-l, st[n<<1|1], r-m);
	}
	else
		st[n].set(s[l]=='>');
	//printf("[%d, %d): l(%d), m(%d), r(%d)\n", l, r, st[n].l[0], st[n].m[0], st[n].r[0]);
}
void upd(int n, int l, int r, int ql, int qr)
{
	if(ql <= l && r <= qr)
	{
		st[n].flip();
		if(cL) cur = merge(cur, cL, st[n], r-l);
		else cur = st[n];
		cL += r-l;
	}
	else
	{
		int m = l+(r-l)/2;
		down(n);
		if(ql < m) upd(n<<1, l, m, ql, qr);
		if(m < qr) upd(n<<1|1, m, r, ql, qr);
		st[n] = merge(st[n<<1], m-l, st[n<<1|1], r-m);
	}
}
int main()
{
	scanf("%d%d", &N, &Q);
	scanf(" %s", s);
	build(1, 0, N);
	for(int i=0,l,r;i<Q;++i)
	{
		scanf("%d%d", &l, &r), --l;
		upd(1, 0, N, l, r);
		printf("%d\n", cur.m[0]);
		cL = 0;
	}
	return 0;
}