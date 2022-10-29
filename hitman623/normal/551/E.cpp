#include <bits/stdc++.h>
#define long long long
#define pb push_back
using namespace std;
long cmp(pair <long , long > a ,pair < long ,long > b)
{
    if(a.first!=b.first) return a.first<b.first;
    else return a.second<b.second;
}
long n,q,a[500005],i,s,m,x,y,z,l,r,mx,mn;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>q;
    pair < long , long >p;
    for(i=0;i<n;++i)
    cin>>a[i];
    s=sqrt(n);
    vector < pair < long , long > > v[n/s+1];
    long inc[n/s+1]={0};
    for(i=0;i<n;++i)
    v[i/s].pb({a[i],i});
    m=(n-1)/s+1;
    for(i=0;i<m;++i)
    sort(v[i].begin(),v[i].end(),cmp);
    while(q--)
    {
        cin>>x;
        if(x==1)
        {
            cin>>x>>y>>z;
            x--;y--;
            for(i=x/s+1;i<y/s;++i)
            inc[i]+=z;
            r=min((x/s+1)*s,y+1);
            l=x;
            for(i=0;i<v[x/s].size();++i)
            if(v[x/s][i].second>=l && v[x/s][i].second<r)
            v[x/s][i].first+=z;
            sort(v[x/s].begin(),v[x/s].end(),cmp);
            if(y/s==x/s) continue;
            l=(y/s)*s;
            r=y+1;
            for(i=0;i<v[y/s].size();++i)
            if(v[y/s][i].second>=l && v[y/s][i].second<r)
            v[y/s][i].first+=z;
            sort(v[y/s].begin(),v[y/s].end(),cmp);
        }
        else  if(x==2)
        {
            cin>>y;
            mx=-1;
            mn=1e9;
            for(i=0;i<m;++i)
            {
                p={y-inc[i],(long)-1};
                l=upper_bound(v[i].begin(),v[i].end(),p)-v[i].begin();
                p={y-inc[i],(long)1e9};
                r=upper_bound(v[i].begin(),v[i].end(),p)-v[i].begin();
                if(r==0) continue;
                if(v[i][r-1].first!=y-inc[i]) continue;
                mx=max(v[i][r-1].second,mx);
                mn=min(v[i][l].second,mn);
            }
            if(mn==1e9) mn=0;
            cout<<mx-mn<<endl;
        }
    }
    return 0;
}