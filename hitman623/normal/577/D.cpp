#include <bits/stdc++.h>
#define long long long
#define pb push_back
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    long n,i,p[100005],v[100005]={0},j,d,f;
    vector < pair < long , long > > e;
    map < pair < long , long > ,long > mp;
    cin>>n;
    for(i=1;i<=n;++i)
    cin>>p[i];
    for(i=1;i<=n;++i)
    if(p[i]==i)
    {
        cout<<"YES"<<endl;
        for(j=1;j<=n;++j)
        if(j!=i) cout<<i<<" "<<j<<endl;
        exit(0);
    }
    for(i=1;i<=n;++i)
    if(i==p[p[i]]) break;
    if(i==n+1) {cout<<"NO";exit(0);}
    v[i]=1;
    v[p[i]]=1;
    e.pb({i,p[i]});
    mp[{i,p[i]}]=1;
    v[p[i]]=1;
    for(j=1;j<=n;++j)
    if(v[j]==0)
    {
        e.pb({i,j});
        mp[{i,j}]=1;
        v[j]=1;
        d=j;
        f=i;
        while(!v[p[d]])
        {
            v[p[d]]=1;
            e.pb({p[f],p[d]});
            mp[{p[f],p[d]}]=1;
            f=p[f];
            d=p[d];
        }
        if(mp[{p[f],p[d]}]+mp[{p[d],p[f]}]==0) {cout<<"NO";exit(0);}
    }
    cout<<"YES"<<endl;
    for(i=0;i<e.size();++i)
    cout<<e[i].first<<" "<<e[i].second<<endl;
    return 0;
}