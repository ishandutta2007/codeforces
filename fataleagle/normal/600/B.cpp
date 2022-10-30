#include <bits/stdc++.h>

using namespace std;

int N, M;

int main()
{
    scanf("%d%d", &N, &M);
    vector<int> A;
    for(int i=0; i<N; i++)
    {
        int a;
        scanf("%d", &a);
        A.push_back(a);
    }
    sort(begin(A), end(A));
    for(int i=0; i<M; i++)
    {
        int a;
        scanf("%d", &a);
        printf("%d ", upper_bound(begin(A), end(A), a)-begin(A));
    }
    printf("\n");
    return 0;
}