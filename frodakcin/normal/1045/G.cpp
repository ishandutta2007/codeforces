#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
#include <functional>

using ll = long long;
const int MN=1e5+10;
int N, K, Q, iq[MN], loc[MN], rm[MN];
bool cmp(int x, int y){return rm[x]>rm[y];}//reversed for pq
std::priority_queue<int, std::vector<int>, std::function<bool(int, int)> > q(cmp);
ll ans;
struct robot
{
public:
	int x, r, q;
	void in(){scanf("%d%d%d", &x, &r, &q);}
	bool operator < (robot o) const {return x < o.x;}
};
robot a[MN];
struct BIT
{
public:
	std::vector<int> a;
	std::vector<int> x;
	int S, L, tot;
	void build()
	{
		S=x.size();
		a.assign(S, 0);
		L=31-__builtin_clz(S);
	}
	void upd(int n, int v)
	{
		tot+=v;
		for(++n;n<=S;n+=-n&n)
			a[n-1]+=v;
	}
	int get(int n)
	{
		int i=0,j=L,f=0;
		for(;j>=0;--j)
			if((i|1<<j)<=S&&x[(i|1<<j)-1]<n)
				f+=a[(i|=1<<j)-1];
		return tot-f;
	}
};
BIT bit[MN];
int main(void)
{
	scanf("%d%d", &N, &K);
	for(int i=0;i<N;++i)
		a[i].in(), iq[i]=a[i].q;
	std::sort(a, a+N);
	std::sort(iq, iq+N);
	Q = std::unique(iq, iq+N)-iq;
	for(int i=0;i<N;++i)
	{
		int q=a[i].q=std::lower_bound(iq, iq+Q, a[i].q)-iq;
		if(bit[q].x.empty() || bit[q].x.back() != a[i].x)
			bit[q].x.push_back(a[i].x);
		loc[i]=bit[q].x.size()-1;
	}
	for(int i=0;i<Q;++i)
		bit[i].build();
	for(int i=0;i<N;++i)
	{
		while(!q.empty() && rm[q.top()] < a[i].x)
		{
			int x=q.top(); q.pop();
			bit[a[x].q].upd(loc[x], -1);
		}
		int miq=iq[a[i].q];
		for(int j=a[i].q;j<Q&&miq+K>=iq[j];++j)
			ans+=bit[j].get(a[i].x-a[i].r);
		for(int j=a[i].q-1;j>=0&&iq[j]+K>=miq;--j)
			ans+=bit[j].get(a[i].x-a[i].r);
		bit[a[i].q].upd(loc[i], 1);
		rm[i]=a[i].x+a[i].r;
		q.push(i);
	}
	printf("%lld\n", ans);
	return 0;
}