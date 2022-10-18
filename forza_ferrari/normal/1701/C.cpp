#include<iostream>
#include<cstdio>
#include<set>
using namespace std;
int t,n,m,a[200001];
int main()
{
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        for(int i=1;i<=n;++i)
            a[i]=0;
        while(m--)
        {
            int x;
            cin>>x;
            ++a[x];
        }
        multiset<pair<int,int> > s;
        for(int i=1;i<=n;++i)
            s.emplace(a[i],a[i]);
        int ans=(--s.end())->first;
        while((--s.end())->second)
        {
            if(s.size()==1)
                break;
            pair<int,int> x=*s.begin(),y=*--s.end();
            s.erase(s.begin());
            s.erase(--s.end());
            x.first+=2;
            --y.first;
            --y.second;
            s.emplace(x);
            s.emplace(y);
            ans=min(ans,(--s.end())->first);
        }
        cout<<ans<<'\n';
    }
    return 0;
}