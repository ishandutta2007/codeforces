#include <bits/stdc++.h>

using namespace std;

struct posn
{
    int x, y, dx, dy;
    bool operator< (const posn& o) const
    {
        if(x!=o.x)
            return x<o.x;
        if(y!=o.y)
            return y<o.y;
        if(dx!=o.dx)
            return dx<o.dx;
        return dy<o.dy;
    }
};

int n, m, K;
long long ans[100000];
map<int, vector<pair<int, int>>> leftDiagonal;
map<int, vector<pair<int, int>>> rightDiagonal;
set<posn> s;

int main()
{
    memset(ans, 0x3f, sizeof ans);
    scanf("%d%d%d", &n, &m, &K);
    int a, b;
    for(int i=0; i<K; i++)
    {
        scanf("%d%d", &a, &b);
        leftDiagonal[a+b].push_back({a-b, i});
        rightDiagonal[a-b].push_back({a+b, i});
    }
    long long t=0;
    int x=0, y=0, dx=1, dy=1;
    while(!s.count((posn){x, y, dx, dy}))
    {
        s.insert((posn){x, y, dx, dy});
        int d=0;
        if(dx==1 && dy==1) // right up
        {
            for(auto& it: rightDiagonal[x-y])
                ans[it.second]=min(ans[it.second], t+(it.first-(x+y))/2);
            d=min(n-x, m-y);
        }
        if(dx==-1 && dy==-1) // left down
        {
            for(auto& it: rightDiagonal[x-y])
                ans[it.second]=min(ans[it.second], t+((x+y)-it.first)/2);
            d=min(x, y);
        }
        if(dx==1 && dy==-1) // right down
        {
            for(auto& it: leftDiagonal[x+y])
                ans[it.second]=min(ans[it.second], t+(it.first-(x-y))/2);
            d=min(n-x, y);
        }
        if(dx==-1 && dy==1) // left up
        {
            for(auto& it: leftDiagonal[x+y])
                ans[it.second]=min(ans[it.second], t+((x-y)-it.first)/2);
            d=min(x, m-y);
        }
        t+=d;
        x+=d*dx;
        y+=d*dy;
        if(x==0 || x==n)
            dx*=-1;
        if(y==0 || y==m)
            dy*=-1;
    }
    for(int i=0; i<K; i++)
    {
        if(ans[i]==0x3f3f3f3f3f3f3f3fLL)
            printf("-1\n");
        else
            printf("%lld\n", ans[i]);
    }
    return 0;
}