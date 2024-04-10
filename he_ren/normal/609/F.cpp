#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<int,ll> pil;
const int MAXN = 2e5 + 5;
const int inf = 0x3f3f3f3f;

template<typename T = int>
inline T read(void)
{
	T res=0;
	char c=getchar();
	while(c<'0'||c>'9') c=getchar();
	while(c>='0'&&c<='9') res=res*10+c-'0', c=getchar();
	return res;
}

struct Segment_Tree
{
	ll mx[MAXN<<2];
	#define ls(u) ((u)<<1)
	#define rs(u) ((u)<<1|1)
	#define lson(u) ls(u),l,mid
	#define rson(u) rs(u),mid+1,r
	inline void push_up(int u){ mx[u] = max(mx[ls(u)], mx[rs(u)]);}
	
	void update(int u,int l,int r,int q,ll k)
	{
		if(l==r){ mx[u]=k; return;}
		int mid = (l+r)>>1;
		if(q<=mid) update(lson(u),q,k);
		else update(rson(u),q,k);
		push_up(u);
	}
	
	int query(int u,int l,int r,int ql,int qr,ll k)
	{
		if(mx[u] < k) return inf;
		if(ql<=l && r<=qr)
		{
			if(l==r) return l;
			int mid = (l+r)>>1;
			if(mx[ls(u)] >= k) return query(lson(u),ql,qr,k);
			return query(rson(u),ql,qr,k);
		}
		int mid = (l+r)>>1, res = inf;
		if(ql<=mid) res = query(lson(u),ql,qr,k);
		if(res == inf && mid<qr) res = query(rson(u),ql,qr,k);
		return res;
	}
}tree;

struct Node
{
	int pos;
	ll len;
	int id;
}p[MAXN];
inline bool cmp(const Node &p,const Node &q){ return p.pos < q.pos;}

pil ans[MAXN];

int main(void)
{
	int n = read(), m = read();
	for(int i=1; i<=n; ++i)
	{
		p[i].pos = read();
		p[i].len = read();
		p[i].id = i;
	}
	
	sort(p+1,p+n+1,cmp);
	
	for(int i=1; i<=n; ++i)
		tree.update(1,1,n, i, p[i].pos + p[i].len);
	
	multiset<pii> rem;
	while(m--)
	{
		int x = read(), sz = read();
		
		int rig = upper_bound(p+1,p+n+1,(Node){x,0,0},cmp) - p - 1;
		if(rig < 1) continue;
		
		int id = tree.query(1,1,n, 1,rig, x);
		if(id == inf){ rem.insert(make_pair(x,sz)); continue;}
		
		Node &cur = p[id];
		
		++ans[cur.id].first;
		cur.len += sz;
		
		multiset<pii>::iterator it = rem.lower_bound(make_pair(cur.pos, -inf));
		while(it != rem.end() && it -> first <= cur.pos + cur.len)
		{
			++ans[cur.id].first;
			cur.len += it -> second,
			rem.erase(it++);
		}
		
		tree.update(1,1,n, id, cur.pos + cur.len);
	}
	
	for(int i=1; i<=n; ++i)
		ans[p[i].id].second = p[i].len;
	
	for(int i=1; i<=n; ++i)
		printf("%d %lld\n",ans[i].first,ans[i].second);
	return 0;
}