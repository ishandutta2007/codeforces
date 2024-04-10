#include <bits/stdc++.h>

using namespace std;

int N, M, dx, dy;
int dxcong[1000000];
int dycong[1000000];
pair<int, int> A[100000];
map<int, int> m;

int main()
{
    scanf("%d%d%d%d", &N, &M, &dx, &dy);
    int u=0, cnt=0;
    do
        dxcong[u]=cnt++, u=(u+dx)%N;
    while(u);
    u=0, cnt=0;
    do
        dycong[u]=cnt++, u=(u+dy)%N;
    while(u);
    int a, b;
    int best=0;
    for(int i=0; i<M; i++)
    {
        scanf("%d%d", &a, &b);
        A[i]=make_pair(a, b);
        int len=(dxcong[a]-dycong[b]+N)%N;
        best=max(best, ++m[len]);
    }
    for(int i=0; i<M; i++)
    {
        a=A[i].first;
        b=A[i].second;
        int len=(dxcong[a]-dycong[b]+N)%N;
        if(m[len]==best)
        {
            printf("%d %d\n", a, b);
            return 0;
        }
    }
    return 0;
}