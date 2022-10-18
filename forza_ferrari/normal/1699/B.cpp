#include<iostream>
#include<cstdio>
using namespace std;
int t,n,m,a[51][51];
int main()
{
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        for(int i=1;i<=n;i+=2)
            for(int j=1;j<=m;j+=2)
            {
                int tag=(i/2+j/2)&1;
                a[i][j]=a[i+1][j+1]=tag;
                a[i+1][j]=a[i][j+1]=tag^1;
            }
        for(int i=1;i<=n;++i,cout<<'\n')
            for(int j=1;j<=m;++j)
                cout<<a[i][j]<<" ";
    }
    return 0;
}