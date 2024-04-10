#include<cstdio>
#include<algorithm>
#include<cstring>

#define N 100005

using namespace std;
int i,j,m,n,p,k,a[N],ans,x;
int main()
{
	 freopen("input.txt","r",stdin);
	 freopen("output.txt","w",stdout);
     scanf("%d%d",&n,&x);
     for (i=1;i<=n;++i) scanf("%d",&a[i]),a[i]*=(n-i+1);
     sort(a+1,a+n+1);
     for (i=1;i<=n;++i)
       if (a[i]<=x) x-=a[i]; else break;
     printf("%d\n",i-1);
}