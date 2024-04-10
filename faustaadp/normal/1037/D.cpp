#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
ll n,i,ta,tb,d[202020],a[202020],pri[202020],x[202020],y[202020],u,b[202020],wak;
vector<pair<ll,ll> > v[202020];
queue<ll> q;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    for(i=1;i<n;i++)
        cin>>x[i]>>y[i];
    for(i=1;i<=n;i++)
    {
        cin>>ta;
        pri[ta]=i;
    }
    for(i=1;i<n;i++)
    {
        v[x[i]].pb(mp(pri[y[i]],y[i]));
        v[y[i]].pb(mp(pri[x[i]],x[i]));
    }
    for(i=1;i<=n;i++)
        sort(v[i].begin(),v[i].end());
    q.push(1);
    b[1]=1;
    while(!q.empty())
    {
        wak++;
        u=q.front();
        if(wak!=pri[u])
        {
            cout<<"No\n";
            return 0;
        }
        q.pop();
        for(i=0;i<v[u].size();i++)
        {
            if(!b[v[u][i].se])
            {
                b[v[u][i].se]=1;
                q.push(v[u][i].se);
            }
        }
    }
    cout<<"Yes\n";
}