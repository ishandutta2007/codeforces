#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>

const int MN = 5e5+10;

int N, M, hd[MN], to[MN*2], nx[MN*2], t[MN], X, q[MN], d[MN];

void adde(int a, int b)
{
	nx[X]=hd[a], to[X]=b;
	hd[a]=X++;
}

int bfs(int s)
{
	memset(d, -1, sizeof d);
	q[0]=s; d[s]=1;
	int n;
	for(int i=0,Q=1;i<Q;++i)
	{
		n=q[i];
		for(int j=hd[n];~j;j=nx[j])
			if(!~d[to[j]])
				d[to[j]]=d[n]+1, q[Q++]=to[j];
	}
	return n;
}

struct tree
{
	public:
		int pre[MN], post[MN], c;
		int e[1<<20], o[1<<20], q[MN];
		bool z[1<<20];
		tree() {}
		void dfs(int n, int p=0, int d=0, int m=1)
		{
			set(1, 0, N, c, m*d);
			pre[n]=c++;
			for(int i=hd[n];~i;i=nx[i])
				if(to[i]!=p)
				{
					q[i>>1]=to[i];
					dfs(to[i], n, d+1, m*(1-2*t[i>>1]));
				}
			post[n]=c;
		}
		void upd(int n)
		{
			std::swap(e[n], o[n]);
			z[n] ^= 1;
		}
		void up(int n)
		{
			e[n]=std::max(e[n<<1], e[n<<1|1]);
			o[n]=std::max(o[n<<1], o[n<<1|1]);
		}
		void down(int n)
		{
			if(z[n])
			{
				upd(n<<1);
				upd(n<<1|1);
				z[n]=0;
			}
		}
		void set(int n, int l, int r, int q, int v)
		{
			if(r-l>1)
			{
				int m=l+(r-l)/2;
				//no need for down(n) here
				if(q<m) set(n<<1, l, m, q, v);
				else set(n<<1|1, m, r, q, v);
				up(n);
			}
			else
			{
				if(v>=0) e[n]=v;
				else o[n]=-v;
			}
		}
		void flip(int n, int l, int r, int ql, int qr)
		{
			if(ql <= l&&r <= qr)
				upd(n);
			else
			{
				down(n);
				int m=l+(r-l)/2;
				if(ql<m) flip(n<<1, l, m, ql, qr);
				if(m<qr) flip(n<<1|1, m, r, ql, qr);
				up(n);
			}
		}
		void flip(int id)
		{
			if(q[id])
				flip(1, 0, N, pre[q[id]], post[q[id]]);
		}
} v[2];

int main()
{
	memset(hd, -1, sizeof hd);
	scanf("%d", &N);
	for(int i=0;i+1<N;++i)
	{
		int a, b;
		scanf("%d%d%d", &a, &b, t+i);
		adde(a, b);
		adde(b, a);
	}
	int x=bfs(1);
	v[0].dfs(x);
	v[1].dfs(bfs(x));
	scanf("%d", &M);
	for(int i=0;i<M;++i)
	{
		int id;
		scanf("%d", &id); --id;
		v[0].flip(id);
		v[1].flip(id);
		printf("%d\n", std::max(v[0].e[1], v[1].e[1]));
	}
	return 0;
}