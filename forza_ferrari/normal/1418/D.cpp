#include<iostream>
#include<cstdio>
#include<set>
#include<algorithm>
using namespace std;
int n,m,sum,a[100001];
multiset<int> s,val;
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;++i)
    {
        cin>>a[i];
        s.emplace(a[i]);
    }
    sort(a+1,a+n+1);
    for(int i=2;i<=n;++i)
    {
        val.emplace(a[i]-a[i-1]);
        sum+=a[i]-a[i-1];
    }
    if(s.size()<=2)
        cout<<0<<'\n';
    else
        cout<<sum-*--val.end()<<'\n';
    while(m--)
    {
        int opt,x;
        cin>>opt>>x;
        if(opt==0)
        {
            auto it=s.find(x),nxt=next(it);
            if(nxt!=s.end())
            {
                val.erase(val.find(*nxt-*it));
                sum-=*nxt-*it;
            }
            if(it!=s.begin())
            {
                auto pre=prev(it);
                val.erase(val.find(*it-*pre));
                sum-=*it-*pre;
                if(nxt!=s.end())
                {
                    val.emplace(*nxt-*pre);
                    sum+=*nxt-*pre;
                }
            }
            s.erase(s.find(x));
        }
        else
        {
            auto nxt=s.upper_bound(x);
            if(nxt!=s.begin())
            {
                auto pre=prev(nxt);
                if(nxt!=s.end())
                {
                    val.erase(val.find(*nxt-*pre));
                    sum-=*nxt-*pre;
                }
                val.emplace(x-*pre);
                sum+=x-*pre;
            }
            if(nxt!=s.end())
            {
                val.emplace(*nxt-x);
                sum+=*nxt-x;
            }
            s.emplace(x);
        }
        if(s.size()<=2)
            cout<<"0\n";
        else
            cout<<sum-*--val.end()<<'\n';
    }
    return 0;
}