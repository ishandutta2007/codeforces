#include<iostream>
#include<cstdio>
#include<set>
#include<cmath>
using namespace std;
int n,m;
set<pair<int,int> > s;
int main()
{
    cin>>n>>m;
    for(int i=1;i<=m;++i)
    {
        int x,y;
        cin>>x>>y;
        if(x>y)
            x^=y^=x^=y;
        s.insert({x,y});
    }
    for(int i=2;i*i<=n;++i)
        if(n%i==0)
        {
            int g=i;
            bool flag=1;
            for(auto i:s)
            {
                pair<int,int> p={(i.first+g-1)%n+1,(i.second+g-1)%n+1};
                if(p.first>p.second)
                    p.first^=p.second^=p.first^=p.second;
                if(!s.count(p))
                {
                    p={p.second,p.first};
                    if(s.count(p))
                        continue;
                    flag=0;
                    break;
                }
            }
            if(flag)
            {
                puts("YES");
                return 0;
            }
            g=n/i;
            flag=1;
            for(auto i:s)
            {
                pair<int,int> p={(i.first+g-1)%n+1,(i.second+g-1)%n+1};
                if(p.first>p.second)
                    p.first^=p.second^=p.first^=p.second;
                if(!s.count(p))
                {
                    p={p.second,p.first};
                    if(s.count(p))
                        continue;
                    flag=0;
                    break;
                }
            }
            if(flag)
            {
                puts("YES");
                return 0;
            }
        }
    int g=1;
    bool flag=1;
    for(auto i:s)
    {
        pair<int,int> p={(i.first+g-1)%n+1,(i.second+g-1)%n+1};
        if(p.first>p.second)
            p.first^=p.second^=p.first^=p.second;
        if(!s.count(p))
        {
            p={p.second,p.first};
            if(s.count(p))
                continue;
            flag=0;
            break;
        }
    }
    if(flag)
    {
        puts("YES");
        return 0;
    }
    puts("NO");
    return 0;
}