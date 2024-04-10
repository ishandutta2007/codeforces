#include<bits/stdc++.h>
#define eprintf(...) fprintf(stderr, __VA_ARGS__) 
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXD = 20 + 15;
const int inf = 0x3f3f3f3f;

struct Data
{
	int mn, mask;
	Data(void){}
	Data(int _mn,int _mask): mn(_mn), mask(_mask) {};
	Data operator + (const Data &oth) const
	{
		if(mn < oth.mn) return *this;
		if(oth.mn < mn) return oth;
		return Data(mn, mask | oth.mask);
	}
};

int dsc[MAXD], dcnt = 0;

struct Segment_Tree
{
	Data tree[MAXD<<2]; int tag[MAXD<<2];
	#define ls(u) ((u)<<1)
	#define rs(u) ((u)<<1|1)
	#define lson(u) ls(u),l,mid
	#define rson(u) rs(u),mid+1,r
	inline void push_up(int u)
	{
		tree[u] = tree[ls(u)] + tree[rs(u)];
	}
	inline void upd(int u,int k)
	{
		tree[u].mn += k;
		tag[u] += k;
	}
	inline void push_down(int u)
	{
		if(tag[u])
		{
			upd(ls(u), tag[u]); upd(rs(u), tag[u]);
			tag[u] = 0;
		}
	}
	void build(int u,int l,int r)
	{
		tag[u] = 0;
		if(l == r)
		{
			tree[u].mn = 0;
			tree[u].mask = dsc[l+1]-dsc[l] >= 2? 3: 1<<(dsc[l]&1);
			return;
		}
		int mid = (l+r)>>1;
		build(lson(u)); build(rson(u));
		push_up(u);
	}
	void add(int u,int l,int r,int ql,int qr,int k)
	{
		if(ql<=l && r<=qr){ upd(u,k); return;}
		push_down(u);
		int mid = (l+r)>>1;
		if(ql<=mid) add(lson(u),ql,qr,k);
		if(mid<qr) add(rson(u),ql,qr,k);
		push_up(u);
	}
	Data getData(int u,int l,int r,int ql,int qr)
	{
		if(ql<=l && r<=qr) return tree[u];
		push_down(u);
		int mid = (l+r)>>1;
		if(ql<=mid && mid<qr)
			return getData(lson(u),ql,qr) + getData(rson(u),ql,qr);
		else
			return ql<=mid? getData(lson(u),ql,qr): getData(rson(u),ql,qr);
	}
	
	int n;
	void build(int _n){ n = _n; build(1,1,n);}
	void add(int ql,int qr,int k){ if(ql<=qr) add(1,1,n,ql,qr,k);}
	Data getData(int ql,int qr){ return getData(1,1,n,ql,qr);}
}tree;

int n,m,d;
array<int,2> p[MAXD];

pii check(int tim)
{
	if(tim < 0) return { 2, 0 };
	
	dcnt = 0;
	dsc[++dcnt] = 1 - m; dsc[++dcnt] = n - 1 + 1;
	for(int i=1; i<=d; ++i)
	{
		int y = p[i][0] - p[i][1];
		dsc[++dcnt] = max(y - tim, 1 - m);
		dsc[++dcnt] = min(y + tim, n - 1) + 1;
	}
	sort(dsc+1,dsc+dcnt+1);
	dcnt = unique(dsc+1,dsc+dcnt+1) - dsc - 1;
	
	auto getdsc = [&] (int y) -> int
	{
		return upper_bound(dsc+1,dsc+dcnt+1,y) - dsc - 1;
	};
	
	vector< tuple<int,int,int,int> > eff;
	eff.emplace_back(2, 1, 0, 0);
	eff.emplace_back(n + m + 1, 1, 0, 0);
	for(int i=1; i<=d; ++i)
	{
		int x = p[i][0] + p[i][1], y = p[i][0] - p[i][1];
		int xl = max(x - tim, 2), xr = min(x + tim, n + m) + 1;
		int yl = max(y - tim, 1 - m), yr = min(y + tim, n - 1) + 1;
		
		yl = getdsc(yl);
		yr = getdsc(yr) - 1;
		
		eff.emplace_back(xl, yl, yr, 1);
		eff.emplace_back(xr, yl, yr, -1);
	}
	
	tree.build(dcnt - 1);
	
	sort(eff.begin(), eff.end());
	for(int rn=0; rn+1<(int)eff.size(); ++rn)
	{
		if(get<3>(eff[rn]))
			tree.add(get<1>(eff[rn]), get<2>(eff[rn]), get<3>(eff[rn]));
		
		int xl = get<0>(eff[rn]), xr = get<0>(eff[rn+1]) - 1;
		if(xl > xr) continue;
		
		int yl = 1, yr = dcnt - 1;
		
		// x + y = 2
		{
			int l = getdsc(2 - xr), r = getdsc(2 - xl);
			
			l = max(l, 1); r = max(r, 0);
			yl = max(yl, r + 1);
			
			if(l <= r && tree.getData(l, r).mn == 0)
			{
				for(int i=l; i<=r; ++i) if(tree.getData(i, i).mn == 0)
				{
					int y = max(dsc[i], 2 - xr);
					return { 2 - y, y };
				}
			}
		}
		
		// x - y = 2 * m
		{
			int l = getdsc(xl - 2 * m), r = getdsc(xr - 2 * m);
			
			l = max(l, 1); r = max(r, 0);
			yl = max(yl, r + 1);
			
			if(l <= r && tree.getData(l, r).mn == 0)
			{
				for(int i=l; i<=r; ++i) if(tree.getData(i, i).mn == 0)
				{
					int y = max(dsc[i], xl - 2 * m);
					return { y + 2 * m, y };
				}
			}
		}
		
		// x + y = 2 * n
		{
			int l = getdsc(2 * n - xr), r = getdsc(2 * n - xl);
			
			l = min(l, dcnt); r = min(r, dcnt - 1);
			yr = min(yr, l - 1);
			
			if(l <= r && tree.getData(l, r).mn == 0)
			{
				for(int i=l; i<=r; ++i) if(tree.getData(i, i).mn == 0)
				{
					int y = max(dsc[i], 2 * n - xr);
					return { 2 * n - y, y };
				}
			}
		}
		
		// x - y = 2
		{
			int l = getdsc(xl - 2), r = getdsc(xr - 2);
			
			l = min(l, dcnt); r = min(r, dcnt - 1);
			yr = min(yr, l - 1);
			
			if(l <= r && tree.getData(l, r).mn == 0)
			{
				for(int i=l; i<=r; ++i) if(tree.getData(i, i).mn == 0)
				{
					int y = max(dsc[i], xl - 2);
					return { y + 2, y };
				}
			}
		}
		
		if(yl <= yr)
		{
			auto cur = tree.getData(yl, yr);
			if(cur.mn == 0)
			{
				if(xr - xl + 1 >= 2 || ((cur.mask >> (xl & 1)) & 1))
				{
					for(int i=yl; i<=yr; ++i) if(tree.getData(i, i).mn == 0)
					{
						int x = xl, y = dsc[i];
						if((x + y) % 2 == 0)
							return { x, y };
						if(x+1 <= xr)
							return { x+1, y };
						if(y+1 <= dsc[i+1])
							return { x, y+1 };
					}
				}
			}
		}
	}
	
	return {inf, inf};
}

int main(void)
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	
	scanf("%d%d%d",&n,&m,&d);
	for(int i=1; i<=d; ++i)
		scanf("%d%d",&p[i][0],&p[i][1]);
	
	int l = -1, r = n + m;
	while(l < r)
	{
		int mid = l + (r - l + 1) / 2;
		if(check(mid).first == inf)
			r = mid - 1;
		else
			l = mid;
	}
	
	// eprintf("l = %d\n",l);
	
	auto ans = check(l);
	int x = (ans.first + ans.second) / 2;
	int y = (ans.first - ans.second) / 2;
	printf("%d %d\n",x,y);
	return 0;
}