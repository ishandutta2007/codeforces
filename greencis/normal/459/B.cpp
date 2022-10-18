#include <bits/stdc++.h>
using namespace std;
int n,x,mn=2e9,mx=-2e9;
map<int,int> mp;
int main() {
 cin>>n;
 while(n--) cin>>x,mn=min(mn,x),mx=max(mx,x),++mp[x];
 cout << mx-mn << " " << (mx==mn?mp[mx]*1ll*(mp[mx]-1ll)/2ll:mp[mx] * 1ll * mp[mn]);
 return 0;
}