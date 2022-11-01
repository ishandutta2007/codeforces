#include <bits/stdc++.h>

using namespace std;

const int MOD=1000000007;
int N, M;
char S[1000005];
int A[1000005];
bool seen[1000005];
int P[2000005];

int gcd(int a, int b)
{
    if(b==0)
        return a;
    return gcd(b, a%b);
}

int main()
{
    scanf("%d%d%s", &N, &M, S);
    int K=strlen(S);
    for(int i=0; i<M; i++)
        scanf("%d", A+i), P[A[i]]++, P[A[i]+K]--;
    int g=0;
    for(int i=1; i<M; i++)
        if(A[i]-A[i-1]<K)
            g=gcd(g, A[i]-A[i-1]);
    if(g)
    {
        for(int i=0; i<K; i++) if(!seen[i])
        {
            char target=S[i];
            for(int j=i; j<K; j+=g)
            {
                if(S[j]!=target)
                {
                    printf("0\n");
                    return 0;
                }
                seen[j]=true;
            }
        }
    }
    int ans=1;
    for(int i=1; i<=N; i++)
    {
        if(i)
            P[i]+=P[i-1];
        if(!P[i])
            ans=26LL*ans%MOD;
    }
    printf("%d\n", ans);
    return 0;
}