#include <bits/stdc++.h>
#define pb push_back
#define long long long
using namespace std;

int main()
{
    long a[5][5],i,j,b[5][5]={0};
    for(i=1;i<=3;++i)
    for(j=1;j<=3;++j)
    {
        cin>>a[i][j];
        b[i][j]=1;
        a[i][j]%=2;
    }
    for(i=1;i<=3;++i)
    for(j=1;j<=3;++j)
    {
        if(a[i][j]==1)
        {
            b[i][j]=!(b[i][j]);
            b[i+1][j]=!(b[i+1][j]);
            b[i-1][j]=!(b[i-1][j]);
            b[i][j+1]=!(b[i][j+1]);
            b[i][j-1]=!(b[i][j-1]);
        }
    }
    for(i=1;i<=3;++i)
    {
        for(j=1;j<=3;++j)
        cout<<b[i][j];
        cout<<endl;
    }
    return 0;
}