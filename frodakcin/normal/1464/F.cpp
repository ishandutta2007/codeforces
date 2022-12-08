#include <cstdio>
#include <cassert>
#include <vector>
#include <set>
#include <algorithm>
#include <functional>

const int MN = 2e5+10;
const int INF = 0x3f3f3f3f;

template<typename T> bool ckmax(T& a, const T& b) {return b>a?a=b,1:0;}
template<typename T> bool ckmin(T& a, const T& b) {return b<a?a=b,1:0;}

struct BIT: public std::vector<int>
{
	public:
		int S;
		BIT(int _S=0): S(_S), vector<int>(_S) {}
		void upd(int n, int x)
		{
			for(++n;n<=S;n+=-n&n)
				at(n-1)+=x;
		}
		int qry(int n)
		{
			int f=0;
			for(;n;n-=-n&n)
				f+=at(n-1);
			return f;
		}
		int qry(int l, int r) {return qry(r)-qry(l);}
};

struct ST
{
	public:
		int S;
		std::vector<int> v;
		void init(int _S)
		{
			S=_S;
			v.assign(1 << 31-__builtin_clz(S)+2, -INF);
		}
		ST(int _S=1) {init(_S);}

		void up(int n) {v[n]=std::max(v[n<<1], v[n<<1|1]);}

		void upd(int n, int l, int r, int q, int x)
		{
			if(r-l>1)
			{
				int m=l+(r-l)/2;
				if(q < m) upd(n<<1, l, m, q, x);
				else upd(n<<1|1, m, r, q, x);
				up(n);
			}
			else
				v[n]=x;
		}
		void upd(int q, int x) {upd(1, 0, S, q, x);}

		int qry(int n, int l, int r, int ql, int qr)
		{
			if(ql <= l && r <= qr) return v[n];
			int m=l+(r-l)/2, f=-INF;
			if(ql < m) ckmax(f, qry(n<<1, l, m, ql, qr));
			if(m < qr) ckmax(f, qry(n<<1|1, m, r, ql, qr));
			return f;
		}
		int qry(int ql, int qr) {return qry(1, 0, S, ql, qr);}
};

int N, Q, p[MN][20], d[MN], s[MN], h[MN], l[MN], t[MN], X, pre[MN], post[MN], ctr[MN], alive, hv[MN];
std::vector<int> a[MN];
BIT bit;
ST max, hvst;

void dfs(int n=1)
{
	pre[n]=X++;
	s[n]=1;
	for(int i=0;p[n][i]&&p[p[n][i]][i];++i)
		p[n][i+1]=p[p[n][i]][i];

	int ms=-1;
	for(int x:a[n])
		if(x!=p[n][0])
		{
			p[x][0]=n, d[x]=d[n]+1, dfs(x), s[n]+=s[x];
			if(ckmax(ms, s[x]))
				h[n]=x;
		}
	post[n]=X;
}

void dfs2(int n=1)
{
	if(h[n]!=0)
	{
		if(t[n]==0)
			t[n]=n, l[n]=0;
		t[h[n]]=t[n];
		l[h[n]]=l[n]+1;
	}
	for(int x:a[n])
		if(x!=p[n][0])
			dfs2(x);
	if(h[n]==0 && t[n]!=0)
	{
		hv[t[n]]=X;
		X+=l[n];
	}
}

int mu(int a, int x) // move up a by x
{
	assert(0 <= x && x <= d[a]);
	for(int i=0;x;++i)
		if(x>>i&1)
			x^=1<<i, a=p[a][i];
	return a;
}
int lca(int a, int b)
{
	if(d[b]>d[a]) std::swap(a,b);
	a=mu(a, d[a]-d[b]);
	if(a==b) return a;
	for(int i=17;i>=0;--i)
		if(p[a][i]!=p[b][i])
			a=p[a][i], b=p[b][i];
	return p[a][0];
}

int getval(int n, int c)
{
	int v=max.qry(pre[n], pre[c]);
	if(post[c]<post[n]) ckmax(v, max.qry(post[c], post[n]));
	return v;
}
void updhld(int n)
{
	for(;n!=0;n=p[n][0])
		if(h[n]!=0)
		{
			hvst.upd(hv[t[n]]+l[n], getval(n, h[n])-2*d[n]);
			n=t[n];
		}
}
int gethld(int n, int g)
{
	int ans=-INF;
	for(;n!=g;)
		if(t[n]==0 || t[n]==n)
		{
			ckmax(ans, getval(p[n][0], n)-2*d[p[n][0]]);
			n=p[n][0];
		}
		else
		{
			if(d[g]>=d[t[n]])
			{
				assert(t[g]==t[n]);
				ckmax(ans, hvst.qry(hv[t[n]]+l[g], hv[t[n]]+l[n]));
				break;
			}
			ckmax(ans, hvst.qry(hv[t[n]], hv[t[n]]+l[n]));
			n=t[n];
		}
	return ans;
}

int main()
{
	scanf("%d%d", &N, &Q);
	for(int i=0,u,v;i+1<N;++i)
		scanf("%d%d", &u, &v), a[u].push_back(v), a[v].push_back(u);
	
	dfs();
	assert(X==N);
	X=0;
	dfs2();

	bit = BIT(N);
	max = ST(N), hvst = ST(X);
	std::set<int, std::function<bool(int, int)> > poman([&](int u, int v){return d[u]>d[v] || !(d[v]>d[u]) && u<v;}); // deepest first

	for(int i=0;i<Q;++i)
	{
		int t; scanf("%d", &t);
		if(t==1)
		{
			++alive;
			int u, v;
			scanf("%d%d", &u, &v);
			int l=lca(u, v);
			bit.upd(pre[u], 1);
			bit.upd(pre[v], 1);
			bit.upd(pre[l], -1);

			if(!ctr[l]++)
			{
				max.upd(pre[l], d[l]);
				updhld(l);
				poman.insert(l);
			}
		}
		if(t==2)
		{
			--alive;
			int u, v;
			scanf("%d%d", &u, &v);
			int l=lca(u, v);
			bit.upd(pre[u], -1);
			bit.upd(pre[v], -1);
			bit.upd(pre[l], 1);

			if(!--ctr[l])
			{
				max.upd(pre[l], -INF);
				updhld(l);
				poman.erase(l);
			}
		}
		if(t==3)
		{
			int x;
			scanf("%d", &x);

			int n=*poman.begin();
			n=mu(n, std::min(d[n], x));
			int top=mu(n, std::min(d[n], x));
			
			if(bit.qry(pre[top], post[top]) < alive)
			{
				printf("No\n");
				continue;
			}

			int mv = gethld(n, top); // max {d[o]-2*d[l]}
			if(mv+d[n]>x)
				printf("No\n");
			else
				printf("Yes\n");
		}
	}

	return 0;
}