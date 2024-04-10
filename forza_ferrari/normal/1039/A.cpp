#include<iostream>
#include<cstdio>
using namespace std;
#define int long long
int n,t,a[200001],pos[200001],b[200001],maxn;
signed main()
{
    cin>>n>>t;
    for(int i=1;i<=n;++i)
    {
        cin>>a[i];
        b[i]=a[i]+t;
    }
    for(int i=1;i<=n;++i)
    {
        cin>>pos[i];
        if(pos[i]<i||pos[i]<pos[i-1])
        {
            puts("No");
            return 0;
        }
        maxn=max(maxn,pos[i]);
        if(maxn>i)
            b[i]=b[i+1]++;
    }
    for(int i=1,j=0;i<=n;++i)
    {
        j=max(j,i+1);
        while(j<=n&&a[j]+t<=b[j-1])
            ++j;
        if(pos[i]^(j-1))
        {
            puts("No");
            return 0;
        }
    }
    puts("Yes");
    for(int i=1;i<=n;++i)
        cout<<b[i]<<' ';
    cout<<'\n';
    return 0;
}