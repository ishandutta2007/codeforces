#include <bits/stdc++.h>
#define pb push_back
#define long long long
using namespace std;

int main()
{
    long n,m,b[103],i,a[102]={0},j;
    cin>>n>>m;
    for(i=0;i<m;++i)
    {
        cin>>b[i];
        for(j=b[i];j<=n;++j)
        if(a[j]==0) a[j]=b[i];
    }
    for(i=1;i<=n;++i)
    cout<<a[i]<<" ";
    return 0;
}