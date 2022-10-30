#include <bits/stdc++.h>

using namespace std;

int N, M, Q;
pair<int, int> A[100][100];
int ans[100][100];

int main()
{
    scanf("%d%d%d", &N, &M, &Q);
    for(int i=0; i<N; i++)
        for(int j=0; j<M; j++)
            A[i][j]=make_pair(i, j);
    while(Q--)
    {
        int op;
        scanf("%d", &op);
        if(op==1)
        {
            int r;
            scanf("%d", &r);
            r--;
            rotate(A[r], A[r]+1, A[r]+M);
        }
        else if(op==2)
        {
            int c;
            scanf("%d", &c);
            c--;
            auto tmp=A[0][c];
            for(int i=0; i<N-1; i++)
                A[i][c]=A[i+1][c];
            A[N-1][c]=tmp;
        }
        else
        {
            int x, y, z;
            scanf("%d%d%d", &x, &y, &z);
            x--, y--;
            ans[A[x][y].first][A[x][y].second]=z;
        }
    }
    for(int i=0; i<N; i++)
        for(int j=0; j<M; j++)
            printf("%d%c", ans[i][j], " \n"[j==M-1]);
    return 0;
}