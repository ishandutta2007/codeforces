#include<cstdio>
#include<algorithm>
#include<cstring>

#define N 5005

using namespace std;
int i,j,m,n,p,k,sum[N],a[N],Ans[N];
int main()
{
    scanf("%d",&n);
    for (i=1;i<=n;++i) scanf("%d",&a[i]);
    for (i=1;i<=n;++i)
    {
       memset(sum,0,sizeof(sum));
       int id=0;
       for (j=i;j<=n;++j)
       {
                sum[a[j]]++;
                if (sum[a[j]]>sum[id]||sum[a[j]]==sum[id]&&a[j]<id) id=a[j];
                Ans[id]++;
       }
    }
    for (i=1;i<=n;++i) printf("%d ",Ans[i]);
}