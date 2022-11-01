#include <bits/stdc++.h>

using namespace std;

int N;
vector<int> A[4];

int main()
{
    scanf("%d", &N);
    int a;
    for(int i=0; i<N; i++)
    {
        scanf("%d", &a);
        A[a].push_back(i+1);
    }
    int K=min(A[1].size(), min(A[2].size(), A[3].size()));
    printf("%d\n", K);
    for(int i=0; i<K; i++)
        printf("%d %d %d\n", A[1][i], A[2][i], A[3][i]);
    return 0;
}