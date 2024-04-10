#include<iostream>
#include<cstdio>
#include<algorithm>
#include<map>
using namespace std;
int t,n,cnt[3];
map<int,int> mp;
int main()
{
    cin>>t;
    while(t--)
    {
        mp.clear();
        cin>>n;
        cnt[1]=cnt[2]=0;
        for(int i=1;i<=n;++i)
        {
            int x;
            cin>>x;
            ++mp[x];
        }
        for(auto i:mp)
            ++cnt[min(i.second,2)];
        cout<<((cnt[1]+1)>>1)+cnt[2]<<'\n';
    }
    return 0;
}