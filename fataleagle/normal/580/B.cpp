#include <bits/stdc++.h>

using namespace std;

int N, M;
pair<int, int> A[100000];

int main()
{
    scanf("%d%d", &N, &M);
    for(int i=0; i<N; i++)
        scanf("%d%d", &A[i].first, &A[i].second);
    sort(A, A+N);
    int ptr=0;
    long long sum=0, ans=0;
    for(int i=0; i<N; i++)
    {
        sum+=A[i].second;
        while(ptr<i && A[i].first-A[ptr].first>=M)
        {
            sum-=A[ptr].second;
            ptr++;
        }
        ans=max(ans, sum);
    }
    printf("%lld\n", ans);
    return 0;
}