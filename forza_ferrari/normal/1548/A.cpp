#include<iostream>
#include<cstdio>
#include<set>
using namespace std;
int n,m,q,ans;
set<int> s[200001];
int main()
{
    cin>>n>>m;
    ans=n;
    for(int i=1;i<=m;++i)
    {
        int x,y;
        cin>>x>>y;
        if(x>y)
            x^=y^=x^=y;
        if(s[x].empty()||*--s[x].end()<x)
            --ans;
        s[x].emplace(y);
        s[y].emplace(x);
    }
    cin>>q;
    while(q--)
    {
        int opt;
        cin>>opt;
        if(opt==1)
        {
            int x,y;
            cin>>x>>y;
            if(x>y)
                x^=y^=x^=y;
            if(s[x].empty()||*--s[x].end()<x)
                --ans;
            s[x].emplace(y);
            s[y].emplace(x);
        }
        if(opt==2)
        {
            int x,y;
            cin>>x>>y;
            if(x>y)
                x^=y^=x^=y;
            s[x].erase(y);
            s[y].erase(x);
            if(s[x].empty()||*--s[x].end()<x)
                ++ans;
        }
        if(opt==3)
            cout<<ans<<'\n';
    }
    return 0;
}