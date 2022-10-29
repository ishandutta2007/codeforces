#include <bits/stdc++.h>
#define pb push_back
using namespace std;

int main()
{
    long k,i,j;
    cin>>k;
    if(k%2==0) {cout<<"NO";exit(0);}
    cout<<"YES"<<endl;
    cout<<4*k-2<<" "<<k*(2*k-1)<<endl;
    for(i=2;i<=k;++i)
    cout<<1<<" "<<i<<endl;
    for(i=2;i<=k;++i)
    for(j=k+1;j<=2*k-1;j++)
    cout<<i<<" "<<j<<endl;
    for(i=2*k+1;i<3*k;++i)
    cout<<2*k<<" "<<i<<endl;
    for(i=2*k+1;i<3*k;++i)
    for(j=3*k;j<=4*k-2;j++)
    cout<<i<<" "<<j<<endl;
    for(j=k+1;j<=2*k-1;j+=2)
    cout<<j<<" "<<j+1<<endl;
    for(j=3*k;j<=4*k-2;j+=2)
    cout<<j<<" "<<j+1<<endl;
    cout<<1<<" "<<2*k<<endl;
    return 0;
}