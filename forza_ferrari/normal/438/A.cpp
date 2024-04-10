#include<iostream>
#include<cstdio>
using namespace std;
int n,m,ans,a[1001];
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;++i)
        cin>>a[i];
    for(int i=1;i<=m;++i)
    {
        int x,y;
        cin>>x>>y;
        ans+=min(a[x],a[y]);
    }
    cout<<ans<<'\n';
    return 0;
}