#include <bits/stdc++.h>

using namespace std;

int N;
char S[201];
int R, G, B;
bool seen[201][201][201];
int rAns, gAns, bAns;

void dfs(int r, int g, int b)
{
    if(seen[r][g][b])
        return;
    seen[r][g][b]=true;
    if(r+g+b==1)
    {
        rAns|=r;
        gAns|=g;
        bAns|=b;
        return;
    }
    if(r>=2)
        dfs(r-1, g, b);
    if(g>=2)
        dfs(r, g-1, b);
    if(b>=2)
        dfs(r, g, b-1);
    if(r>=1 && g>=1)
        dfs(r-1, g-1, b+1);
    if(r>=1 && b>=1)
        dfs(r-1, g+1, b-1);
    if(g>=1 && b>=1)
        dfs(r+1, g-1, b-1);
}

int main()
{
    scanf("%d", &N);
    scanf("%s", S);
    for(int i=0; i<N; i++)
    {
        R+=S[i]=='R';
        G+=S[i]=='G';
        B+=S[i]=='B';
    }
    dfs(R, G, B);
    if(bAns)
        printf("B");
    if(gAns)
        printf("G");
    if(rAns)
        printf("R");
    printf("\n");
    return 0;
}