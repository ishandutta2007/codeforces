#include <bits/stdc++.h>

using namespace std;

int N, M;
int X[501];
int C[501][501];

int main()
{
    scanf("%d%d", &N, &M);
    int a, b, c;
    for(int i=1; i<=N; i++)
        scanf("%d", X+i);
    for(int i=0; i<M; i++)
    {
        scanf("%d%d%d", &a, &b, &c);
        C[a][b]=C[b][a]=c;
    }
    double ans=0.0;
    for(int i=1; i<=N; i++)
        for(int j=i+1; j<=N; j++)
            if(C[i][j])
                ans=max(ans, double(X[i]+X[j])/C[i][j]);
    printf("%.18lf\n", ans);
    return 0;
}