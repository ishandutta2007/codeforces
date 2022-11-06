#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
ll n,has,ta,tb,tc,td,nil,i,tem;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    has=1;
    cin>>ta>>tb>>tc>>td;
    nil=ta+tb+tc+td;
    for(i=2;i<=n;i++)
    {
        cin>>ta>>tb>>tc>>td;
        tem=ta+tb+tc+td;
        if(tem>nil)
            has++;
    }
    cout<<has<<"\n";
}