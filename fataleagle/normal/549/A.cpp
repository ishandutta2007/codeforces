#include <bits/stdc++.h>

using namespace std;

int N, M;
char grid[100][100];

int check(int x, int y)
{
    string s;
    for(int i=0; i<2; i++)
        for(int j=0; j<2; j++)
            s+=grid[x+i][y+j];
    sort(s.begin(), s.end());
    return s=="acef";
}

int main()
{
    scanf("%d%d", &N, &M);
    for(int i=0; i<N; i++)
        scanf("%s", grid[i]);
    int ans=0;
    for(int i=1; i<N; i++)
        for(int j=1; j<M; j++)
            ans+=check(i-1, j-1);
    printf("%d\n", ans);
    return 0;
}