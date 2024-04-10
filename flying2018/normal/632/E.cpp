#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define N 1000010
#define M 1010
using namespace std;
int a[M],d[M],f[N];
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) d[i]=a[i]-a[1];
	memset(f,60,sizeof(f));
	f[0]=0;
    for(int i=1;i<=n;i++)
        for(int j=d[i];j<=N-10;j++) f[j]=min(f[j],f[j-d[i]]+1);
    for(int i=0;i<=N-10;i++)
        if(f[i]<=m) printf("%d ",m*a[1]+i);
	return 0;
}