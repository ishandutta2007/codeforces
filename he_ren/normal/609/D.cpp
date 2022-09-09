#include<cstdio>
#include<algorithm>
typedef long long ll;
typedef long double db;
const int MAXN = 2e5 + 5;
const int MAXM = 2e5 + 5;
const int inf = 1e6;
const db eps = 1e-7;
using namespace std;

inline db Fabs(db x){ return x<0? -x: x;}
inline bool eq(db x,db y){ return Fabs(x-y)<=eps;}
inline bool leq(db x,db y){ return x<y || eq(x,y);}
inline int min(int a,int b){ return a<b? a: b;}
inline void chk_min(int &a,int b){ if(a>b) a=b;}

int a[MAXN],b[MAXN];
int mda[MAXN],mdb[MAXN];
struct Node
{
	int id,c;
}c1[MAXM],c2[MAXM];
ll s1[MAXM],s2[MAXM];
int cnt1=0,cnt2=0;
inline bool cmp(const Node x,const Node y){ return x.c<y.c;}

int p,s;
int i1,i2;
inline bool check(int d)
{
	int ma=a[mda[d]], mb=b[mdb[d]];
	
	i1=0,i2=0;
	for(i1=1; i1<=cnt1 && s1[i1]*ma<=s; ++i1);
	--i1;
	
	for(; i1>=0; --i1)
	{
		for(; i2<=cnt2 && s1[i1]*ma + s2[i2]*mb <=  s; ++i2);
		--i2;
		if(i1+i2>=p) return 1;
	}
	return 0;
}

int main(void)
{
	int n,m;
	scanf("%d%d%d%d",&n,&m,&p,&s);
	for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
	for(int i=1; i<=n; ++i) scanf("%d",&b[i]);
	
	for(int i=1; i<=m; ++i)
	{
		int t,x;
		scanf("%d%d",&t,&x);
		if(t==1)
			c1[++cnt1] = (Node){i,x};
		else
			c2[++cnt2] = (Node){i,x};
	}
	sort(c1+1, c1+cnt1+1, cmp);
	sort(c2+1, c2+cnt2+1, cmp);
	for(int i=1; i<=cnt1; ++i) s1[i] = s1[i-1] + c1[i].c;
	for(int i=1; i<=cnt2; ++i) s2[i] = s2[i-1] + c2[i].c;
	
	a[0]=b[0]=inf;
	for(int i=1; i<=n; ++i)
	{
		if(a[i]<a[mda[i-1]]) mda[i]=i;
		else mda[i] = mda[i-1];
		
		if(b[i]<b[mdb[i-1]]) mdb[i]=i;
		else mdb[i] = mdb[i-1];
	}
	
	int l=1, r=n+1;
	while(l<r)
	{
		int mid = (l+r)>>1;
		if(check(mid)) r=mid;
		else l=mid+1;
	}
	
	if(l==n+1)
	{
		printf("-1");
		return 0;
	}
	
	check(l);
	printf("%d\n",l);
	for(int i=1; i<=i1 && i<=p; ++i) printf("%d %d\n",c1[i].id, mda[l]);
	for(int i=1; i1+i<=p; ++i) printf("%d %d\n",c2[i].id, mdb[l]);
	return 0;
}