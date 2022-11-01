#include <bits/stdc++.h>

#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define print(x) do{if(!x)putchar('0');else{for(;x;x/=10)*_p++='0'+x%10;do putchar(*--_p);while(_p!=_buf);}}while(0)
char _buf[20], *_p=_buf;

using namespace std;

int N;
int A[100001];
int seg[262144];
unordered_map<int, int> tmp;
unordered_map<int, long long> cnt;

inline int gcd(int a, int b)
{
    if(!b)
        return a;
    return gcd(b, a%b);
}

void solve(int L, int R)
{
    if(L==R)
    {
        cnt[A[L]]++;
        return;
    }
    int M=(L+R)/2;
    solve(L, M);
    solve(M+1, R);
    tmp.clear();
    int x=0;
    for(int i=M; i>=L; i--)
        tmp[x=gcd(x, A[i])]++;
    x=0;
    for(int i=M+1; i<=R; i++)
    {
        x=gcd(x, A[i]);
        for(auto it: tmp)
            cnt[gcd(x, it.first)]+=it.second;
    }
}

int main()
{
    scan(N);
    for(int i=1; i<=N; i++)
    {
        scan(A[i]);
    }
    solve(1, N);
    int Q, a;
    scan(Q);
    for(int i=0; i<Q; i++)
    {
        scan(a);
        long long ans=cnt[a];
        print(ans);
        putchar('\n');
    }
    return 0;
}