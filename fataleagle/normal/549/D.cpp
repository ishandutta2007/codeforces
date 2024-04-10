#include <bits/stdc++.h>

using namespace std;

int N, M;
char grid[200][200];
int A[200][200];

int main()
{
    scanf("%d%d", &N, &M);
    for(int i=0; i<N; i++)
        scanf("%s", grid[i]);
    vector<pair<int, pair<int, int>>> pos;
    for(int i=0; i<N; i++)
        for(int j=0; j<M; j++)
            pos.push_back({i+j, {i, j}});
    sort(pos.rbegin(), pos.rend());
    int ans=0;
    for(auto& it: pos)
    {
        int x=it.second.first, y=it.second.second;
        int t;
        if(grid[x][y]=='W')
            t=1;
        else
            t=-1;
        int d=t-A[x][y];
        if(d!=0)
        {
            for(int i=0; i<=x; i++)
                for(int j=0; j<=y; j++)
                    A[i][j]+=d;
            ans++;
        }
    }
    printf("%d\n", ans);
    return 0;
}