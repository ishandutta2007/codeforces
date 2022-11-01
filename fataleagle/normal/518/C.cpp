#include <bits/stdc++.h>

using namespace std;

int N, M, K;
int A[100000];
int B[100000];
int pos[100001];

int main()
{
    scanf("%d%d%d", &N, &M, &K);
    for(int i=0; i<N; i++)
    {
        scanf("%d", A+i);
        pos[A[i]]=i;
    }
    long long ans=0;
    for(int i=0; i<M; i++)
    {
        scanf("%d", B+i);
        int p=pos[B[i]];
        ans+=p/K;
        if(p>0)
        {
            swap(pos[A[p-1]], pos[A[p]]);
            swap(A[p-1], A[p]);
        }
    }
    printf("%lld\n", ans+M);
    return 0;
}