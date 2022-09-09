#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXN = 3e5 + 5;
const int MAXM = 8 + 5;
const int ALL = (1<<8) + 5;

#define bit(x,i) (((x)>>(i))&1)

int n,m,all;
int a[MAXN][MAXM];

int s[MAXN],tot=0;
bool chk(int lim)
{
	for(int i=1; i<=n; ++i)
	{
		s[i]=0;
		for(int j=1; j<=m; ++j)
			if(a[i][j]>lim) s[i] |= 1<<(j-1);
	}
	sort(s+1,s+n+1);
	tot=unique(s+1,s+n+1)-s-1;
	for(int i=1; i<=tot; ++i)
		for(int j=1; j<=i; ++j)
			if((s[i]|s[j])==all)
				return 1;
	return 0;
}

int dsc[MAXN*MAXM],cnt=0;

struct Node
{
	int x,id;
	inline friend bool operator < (const Node &p,const Node &q){ return p.x<q.x;}
	inline friend bool operator == (const Node &p,const Node &q){ return p.x==q.x;}
}t[MAXN];

int main(void)
{
	scanf("%d%d",&n,&m);
	for(int i=1; i<=n; ++i)
		for(int j=1; j<=m; ++j)
			scanf("%d",&a[i][j]);
	
	for(int i=1; i<=n; ++i)
		for(int j=1; j<=m; ++j)
			dsc[++cnt]=a[i][j];
	sort(dsc+1,dsc+cnt+1);
	cnt=unique(dsc+1,dsc+cnt+1)-dsc-1;
	
	all=(1<<m)-1;
	int l=1,r=cnt;
	while(l<r)
	{
		int mid = (l+r)>>1;
		if(chk(dsc[mid])) l=mid+1;
		else r=mid;
	}
	
	for(int i=1; i<=n; ++i)
	{
		t[i]=(Node){0,i};
		for(int j=1; j<=m; ++j)
			if(a[i][j]>=dsc[l]) t[i].x |= 1<<(j-1);
	}
	sort(t+1,t+n+1);
	tot=unique(t+1,t+n+1)-t-1;
	for(int i=1; i<=tot; ++i)
		for(int j=1; j<=i; ++j)
		{
			if((t[i].x|t[j].x)==all)
			{
				printf("%d %d",t[i].id,t[j].id);
				return 0;
			}
		}
	return 0;
}