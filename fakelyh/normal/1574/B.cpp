#include<bits/stdc++.h>
using namespace std;
#define int long long
int t,a[3],m;
signed main(){
    ios::sync_with_stdio(false);cin.tie(0),cout.tie(0);
    cin>>t;
    while(t--){
        cin>>a[0]>>a[1]>>a[2]>>m;
        sort(a,a+3);
        cout<<(a[2]-a[1]-a[0]-1<=m&&m<=a[0]+a[1]+a[2]-3?"YES\n":"NO\n");
    }
    return 0;
}