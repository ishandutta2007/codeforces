#include<iostream>
#include<cstdio>
using namespace std;
#define int long long
int n,m,a[200001],ans,tag[200001],pos,val;
signed main()
{
    cin>>n>>m;
    for(int i=1;i<=n;++i)
    {
        cin>>a[i];
        ans+=a[i];
    }
    pos=-1;
    for(int i=1;i<=m;++i)
    {
        int opt;
        cin>>opt;
        if(opt==1)
        {
            int x,y;
            cin>>x>>y;
            ans+=y-(tag[x]>pos? a[x]:val);
            tag[x]=i;
            a[x]=y;
        }
        else
        {
            cin>>val;
            ans=n*val;
            pos=i;
        }
        cout<<ans<<'\n';
    }
    return 0;
}