#include <bits/stdc++.h>

using namespace std;

int N, K;
int A[200001];
int B[200001];
map<int, long long> cnt;

int main()
{
    scanf("%d%d", &N, &K);
    for(int i=1; i<=N; i++)
        scanf("%d", A+i);
    for(int i=1; i<=N; i++)
    {
        if(A[i]%K==0)
            B[i]=cnt[A[i]/K];
        else
            B[i]=0;
        cnt[A[i]]++;
    }
    cnt.clear();
    long long ans=0;
    for(int i=1; i<=N; i++)
    {
        if(A[i]%K==0)
            ans+=cnt[A[i]/K];
        cnt[A[i]]+=B[i];
    }
    printf("%lld\n", ans);
    return 0;
}