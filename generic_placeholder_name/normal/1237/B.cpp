#include <bits/stdc++.h>
#define ll long long
using namespace std;
 
int main()
{
    int n, ans=0, tmp; cin>>n; int a[n], b[n];
    for(int i=0; i<n; i++) {cin>>tmp; a[tmp]=i;} for(int i=0; i<n; i++) {cin>>tmp; b[i]=a[tmp];}
    int curr=b[n-1]; for(int i=n-2; i>=0; i--) {
        if(b[i]>curr) ans++;
        else curr=b[i];
    }
    cout<<ans;
}