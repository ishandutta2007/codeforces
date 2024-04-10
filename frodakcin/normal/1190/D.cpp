#include <cstdio>
#include <algorithm>

using namespace std;

using ll = long long;
#define tl(X) static_cast<ll>(X)

const int MN = 2e5 + 100;

int N;
int x[MN], X;
struct P
{
	int x,y;
	bool operator < (const P& o) const {return y>o.y||(!(o.y>y) && x < o.x);}
};
P p[MN];
int b[MN];
void upd(int x, int v) {for(++x;x<=X+5;x+=x&-x) b[x]+=v;}
int cnt(int x)
{
	int r = 0;
	for(++x;x;x-=-x&x) r += b[x];
	return r;
}
bool u[MN];
ll ans;
int main(void)
{
	scanf("%d", &N);
	for(int i = 0;i < N;i++)
		scanf("%d%d", &p[i].x, &p[i].y), x[X++] = p[i].x;
	sort(x,x+X); X = unique(x,x+X)-x;
	for(int i = 0;i < N;i++)
		p[i].x = lower_bound(x,x+X,p[i].x)-x;
	sort(p,p+N);
	for(int i = 0, j;i < N;i=j)
	{
		for(j=i;j < N && p[i].y==p[j].y;j++)
			if(!u[p[j].x])
				upd(p[j].x+1, u[p[j].x]=1);
		for(int k = i, l=-1;k < j;l=p[k++].x)
			ans += tl(cnt(p[k].x+1)-cnt(l+1))*(cnt(X)-cnt(p[k].x));
	}
	printf("%lld\n", ans);
	return 0;
}