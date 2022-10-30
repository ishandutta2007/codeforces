#include <bits/stdc++.h>

using namespace std;

int N, M;
int P[300001];
int I[300001];
int maxi[300001];

int main()
{
    scanf("%d%d", &N, &M);
    for(int i=1; i<=N; i++)
        scanf("%d", P+i), I[P[i]]=i;
    int a, b;
    for(int i=0; i<M; i++)
    {
        scanf("%d%d", &a, &b);
        a=I[a];
        b=I[b];
        if(a>b)
            swap(a, b);
        maxi[b]=max(maxi[b], a+1);
    }
    long long ans=0;
    int l=1;
    for(int r=1; r<=N; r++)
    {
        l=max(l, maxi[r]);
        ans+=r-l+1;
    }
    printf("%lld\n", ans);
    return 0;
}