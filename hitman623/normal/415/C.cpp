#include <bits/stdc++.h>
#define pb push_back
#define long long long
using namespace std;

int main()
{
    long n,k,m,i,x,y,d=1e9;
    cin>>n>>k;
    if(n==1)
    {
        if(k==0) cout<<1;
        else cout<<-1;
        exit(0);
    }
    m=n/2;
    if(k<m) {cout<<-1;exit(0);}
    k=k-m+1;
    cout<<(d/k)*k<<" "<<(d/k-1)*k<<" ";
    for(i=1;i<=n-2;++i)
    cout<<i<<" ";
    return 0;
}