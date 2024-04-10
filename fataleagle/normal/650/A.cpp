#include <bits/stdc++.h>

using namespace std;

map<int, int> X;
map<int, int> Y;
map<pair<int, int>, int> XY;

int main()
{
    int N;
    scanf("%d", &N);
    long long ans=0;
    for(int i=0; i<N; i++)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        ans+=X[a]++;
        ans+=Y[b]++;
        ans-=XY[{a, b}]++;
    }
    printf("%lld\n", ans);
    return 0;
}