#include <bits/stdc++.h>

using namespace std;

int N, Q;
long long V[100001];
long long V2[100001];

int main()
{
    scanf("%d", &N);
    for(int i=1; i<=N; i++)
    {
        scanf("%lld", V+i);
        V2[i]=V[i];
    }
    sort(V2+1, V2+1+N);
    for(int i=1; i<=N; i++)
    {
        V[i]+=V[i-1];
        V2[i]+=V2[i-1];
    }
    int a, b, c;
    scanf("%d", &Q);
    for(int i=0; i<Q; i++)
    {
        scanf("%d%d%d", &a, &b, &c);
        if(a==1)
            printf("%lld\n", V[c]-V[b-1]);
        else
            printf("%lld\n", V2[c]-V2[b-1]);
    }
    return 0;
}