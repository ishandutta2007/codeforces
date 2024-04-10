#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    int n, m, k; cin>>n>>m>>k; int a[n], diff[n-1]; for(int i=0; i<n; i++) cin>>a[i];
    for(int i=1; i<n; i++) diff[i-1]=a[i]-a[i-1];
    sort(diff, diff+n-1);
    ll ans=k; for(int i=0; i<n-k; i++) ans+=diff[i];
    cout<<ans; return 0;
}