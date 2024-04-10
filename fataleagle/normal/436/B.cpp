#include <bits/stdc++.h>

using namespace std;

int N, M, K;
char grid[2000][2000];

int spiders(int x, int y, int t)
{
    int ret=0;
    ret+=y-t>=0 && grid[x][y-t]=='R';
    ret+=y+t<M && grid[x][y+t]=='L';
    ret+=x-t>=0 && grid[x-t][y]=='D';
    ret+=x+t<N && grid[x+t][y]=='U';
    return ret;
}

int main()
{
    scanf("%d%d%d", &N, &M, &K);
    for(int i=0; i<N; i++)
        for(int j=0; j<M; j++)
            while((grid[i][j]=getchar())<=' ');
    for(int j=0; j<M; j++)
    {
        int ans=0;
        for(int i=0; i<N; i++)
            ans+=spiders(i, j, i);
        printf("%d ", ans);
    }
    printf("\n");
    return 0;
}