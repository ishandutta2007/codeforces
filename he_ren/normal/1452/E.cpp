#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 2e3 + 5;
const int MAXM = 2e3 + 5;

struct Segment_Tree
{
	int sum[MAXN<<2],tag[MAXN<<2];
	#define ls(u) ((u)<<1)
	#define rs(u) ((u)<<1|1)
	#define lson(u) ls(u),l,mid
	#define rson(u) rs(u),mid+1,r
	inline void push_up(int u){ sum[u] = sum[ls(u)] + sum[rs(u)];}
	inline void push_down(int u,int l,int r)
	{
		if(tag[u])
		{
			int mid = (l+r)>>1;
			tag[ls(u)] += tag[u]; sum[ls(u)] += tag[u] * (mid-l+1);
			tag[rs(u)] += tag[u]; sum[rs(u)] += tag[u] * (r-mid);
			tag[u] = 0;
		}
	}
	void clear(void){ memset(sum,0,sizeof(sum)); memset(tag,0,sizeof(tag));}
	void update(int u,int l,int r,int ql,int qr,int k)
	{
		if(ql<=l && r<=qr){ tag[u] += k; sum[u] += (r-l+1) * k; return;}
		push_down(u,l,r);
		int mid = (l+r)>>1;
		if(ql<=mid) update(lson(u),ql,qr,k);
		if(mid<qr) update(rson(u),ql,qr,k);
		push_up(u);
	}
	int query(int u,int l,int r,int ql,int qr)
	{
		if(ql<=l && r<=qr) return sum[u];
		push_down(u,l,r);
		int mid = (l+r)>>1, res = 0;
		if(ql<=mid) res += query(lson(u),ql,qr);
		if(mid<qr) res += query(rson(u),ql,qr);
		return res;
	}
};

struct Seg
{
	int l,r;
	Seg(void){}
	Seg(int l,int r): l(l), r(r) {}
	
	inline int len(void) const { return l>r? 0: r - l + 1;}
	inline bool incl(const int x) const { return x >= l && x <= r;}
	inline bool incl(const Seg &oth) const { return oth.l >= l && oth.r <= r;}
}p[MAXM];

inline Seg inter(const Seg &p,const Seg &q){ return Seg(max(p.l, q.l), min(p.r, q.r));}

int main(void)
{
	int n,m,d;
	scanf("%d%d%d",&n,&m,&d);
	for(int i=1; i<=m; ++i) scanf("%d%d",&p[i].l,&p[i].r);
	
	int ans = 0;
	for(int k=1; k+d-1<=n; ++k)
	{
		Seg seg1(k, k+d-1);
		
		static Segment_Tree tree;
		static vector<pii> dif[MAXN];
		static int lens[MAXN];
		
		tree.clear();
		for(int i=1; i<=n+1; ++i) dif[i].clear();
		
		int res = 0;
		for(int i=1; i<=m; ++i)
		{
			int &len = lens[i] = inter(seg1, p[i]).len();
			res += len;
			if(seg1.incl(p[i]) || p[i].incl(seg1)) continue;
			
			int lef = max(1, p[i].l + len - d + 1), rig = min(n, p[i].r - len);
			
			dif[lef].push_back(make_pair(i, 1));
			dif[rig+1].push_back(make_pair(i, -1));
		}
		
		int tot = 0;
		for(int i=1; i+d-1<=n; ++i)
		{
			vector<pii> &vec = dif[i];
			for(int j=0; j<(int)vec.size(); ++j)
			{
				int id = vec[j].first;
				tree.update(1,1,n, p[id].l, p[id].r, vec[j].second);
				tot += vec[j].second * lens[id];
			}
			ans = max(ans, res + tree.query(1,1,n, i, i+d-1) - tot);
		}
	}
	
	printf("%d",ans);
	return 0;
}