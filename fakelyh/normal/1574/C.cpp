#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,a[200005],m,x,y,sum;
signed main(){
    ios::sync_with_stdio(false);cin.tie(0),cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;sum+=a[i],i++)cin>>a[i];
    sort(a+1,a+n+1);
    cin>>m;
    for(int i=1;i<=m;i++){
        cin>>x>>y;
        int k=lower_bound(a+1,a+n+1,x)-a;
        if(a[k]<x)cout<<(x-a[n]+max(y-(sum-a[n]),0ll))<<endl;
        else cout<<min((k>1?x-a[k-1]+max(y-(sum-a[k-1]),0ll):1ll<<60),max(y-(sum-a[k]),0ll))<<endl;
    }
    return 0;
}