#include<iostream>
#include<cstdio>
using namespace std;
int t,n,a[200001],ans[200001];
int main()
{
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(int i=1;i<=n;++i)
        {
            cin>>a[i];
            ans[i]=1;
        }
        int pos=0;
        for(int i=1;i<=n;++i)
        {
            if(pos<i)
                ans[i]=(bool)a[i];
            if(ans[i])
                ans[pos=a[i]+1]=0;
            else
                ans[pos=a[i]+i]=0;
        }
        for(int i=1;i<=n;++i)
            cout<<ans[i]<<" ";
        cout<<'\n';
    }
    return 0;
}