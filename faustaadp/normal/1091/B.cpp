#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
ll n,X,Y,x,y,ta,tb,i;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    X=-1e18;
    Y=-1e18;
    x=1e18;
    y=1e18;
    for(i=1;i<=n;i++)
    {
        cin>>ta>>tb;
        X=max(X,ta);
        Y=max(Y,tb);
    }
    for(i=1;i<=n;i++)
    {
        cin>>ta>>tb;
        x=min(x,ta);
        y=min(y,tb);
    }
    cout<<x+X<<" "<<y+Y<<"\n";
}