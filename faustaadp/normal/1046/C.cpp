#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
ll n,d,ta,i,poin,p[202020],has,L,R,C,po[202020],HA;
vector<ll> v;
bool cek(ll aa)
{
    ll ii,te=n-2,R=1;
    for(ii=aa;ii<(n-1);ii++)
    {
        po[ii]=v[ii]+p[te];
        if(po[ii]>poin)
            return 0;
        te--;
    }
    /*
    for(ii=aa;ii<(n-1);ii++)
        cout<<po[ii]<<" ";
    cout<<"\n";*/
    return 1;
}
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>d;
	for(i=1;i<=n;i++)
    {
        cin>>ta;
        if(i==d)poin=ta;
        else    v.pb(ta);
    }
    cin>>ta;
    poin+=ta;
    for(i=0;i<(n-1);i++)
        cin>>p[i];
    has=d;
    L=0;
    R=n-1;
    while(L<=R)
    {
        C=(L+R)/2;
        if(cek(C))
        {
            has=min(has,C+1);
            R=C-1;
        }
        else
            L=C+1;
    }
    cout<<has<<"\n";
}