#include <cstdio>
#include <cstring>
#include <vector>

const int MN = 1e5+10;

struct BIT
{
	public:
		int v[MN*2], L;
		std::vector<int> q;
		void init(int _L)
		{
			memset(v, 0, L*sizeof*v);
			L=_L;
		}
		void upd(int n, int x)
		{
			for(++n;n<=L;n+=-n&n)
				v[n-1]^=x, q.push_back(n-1);
		}
		int qry(int n)
		{
			int f=0;
			for(;n;n-=-n&n)
				f^=v[n-1];
			return f;
		}
		int qry(int l, int r) {return qry(l)^qry(r);}
		void reset()
		{
			for(int x:q) v[x]=0;
			q.clear();
		}
};
BIT bit;

std::vector<int> a[MN];
int N, K, val[MN], s[MN], f[MN];
bool r[MN];

int dfs(int n, int p=0)
{
	s[n]=1;
	for(int x:a[n])
		if(x!=p && !r[x])
			s[n] += dfs(x, n);
	return s[n];
}

int get_centroid(int n, int ms, int p=0)
{
	for(int x:a[n])
		if(x!=p && !r[x] && s[x]*2>=ms)
			return get_centroid(x, ms, n);
	return n;
}

void upd(int n, int p, int d=1)
{
	//printf("WTF %d: %d\n", n, d);
	bit.upd(d, val[n]);
	if(++d==2*K) d=0;
	for(int x:a[n])
		if(x!=p && !r[x])
			upd(x, n, d);
}

void qry(int n, int p, int d=1)
{
	//d + q = [K, 2*K)
	//q = [K, 2*K)-d

	int qr=2*K-d;
	int ql=qr-K;
	//printf("WHY %d: %d %d\n", n, ql, qr);
	f[n] ^= ql<0?bit.qry(ql+2*K, 2*K)^bit.qry(qr):bit.qry(ql, qr);//answer
	//printf("WHY %d [%d]: %d\n", n, d, ql<0?bit.qry(qr)^bit.qry(ql+2*K, 2*K):bit.qry(ql, qr));

	if(++d == 2*K+1) d=1;
	for(int x:a[n])
		if(x!=p && !r[x])
			qry(x, n, d);
}

void centroid(int n)
{
	n=get_centroid(n, dfs(n));

	for(int x:a[n])
		if(!r[x])
		{
			upd(x, n);
			qry(x, n);
		}
	f[n] ^= bit.qry(K, 2*K);
	//printf("%d: %d\n", n, bit.qry(K, 2*K));
	bit.reset();

	bit.upd(0, val[n]);
	for(int i=(int)a[n].size()-1;i>=0;--i)
		if(!r[a[n][i]])
		{
			upd(a[n][i], n);
			qry(a[n][i], n);
		}
	bit.reset();

	r[n]=1;
	for(int x:a[n])
		if(!r[x])
			centroid(x);
}

int main()
{
	scanf("%d%d", &N, &K);
	bit.init(K*2);
	for(int i=0,u,v;i+1<N;++i)
		scanf("%d%d", &u, &v), a[u].push_back(v), a[v].push_back(u);
	for(int i=1;i<=N;++i) scanf("%d", val+i);

	centroid(1);

	for(int i=1;i<=N;++i)
		printf("%d%c", !!f[i], " \n"[i==N]);
	return 0;
}