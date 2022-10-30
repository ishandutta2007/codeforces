#include <bits/stdc++.h>

#ifdef getchar
#undef getchar
#endif
#define getchar() (*_pinp?*_pinp++:(_inp[fread(_pinp=_inp, 1, 4096, stdin)]='\0', *_pinp++))
char _inp[4097], *_pinp=_inp;

#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

using namespace std;

int N, M;
vector<pair<int, int>> edges;
int stfu[1000001];

int main()
{
    scan(N);
    scan(M);
    int a, b;
    for(int i=0; i<M; i++)
    {
        scan(a);
        scan(b);
        stfu[a]++;
        stfu[b]++;
        edges.push_back({a, b});
    }
    long long ans=1LL*N*(N-1)*(N-2)/6, sum=0;
    for(auto& it: edges)
    {
        int u=it.first, v=it.second;
        sum+=N*2-stfu[u]-stfu[v]-2;
    }
    printf("%lld\n", ans-sum/2);
    return 0;
}