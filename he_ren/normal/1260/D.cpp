#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 2e5 + 5;
const int MAXM = 2e5 + 5;
const int MAXD = 2e5 + 5;

struct Seg
{
	int l,r,d;
}p[MAXD];
int a[MAXN];

int n,m,d,t;

bool check(int mid)
{
	if(mid > n) return 1;
	
	static int dif[MAXM];
	for(int i=1; i<=m+1; ++i) dif[i] = 0;
	for(int i=1; i<=d; ++i)
		if(p[i].d > a[mid])
		{
			++dif[p[i].l];
			--dif[p[i].r+1];
		}
	
	int res = m+1;
	for(int i=1; i<=m; ++i)
	{
		dif[i] += dif[i-1];
		if(dif[i]) res += 2;
	}
	
	return res <= t;
}

int main(void)
{
	scanf("%d%d%d%d",&n,&m,&d,&t);
	for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
	for(int i=1; i<=d; ++i)
		scanf("%d%d%d",&p[i].l,&p[i].r,&p[i].d);
	
	sort(a+1,a+n+1);
	
	int l=1, r=n+1;
	while(l<r)
	{
		int mid = (l+r)>>1;
		if(check(mid)) r=mid;
		else l=mid+1;
	}
	printf("%d",n-l+1);
	return 0;
}