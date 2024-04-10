#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 2e5 + 5;
const int MAXQ = 2e5 + 5;
const int MAXP = MAXN * 2;

template<typename T>
ostream& operator << (ostream &o,const vector<T> &vec)
{
	if(!vec.size()) return o << "{}";
	o << '{' << vec[0];
	for(int i=1; i<(int)vec.size(); ++i)
		o << ", " << vec[i];
	return o << '}';
}

struct BIT
{
	ll tree[MAXN * 2], n;
	#define lowbit(x) ((x)&-(x))
	inline void update(int x,int k)
	{
		while(x<=n)
			tree[x] += k,
			x += lowbit(x);
	}
	inline ll query(int x)
	{
		ll res=0;
		while(x)
			res += tree[x],
			x ^= lowbit(x);
		return res;
	}
	inline ll query(int l,int r){ return query(r) - query(l-1);}
};

int mx_val;

struct Counter_2D
{
	struct Data
	{
		int type, x, yl, yr;
		Data(void){}
		Data(int _type,int _x,int _yl,int _yr): type(_type), x(_x), yl(_yl), yr(_yr) {}
	};
	static inline bool cmp(const Data &p,const Data &q){ return p.x == q.x? p.type < q.type: p.x < q.x;}
	vector<Data> dat;
	ll res[MAXQ * 2];
	BIT tree;
	inline void clear(void){ dat.clear();}
	inline void add_p(int x,int y,int val){ dat.push_back(Data(0, x, y, val));}
	inline void add_qry(int id,int x,int yl,int yr){ dat.push_back(Data(id, x, yl, yr));}
	inline void add_qry(int id,int xl,int xr,int yl,int yr)
	{
		add_qry(id, xl-1, yl, yr);
		add_qry(MAXQ + id, xr, yl, yr);
	}
	inline void build(void)
	{
		sort(dat.begin(), dat.end(), cmp);
		for(int i=0; i<(int)dat.size(); ++i)
		{
			if(dat[i].type)
				res[dat[i].type] = tree.query(dat[i].yl, dat[i].yr);
			else tree.update(dat[i].yl, dat[i].yr);
		}
		for(int i=0; i<(int)dat.size(); ++i)
			if(!dat[i].type)
				tree.update(dat[i].yl, -dat[i].yr);
	}
	inline ll get(int id){ return res[id + MAXQ] - res[id];}
}slv1, slv2;

namespace SAM
{
	int len[MAXP], son[MAXP][26], fail[MAXP], pcnt = 1;
	inline int new_Node(int _len){ len[++pcnt] = _len; return pcnt;}
	inline int get_nq(int p,int c)
	{
		int q = son[p][c];
		if(len[q] == len[p] + 1) return q;
		int nq = new_Node(len[p] + 1);
		memcpy(son[nq], son[q], sizeof(son[q]));
		fail[nq] = fail[q]; fail[q] = nq;
		for(; q && son[p][c] == q; p = fail[p]) son[p][c] = nq;
		return nq;
	}
	inline int insert(int p,int c)
	{
		int np = new_Node(len[p] + 1);
		for(; p && !son[p][c]; p = fail[p]) son[p][c] = np;
		fail[np] = p? get_nq(p,c): 1;
		return np;
	}
} using SAM::len;

vector<int> g[MAXP];
int dep[MAXP], t[MAXP], pt[MAXN];
vector<pii> qs[MAXN];
ll res[MAXQ];

namespace Divid
{
	bool del[MAXP];
	int siz[MAXP], mxson[MAXP];
	void dfs_siz(int u,int fa)
	{
		siz[u] = 1; mxson[u] = 0;
		for(int i=0; i<(int)g[u].size(); ++i)
		{
			int v = g[u][i];
			if(v == fa || del[v]) continue;
			dfs_siz(v,u);
			siz[u] += siz[v];
			mxson[u] = max(mxson[u], siz[v]);
		}
	}
	int rt, tot_siz;
	void dfs_rt(int u,int fa)
	{
		mxson[u] = max(mxson[u], tot_siz - siz[u]);
		if(mxson[u] < mxson[rt]) rt = u;
		for(int i=0; i<(int)g[u].size(); ++i)
		{
			int v = g[u][i];
			if(v == fa || del[v]) continue;
			dfs_rt(v, u);
		}
	}
	
	int f[MAXN];
	void dfs_f(int u,int fa)
	{
		for(int i=0; i<(int)g[u].size(); ++i)
		{
			int v = g[u][i];
			if(v == fa || del[v]) continue;
			f[v] = dep[v] < dep[f[u]]? v: f[u];
			dfs_f(v,u);
		}
	}
	
	void dfs_nodes(int u,int fa,int seq[],int &cur)
	{
		if(t[u]) seq[++cur] = t[u];
		for(int i=0; i<(int)g[u].size(); ++i)
		{
			int v = g[u][i];
			if(v == fa || del[v]) continue;
			dfs_nodes(v,u,seq,cur);
		}
	}
	
	int fv[MAXN], sv[MAXN], fsiz, ssiz;
	ll sum[MAXN];
	
	inline ll calc(int vl,int vr,int k,int ql,int qr)// sum_{vl <= i <= vr} min(vr+1, i+k)
	{
		int il = lower_bound(sv+ql, sv+qr+1, vl) - sv;
		int ir = upper_bound(sv+ql, sv+qr+1, vr) - sv - 1;
		if(il > ir) return 0;
		int pos = lower_bound(sv+il, sv+ir+1, vr + 1 - k) - sv - 1;
		return
			sum[pos] - sum[il-1] + (ll)k * (pos - il + 1)
			+ (ll)(ir - pos) * (vr + 1);
	}
}

void divid(int u)
{
	using namespace Divid;
	dfs_siz(u,0);
	tot_siz = siz[rt = u];
	dfs_rt(u,0);
	del[u = rt] = 1;
	
//	printf("rt = %d\n",rt);
	
	fsiz = ssiz = 0;
	f[u] = u;
	if(t[u]) sv[++ssiz] = t[u];
	for(int i=0; i<(int)g[u].size(); ++i)
	{
		int v = g[u][i];
		if(del[v]) continue;
		if(dep[v] < dep[u])
		{
			f[v] = v;
			dfs_nodes(v,u, fv,fsiz);
			dfs_f(v,u);
		}
		else
		{
			int lst = ssiz;
			dfs_nodes(v,u, sv,ssiz);
			sort(sv + lst + 1, sv + ssiz + 1);
			for(int j=lst+1; j<=ssiz; ++j)
				sum[j] = sum[j-1] + sv[j];
			for(int j=lst+1; j<=ssiz; ++j)
			{
				int cur = sv[j], vl = cur;
				for(int k=0; k<(int)qs[cur].size(); ++k)
				{
					int vr = qs[cur][k].first, qid = qs[cur][k].second;
					res[qid] -= calc(vl, vr, len[u], lst + 1, ssiz);
//					printf("calc(%d, %d, %d, %d, %d) = %lld\n",vl,vr,len[u],lst+1,ssiz,calc(vl, vr, len[u], lst + 1, ssiz));
				}
			}
		}
	}
	
//	cout << "fv = " << vector<int>(fv+1, fv+fsiz+1) << endl;
//	cout << "sv = " << vector<int>(sv+1, sv+ssiz+1) << endl;
	
	sort(sv+1, sv+ssiz+1);
	for(int i=1; i<=ssiz; ++i)
		sum[i] = sum[i-1] + sv[i];
	for(int i=1; i<=ssiz; ++i)
	{
		int cur = sv[i], vl = cur;
		for(int k=0; k<(int)qs[cur].size(); ++k)
		{
			int vr = qs[cur][k].first, qid = qs[cur][k].second;
			res[qid] += calc(vl, vr, len[u], 1, ssiz);
//			printf("calc(%d, %d, %d, %d, %d) = %lld\n",vl,vr,len[u],1,ssiz,calc(vl, vr, len[u], 1, ssiz));
		}
	}
	for(int i=1; i<=fsiz; ++i)
	{
		int cur = fv[i], vl = cur;
		for(int k=0; k<(int)qs[cur].size(); ++k)
		{
			int vr = qs[cur][k].first, qid = qs[cur][k].second;
			res[qid] += calc(vl, vr, len[f[ pt[cur] ]], 1, ssiz);
//			printf("calc(%d, %d, %d, %d, %d) = %lld\n",vl, vr, len[f[pt[cur]]],1,ssiz,calc(vl, vr, len[f[ pt[cur] ]], 1, ssiz));
		}
	}
	
	slv1.clear(); slv2.clear();
	for(int i=1; i<=fsiz; ++i)
	{
		int v = fv[i], k = len[f[ pt[v] ]] + v;
		slv1.add_p(v, k, 1);
		slv2.add_p(v, k, k);
//		printf("slv1.add: %d %d\n",v,k);
//		printf("slv2.add: %d %d %d\n",v,k,k);
	}
	
	for(int i=1; i<=ssiz; ++i)
	{
		int v = sv[i], vl = v;
		for(int j=0; j<(int)qs[v].size(); ++j)
		{
			int vr = qs[v][j].first, qid = qs[v][j].second;
			slv1.add_qry(qid, vl, vr, vr+1, mx_val);
			slv2.add_qry(qid, vl, vr, 1, vr);
//			printf("slv1.add_qry: %d %d %d %d\n",vl,vr,vr+1,mx_val);
//			printf("slv2.add_qry: %d %d %d %d\n",vl,vr,1,vr);
		}
	}
	
	slv1.build(); slv2.build();
	
	for(int i=1; i<=ssiz; ++i)
	{
		int v = sv[i];
		for(int j=0; j<(int)qs[v].size(); ++j)
		{
			int vr = qs[v][j].first, qid = qs[v][j].second;
			res[qid] += (ll)slv1.get(qid) * (vr + 1) + slv2.get(qid);
//			printf("res += %lld\n",(ll)slv1.get(qid) * (vr + 1) + slv2.get(qid));
		}
	}
	
	for(int i=0; i<(int)g[u].size(); ++i)
		if(!del[g[u][i]]) divid(g[u][i]);
}

void dfs_dep(int u,int fa)
{
	for(int i=0; i<(int)g[u].size(); ++i)
	{
		int v = g[u][i];
		if(v == fa) continue;
		dep[v] = dep[u] + 1;
		dfs_dep(v, u);
	}
}

char s[MAXN];
pii qry[MAXQ];

inline ll calc(int k){ return (ll)k * (k+1) / 2;}

int main(void)
{
	int Q;
	scanf("%s%d",s+1,&Q);
	int n = strlen(s+1);
	
	int lst = 1;
	for(int i=n; i>=1; --i)
	{
		lst = SAM::insert(lst, s[i] - 'a');
		pt[i] = lst; t[lst] = i;
//		printf("pt[%d] = %d\n",i,lst);
	}
	
//	for(int i=1; i<=SAM::pcnt; ++i)
//		printf("len[%d] = %d\n",i, len[i]);
	for(int i=2; i<=SAM::pcnt; ++i)
	{
		int u = i, v = SAM::fail[i];
//		printf("fail[%d] = %d\n",u,v);
		g[u].push_back(v);
		g[v].push_back(u);
	}
	
	for(int i=1; i<=Q; ++i)
	{
		int l,r;
		scanf("%d%d",&l,&r);
		qry[i] = make_pair(l,r);
		qs[l].push_back(make_pair(r, i));
		res[i] = -(calc(r) - calc(l-1));
	}
	
	slv1.tree.n = slv2.tree.n = mx_val = n * 2;
	
	dfs_dep(1,0);
	divid(1);
	
	for(int i=1; i<=Q; ++i)
		printf("%lld\n",res[i]);
	return 0;
}