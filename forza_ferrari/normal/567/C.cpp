#include<iostream>
#include<cstdio>
#include<map>
using namespace std;
int n,m,a[200001];
long long ans;
map<long long,int> cnt[2];
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;++i)
    {
        cin>>a[i];
        ++cnt[1][a[i]];
    }
    for(int i=1;i<=n;++i)
    {
        --cnt[1][a[i]];
        if(a[i]%m==0)
            ans+=1ll*cnt[0][a[i]/m]*cnt[1][1ll*a[i]*m];
        ++cnt[0][a[i]];
    }
    cout<<ans<<'\n';
    return 0;
}