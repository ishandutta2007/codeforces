#include <cstdio>
#include <cassert>
#include <cstring>
#include <algorithm>
#include <functional>
#include <set>

template<typename T> bool ckmax(T& a, const T& b) {return b>a?a=b,1:0;}
template<typename T> bool ckmin(T& a, const T& b) {return b<a?a=b,1:0;}

const int MN = 2e5+10;
const int MM = 3e5+10;
const int MQ = 5e5+10;

int N, M, Q;


struct Edge
{
	public:
		int u,v;
		void in() {scanf("%d%d", &u, &v);}
};

struct DSU
{
	public:
		int p[MN], r[MN];
		int find(int n) {return p[n]?p[n]=find(p[n]):n;}
		bool merge(int a, int b)
		{
			a=find(a), b=find(b);
			if(a==b) return 0;
			if(r[a]<r[b]) std::swap(a,b);
			else r[a]+=r[a]==r[b];
			p[b]=a, r[b]=-1;
			return 1;
		}
		bool merge(const Edge& x) {return merge(x.u, x.v);}
};

struct Qry
{
	public:
		int t, v;
		void in()
		{
			scanf("%d%d", &t, &v);
			if(t==2) --v;
		}
} q[MQ];

struct Dat
{
	public:
		int v, n;
		Dat(int _v=-1, int _n=-1) : v(_v), n(_n) {}
		bool operator < (const Dat& o) const {return v < o.v;}
		bool operator > (const Dat& o) const {return v > o.v;}
};

struct ST
{
	public:
		Dat v[1 << 19];
		void down(int n)
		{
			ckmax(v[n<<1], v[n]);
			ckmax(v[n<<1|1], v[n]);
		}
		void upd(int n, int l, int r, int ql, int qr, const Dat& x)
		{
			if(x < v[n]) return;
			if(ql <= l&&r <= qr) v[n] = x;
			else
			{
				int m=l+(r-l)/2;
				down(n);
				if(ql<m) upd(n<<1, l, m, ql, qr, x);
				if(m<qr) upd(n<<1|1, m, r, ql, qr, x);
			}
		}
		Dat qry(int n, int l, int r, int q)
		{
			if(r-l>1)
			{
				int m=l+(r-l)/2;
				down(n);
				if(q<m) return qry(n<<1, l, m, q);
				else return qry(n<<1|1, m, r, q);
			}
			return v[n];
		}
};

struct BIT
{
	public:
		int v[1 << 18];
		void init()
		{
			for(int i=0;i<N;++i)
				v[i]=-(i+1)&(i+1);
		}
		void upd(int n, int x)
		{
			for(++n;n<=N;n+=-n&n)
				v[n-1]+=x;
		}
		int qry(int n)
		{
			int f=0;
			for(++n;n;n-=-n&n)
				f+=v[n-1];
			return f;
		}
		int qry(int l, int r)//inc/exc
		{
			return qry(r-1)-qry(l-1);
		}
};

DSU dsu;
ST st;
BIT bit;
Edge e[MM];

int p[MN], d[MN], hd[MN], pr[MM*2], nx[MM*2], to[MM*2], pre[MN], post[MN], ctr;
bool vis[MN], use[MM];

struct cmp
{
	bool operator () (const int& a, const int& b) const {return p[a] < p[b];}
};

using Set = std::set<int, cmp, std::allocator<int> >;
Set set[MN];

void adde(int u, int v, int id)
{
	nx[id]=hd[u], pr[id]=-1;
	if(~hd[u]) pr[hd[u]]=id;
	hd[u]=id,	to[id]=v;
}
void reme(int u, int id)
{
	if(~pr[id]) nx[pr[id]]=nx[id];
	else hd[u]=nx[id];
	if(~nx[id]) pr[nx[id]]=pr[id];
}

void dfs(int n, int p, Set& s)
{
	vis[n]=1;
	pre[n]=ctr++;
	s.insert(n);
	for(int i=hd[n],x;~i;i=nx[i])
		if(p!=(x=to[i]))
		{
			d[x]=d[n]+1;
			dfs(x, n, s);
		}
	post[n]=ctr;
}

void dfs2(int n, int p, Set& rem, Set& add)
{
	if(::p[n])
	{
		rem.erase(n);
		add.insert(n);
	}
	for(int i=hd[n],x;~i;i=nx[i])
		if(p!=(x=to[i]))
			dfs2(x, n, rem, add);
}

int main()
{
	memset(hd, -1, sizeof hd);
	scanf("%d%d%d", &N, &M, &Q);
	for(int i=1;i<=N;++i) scanf("%d", p+i);
	for(int i=0,x,y;i<M;++i)
		e[i].in();
	for(int i=0;i<Q;++i)
		q[i].in();
	for(int i=0;i<Q;++i)
		if(q[i].t==2)
			use[q[i].v]=1;
	for(int i=0;i<M;++i)
		if(!use[i])
			if(dsu.merge(e[i]))
			{
				adde(e[i].u, e[i].v, i*2);
				adde(e[i].v, e[i].u, i*2+1);
				use[i]=1;
			}
	for(int i=Q-1;i>=0;--i)
		if(q[i].t==2)
		{
			int id=q[i].v;
			if(dsu.merge(e[id]))
			{
				adde(e[id].u, e[id].v, id*2);
				adde(e[id].v, e[id].u, id*2+1);
			}
			else
				use[id]=0;
		}
	bit.init();
	for(int i=1;i<=N;++i)
		if(!vis[i])
		{
			dfs(i, 0, set[i]);
			st.upd(1, 0, N, pre[i], post[i], {0, i});
		}
	assert(ctr==N);
	for(int i=0;i<Q;++i)
		if(q[i].t==1)
		{
			int n=q[i].v;
			int t=st.qry(1, 0, N, pre[n]).n;
			if(set[t].empty()) printf("0\n");
			else
			{
				Set::iterator it = std::prev(set[t].end());
				int id=*it;
				set[t].erase(it);
				printf("%d\n", p[id]);
				p[id]=0;
			}
		}
		else
		{
			int id=q[i].v;
			if(!use[id]) continue;
			int b=e[id].u, t=e[id].v;
			if(d[b]<d[t]) std::swap(b, t);
			assert(d[b]-1==d[t]);
			t = st.qry(1, 0, N, pre[t]).n;//get "representative node" for t
			st.upd(1, 0, N, pre[b], post[b], {d[b], b});//update "representative node" at b
			reme(e[id].u, id*2), reme(e[id].v, id*2+1);//must be in sync with adde
			int sb=bit.qry(pre[b], post[b]);//b has NOT been removed before, so this makes sense. B cannot have been "offset" before
			int st=1+bit.qry(pre[t]+1, post[t]);
			bit.upd(pre[b], -sb);
			bit.upd(pre[t], sb);
			if(sb*2>st)
				set[b].swap(set[t]), dfs2(t, 0, set[b], set[t]);
			else
				dfs2(b, 0, set[t], set[b]);
		}
	return 0;
}