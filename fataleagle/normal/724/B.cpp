#include <bits/stdc++.h>

using namespace std;

int N, M;
int A[50][50];

bool check(int row)
{
    for(int i=0; i<M; i++) if(A[row][i]!=i+1)
        return false;
    return true;
}

bool solve(int x, int y)
{
    for(int i=0; i<N; i++)
    {
        bool good=false;
        for(int j=0; j<M; j++)
            for(int k=j; k<M; k++)
            {
                swap(A[i][j], A[i][k]);
                swap(A[i][x], A[i][y]);
                bool ok=check(i);
                swap(A[i][x], A[i][y]);
                swap(A[i][j], A[i][k]);

                swap(A[i][x], A[i][y]);
                swap(A[i][j], A[i][k]);
                bool ok2=check(i);
                swap(A[i][j], A[i][k]);
                swap(A[i][x], A[i][y]);
                if(ok || ok2)
                {
                    good=true;
                    break;
                }
            }
        if(!good)
            return false;
    }
    return true;
}

int main()
{
    scanf("%d%d", &N, &M);
    for(int i=0; i<N; i++)
        for(int j=0; j<M; j++)
            scanf("%d", A[i]+j);
    for(int i=0; i<M; i++)
        for(int j=i; j<M; j++) if(solve(i, j))
            return printf("YES\n"), 0;
    printf("NO\n");
    return 0;
}