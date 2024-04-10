#include<cstdio>
#include<iostream>
#include<algorithm>
typedef long long ll;
const int MAXN = 2e3 + 5;
using namespace std;

struct Point
{
	int x,y;
}a[MAXN];

typedef Point Vec;

Vec v[MAXN*MAXN];
int cnt=0;
inline bool cmp(const Vec &a,const Vec &b){ return a.x==b.x? a.y<b.y: a.x<b.x;}

int main(void)
{
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i) scanf("%d%d",&a[i].x,&a[i].y);
	for(int i=1; i<=n; ++i)
		for(int j=1; j<=n; ++j)
			if(i!=j) v[++cnt] = (Vec){a[i].x-a[j].x, a[i].y-a[j].y};
	sort(v+1,v+cnt+1,cmp);
	
	ll ans=0;
	for(int l=1,r=1; l<=cnt; l=r)
	{
		while(r<=cnt && v[r].x==v[l].x && v[r].y==v[l].y) ++r;
		ans += ((ll)(r-l)*(r-l-1))>>1ll;
	}
	cout<<(ans>>2ll);
	return 0;
}