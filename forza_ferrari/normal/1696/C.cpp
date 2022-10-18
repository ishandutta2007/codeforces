#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
#define int long long
int t,n,m;
vector<pair<int,int> > a,b;
signed main()
{
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        a.clear();
        b.clear();
        for(int i=1;i<=n;++i)
        {
            int x,cnt=1;
            cin>>x;
            while(x%m==0)
            {
                cnt*=m;
                x/=m;
            }
            if(!a.empty()&&a.back().first==x)
                a.back().second+=cnt;
            else
                a.emplace_back(x,cnt);
        }
        cin>>n;
        for(int i=1;i<=n;++i)
        {
            int x,cnt=1;
            cin>>x;
            while(x%m==0)
            {
                cnt*=m;
                x/=m;
            }
            if(!b.empty()&&b.back().first==x)
                b.back().second+=cnt;
            else
                b.emplace_back(x,cnt);
        }
        cout<<(a==b? "YES":"NO")<<'\n';
    }
    return 0;
}