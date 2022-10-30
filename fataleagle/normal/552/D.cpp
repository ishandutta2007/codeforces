#include <bits/stdc++.h>

using namespace std;

int N, M;
pair<int, int> A[2000];
pair<int, int> B[2000];

int main()
{
    scanf("%d", &N);
    for(int i=0; i<N; i++)
        scanf("%d%d", &A[i].first, &A[i].second);
    long long ans=1LL*N*(N-1)*(N-2)/6, suma=0;
    for(int i=0; i<N; i++)
    {
        M=0;
        for(int j=0; j<N; j++) if(i!=j)
            B[M++]=make_pair(A[j].first-A[i].first, A[j].second-A[i].second);
        map<pair<int, int>, int> cnt;
        for(int j=0; j<M; j++)
        {
            int g;
            if(B[j].first==0 || B[j].second==0)
                g=max(abs(B[j].first), abs(B[j].second));
            else
                g=__gcd(abs(B[j].first), abs(B[j].second));
            cnt[make_pair(B[j].first/g, B[j].second/g)]++;
            cnt[make_pair(-B[j].first/g, -B[j].second/g)]++;
        }
        long long sum=0;
        for(auto& it: cnt)
            sum+=1LL*it.second*(it.second-1)/2;
        suma+=sum/2;
    }
    suma/=3;
    printf("%lld\n", ans-suma);
    return 0;
}