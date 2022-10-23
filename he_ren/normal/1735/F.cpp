#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef __float128 ldb;
typedef pair<int,int> pii;
const int MAXN = 3e5 + 5;
const ldb eps = 1e-9;

mt19937 gen((unsigned long long)new char ^ time(0));

inline int sgn(ldb x){ return x<-eps? -1: x>eps? 1: 0;}

int a[MAXN], b[MAXN];

void solve(void)
{
	int n;
	scanf("%d%d%d",&n,&b[0],&a[0]);
	for(int i=1; i<=n; ++i)
		scanf("%d",&b[i]);
	for(int i=1; i<=n; ++i)
		scanf("%d",&a[i]);
	
	ldb sx = a[0], sy = b[0], tx = sx, ty = sy;
	multiset< pair<ldb,ldb> > q;
	
	for(int rn=1; rn<=n; ++rn)
	{
		{
			ldb x = a[rn], y = b[rn];
			q.emplace(y / x, 2 * x);
			sx -= x; sy += y; tx += x; ty -= y;
		}
		
		while(sgn(sx) < 0 && q.size())
		{
			auto V = *q.begin(); q.erase(q.begin());
			ldb delta = min(V.second, - sx);
			sx += delta; sy -= delta * V.first;
			V.second -= delta;
			if(sgn(V.second) > 0) q.emplace(V); 
		}
		while(sgn(ty) < 0 && q.size())
		{
			auto V = *q.rbegin(); q.erase(q.find(V));
			ldb delta = min(V.second, - ty / V.first);
			tx -= delta; ty += delta * V.first;
			V.second -= delta;
			if(sgn(V.second) > 0) q.emplace(V);
		}
		
		printf("%.10lf\n",(double)sy);
	}
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}