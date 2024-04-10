#include <iostream>
#include <cstdio>
#include <set>
#include <utility>
#include <vector>

#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define print(x) do{if(!x)putchar('0');else{for(;x;x/=10)*_p++='0'+x%10;do putchar(*--_p);while(_p!=_buf);}}while(0)
char _buf[20], *_p=_buf;

using namespace std;

int N, K;
pair<int, int> to[1000002];
int link[1000002], start[500001], nedge;
int good[500001];
long long C[500001];
int numteams[500001];
multiset<long long> maxdist[500001];
long long ans[500001];

void add_edge(int u, pair<int, int> data)
{
    nedge++;
    to[nedge]=data;
    link[nedge]=start[u];
    start[u]=nedge;
}

void dfs(int u, int p)
{
    if(good[u])
    {
        maxdist[u].insert(0);
        numteams[u]++;
    }
    for(int it=start[u]; it!=0; it=link[it])
    {
        int v=to[it].first;
        int c=to[it].second;
        if(v==p)
            continue;
        dfs(v, u);
        C[u]+=C[v];
        numteams[u]+=numteams[v];
        if(numteams[v]>0)
        {
            C[u]+=c*2;
            maxdist[u].insert(c+*maxdist[v].rbegin());
        }
    }
}

inline void moveroot(int u, int v, int c)
{
    C[u]-=C[v];
    numteams[u]-=numteams[v];
    if(numteams[v]>0)
    {
        C[u]-=c*2;
        maxdist[u].erase(maxdist[u].find(c+*maxdist[v].rbegin()));
    }
    C[v]+=C[u];
    numteams[v]+=numteams[u];
    if(numteams[u]>0)
    {
        C[v]+=c*2;
        maxdist[v].insert(c+*maxdist[u].rbegin());
    }
}

void dfs2(int u, int p)
{
    ans[u]=C[u]-*maxdist[u].rbegin();
    for(int it=start[u]; it!=0; it=link[it])
    {
        int v=to[it].first;
        int c=to[it].second;
        if(v==p)
            continue;
        moveroot(u, v, c);
        dfs2(v, u);
        moveroot(v, u, c);
    }
}

int main()
{
    scan(N);
    scan(K);
    int a, b, c;
    for(int i=1; i<N; i++)
    {
        scan(a);
        scan(b);
        c=1;
        add_edge(a, make_pair(b, c));
        add_edge(b, make_pair(a, c));
    }
    for(int i=0; i<K; i++)
    {
        scan(a);
        good[a]=true;
    }
    dfs(1, -1);
    dfs2(1, -1);
    pair<long long, int> rans=make_pair(0x3f3f3f3f3f3f3f3fLL, 0);
    for(int i=1; i<=N; i++)
        rans=min(rans, make_pair(ans[i], i));
    cout<<rans.second<<'\n';
    cout<<rans.first<<'\n';
    return 0;
}