#include<iostream>
#include<cstdio>
using namespace std;
int t,n,c[501][501];
long long ans;
int main()
{
    cin>>t;
    while(t--)
    {
        cin>>n;
        ans=0;
        for(int i=1;i<=n+n;++i)
            for(int j=1;j<=n+n;++j)
            {
                cin>>c[i][j];
                if(i>n&&j>n)
                    ans+=c[i][j];
            }
        cout<<ans+min(min(min(c[1][1+n],c[1][n+n]),min(c[n][1+n],c[n][n+n])),min(min(c[1+n][1],c[1+n][n]),min(c[n+n][1],c[n+n][n])))<<'\n';
    }
    return 0;
}