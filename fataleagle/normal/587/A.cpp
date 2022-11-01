#include <bits/stdc++.h>

#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

using namespace std;

int N;
int A[2000001];

int main()
{
    scan(N);
    int a;
    for(int i=0; i<N; i++)
    {
        scan(a);
        A[a]++;
    }
    int ans=0;
    for(int i=0; i<2000001; i++)
    {
        A[i+1]+=A[i]/2;
        A[i]%=2;
        if(A[i]==1)
            ans++;
    }
    printf("%d\n", ans);
    return 0;
}