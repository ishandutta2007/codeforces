#include <iostream>
#include <cstdio>

#ifdef getchar
#undef getchar
#endif
#define getchar() (*_pinp?*_pinp++:(_inp[fread(_pinp=_inp, 1, 4096, stdin)]='\0', *_pinp++))
char _inp[4097], *_pinp=_inp;
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

using namespace std;

int N, Q;
long long K;
int A[2000002];
int L[2000002];
int R[2000002];
pair<int, int> loc[2000002];

void _main()
{
    long long sum=0;
    for(int i=1, j=0; i<=N*2; i++)
    {
        while(j<N*2 && sum+A[j+1]<=K)
            sum+=A[++j];
        R[i]=j+1;
        sum-=A[i];
    }
    sum=0;
    for(int i=N*2, j=N*2+1; i>=1; i--)
    {
        while(j>1 && sum+A[j-1]<=K)
            sum+=A[--j];
        L[i]=j-1;
        sum-=A[i];
    }
    int ans=0x3f3f3f3f;
    for(int i=N*2; i>=1; i--)
    {
        if(R[i]<min(N*2+1, i+N))
        {
            loc[i].first=loc[R[i]].first;
            loc[i].second=loc[R[i]].second+1;
        }
        else
        {
            loc[i].first=i;
            loc[i].second=1;
        }
        while(loc[i].first>=i+N)
        {
            loc[i].first=L[loc[i].first-1]+1;
            loc[i].second--;
        }
        if(i<=N)
            ans=min(ans, loc[i].second);
    }
    printf("%d\n", ans);
}

int main()
{
    scan(N);
    scan(Q);
    for(int i=1; i<=N; i++)
    {
        scan(A[i]);
        A[i+N]=A[i];
    }
    while(Q--)
    {
        scan(K);
        _main();
    }
    return 0;
}