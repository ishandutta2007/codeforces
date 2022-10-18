#include<iostream>
#include<cstdio>
#include<set>
using namespace std;
#define int long long
int t,n,m;
multiset<int> s;
signed main()
{
    cin>>t;
    while(t--)
    {
        s.clear();
        cin>>n>>m;
        for(int i=1;i<=n;++i)
        {
            int x;
            cin>>x;
            s.insert(x);
        }
        int ans=0;
        while(!s.empty())
        {
            int val=*s.begin();
            s.erase(s.begin());
            if(s.find(val*m)!=s.end())
                s.erase(s.find(val*m));
            else
                ++ans;
        }
        cout<<ans<<'\n';
    }
    return 0;
}