#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define ll long long
#define N 510
using namespace std;
ll f[N][N];
struct node{
	ll a,b,k;
	bool operator <(const node a)const{return b>a.b;}
}p[N];
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%lld%lld%lld",&p[i].a,&p[i].b,&p[i].k);
	sort(p+1,p+n+1);
	ll ans=0;
	for(int i=1;i<=n;i++)
	{
		f[i][0]=0;
		for(int j=0;j<=i;j++)
		{
			f[i][j]=max(f[i][j],f[i-1][j]+max(p[i].a-p[i].b*p[i].k,0ll));
			if(j) f[i][j]=max(f[i][j],f[i-1][j-1]+p[i].a-(j-1)*p[i].b);
			ans=max(ans,f[i][j]);
		}
	}
	printf("%lld\n",ans);
	return 0;
}