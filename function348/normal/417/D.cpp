#include<cstring>
#include<iostream>
#include<cstdio>
#include<algorithm>
#define LL long long
using namespace std;
const int N=110,M=1100000;
const LL inf=3000000000000000000;
			 
struct re{int x,k,b;};
re a[N];
LL f[M];
int n,m,b;
LL ans;
int cmp(re a,re b){return a.k<b.k;}
int main()
{
	scanf("%d%d%d",&n,&m,&b);
	for (int i=1;i<=n;i++) 
	{
		int x;
		scanf("%d%d%d",&a[i].x,&a[i].k,&x);
		a[i].b=0;
		while (x--)
		{
			int y;
			scanf("%d",&y);
			a[i].b+=1<<(y-1);
		}
	}
	sort(a+1,a+1+n,cmp);ans=inf;
	for (int i=1;i<=(1<<m)-1;i++) f[i]=inf;f[0]=0;
	for (int i=1;i<=n;i++)
	{
		for (int j=(1<<m)-1;j>=0;j--)
			f[j|a[i].b]=min(f[j|a[i].b],f[j]+a[i].x);
		ans=min(ans,f[(1<<m)-1]+(LL)a[i].k*b);
	}
	if (ans==inf) ans=-1;
	cout << ans;
	return 0;
}