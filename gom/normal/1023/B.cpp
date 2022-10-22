#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,k,ans;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>k;
    ans=min(n,(k+1)/2-1)-max(1LL,k-n)+1;
    if(ans<0) ans=0;
    cout<<ans;
    return 0;
}