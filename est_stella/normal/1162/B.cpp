#include<bits/stdc++.h>
using namespace std;

int n, m;
int a[60][60];
int b[60][60];
int cnt[60][60];

void Swap(int i, int j)
{
    int t = a[i][j];
    a[i][j]=b[i][j];
    b[i][j]=t;
}

int main()
{
    scanf("%d%d", &n, &m);

    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++)
            scanf("%d", &a[i][j]);

    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++)
            scanf("%d", &b[i][j]);

    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            if(j > 1 && ((max(a[i][j], b[i][j]) <= max(a[i][j-1], b[i][j-1])) || (min(a[i][j], b[i][j]) <= min(a[i][j-1], b[i][j-1]))))
            {
                printf("Impossible");
                return 0;
            }
            if(i > 1 && ((max(a[i][j], b[i][j]) <= max(a[i-1][j], b[i-1][j])) || (min(a[i][j], b[i][j]) <= min(a[i-1][j], b[i-1][j]))))
            {
                printf("Impossible");
                return 0;
            }
        }
    }

    printf("Possible");
}