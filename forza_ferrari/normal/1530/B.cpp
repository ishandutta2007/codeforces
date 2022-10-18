#include<iostream>
#include<cstdio>
using namespace std;
int t,n,m,a[21][21];
int main()
{
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        for(int i=1;i<=n;++i)
            for(int j=1;j<=m;++j)
                a[i][j]=0;
        for(int i=1;i<=m;i+=2)
            a[1][i]=1;
        for(int i=1;i<=n;i+=2)
            a[i][1]=1;
        for(int i=3;i<=n;i+=2)
            a[i][m]=1;
        for(int i=3;i<=m;i+=2)
            a[n][i]=1;
        if(a[n][m])
            a[n][m-1]=a[n-1][m]=0;
        else if(a[n][m-1])
            a[n-1][m]=0;
        for(int i=1;i<=n;++i,cout<<'\n')
            for(int j=1;j<=m;++j)
                cout<<a[i][j];
    }
    return 0;
}