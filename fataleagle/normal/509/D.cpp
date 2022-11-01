#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>

using namespace std;

int N, M;
long long K;
int A[101][101];
long long B[101];
long long C[101];

int main()
{
    scanf("%d%d", &N, &M);
    for(int i=1; i<=N; i++)
        for(int j=1; j<=M; j++)
            scanf("%d", A[i]+j);
    B[1]=A[1][1];
    for(int i=2; i<=N; i++)
    {
        vector<int> v;
        for(int j=1; j<=M; j++)
            v.push_back(A[i][j]-A[i-1][j]);
        sort(v.begin(), v.end());
        v.resize(unique(v.begin(), v.end())-v.begin());
        if(v.size()>2 || (v.size()==2 && (v[0]<0)==(v[1]<0)))
            return printf("NO\n"), 0;
        if(v.size()==2)
        {
            long long n=v[1]-v[0];
            if(K!=0 && K!=n)
                return printf("NO\n"), 0;
            K=n;
        }
        B[i]=B[i-1]+v.back();
    }
    C[1]=0;
    for(int j=2; j<=M; j++)
    {
        vector<int> v;
        for(int i=1; i<=N; i++)
            v.push_back(A[i][j]-A[i][j-1]);
        sort(v.begin(), v.end());
        v.resize(unique(v.begin(), v.end())-v.begin());
        if(v.size()>2 || (v.size()==2 && (v[0]<0)==(v[1]<0)))
            return printf("NO\n"), 0;
        if(v.size()==2)
        {
            long long n=v[1]-v[0];
            if(K!=0 && K!=n)
                return printf("NO\n"), 0;
            K=n;
        }
        C[j]=C[j-1]+v.back();
    }
    if(K==0)
        for(int i=1; i<=N; i++)
            for(int j=1; j<=M; j++)
                K=max(K, A[i][j]+1LL);
    for(int i=1; i<=N; i++)
        for(int j=1; j<=M; j++)
            if(A[i][j]!=((B[i]+C[j])%K+K)%K)
                return printf("NO\n"), 0;
    printf("YES\n");
    printf("%lld\n", K);
    for(int i=1; i<=N; i++)
        printf("%lld%c", (B[i]%K+K)%K, " \n"[i==N]);
    for(int i=1; i<=M; i++)
        printf("%lld%c", (C[i]%K+K)%K, " \n"[i==M]);
    return 0;
}