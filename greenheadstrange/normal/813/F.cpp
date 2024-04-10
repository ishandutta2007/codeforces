#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <set>
#define maxn 200005
using namespace std;
struct eg
{
	int u, v, id;
	bool operator < (const eg &a)const
	{
		if(u != a.u) return u < a.u;
		return v < a.v;
	}
};
set <eg> hv;
struct edge
{
	int id;
	edge *next;
}pool[maxn << 3];

edge *h[maxn];
int l[maxn], r[maxn], ch[maxn][2], root = 1;
int cnt = 2, egcnt = 1;
void bdtree(int id, int nl, int nr)
{
	l[id] = nl, r[id] = nr;
	if(nl == nr) return;
	ch[id][0] = cnt++, ch[id][1] = cnt++;
	int mid = (nl + nr) >> 1;
	bdtree(ch[id][0], nl, mid), bdtree(ch[id][1], mid + 1, nr);
}

void ins(int id, int ql, int qr, int pl)
{
	if(l[id] == ql && r[id] == qr)
	{
		edge *new1 = &pool[egcnt++];
		new1->id = pl;
		new1->next = h[id], h[id] = new1;
	///	cout<<"IEDGE"<<id<<" "<<ql<<" "<<qr<<" "<<pl<<endl;
		return;
	}
	int mid = (l[id] + r[id]) >> 1;
	if(qr <= mid) ins(ch[id][0], ql, qr, pl);
	else if(ql > mid) ins(ch[id][1], ql, qr, pl);
	else ins(ch[id][0], ql, mid, pl), ins(ch[id][1], mid + 1, qr, pl);
}
int ans[maxn];
int fa[maxn], len[maxn], size[maxn]; // len 0 : same 1 : notsame
int lk[maxn], u[maxn], v[maxn];
int bg[maxn], ed[maxn];
int nl;
int gfa(int a)
{
	if(fa[a] == a)
	{
		nl = 0;
		return a;
	}
	int ans = gfa(fa[a]);
	nl ^= len[a];
	return ans;
} 
void del(int a, int num)
{
	size[a] -= num;
	if(fa[a] == a) return ;
	else del(fa[a], num);
}	
int n, q;
void dfs(int id, int ql, int qr)
{
//	cout<<id<<" "<<ql<<" "<<qr<<endl;
//	cout<<"TREE"<<endl;
//	for(int i = 1; i <= n; i++)
//		cout<<i<<" "<<fa[i]<<" "<<len[i]<<" "<<size[i]<<endl;

	bool flag = 1;
	for(edge *p = h[id]; p; p = p->next)
	{
	
		int ufa = gfa(u[p->id]);
		int ul = nl;
		int vfa = gfa(v[p->id]);
		int vl = nl;
		if(vfa != ufa)
		{	
		//	cout<<"INS"<<p->id<<endl;
			if(size[vfa] > size[ufa]) swap(ufa, vfa);
			len[vfa] = (ul ^ vl) ^ 1, fa[vfa] = ufa, size[ufa] += size[vfa], lk[p->id] = vfa;
		}
		else
			if(ul == vl)
			{
			//	cout<<"!!!"<<endl;
				flag = 0, lk[p->id] = 0;
				break;
			}
	}
	int mid = (ql + qr) >> 1;
	if(!flag) for(int i = ql; i <= qr; i++) ans[i] = 0;
	else if(ql == qr) ans[ql] = 1;
	else dfs(ch[id][0], ql, mid), dfs(ch[id][1], mid + 1, qr);
	for(edge *p = h[id]; p; p = p->next)
	{
		int ns = lk[p->id];
		if(!ns) continue;
		else del(fa[ns], size[ns]), fa[ns] = ns, len[ns] = 0;
		lk[p->id] = 0;
	}
}
int main()
{

	scanf("%d%d", &n, &q);
	for(int i = 1; i <= n; i++)
		fa[i] = i, len[i] = 0, size[i] = 1;
	int idcnt = 1;
	for(int i = 1; i <= q; i++)
	{
		eg new1;
		scanf("%d%d", &new1.u, &new1.v), new1.id = idcnt;
		set <eg> ::iterator it;
		it = hv.find(new1);
		if(it != hv.end()) ed[(*it).id] = i, hv.erase(it);
		else idcnt++, bg[new1.id] = i, u[new1.id] = new1.u, v[new1.id] = new1.v, hv.insert(new1);
	}
	bdtree(root, 1, q);
	for(int i = 1; i < idcnt; i++)
	{
		if(!ed[i]) ed[i] = q + 1;
	//	cout<<i<<" "<<bg[i]<<" "<<ed[i]<<" "<<u[i]<<" "<<v[i]<<endl;
		ins(root, bg[i], ed[i] - 1, i);
	}
	dfs(1, 1, q);
	for(int i = 1; i <= q; i++)
		if(ans[i]) printf("YES\n");
		else printf("NO\n");
	return 0;
}