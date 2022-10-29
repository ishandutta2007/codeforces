#include <cstdio>
using namespace std;
int A[102][102],B[102][102];
int n,m;
int main()
{
    scanf("%d%d",&n,&m);
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++) scanf("%d",&A[i][j]),B[i][j]=1;
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)
        if (!A[i][j])
        {
            for (int k=1;k<=n;k++) B[k][j]=0;
            for (int k=1;k<=m;k++) B[i][k]=0;
        }
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)
        if (A[i][j])
        {
            bool X=0;
            for (int k=1;k<=n;k++) X|=B[k][j];
            for (int k=1;k<=m;k++) X|=B[i][k];
            if (!X)
            {
                puts("NO");
                return 0;
            }
        }
    puts("YES");
    for (int i=1;i<=n;i++)
    {
        printf("%d",B[i][1]);
        for (int j=2;j<=m;j++) printf(" %d",B[i][j]);
        puts("");
    }
    return 0;
}