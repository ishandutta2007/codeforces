#include<iostream>
#include<cstdio>
using namespace std;
int t,n,m,cnt;
char a[501][501];
int main()
{
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        cnt=0;
        for(int i=1;i<=n;++i)
            for(int j=1;j<=m;++j)
            {
                cin>>a[i][j];
                cnt+=a[i][j]-='0';
            }
        int w=3;
        for(int i=1;i<n;++i)
            for(int j=1;j<m;++j)
            {
                w=min(w,a[i][j]+a[i+1][j]+a[i][j+1]);
                w=min(w,a[i][j]+a[i+1][j]+a[i+1][j+1]);
                w=min(w,a[i][j]+a[i][j+1]+a[i+1][j+1]);
                w=min(w,a[i+1][j]+a[i][j+1]+a[i+1][j+1]);
            }
        cout<<min(cnt,cnt-w+1)<<'\n';
    }
    return 0;
}