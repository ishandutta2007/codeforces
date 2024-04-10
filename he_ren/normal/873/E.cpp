#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
const int MAXN = 3e3 + 5;
const int LB = 12 + 5;

inline int min(int a,int b){ return a<b? a: b;}
inline int max(int a,int b){ return a>b? a: b;}

struct Node
{
	int x,id;
}a[MAXN];
inline bool cmp(const Node &p,const Node &q){ return p.x>q.x;}

int n,b[MAXN],ans[MAXN];

int lb[MAXN],st[MAXN][LB],mxp[MAXN][LB];
void st_init(void)
{
	++n;
	
	lb[1]=0;
	for(int i=2; i<=n; ++i) lb[i]=lb[i>>1]+1;
	
	for(int i=1; i<=n; ++i)
		st[i][0]=b[i], mxp[i][0]=i;
	for(int j=1; j<=lb[n]; ++j)
		for(int i=1; i+(1<<j)-1<=n; ++i)
		{
			int i2=i+(1<<(j-1));
			if(st[i][j-1] >= st[i2][j-1])
				st[i][j]=st[i][j-1], mxp[i][j]=mxp[i][j-1];
			else st[i][j]=st[i2][j-1], mxp[i][j]=mxp[i2][j-1];
		}
	
	--n;
}
int query(int l,int r)
{
	int lbl=lb[r-l+1], l2=r-(1<<lbl)+1;
	if(st[l][lbl] >= st[l2][lbl]) return mxp[l][lbl];
	return mxp[l2][lbl];
}

int main(void)
{
	scanf("%d",&n);
	for(int i=1; i<=n; ++i)
		scanf("%d",&a[i].x), a[i].id=i;
	
	sort(a+1,a+n+1,cmp);
	for(int i=2; i<=n+1; ++i) b[i] = a[i-1].x-a[i].x;
	
	st_init();
	
	int ai=1+n/3, aj=1+n/3*2, ak=n+1;
	for(int i=2; i<n; ++i) if(b[i]>=b[ai])
	{
		for(int j=(3*i)>>1; j<=n && j<=3*i-2; ++j)
		{
			int l = ((max(j-i,i-1)+1)>>1)+j, r = min(2*min(j-i,i-1)+j, n+1);
			if(l>r) continue;
			
			int k=query(l,r);
			bool flag=0;
			
			if(b[i]>b[ai]) flag=1;
			else if(b[i]==b[ai])
			{
				if(b[j]>b[aj]) flag=1;
				else if(b[j]==b[aj] && b[k]>b[ak]) flag=1;
			}
			if(flag) ai=i, aj=j, ak=k;
		}
	}
	
	for(int i=1; i<ai; ++i) ans[a[i].id]=1;
	for(int i=ai; i<aj; ++i) ans[a[i].id]=2;
	for(int i=aj; i<ak; ++i) ans[a[i].id]=3;
	for(int i=ak; i<=n; ++i) ans[a[i].id]=-1;
	
	for(int i=1; i<=n; ++i) printf("%d ",ans[i]);
	return 0;
}