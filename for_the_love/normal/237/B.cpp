#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
struct node
{
        int i,j,a;
};
node p[10000];
int res[10000][10];
int po[100][100];
int c[100];
int t[100][100];
int i,j,n,cnt,ans;
int cmp(node a,node b)
{
        if (a.a<b.a) return 1; else return 0;
}
int main()
{
        scanf("%d",&n);
        for (i=1;i<=n;i++) scanf("%d",&c[i]);
        for (i=1;i<=n;i++)
        for (j=1;j<=c[i];j++)
        {
                cnt++; scanf("%d",&p[cnt].a);
                p[cnt].i=i;p[cnt].j=j;
        }
        sort(p+1,p+cnt+1,cmp);
        for (i=1;i<=cnt;i++) po[p[i].i][p[i].j]=i;
        cnt=0;
        for (i=1;i<=n;i++)
        for (j=1;j<=c[i];j++)
        {
                cnt++; t[i][j]=p[cnt].a;
                if (p[cnt].i==i&&p[cnt].j==j) continue;
                ans++; po[p[cnt].i][p[cnt].j]=po[i][j];
                p[po[i][j]].i=p[cnt].i; p[po[i][j]].j=p[cnt].j;
                res[ans][1]=i;res[ans][2]=j;res[ans][3]=p[cnt].i;res[ans][4]=p[cnt].j;
        }
        printf("%d\n",ans);
        for (i=1;i<=ans;i++) printf("%d %d %d %d\n",res[i][1],res[i][2],res[i][3],res[i][4]);
}