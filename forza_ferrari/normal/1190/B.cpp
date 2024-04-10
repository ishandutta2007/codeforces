#include<iostream>
#include<cstdio>
#include<algorithm>
#include<map>
using namespace std;
int n,a[100001],cnt,maxn,qwq;
long long ans;
map<int,int> mp;
int main()
{
    cin>>n;
    for(int i=1;i<=n;++i)
    {
        cin>>a[i];
        cnt+=(bool)mp[a[i]];
        ++mp[a[i]];
        qwq+=!a[i];
        maxn=max(maxn,a[i]);
    }
    for(auto i:mp)
        if(i.second>1&&mp.count(i.first-1))
        {
            puts("cslnb");
            return 0;
        }
    if(cnt>=2||qwq>=2)
    {
        puts("cslnb");
        return 0;
    }
    if(!maxn)
    {
        puts("cslnb");
        return 0;
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;++i)
        ans+=a[i]-i+1;
    cout<<(ans&1? "sjfnb":"cslnb")<<'\n';
    return 0;
}