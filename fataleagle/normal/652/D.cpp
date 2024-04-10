#include <bits/stdc++.h>

using namespace std;

struct segment
{
    int l, r, i;
    bool operator< (const segment& other) const
    {
        if(l!=other.l)
            return l>other.l;
        return r<other.r;
    }
} A[200000];

int N, M;
int ans[200000];
int X[200000], NX;
int bit[200001];

void add(int x, int v)
{
    for(; x<=N; x+=x&-x)
        bit[x]+=v;
}

int sum(int x)
{
    int ret=0;
    for(; x>0; x-=x&-x)
        ret+=bit[x];
    return ret;
}

int main()
{
    scanf("%d", &N);
    for(int i=0; i<N; i++)
        scanf("%d%d", &A[i].l, &A[i].r), A[i].i=i, X[NX++]=A[i].r;
    sort(A, A+N);
    sort(X, X+NX);
    for(int i=0; i<N; i++)
    {
        int kr=lower_bound(X, X+NX, A[i].r)-X+1;
        ans[A[i].i]=sum(kr-1);
        add(kr, 1);
    }
    for(int i=0; i<N; i++)
        printf("%d\n", ans[i]);
    return 0;
}