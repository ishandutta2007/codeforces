#include <bits/stdc++.h>

using namespace std;

int N, M, K;
bool black[1001][1001];

bool bounds(int x, int y)
{
    return 1<=x && x<=N && 1<=y && y<=M;
}

int main()
{
    scanf("%d%d%d", &N, &M, &K);
    int x, y;
    for(int i=1; i<=K; i++)
    {
        scanf("%d%d", &x, &y);
        black[x][y]=true;
        for(int j=x-1; j<=x; j++)
            for(int k=y-1; k<=y; k++)
            {
                bool good=true;
                for(int l=0; l<2; l++)
                    for(int m=0; m<2; m++)
                        if(!bounds(j+l, k+m) || !black[j+l][k+m])
                            good=false;
                if(good)
                {
                    printf("%d\n", i);
                    return 0;
                }
            }
    }
    printf("0\n");
    return 0;
}