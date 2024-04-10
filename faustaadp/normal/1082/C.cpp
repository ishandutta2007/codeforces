#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
ll n,m,i,ta,tb,hz,has,j,b[101010],jum[101010];
vector<ll> v[101010],isi[101010],keluar[101010],nil[101010];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(i=1;i<=n;i++)
    {
        cin>>ta>>tb;
        v[ta].pb(tb);
    }
    for(i=1;i<=m;i++)
    {
        sort(v[i].begin(),v[i].end());
        reverse(v[i].begin(),v[i].end());
        ll vs=v[i].size();
        for(j=0;j<vs;j++)
        {
            isi[j+1].pb(i);
            nil[j+1].pb(v[i][j]);
        }
        keluar[vs].pb(i);
    }
    for(i=1;i<=100000;i++)
    {
        for(j=0;j<isi[i].size();j++)
        {
            if(b[isi[i][j]])continue;
            jum[isi[i][j]]+=nil[i][j];
            hz+=nil[i][j];
            if(jum[isi[i][j]]<0)
            {
                hz-=jum[isi[i][j]];
                b[isi[i][j]]=1;
            }
        }
        has=max(has,hz);
        for(j=0;j<keluar[i].size();j++)
        {
            if(b[keluar[i][j]])continue;
            hz-=jum[keluar[i][j]];
            b[keluar[i][j]]=1;
        }
    }
    cout<<has<<"\n";
}