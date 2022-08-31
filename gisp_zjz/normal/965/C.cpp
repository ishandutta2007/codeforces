#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
ll n,k,p,q,ans,d;

int main()
{
    cin >> n >> k >> p >> q; d=1;
    for (ll i=1;i<=q;i++)
    {
        if (d>n) break;
        ans=max(ans,min(p,n/d)*i);
        d=d+k;
    }
    cout << ans << endl;
}