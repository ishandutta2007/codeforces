#include <bits/stdc++.h>

using namespace std;

int N, M, Q;
bitset<1000> A[100001];
int B[100001][1000];
int cur[1000];
int ans[100001];
int cans;

int main()
{
    scanf("%d%d%d", &N, &M, &Q);
    for(int i=1; i<=Q; i++)
    {
        int t;
        scanf("%d", &t);
        if(t==1)
        {
            int x, y;
            scanf("%d%d", &x, &y);
            x--, y--;
            A[i]=A[cur[x]];
            cur[x]=i;
            cans-=A[i][y];
            A[i][y]=1;
            cans+=A[i][y];
        }
        else if(t==2)
        {
            int x, y;
            scanf("%d%d", &x, &y);
            x--, y--;
            A[i]=A[cur[x]];
            cur[x]=i;
            cans-=A[i][y];
            A[i][y]=0;
            cans+=A[i][y];
        }
        else if(t==3)
        {
            int x;
            scanf("%d", &x);
            x--;
            A[i]=A[cur[x]];
            cur[x]=i;
            cans-=A[i].count();
            for(int j=0; j<M; j++)
                A[i][j]=A[i][j]^1;
            cans+=A[i].count();
        }
        else
        {
            int k;
            scanf("%d", &k);
            for(int j=0; j<N; j++)
                cur[j]=B[k][j];
            cans=ans[k];
        }
        for(int j=0; j<N; j++)
            B[i][j]=cur[j];
        ans[i]=cans;
        printf("%d\n", cans);
    }
    return 0;
}