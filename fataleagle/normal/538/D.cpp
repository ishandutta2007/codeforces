#include <bits/stdc++.h>

using namespace std;

int N;
char grid[51][51];
char hit[51][51];
char ans[200][200];
vector<pair<int, int>> pieces;

bool bounds(int x, int y)
{
    return 0<=x && x<N && 0<=y && y<N;
}

int main()
{
    scanf("%d", &N);
    for(int i=0; i<N; i++)
    {
        scanf("%s", grid[i]);
        for(int j=0; j<N; j++) if(grid[i][j]=='o')
            pieces.push_back({i, j});
    }
    for(int i=0; i<2*N-1; i++)
        for(int j=0; j<2*N-1; j++)
            ans[i][j]='.';
    int x=N-1, y=N-1;
    ans[x][y]='o';
    for(int i=0; i<2*N-1; i++)
        for(int j=0; j<2*N-1; j++) if(ans[i][j]=='.')
        {
            int dx=i-x, dy=j-y;
            for(auto& it: pieces)
            {
                int nx=it.first, ny=it.second;
                if(bounds(nx+dx, ny+dy) && grid[nx+dx][ny+dy]=='.')
                    goto bad;
            }
            ans[i][j]='x';
            bad:;
        }
    for(int i=0; i<2*N-1; i++)
        for(int j=0; j<2*N-1; j++) if(ans[i][j]=='x')
        {
            int dx=i-x, dy=j-y;
            for(auto& it: pieces)
            {
                int nx=it.first, ny=it.second;
                if(bounds(nx+dx, ny+dy))
                    hit[nx+dx][ny+dy]='x';
            }
        }
    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++)
            if((grid[i][j]=='.' && hit[i][j]=='x') || (grid[i][j]=='x' && hit[i][j]!='x'))
            {
                printf("NO\n");
                return 0;
            }
    printf("YES\n");
    for(int i=0; i<2*N-1; i++, putchar('\n'))
        for(int j=0; j<2*N-1; j++)
            putchar(ans[i][j]);
    return 0;
}