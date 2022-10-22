#include <bits/stdc++.h>

using namespace std;
#define int long long
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
   int n;cin>>n;++n;if(n==2) {cout<<3;return 0;}
   int x=(n/3);int ans=4*x+1;
   if(n%3==0) cout<<ans;
   else if(n%3==1) cout<<(ans+2);
   else cout<<(ans+3);
    return 0;
}