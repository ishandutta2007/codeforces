#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int t,n,m,a[101],p[101];
int main()
{
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        for(int i=1;i<=n;++i)
        {
            p[i]=i;
            cin>>a[i];
        }
        sort(p+1,p+n+1,[&](int x,int y){return a[x]<a[y];});
        int ans=0;
        for(int i=1;i<=m;++i)
            ans+=p[i]>m;
        cout<<ans<<'\n';
    }
    return 0;
}