#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

const int MN = 1e5 + 100;
const int MV = 3e5 + 10000;

int N;

int gcd(int a, int b) {return a?gcd(b%a,a):b;}
struct vec
{
	int x, y;
	vec(int a = 0, int b = 0) : x(a), y(b) {}
	vec simp(void)
	{
		int k = gcd(abs(x), abs(y));
		if(k) x/=k, y/=k;
		return *this;
	}
	bool operator < (const vec& o) const {return x < o.x || (!(o.x < x) && y < o.y);}
	vec operator - (const vec& o) const {return {x-o.x,y-o.y};}
	bool operator == (const vec& o) const {return x==o.x&&y==o.y;}
};
vec nvec(void)
{
	int x, y; scanf("%d%d", &x, &y);
	return {x,y};
}

vec v[MV]; int V;
int k[MN];
vector<vec> n[MN], d[MN];
vector<int> s[MN];


int Q, H;
int q[MV], last[MV];
int h[MV];
int bit[MV];
void upd(int x, int v = 1)
{
	for(++x;x<MV;x+=-x&x)
		bit[x]+=v;
}
int cnt(int x)
{
	int r = 0;
	for(;x;x-=-x&x)//no ++x
		r+=bit[x];
	return r;
}
void append(int i, int v)
{
	if(last[v])
		upd(last[v], -1);
	last[v] = i;
	upd(i);
}
int ans[MN];
struct Qry
{
	int l, r;
	int id;
	bool operator < (const Qry& o) const {return l < o.l || (!(o.l < l) && id < o.id);}
};
vector<Qry> qry;

int main(void)
{
	scanf("%d", &N);
	for(int i = 0;i < N;i++)
	{
		scanf("%d", k+i);
		for(int j = 0;j < k[i];j++)
			n[i].push_back(nvec());
		for(int j = 0;j < k[i]-1;j++)
			d[i].push_back(n[i][j+1]-n[i][j]);
		d[i].push_back(n[i].front()-n[i].back());
		for(vec& x : d[i])
			v[V++] = x.simp();
	}
	//assert(V < MV);
	sort(v, v+V);
	V = unique(v,v+V)-v;
	for(int i = 0;i < N;d[i++].clear())
		for(vec& x : d[i])
			s[i].push_back(lower_bound(v,v+V,x)-v);

	//for(int i = 0;i < N;i++) for(int j = 0;j < s[i].size();j++) printf("%d%c", s[i][j], "\n "[j+1<s[i].size()]);

	H = 1;
	for(int i = 0;i < N;i++)
	{
		q[i] = H;
		for(int x : s[i])
			h[H++] = x;
	}
	q[N] = H;

	//for(int i = 0;i < N;i++) printf("%d: %d\n", i, q[i]);
	//printf("\n"); for(int i = 1;i < H;i++) printf("%d: %d\n", i, h[i]); printf("\n");
	
	scanf("%d", &Q);
	for(int i = 0, l, r;i < Q;i++)
		scanf("%d%d", &l, &r), qry.push_back({q[--l], q[r], i});
	sort(qry.begin(), qry.end());
	for(int i = H-1, j = Q-1;i >= 1;i--)
	{
		append(i, h[i]);
		for(;j >= 0 && i == qry[j].l;j--)
			ans[qry[j].id] = cnt(qry[j].r);
	}
	for(int i = 0;i < Q;i++)
		printf("%d\n", ans[i]);
	return 0;
}