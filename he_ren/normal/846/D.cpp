#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXN = 5e2 + 5;
const int MAXM = 5e2 + 5;
const int MAXQ = MAXN * MAXM;

struct Node
{
	int x,y,t;
}a[MAXQ];
inline bool cmp(const Node &p,const Node &q){ return p.t<q.t;}

int n,m,d;
int b[MAXN][MAXM],s[MAXN][MAXM];

bool chk(int mid)
{
	for(int i=1; i<=n; ++i)
		for(int j=1; j<=m; ++j)
			b[i][j]=1, s[i][j]=0;
	for(int i=1; i<=mid; ++i)
		b[a[i].x][a[i].y]=0;
	
	for(int i=1; i<=n; ++i)
		for(int j=1; j<=m; ++j)
			s[i][j] = b[i][j] + s[i-1][j]+s[i][j-1]-s[i-1][j-1];
	
	for(int i=d; i<=n; ++i)
		for(int j=d; j<=m; ++j)
		{
			int sum = s[i][j]-s[i-d][j]-s[i][j-d]+s[i-d][j-d];
			if(!sum) return 1;
		}
	return 0;
}

int main(void)
{
	int q;
	scanf("%d%d%d%d",&n,&m,&d,&q);
	for(int i=1; i<=q; ++i)
		scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].t);
	
	sort(a+1,a+q+1,cmp);
	int l=1, r=q;
	while(l<r)
	{
		int mid=(l+r)>>1;
		if(chk(mid)) r=mid;
		else l=mid+1;
	}
	
	if(chk(l)) printf("%d",a[l].t);
	else printf("-1");
	return 0;
}