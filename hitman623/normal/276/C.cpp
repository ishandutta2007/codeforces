#include <bits/stdc++.h>
#define pb push_back
#define long long long
#define pll pair < long , long >
#define vll vector < pll >
#define vl vector < long >
#define io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
long n,a[200005],val[200005],x,y,q,i,j,cur=0,ans=0;
int main()
{
    io
    vll v;
    cin>>n>>q;
    for(i=0;i<n;++i)
    cin>>a[i];
    sort(a,a+n);
    reverse(a,a+n);
    while(q--)
    {
        cin>>x>>y;
        v.pb({x,-1});
        v.pb({y,1});
    }
    sort(v.begin(),v.end());
    for(i=0;i<v[0].first;++i)
    val[i]=0;
    for(i=0;i<v.size();++i)
    {
        cur-=v[i].second;
        for(j=v[i].first;j<=((i<(v.size()-1))?v[i+1].first:200003);++j)
        val[j]=max(val[j],cur);
    }
    sort(val,val+200005);
    reverse(val,val+200005);
    i=0;
    while(1)
    {
        if(val[i]==0) break;
        ans+=val[i]*a[i];
        i++;
    }
    cout<<ans;
    return 0;
}