#include <bits/stdc++.h>
#define pb push_back
using namespace std;

int main()
{
    long n,m,f[100005],b[100005],a[100005],p[100005]={0},i,fl=0,v[100005]={0};
    cin>>n>>m;
    for(i=1;i<=n;++i)
    {
        cin>>f[i];
        if(p[f[i]]==0)
        p[f[i]]=i;
        else v[f[i]]=1;;
    }
    for(i=1;i<=m;++i)
    { 
        cin>>b[i];
        if(v[b[i]]==1) fl=1;
    }
    for(i=1;i<=m;++i)
    {
        a[i]=p[b[i]];
        if(p[b[i]]==0)
        fl=2;
    }
    if(fl==1) cout<<"Ambiguity";
    else if(fl==2) cout<<"Impossible";
    else
    {
        for(i=1;i<=m;++i)
        if(b[i]!=f[a[i]])
        {cout<<"Impossible";exit(0);}
        cout<<"Possible"<<endl;
        for(i=1;i<=m;++i)
            cout<<a[i]<<" ";
    }
    return 0;
}