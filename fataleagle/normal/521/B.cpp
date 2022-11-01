#include <bits/stdc++.h>

using namespace std;

const int MOD=1000000009;
int N;
map<pair<int, int>, int> all;
pair<int, int> points[100001];
set<pair<int, pair<int, int>>> good;
int ans;

bool isstable(int x, int y, int bx, int by)
{
    if(!all.count({x, y}))
        return true;
    return y==0 ||
           (make_pair(x-1, y-1)!=make_pair(bx, by) && all.count({x-1, y-1})) ||
           (make_pair(x, y-1)!=make_pair(bx, by) && all.count({x, y-1})) ||
           (make_pair(x+1, y-1)!=make_pair(bx, by) && all.count({x+1, y-1}));
}

bool canremove(int x, int y)
{
    return all.count({x, y}) &&
           isstable(x-1, y+1, x, y) &&
           isstable(x, y+1, x, y) &&
           isstable(x+1, y+1, x, y);
}

void check(int x, int y)
{
    if(canremove(x, y))
        good.insert({all[{x, y}], {x, y}});
}

void work(int x, int y)
{
    if(all.count({x, y}) && !canremove(x, y))
        good.erase({all[{x, y}], {x, y}});
}

void recheck(int x, int y)
{
    if(all.count({x, y}))
    {
        work(x-1, y-1);
        work(x, y-1);
        work(x+1, y-1);
    }
}

int main()
{
    scanf("%d", &N);
    int a, b;
    for(int i=0; i<N; i++)
    {
        scanf("%d%d", &a, &b);
        points[i]={a, b};
        all[{a, b}]=i;
    }
    for(int i=0; i<N; i++) if(canremove(points[i].first, points[i].second))
        good.insert({i, points[i]});
    for(int i=0; i<N; i++)
    {
        int x, y;
        if(i&1)
        {
            auto cur=*good.begin();
            ans=(1LL*ans*N+cur.first)%MOD;
            all.erase(cur.second);
            x=cur.second.first;
            y=cur.second.second;
            good.erase(cur);
        }
        else
        {
            auto cur=*good.rbegin();
            ans=(1LL*ans*N+cur.first)%MOD;
            all.erase(cur.second);
            x=cur.second.first;
            y=cur.second.second;
            good.erase(cur);
        }
        recheck(x-1, y+1);
        recheck(x, y+1);
        recheck(x+1, y+1);
        recheck(x-1, y);
        recheck(x, y);
        recheck(x+1, y);
        check(x-1, y-1);
        check(x, y-1);
        check(x+1, y-1);
    }
    printf("%d\n", ans);
    return 0;
}