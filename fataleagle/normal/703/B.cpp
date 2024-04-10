#include <bits/stdc++.h>

using namespace std;

int N, K;
int A[100000];

int main()
{
    scanf("%d%d", &N, &K);
    long long S=0, T=0, U=0;
    for(int i=0; i<N; i++)
        scanf("%d", A+i), U+=A[i];
    set<int> B;
    for(int i=0; i<K; i++)
    {
        int a;
        scanf("%d", &a);
        a--;
        B.insert(a);
        S+=A[a];
        T+=1LL*A[a]*A[a];
    }
    long long ans=U*S-(S*S-T)/2-T;
    for(int i=0; i<N; i++)
    {
        if(!B.count(i) && !B.count((i+1)%N))
            ans+=1LL*A[i]*A[(i+1)%N];
    }
    printf("%lld\n", ans);
    return 0;
}