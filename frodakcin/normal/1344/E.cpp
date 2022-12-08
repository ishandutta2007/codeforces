#include <cstdio>
#include <cstring>
#include <vector>
#include <stack>
#include <set>
#include <algorithm>

template<typename T> bool ckmax(T* a, T b) {return *a<b?*a=b,1:0;}

using ll = long long;
const ll INF = 1e16;
const int MN = 1e5+100;
int N, M, b[MN], c[MN];
struct edge {public: int n, w;};
std::vector<edge> a[MN];
ll dis[MN];
int s[MN], d[MN], p[MN], pre[MN], post[MN], ctr;
int h[MN], t[MN], l[MN], pf[MN];
std::stack<int> v[MN];
struct range {public: ll l, r; bool operator < (range o) const {return l<o.l;}};
std::vector<range> fin;
std::multiset<ll> end;
ll ans;
int ans2;

void dfs(int n=1)
{
	pre[n] = ctr++;
	s[n]=1;
	for(auto x:a[n])
		if(x.n!=p[n])
		{
			dis[x.n]=dis[n]+x.w;
			d[x.n]=d[n]+1;
			p[x.n]=n;
			dfs(x.n);
			s[n]+=s[x.n];
		}
	post[n] = ctr;
}
void dfs2(int n=1)
{
	int y;
	for(auto x:a[n])
		if(p[n]!=(y=x.n))
		{
			if(s[y]*2>=s[n])
			{
				h[n]=y;
				if(!t[n])
					t[n]=n, l[n]=0;
				t[y]=t[n], l[y]=l[n]+1;
			}
			dfs2(y);
		}
	if(!a[n].empty())
	{
		pf[n]=a[n].back().n;
		if(h[n] && pf[n] != h[n])
			v[t[n]].push(n);
	}
	//printf("%d: h:%d, t:%d, l:%d\n", n, h[n], t[n], l[n]);
}
int st[1<<19];
void upd(int n, int l, int r, int q, int v)
{
	if(r-l>1)
	{
		int m=l+(r-l)/2;
		if(q<m) upd(n<<1, l, m, q, v);
		else upd(n<<1|1, m, r, q, v);
		st[n]=std::max(st[n<<1], st[n<<1|1]);
	}
	else
		st[n]=v;
}
int qry(int n, int l, int r, int ql, int qr)
{
	if(ql <= l&&r <= qr) return st[n];
	else
	{
		int m=l+(r-l)/2, f=-1;
		if(ql < m) ckmax(&f, qry(n<<1, l, m, ql, qr));
		if(m < qr) ckmax(&f, qry(n<<1|1, m, r, ql, qr));
		return f;
	}
}
ll prev(int n)
{
	int v=qry(1, 0, N, pre[n], post[n]);
	if(!~v) return -INF; else return (ll)v;
}
int main(void)
{
	memset(st, -1, sizeof st);
	scanf("%d%d", &N, &M);
	for(int i=0,x,y,z;i+1<N;++i)
		scanf("%d%d%d", &x, &y, &z), a[x].push_back({y, z});
	for(int i=0;i<M;++i)
		scanf("%d%d",b+i,c+i);//b=station,c=time
	dfs();
	dfs2();
	for(int i=0;i<M;++i)
	{
		//printf("ON i=%d\n", i);
		int x=b[i];
		if(x == 1) continue;

		if(t[x])
		{
			std::stack<int> *v = ::v+t[x];
			for(;!v->empty() && d[v->top()] < d[x];v->pop())
			{
				int y=v->top();
				pf[y]=h[y];
				fin.push_back({prev(y)+dis[y], c[i]+dis[y]});
			}
			x = t[x];
		}
		for(;x!=1;)
			if(t[p[x]])
			{
				std::stack<int>* v = ::v+t[p[x]];
				for(;!v->empty() && d[v->top()]+1 < d[x];v->pop())
				{
					int y=v->top();
					pf[y]=h[y];
					fin.push_back({prev(y)+dis[y], c[i]+dis[y]});//can treat as inclusive exclusive (both bounds should be +1, but differences cancel out)
				}
				if(pf[p[x]]!=x)
				{
					fin.push_back({prev(p[x])+dis[p[x]], c[i]+dis[p[x]]});
					if(pf[p[x]]==h[p[x]])
						v->push(p[x]);
					pf[p[x]]=x;
				}
				x=t[p[x]];
			}
			else
			{
				if(pf[p[x]] != x)
				{
					fin.push_back({prev(p[x])+dis[p[x]], c[i]+dis[p[x]]});
					pf[p[x]]=x;
				}
				x=p[x];
			}
		upd(1, 0, N, pre[p[b[i]]], c[i]);
	}
	std::sort(fin.begin(), fin.end());
	for(auto &x:fin)
		x.l=std::max(x.l, 0LL);
	//for(auto x:fin) printf("RANGE: %lld %lld\n", x.l, x.r);
	ans = INF;
	for(int i=0,j;i<fin.size();i=j)
	{
		for(j=i;j<fin.size()&&fin[i].l==fin[j].l;++j)
			end.insert(fin[j].r);
		for(ll k=fin[i].l;!end.empty() && (j==fin.size()||k<fin[j].l);++k)
			if(*end.begin() <= k)
			{
				ans=k;
				goto done;
			}
			else
				end.erase(end.begin());
	}
done: 
	if(ans == INF)
		return printf("-1 %u\n", fin.size()), 0;
	for(auto x:fin)
		if(x.r < ans)
			++ans2;
	printf("%lld %d\n", ans, ans2);
	return 0;
}