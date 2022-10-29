#include <bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;

int main()
{
    long n,i,j,c,ans=0;
    char a[105][105];
    cin>>n;
    for(i=0;i<n;++i)
        cin>>a[i];
    for(i=0;i<n;++i)
    {
        c=0;
        for(j=0;j<n;++j)
        if(a[i][j]=='C') c++;
        ans+=(c*(c-1))/2;
    }
    for(i=0;i<n;++i)
    {
        c=0;
        for(j=0;j<n;++j)
        if(a[j][i]=='C') c++;
        ans+=(c*(c-1))/2;
    }
    cout<<ans;
    return 0;
}