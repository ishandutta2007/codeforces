#include<iostream>
#include<cstdio>
using namespace std;
int t,n,m,maxn,ans;
int main()
{
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        maxn=ans=-1e9;
        for(int i=1;i<=n;++i)
            for(int j=1;j<=m;++j)
            {
                int w;
                cin>>w;
                if(w>maxn)
                {
                    maxn=w;
                    ans=max(i,n-i+1)*max(j,m-j+1);
                }
                else if(w==maxn)
                    ans=max(ans,max(i,n-i+1)*max(j,m-j+1));
            }
        cout<<ans<<'\n';
    }
    return 0;
}