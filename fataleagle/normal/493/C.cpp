#include <bits/stdc++.h>

using namespace std;

int N, M;
int A[200001], B[200001];

bool cmp(pair<int, int> a, pair<int, int> b)
{
    if(a.first-a.second!=b.first-b.second)
        return a.first-a.second<b.first-b.second;
    return a.first<b.first;
}

pair<int, int> calc(int x)
{
    int a=upper_bound(A, A+N, x)-A;
    int b=upper_bound(B, B+M, x)-B;
    return make_pair(2*a+3*(N-a), 2*b+3*(M-b));
}

int main()
{
    scanf("%d", &N);
    for(int i=0; i<N; i++)
        scanf("%d", A+i);
    scanf("%d", &M);
    for(int i=0; i<M; i++)
        scanf("%d", B+i);
    sort(A, A+N);
    sort(B, B+M);
    pair<int, int> ans=max(make_pair(N*2, M*2), make_pair(N*3, M*3), cmp);
    ans=max(ans, calc(0), cmp);
    for(int i=0; i<N; i++)
        ans=max(ans, calc(A[i]), cmp);
    for(int i=0; i<M; i++)
        ans=max(ans, calc(B[i]), cmp);
    printf("%d:%d\n", ans.first, ans.second);
    return 0;
}