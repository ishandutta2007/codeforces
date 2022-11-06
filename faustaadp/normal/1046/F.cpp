#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
ll n,i,a[202020],x,f,has;
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	for(i=1;i<=n;i++)
        cin>>a[i];
    cin>>x>>f;
    for(i=1;i<=n;i++)
    {
        if(a[i]<=x) continue;
        ll X=(a[i]-x),Y=(x+f);
        has+=X/Y+(X%Y!=0);
    }
    has*=f;
    cout<<has<<"\n";
}