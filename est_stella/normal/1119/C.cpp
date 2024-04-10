#include<bits/stdc++.h>
using namespace std;

int n, m;
int A[501][501];
bool row[501];
bool column[501];
bool ans;

int main()
{
    scanf("%d %d", &n, &m);

    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            scanf("%d", &A[i][j]);
        }
    }

    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            int x;
            scanf("%d", &x);

            if(x!=A[i][j]) row[i]=!row[i], column[j] = !column[j];
        }
    }

    for(int i=1; i<=n; i++)
        ans = ans || row[i];

    for(int i=1; i<=m; i++)
        ans = ans || column[i];

    if(ans) printf("No");
    else printf("Yes");
}