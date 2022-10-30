#include <bits/stdc++.h>

using namespace std;

int N, M;
int A[100001];
int ans[100001];

int main()
{
    scanf("%d%d", &N, &M);
    for(int i=1; i<=N; i++)
    {
        int a;
        scanf("%d", &a);
        if(A[a])
            A[a]=-1;
        else
            A[a]=i;
    }
    bool impossible=false, ambiguous=false;
    for(int i=1; i<=M; i++)
    {
        int a;
        scanf("%d", &a);
        if(A[a]==0)
            impossible=true;
        else if(A[a]==-1)
            ambiguous=true;
        else
            ans[i]=A[a];
    }
    if(impossible)
        printf("Impossible\n");
    else if(ambiguous)
        printf("Ambiguity\n");
    else
    {
        printf("Possible\n");
        for(int i=1; i<=M; i++)
            printf("%d ", ans[i]);
        printf("\n");
    }
    return 0;
}