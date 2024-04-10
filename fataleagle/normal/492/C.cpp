#include <bits/stdc++.h>

using namespace std;

int N, R, avg;
long long goal;
pair<int, int> A[100000];

int main()
{
    scanf("%d%d%d", &N, &R, &avg);
    goal=1LL*N*avg;
    for(int i=0; i<N; i++)
        scanf("%d%d", &A[i].second, &A[i].first), goal-=A[i].second;
    goal=max(goal, 0LL);
    sort(A, A+N);
    long long ans=0;
    for(int i=0; i<N; i++)
    {
        long long want=min(goal, (long long)(R-A[i].second));
        ans+=want*A[i].first;
        goal-=want;
    }
    printf("%lld\n", ans);
    return 0;
}