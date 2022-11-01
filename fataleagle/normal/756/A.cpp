#include <bits/stdc++.h>

using namespace std;

int N;
int A[200001];
int B[200001];
int seen[200001];

int main()
{
    scanf("%d", &N);
    for(int i=1; i<=N; i++)
        scanf("%d", A+i);
    int x=1;
    for(int i=1; i<=N; i++)
        scanf("%d", B+i), x^=B[i];
    int cyc=0;
    for(int i=1; i<=N; i++) if(!seen[i])
    {
        int u=i;
        while(!seen[u])
        {
            seen[u]=true;
            u=A[u];
        }
        cyc++;
    }
    if(cyc>1)
        x+=cyc;
    printf("%d\n", x);
    return 0;
}