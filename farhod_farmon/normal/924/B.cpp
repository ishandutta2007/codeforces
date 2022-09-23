#include <bits/stdc++.h>
#define ill int long long
#define fi first
#define se second
#define pb push_back
#define ld long double
using namespace std;
ill n,k,i,j,INF=1e18,a[100005],h;
ld ans=-1e18;
int main()
{
    //freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
    cin>>n>>k;
    for (i=1;i<=n;i++)
        cin>>a[i];
    for (i=1;i<n-1;i++)
    {
        ill l=i+2,r=n;
        while (l+1<r)
        {
            ill m=(l+r)/2;
            if (a[m]-a[i]<=k)l=m;
            else r=m;
        }
        //cout<<i<<" "<<r<<endl;
        if (a[r]-a[i]<=k && ans<((a[r]-a[i+1])*1.0)/((a[r]-a[i])*1.0))
            ans=((a[r]-a[i+1])*1.0)/((a[r]-a[i])*1.0),h=1;
        if (a[l]-a[i]<=k && ans<((a[l]-a[i+1])*1.0)/((a[l]-a[i])*1.0))
            ans=((a[l]-a[i+1])*1.0)/((a[l]-a[i])*1.0),h=1;
    }
    if (!h)cout<<-1;
    else
        cout<<fixed<<setprecision(9)<<ans;
}