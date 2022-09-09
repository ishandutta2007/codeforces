#include<cstdio>
#include<algorithm>
using namespace std;
typedef pair<int,int> pii;
#define fir first
#define sec second
#define Mp make_pair
const int MAXN = 2e5 + 5;
const int MAXM = 2e5 + 5;

struct Query
{
	int k,pos,id,ans;
}qry[MAXM];
inline bool cmp1(const Query &p,const Query &q){ return p.k<q.k;}
inline bool cmp2(const Query &p,const Query &q){ return p.id<q.id;}

int n;
pii a[MAXN];
int b[MAXN];

int sum[MAXN];
#define lowbit(x) ((x)&-(x))
inline void update(int x,int k)
{
	while(x<=n)
		sum[x]+=k,
		x+=lowbit(x);
}
inline int query(int x)
{
	int res=0;
	while(x)
		res+=sum[x],
		x^=lowbit(x);
	return res;
}

int main(void)
{
	scanf("%d",&n);
	for(int i=1; i<=n; ++i)
	{
		scanf("%d",&b[i]);
		a[i] = Mp(-b[i],i);
	}
	sort(a+1,a+n+1);
	
	int m;
	scanf("%d",&m);
	for(int i=1; i<=m; ++i)
	{
		int k,pos;
		scanf("%d%d",&k,&pos);
		qry[i] = (Query){k,pos,i};
	}
	sort(qry+1,qry+m+1,cmp1);
	
	for(int i=1,j=1; j<=m; ++i)
	{
		update(a[i].sec,1);
		for(; j<=m && qry[j].k==i; ++j)
		{
			int l=1,r=n;
			while(l<r)
			{
				int mid=(l+r)>>1;
				if(query(mid)>=qry[j].pos) r=mid;
				else l=mid+1;
			}
			qry[j].ans=b[l];
		}
	}
	
	sort(qry+1,qry+m+1,cmp2);
	for(int i=1; i<=m; ++i)
		printf("%d\n",qry[i].ans);
	return 0;
}