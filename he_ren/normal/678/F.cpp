#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXQ = 3e5 + 5;
const ll linf = 0x3f3f3f3f3f3f3f3f;

struct Line
{
	int k,b;
	Line(void){}
	Line(int _k,int _b): k(_k), b(_b) {}
	ll get(int x) const { return (ll)k * x + b;}
};

struct Convex_Hull
{
	vector<Line> q;
	int hd, tl;
	Convex_Hull(int siz=0): q(siz), hd(0), tl(-1) {}
	void clear(void)
	{
		hd = 0; tl = -1;
	}
	void push_back(Line p)
	{
		if(hd<=tl && q[tl].k == p.k) return;
		while(hd+1<=tl
			&& (ll)(q[tl-1].b - p.b) * (q[tl].k - q[tl-1].k)
			<= (ll)(q[tl-1].b - q[tl].b) * (p.k - q[tl-1].k)
		) --tl;
		if(++tl >= (int)q.size()) q.push_back(p);
		else q[tl] = p;
	}
	ll get(int x)
	{
		if(hd>tl) return -linf;
		while(hd+1<=tl && q[hd+1].get(x) > q[hd].get(x)) ++hd;
		return q[hd].get(x);
	}
};

struct Oper
{
	int type, l, r;
	Line p;
}op[MAXQ];

ll res[MAXQ];

void divid(int l,int r,vector<int> &Ps,vector<int> &Qs)
{
	vector<int> nPs;
	static Convex_Hull conv(MAXQ);
	conv.clear();
	for(int x: Ps)
	{
		if(op[x].r < l || r < op[x].l) continue;
		if(op[x].l <= l && r <= op[x].r)
			conv.push_back(op[x].p);
		else
			nPs.push_back(x);
	}
	for(int x: Qs)
		res[x] = max(res[x], conv.get(op[x].l));
	
	if(l == r) return;
	int mid = (l+r)>>1;
	
	vector<int> lQs, rQs;
	for(int x: Qs)
		(x <= mid? lQs: rQs).push_back(x);
	
	divid(l, mid, nPs, lQs);
	divid(mid+1, r, nPs, rQs);
}

int main(void)
{
	int n;
	scanf("%d",&n);
	vector<int> Ps, Qs;
	for(int i=1; i<=n; ++i)
	{
		int type;
		scanf("%d",&type);
		op[i].type = type;
		if(type == 1)
		{
			int k,b;
			scanf("%d%d",&k,&b);
			op[i].l = i; op[i].r = n;
			op[i].p = Line(k,b);
			Ps.push_back(i);
		}
		if(type == 2)
		{
			int x;
			scanf("%d",&x);
			op[x].r = i;
		}
		if(type == 3)
		{
			int x;
			scanf("%d",&x);
			op[i].l = op[i].r = x;
			Qs.push_back(i);
		}
	}
	
	sort(Ps.begin(), Ps.end(), [&] (int i,int j){
		return op[i].p.k != op[j].p.k? op[i].p.k < op[j].p.k: op[i].p.b > op[j].p.b;
	});
	sort(Qs.begin(), Qs.end(), [&] (int i,int j){
		return op[i].l < op[j].l;
	});
	
	memset(res, 0xc0, sizeof(res));
	divid(1, n, Ps, Qs);
	
	for(int i=1; i<=n; ++i) if(op[i].type == 3)
	{
		if(res[i] <= -linf)
			printf("EMPTY SET\n");
		else
			printf("%lld\n",res[i]);
	}
	return 0;
}