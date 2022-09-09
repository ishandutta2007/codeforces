#include<cstdio>
#include<cmath>
#include<algorithm>
#define pi 3.1415927
typedef long double db;
const int MAXN = 1e5 + 5;
const db inf = 1e6;
using namespace std;

int x[MAXN],y[MAXN];
struct Vec
{
	db t;
	int id;
	inline friend operator < (const Vec &a,const Vec &b){ return a.t < b.t;}
}a[MAXN];

int main(void)
{
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i)
		scanf("%d%d",&x[i],&y[i]);
	
	for(int i=1; i<=n; ++i)
	{
		a[i].t = atan2((db)y[i],(db)x[i]);
		a[i].id = i;
	}
	
	sort(a+1,a+n+1);
	
	int ans=1;
	db anst = a[1].t - a[n].t;
	if(anst<0) anst += 2*acos(-1);
	
	for(int i=2; i<=n; ++i)
		if(a[i].t-a[i-1].t < anst)
		{
			anst = a[i].t-a[i-1].t;
			if(anst<0) anst += 2*acos(-1);
			ans=i;
		}
	
	printf("%d %d",a[ans].id, ans==1? a[n].id: a[ans-1].id);
	return 0;
}