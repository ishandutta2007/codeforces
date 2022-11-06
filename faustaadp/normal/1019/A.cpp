#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
ll n,m,i,ta,tb,j,k,tem,hz,isi1,has;
vector<ll> isi[3030];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(i=1;i<=n;i++)
    {
        cin>>ta>>tb;
        isi[ta].pb(tb);
    }
    for(i=1;i<=m;i++)
    {
        sort(isi[i].begin(),isi[i].end());
        reverse(isi[i].begin(),isi[i].end());
    }
    has=1e18;
    for(i=1;i<=n;i++)
    {
        hz=0;
        isi1=isi[1].size();
        vector<ll> v;
        for(j=2;j<=m;j++)
        {
            tem=isi[j].size();
            tem=min(tem,i-1);
            for(k=0;k<tem;k++)
                v.pb(isi[j][k]);
            for(k=tem;k<isi[j].size();k++)
            {
                isi1++;
                hz+=isi[j][k];
            }
        }
        sort(v.begin(),v.end());
        tem=i-isi1;
        tem=min(tem,(ll)v.size());
        for(j=0;j<tem;j++)
            hz+=v[j];
        has=min(has,hz);
    }
    cout<<has<<"\n";
}