#include <bits/stdc++.h>

using namespace std;

int N, M;

int main()
{
    scanf("%d%d", &N, &M);
    int K=N;
    for(int i=0; i<M; i++)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        K=min(K, b-a+1);
    }
    printf("%d\n", K);
    for(int i=0; i<N; i++)
        printf("%d ", i%K);
    printf("\n");
    return 0;
}