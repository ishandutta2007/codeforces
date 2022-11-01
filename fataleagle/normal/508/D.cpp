#include <bits/stdc++.h>

using namespace std;

int N;
char buf[4];
vector<int> adj[256*256];
int in[256*256];
int out[256*256];
vector<pair<int, int>> fwd, bck;

int main()
{
    scanf("%d", &N);
    for(int i=0; i<N; i++)
    {
        scanf("%s", buf);
        int u=buf[0]*256+buf[1];
        int v=buf[1]*256+buf[2];
        adj[u].push_back(v);
        out[u]++;
        in[v]++;
    }
    int ingtout=0, outgtin=0, start=-1;
    for(int i=0; i<256*256; i++)
        if(in[i]!=out[i])
        {
            if(abs(in[i]-out[i])>1)
            {
                printf("NO\n");
                return 0;
            }
            ingtout+=in[i]>out[i];
            outgtin+=out[i]>in[i];
            if(out[i]>in[i])
                start=i;
        }
    if(!((ingtout==0 && outgtin==0) || (ingtout==1 && outgtin==1)))
    {
        printf("NO\n");
        return 0;
    }
    if(ingtout==0)
        for(int i=0; i<256*256; i++)
            if(!adj[i].empty())
                start=i;
    int u=start;
    while(!adj[u].empty())
    {
        int v=adj[u].back();
        adj[u].pop_back();
        fwd.push_back(make_pair(u, v));
        u=v;
    }
    while(!fwd.empty())
    {
        u=fwd.back().first;
        int v=fwd.back().second;
        fwd.pop_back();
        bck.push_back(make_pair(u, v));
        while(!adj[u].empty())
        {
            int v=adj[u].back();
            adj[u].pop_back();
            fwd.push_back(make_pair(u, v));
            u=v;
        }
    }
    if((int)bck.size()!=N)
        printf("NO\n");
    else
    {
        printf("YES\n");
        putchar(start/256);
        putchar(start%256);
        while(!bck.empty())
        {
            putchar(bck.back().second%256);
            bck.pop_back();
        }
        printf("\n");
    }
    return 0;
}