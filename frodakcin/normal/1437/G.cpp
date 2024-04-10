#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <functional>

template<typename T> bool ckmax(T& a, const T& b) {return b>a?a=b,1:0;}
template<typename T> bool ckmin(T& a, const T& b) {return b<a?a=b,1:0;}

const int MN = 3e5+10;
const int MQ = 3e5+10;
const int B = 20;

template<int ML=MN> struct Aho
{
	public:
		int c[ML][26], g[ML][26], l[ML], X;
		std::vector<int> a[ML]; // link tree
		Aho()
		{
			memset(c, -1, sizeof c);
		}
		int add(char *s)
		{
			int n=0;
			for(int i=0;s[i];++i)
			{
				if(!~c[n][s[i]-'a']) c[n][s[i]-'a']=++X;
				n=c[n][s[i]-'a'];
			}
			return n;
		}
		void solve()
		{
			std::queue<int> q; q.push(0); l[0]=-1;
			for(;!q.empty();)
			{
				int n=q.front(); q.pop();
				if(~l[n])
				{
					memcpy(g[n], g[l[n]], sizeof*g);
					a[l[n]].push_back(n);
				}
				for(char i=0;i<26;++i)
					if(~c[n][i])
					{
						l[c[n][i]]=n?g[l[n]][i]:0;
						g[n][i]=c[n][i];
						q.push(c[n][i]);
					}
			}
		}
};

struct Save
{
	public:
		int *t, v;
		Save(int *x, int nv): t(x), v(*x) {*x=nv;}
		void rev() {*t=v;}
};

struct Segtree
{
	public:
		int v[1 << B];
		std::stack<Save> rb;
		Segtree()
		{
			memset(v, -1, sizeof v);
		}
		void upd(int n, int l, int r, int ql, int qr, int q)
		{
			if(ql <= l&&r <= qr)
			{
				if(v[n] < q)
					rb.push(Save(v+n, q));
			}
			else
			{
				int m=l+(r-l)/2;
				if(ql<m) upd(n<<1, l, m, ql, qr, q);
				if(m<qr) upd(n<<1|1, m, r, ql, qr, q);
			}
		}
		int qry(int n, int l, int r, int q)
		{
			if(r-l>1)
			{
				int m=l+(r-l)/2;
				if(q<m) return std::max(v[n], qry(n<<1, l, m, q));
				else return std::max(v[n], qry(n<<1|1, m, r, q));
			}
			return v[n];
		}
		void rollback(int R)
		{
			for(;rb.size()>R;)
				rb.top().rev(), rb.pop();
		}
};

struct UQ
{
	public:
		int l, r, v;
};
struct QQ
{
	public:
		int i, t;
};

Aho<> aho;
Segtree st;

int main()
{
	int N, M;
	scanf("%d%d", &N, &M);
	int where[N];
	char s[MN];
	for(int i=0;i<N;++i)
	{
		scanf(" %s", s);
		where[i]=aho.add(s);
		//printf("%d: %d\n", i, where[i]);
	}
	aho.solve();

	std::vector<UQ> u[MN];
	std::vector<QQ> q[MN];
	int prv[N], pr[N], C=0, f[M];
	memset(pr, 0, sizeof pr);
	memset(prv, 0, sizeof prv);
	memset(f, -1, sizeof f);
	for(int i=0;i<M;++i)
	{
		int t; scanf("%d", &t);
		if(t==1)
		{
			int w, x;
			scanf("%d%d", &w, &x), --w;
			u[where[w]].push_back({pr[w], i, prv[w]});
			pr[w]=i;
			prv[w]=x;
		}
		else
		{
			scanf(" %s", s);
			int n=0;
			for(int j=0;s[j];++j)
			{
				n=aho.g[n][s[j]-'a'];
				//printf("%d: %d\n", i, n);
				q[n].push_back({C, i});
			}
			++C;
		}
	}

	for(int i=0;i<N;++i)
		if(~pr[i])
			u[where[i]].push_back({pr[i], M, prv[i]});

	std::function<void(int)> dfs=[&](int n)
	{
		int R=st.rb.size();
		for(auto x:u[n])
		{
			st.upd(1, 0, M, x.l, x.r, x.v);
			//printf("%d %d %d\n", x.l, x.r, x.v);
		}
		for(auto x:q[n])
			ckmax(f[x.i], st.qry(1, 0, M, x.t));
		for(int x:aho.a[n])
			dfs(x);
		st.rollback(R);
	};
	dfs(0);

	for(int i=0;i<C;++i)
		printf("%d\n", f[i]);

	return 0;
}