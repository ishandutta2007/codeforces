#include <bits/stdc++.h>

#ifdef getchar
#undef getchar
#endif
#define getchar() (*_pinp?*_pinp++:(_inp[fread(_pinp=_inp, 1, 4096, stdin)]='\0', *_pinp++))
char _inp[4097], *_pinp=_inp;
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

using namespace std;

int N, K;
int A[1000001];
bool seen[1000001];
int cnt[1000001];
int dp[500005];

void go(int n, int m, int k)
{
    int cnt=0;
    for(int i=0; i<k; i++)
        if(n-i*m>=0)
            cnt+=dp[n-i*m];
    for(int i=n; i>=0; i-=m)
    {
        cnt-=dp[i];
        if(i-k*m>=0)
            cnt+=dp[i-k*m];
        if(cnt)
            dp[i]=1;
    }
}

int subsetsum(int k)
{
    dp[0]=1;
    int S=0;
    for(int i=0; i<=N; i++) if(cnt[i])
    {
        S+=i*cnt[i];
        int n=min(S, k);
        for(int j=0; j<i && n-j>=0; j++)
            go(n-j, i, cnt[i]);
    }
    return dp[k];
}

int main()
{
    scan(N);
    scan(K);
    for(int i=1; i<=N; i++)
        scan(A[i]);
    int dec2=0, dec1=0;
    for(int i=1; i<=N; i++) if(!seen[i])
    {
        int len=0;
        int u=A[i];
        do
        {
            seen[u]=true;
            u=A[u];
            len++;
        }
        while(!seen[u]);
        cnt[len]++;
        if(len%2==0)
            dec2+=len/2;
        else
            dec2+=len/2, dec1++;
    }
    int ans1=K+1-subsetsum(min(K, N-K));
    int ans2=0;
    if(K<=dec2)
        ans2=2*K;
    else
        ans2=2*dec2+min(K-dec2, dec1);
    printf("%d %d\n", ans1, ans2);
    return 0;
}