#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int t,n,mp[1001][1001],ans;
bool a[1005][1005],b[1005][1005];
int main()
{
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(int i=1;i<=n;++i)
            for(int j=1;j<=n;++j)
                cin>>mp[i][j];
        for(int i=1;i<=n;++i)
            for(int j=1;j<=n+2;++j)
                b[i][j]=0;
        ans=0;
        for(int k=0;k<30;++k)
        {
            for(int i=1;i<=n;++i)
                for(int j=1;j<=n;++j)
                {
                    a[i][j]=(mp[i][j]>>k)&1;
                    if(i<n)
                        b[i+1][i]=b[i][i-1]^a[i][i];
                }
            for(int i=1;i<n;++i)
            {
                int x=i+2,y=i-1,l=i-1,r=i+2;
                while(x<=n&&l>=1)
                {
                    b[x][l]=a[x-1][l]^a[y][r-1]^b[x-1][l-1]^b[x-2][l]^b[x-1][l+1];
                    ++x;
                    --y;
                    --l;
                    ++r;
                }
            }
            bool flag=0;
            for(int i=1;i<=n;++i)
                for(int j=1;j<=n;++j)
                    flag^=b[i][j];
            ans^=(1<<k)*flag;
        }
        for(int i=1;i<=n;++i)
        {
            for(int j=1;j<=n+2;++j)
            {
                b[i][j]=0;
                
            }
            reverse(mp[i]+1,mp[i]+n+1);
        }
        for(int k=0;k<30;++k)
        {
            for(int i=1;i<=n;++i)
                for(int j=1;j<=n;++j)
                {
                    a[i][j]=(mp[i][j]>>k)&1;
                    if(i<n)
                        b[i+1][i]=b[i][i-1]^a[i][i];
                }
            for(int i=1;i<n;++i)
            {
                int x=i+2,y=i-1,l=i-1,r=i+2;
                while(x<=n&&l>=1)
                {
                    b[x][l]=a[x-1][l]^a[y][r-1]^b[x-1][l-1]^b[x-2][l]^b[x-1][l+1];
                    ++x;
                    --y;
                    --l;
                    ++r;
                }
            }
            bool flag=0;
            for(int i=1;i<=n;++i)
                for(int j=1;j<=n;++j)
                    flag^=b[i][j];
            ans^=(1<<k)*flag;
        }
        cout<<ans<<'\n';
    }
    return 0;
}