#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
ll n,m,nn,i,a[202020],has;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m;
    nn=n/2+1;
    for(i=1;i<=n;i++)
        cin>>a[i];
    sort(a+1,a+1+n);
    has=abs(m-a[nn]);
    a[nn]=m;
    for(i=1;i<nn;i++)
        has+=max(0LL,a[i]-a[nn]);
    for(i=nn+1;i<=n;i++)
        has+=max(0LL,a[nn]-a[i]);
    cout<<has<<"\n";
}