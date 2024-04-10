#include<cstdio>
#include<algorithm>
using namespace std;
int n,maxn,rev;
long long ans;
struct node
{
	int a,c;
}f[100005];
bool cmp(node x,node y)
{
	return x.a<y.a;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&f[i].a,&f[i].c);
		ans+=f[i].c; 
	}
	sort(f+1,f+n+1,cmp);
	maxn=f[1].a+f[1].c;
	for(int i=2;i<=n;i++)
	{
		if(f[i].a+f[i].c>maxn)
		{
			ans+=max(f[i].a-maxn,0);
			maxn=f[i].a+f[i].c;
		}
	}
	printf("%lld\n",ans);
}