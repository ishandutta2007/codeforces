#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long n,m,i,j,a[111][111],b[101][101]={0},r[101]={0},c[101]={0},cnt=0,f=0;
    cin>>n>>m;
    for(i=0;i<n;++i)
    for(j=0;j<m;++j)
    {cin>>a[i][j];
    if(a[i][j]) f=1;}

    for(i=0;i<n;++i)
    {
        cnt=0;
        for(j=0;j<m;++j)
        if(a[i][j]==1) cnt++;
        if(cnt==m) r[i]=1;
    }

    for(i=0;i<m;++i)
    {
        cnt=0;
        for(j=0;j<n;++j)
        if(a[j][i]==1) cnt++;
        if(cnt==n) c[i]=1;
    }
    cnt=0;
    for(i=0;i<n;++i)
    {
        for(j=0;j<m;++j)
        {
            if(a[i][j]==1)
        {
            if(r[i]==1 && c[j]==1) b[i][j]=1;
            else if(r[i]==1 || c[j]==1);
            else {cout<<"NO";exit(0);}
        }
        if(b[i][j]) cnt++;
        }
     }
     if(cnt==0 && f==1) {cout<<"NO";exit(0);}
    cout<<"YES"<<endl;
    for(i=0;i<n;++i)
    {
        for(j=0;j<m;++j)
        cout<<b[i][j]<<" ";
        cout<<endl;
    }
    return 0;
}