#include<iostream>
#include<cstdio>
#include<unordered_map>
using namespace std;
#define int long long
int n,m,ans,a[1001];
unordered_map<int,int> mp;
signed main()
{
    cin>>n>>m;
    mp.reserve(n);
    for(int i=1;i<=n;++i)
    {
        int val=0;
        for(int j=0;j<m;++j)
        {
            int x;
            cin>>x;
            ++x;
            val|=x<<(2*j);
        }
        ++mp[a[i]=val];
    }
    for(int i=1;i<=n;++i)
    {
        int sum=0;
        for(int j=1;j<=n;++j)
            if(i^j)
            {
                int val=0;
                for(int k=0;k<m;++k)
                {
                    int x=a[i]>>(2*k)&3,y=a[j]>>(2*k)&3;
                    if(x==y)
                        val|=x<<(2*k);
                    else
                        val|=(x^y)<<(2*k);
                }
                if(mp.count(val))
                    sum+=mp[val];
            }
        sum>>=1;
        ans+=sum*(sum-1)/2;
    }
    cout<<ans<<'\n';
    return 0;
}