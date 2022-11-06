#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
ll n,c,a[505050],has,hv,te,hebat,gen[505050],d[505050],i,hz,w[505050],XX,ma,D[505050];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>c;
    for(i=1;i<=n;i++)cin>>a[i];
    for(i=1;i<=n;i++)if(a[i]==c)hz++;
    has=hz;
    hv=0;
    te=0;
    hebat=-1;
    for(i=1;i<=n;i++)
    {
        if(a[i]==c)
        {
            hv++;
        }
        else
        {
            if((D[a[i]]-hv)<0)
                D[a[i]]=hv;
            D[a[i]]++;
            //cout<<i<<" "<<D[a[i]]<<" "<<hv<<"\n";
            has=max(has,hz+(D[a[i]]-hv));
        }
    }
    cout<<has<<"\n";
}