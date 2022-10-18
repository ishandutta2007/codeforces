#include<iostream>
#include<cstdio>
#include<set>
using namespace std;
int n,m,q,len,sum;
set<int> pos;
int main()
{
    cin>>n>>m>>len>>q;
    pos.emplace(0);
    pos.emplace(n+1);
    sum=(n+1)/(len+1);
    for(int i=1;i<=q;++i)
    {
        int x,l,r;
        cin>>x;
        if(pos.find(x)!=pos.end())
            continue;
        auto it=pos.upper_bound(x);
        l=*prev(it),r=*it;
        sum-=(r-l)/(len+1);
        sum+=(x-l)/(len+1)+(r-x)/(len+1);
        pos.emplace(x);
        if(sum<m)
        {
            cout<<i<<'\n';
            return 0;
        }
    }
    cout<<"-1\n";
    return 0;
}