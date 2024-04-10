#include <bits/stdc++.h>

#ifdef getchar
#undef getchar
#endif
#define getchar() (*_pinp?*_pinp++:(_inp[fread(_pinp=_inp, 1, 4096, stdin)]='\0', *_pinp++))
char _inp[4097], *_pinp=_inp;
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

using namespace std;

int N;
int D[2001][2001];
bool removed[2001];
priority_queue<pair<int, pair<int, int>>> pq;

int main()
{
    scan(N);
    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++)
        {
            scan(D[i][j]);
            if(i!=j)
                pq.push(make_pair(D[i][j], make_pair(i, j)));
        }
    for(int i=0; i<N; i++)
    {
        if(D[i][i]!=0)
            goto bad;
        for(int j=0; j<N; j++)
            if(D[i][j]!=D[j][i])
                goto bad;
    }
    for(int i=1; i<N; i++)
    {
        int u, v;
        bool good=false;
        while(!pq.empty())
        {
            auto p=pq.top();
            pq.pop();
            u=p.second.first;
            v=p.second.second;
            if(!removed[u] && !removed[v])
            {
                good=true;
                break;
            }
        }
        if(!good)
            goto bad;
        pair<int, int> mini=make_pair(0x3f3f3f3f, -1);
        removed[u]=true;
        for(int j=0; j<N; j++)
            if(!removed[j])
                mini=min(mini, make_pair(D[u][j], j));
        if(mini.first==0)
            goto bad;
        for(int j=0; j<N; j++)
            if(!removed[j])
                if(D[u][mini.second]+D[mini.second][j]!=D[u][j])
                    goto bad;
    }
    printf("YES\n");
    return 0;
    bad:;
    printf("NO\n");
    return 0;
}