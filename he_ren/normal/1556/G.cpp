#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const int MAXN = 50 + 5;
const int MAXM = 5e4 + 5;
const int MAXP = MAXM * 4;

struct Data
{
	ll l,r;
	int t;
	Data(void){}
	Data(ll _l,ll _r,int _t): l(_l), r(_r), t(_t) {}
};

inline bool cmp(const Data &p,const Data &q){ return p.r < q.r;}

int m;
vector<int> g[MAXP], pt[MAXM];
int val[MAXP];
int pcnt = 0;

inline int new_pt(int t)
{
	val[++pcnt] = t;
	pt[t].push_back(pcnt);
	return pcnt;
}

Data dat[MAXM * 2];
vector<Data> get_pt(ll l,ll r,int vl,int vr)
{
	if(vl > vr)
		return vector<Data>();
	if(vl == vr && dat[vl].l <= l && r <= dat[vl].r)
		return vector<Data>(1, Data(l, r, new_pt(dat[vl].t)));
	
	ll mid = (l+r) >> 1;
	int vmid = vl;
	while(vmid <= vr && dat[vmid].l <= mid) ++vmid;
	--vmid;
	
	bool flagl = 0, flagr = 0;
	if(vmid >= vl && dat[vmid].l <= mid && mid < dat[vmid].r)
	{
		flagl = dat[vmid].r >= r;
		flagr = dat[vmid].l <= l;
	}
	
	vector<Data> lef = get_pt(l, mid, vl, vmid - flagl);
	if(vmid < vl) vmid = vl;
	if(vmid <= vr && dat[vmid].r <= mid) ++vmid;
	vector<Data> rig = get_pt(mid+1, r, vmid + flagr, vr);
	
	ll h = ((l ^ r) + 1) >> 1;
	
	int i=0, j=0;
	while(i<(int)lef.size() && j<(int)rig.size())
	{
		while(i<(int)lef.size() && lef[i].r < (rig[j].l ^ h)) ++i;
		if(i >= (int)lef.size()) break;
		while(j<(int)rig.size() && rig[j].r < (lef[i].l ^ h)) ++j;
		if(j >= (int)rig.size()) break;
		
		int u = lef[i].t, v = rig[j].t;
		if(val[u] <= val[v]) g[u].push_back(v);
		else g[v].push_back(u);
		
		if(lef[i].r == (rig[j].r ^ h)) ++i, ++j;
		else if(lef[i].r < (rig[j].r ^ h)) ++i;
		else ++j;
	}
	
	if(flagl) rig[0].l = dat[vmid].l;
	if(flagr) lef[0].r = dat[vmid].r;
	
	lef.insert(lef.end(), rig.begin(), rig.end());
	return lef;
}

pair<ll,ll> qry[MAXM];
int res[MAXM];

int fa[MAXP];
inline void init(int _n){ for(int i=1; i<=_n; ++i) fa[i] = i;}
int find(int u){ return fa[u] == u? u: fa[u] = find(fa[u]);}
inline void connect(int u,int v){ fa[find(u)] = find(v);}

vector<Data> ids;
inline int get_id(ll k)
{
	return lower_bound(ids.begin(), ids.end(), Data(k,k,0), cmp) -> t;
}

int main(void)
{
	int n;
	scanf("%d%d",&n,&m);
	
	vector<Data> vec1(1, Data(-1,-1,0)), vec2;
	for(int i=1; i<=m; ++i)
	{
		static char s[100];
		ll x,y;
		scanf("%s%lld%lld",s+1,&x,&y);
		if(s[1] == 'a') qry[i] = make_pair(x,y);
		else vec1.push_back(Data(x, y, i));
	}
	
	sort(vec1.begin(), vec1.end(), cmp);
	vec1.push_back(Data(1ll<<n, 1ll<<n, 0));
	
	for(int i=1; i<(int)vec1.size(); ++i)
		if(vec1[i].l - 1 >= vec1[i-1].r + 1)
			vec2.push_back(Data(vec1[i-1].r + 1, vec1[i].l - 1, m + 1));
	
	vec1.pop_back(); vec1.erase(vec1.begin());
	int tot = (int)vec1.size() + (int)vec2.size();
	merge(vec1.begin(), vec1.end(), vec2.begin(), vec2.end(), dat+1, cmp);
	
	ids = get_pt(0, (1ll<<n) - 1, 1, tot);
	
	init(pcnt);
	for(int i=m+1; i>=1; --i)
	{
		if(i > m || pt[i].size())
		{
			for(int j=0; j<(int)pt[i].size(); ++j)
			{
				int u = pt[i][j];
				for(int k=0; k<(int)g[u].size(); ++k)
					connect(u, g[u][k]);
			}
		}
		else
		{
			int u = get_id(qry[i].first);
			int v = get_id(qry[i].second);
			res[i] = find(u) == find(v);
		}
	}
	
	for(int i=1; i<=m; ++i)
		if(!pt[i].size()) printf("%d\n",res[i]);
	return 0;
}