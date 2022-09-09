#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN = 2e5 + 5;

inline void chk_max(int &a,int b){ if(a<b) a=b;}

struct Node
{
	int x,t;
}p[MAXN];
inline bool cmp(const Node &p,const Node &q){ return p.t<q.t;}
ll sum[MAXN];
int sa[MAXN],sb[MAXN];

int q[MAXN*2],m;

void solve(void)
{
	int n,t,a,b;
	scanf("%d%d%d%d",&n,&t,&a,&b);
	for(int i=1; i<=n; ++i)
	{
		int type;
		scanf("%d",&type);
		if(type) p[i].x=b;
		else p[i].x=a;
	}
	m=0;
	for(int i=1; i<=n; ++i)
	{
		scanf("%d",&p[i].t);
		q[++m] = max(p[i].t-1, 0);
		q[++m] = p[i].t;
	}
	q[++m]=0; q[++m]=t;
	
	sort(q+1,q+m+1);
	m=unique(q+1,q+m+1)-q-1;
	
	sort(p+1,p+n+1,cmp);
	for(int i=1; i<=n; ++i)
	{
		sum[i] = sum[i-1]+p[i].x;
		sa[i] = sa[i-1];
		sb[i] = sb[i-1];
		if(p[i].x==a) ++sa[i];
		else ++sb[i];
	}
	int tota=sa[n], totb=sb[n];
	
	int ans=0;
	for(int i=1,j=1; i<=m; ++i)
	{
		while(j<=n && p[j].t<=q[i]) ++j;
		if(q[i]<sum[j-1]) continue;
		
		int now = q[i]-sum[j-1];
		int na=tota-sa[j-1], nb=totb-sb[j-1];
		
		int res=j-1;
		if((ll)na*a <= now)
			now -= na*a,
			res += na;
		else res += now/a, now%=a;
		
		if((ll)nb*b <= now)
			now -= nb*b,
			res += nb;
		else res += now/b, now%=b;
		
		chk_max(ans,res);
	}
	//printf("================>");
	printf("%d\n",ans);
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}