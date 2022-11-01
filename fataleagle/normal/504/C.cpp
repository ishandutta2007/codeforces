#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

int N;
int A[100000];
int cnt[100001];
int extra;
int freq[100001];
int nzero, lzero;

void add(int x, int v)
{
    nzero-=freq[x]!=0;
    lzero-=freq[x]<0;
    freq[x]+=v;
    nzero+=freq[x]!=0;
    lzero+=freq[x]<0;
}

bool check()
{
    return nzero==0;
}

bool check2()
{
    return lzero==0;
}

int work(int B[], int n)
{
    nzero=0;
    lzero=0;
    memset(freq, 0, sizeof freq);
    int l=(n-1)/2, r=n/2, len=0;
    while(B[l]==B[r])
        l--, r++, len++;
    for(int i=0; i<=(n-1)/2-len; i++)
        add(B[i], 1);
    for(int i=n/2+len; i<n; i++)
        add(B[i], -1);
    int ret=check();
    for(int i=(n-1)/2-len+1; i<(n-1)/2; i++)
    {
        add(B[i], 1);
        add(B[n/2+(n-1)/2-i], -1);
        ret+=check();
    }
    if(len>0)
        add(B[(n-1)/2], 1);
    if(n&1)
        add(extra, -1);
    else if(len>0)
        add(B[n/2], -1);
    if(len>0)
        ret+=check2();
    for(int i=(n-1)/2+1; i<n; i++)
    {
        add(B[i], 2);
        ret+=check2();
    }
    return ret;
}

int solve(int B[], int n)
{
    int ret=work(B, n);
    reverse(B, B+n);
    return ret+work(B, n);
}

int main()
{
    scanf("%d", &N);
    for(int i=0; i<N; i++)
        scanf("%d", A+i), cnt[A[i]]++;
    int odd=0;
    for(int i=1; i<=N; i++)
        if(cnt[i]&1)
        {
            odd++;
            extra=i;
        }
    if(odd>1)
    {
        printf("0\n");
        return 0;
    }
    int len=0;
    while((len+1)*2<=N && A[len]==A[N-len-1])
        len++;
    if(N-len*2<=1)
        printf("%lld\n", 1LL*N*(N+1)/2);
    else
        printf("%lld\n", 1LL*(solve(A+len, N-len*2)-2)*(len+1)+1LL*(len+1)*(len+1));
    return 0;
}