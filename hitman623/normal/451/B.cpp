#include <bits/stdc++.h>
#define pb push_back
#define int long long
#define pll pair < long , long >
#define vll vector < pll >
#define vl vector < long >
#define io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
main()
{
    io
    long n,a[100005],i,b[100005],j,l,r;
    cin>>n;
    l=n-1;
    r=n-1;
    for(i=0;i<n;++i)
    {
        cin>>a[i];
        b[i]=a[i];
    }
    sort(b,b+n);
    for(i=0;i<n;++i)
    if(a[i]!=b[i]) {l=i;break;}
    for(i=n-1;i>=0;i--)
    if(a[i]!=b[i]) {r=i;break;}
    for(i=l;i<=r;++i)
    if(a[i]!=b[r-(i-l)]) {cout<<"no";exit(0);}
    cout<<"yes"<<endl;
    cout<<l+1<<" "<<r+1;
    return 0;
}