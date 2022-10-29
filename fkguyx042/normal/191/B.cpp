#include<cstdio>
#include<cstring>
#include<algorithm>
#define N 100005
#define ll long long
int n,m,k;
ll S,sum,a[N];
bool b[N];
struct note{ll x; int y;} c[N];
bool cmp(const note i,const note j){return i.x>j.x;}
int main()
{
	scanf("%d%d%I64d",&n,&k,&S);
	for (int i=1;i<=n;i++) scanf("%I64d",&a[i]),c[i].x=a[i],c[i].y=i;
	std::sort(c+1,c+n,cmp);
	for (int i=1;i<=k && i<n;i++) sum+=c[i].x,b[c[i].y]=1;
	int i=n; if (sum>S) for (i=1;i<n;i++)
		if (b[i]) break; else if (sum-c[k].x+a[i]>S) break; 
	printf("%d\n",i); return 0;
}