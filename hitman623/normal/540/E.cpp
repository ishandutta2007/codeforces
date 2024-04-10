#include <bits/stdc++.h>
#define pb push_back
#define long long long
using namespace std;
vector < long > seg[800005],v,p;
void build(long node , long start , long end)
{
    long mid;
    if(start==end) seg[node].pb(v[start]);
    else
    {
        mid=(start+end)/2;
        build(2*node,start,mid);
        build(2*node+1,mid+1,end);
        seg[node]=seg[2*node];
        copy(seg[2*node+1].begin(), seg[2*node+1].end(), std::back_inserter(seg[node]));
        sort(seg[node].begin(),seg[node].end());
    }
}

long query(long node , long start , long end , long l , long r , long k)
{
    long mid,p1,p2;
    if(l>end || r<start) return 0;
    if(start>=l && end<=r) return lower_bound(seg[node].begin(),seg[node].end(),k)-seg[node].begin();
    else
    {
        mid=(start+end)/2;
        p1=query(2*node,start,mid,l,r,k);
        p2=query(2*node+1,mid+1,end,l,r,k);
        return p1+p2;
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    map < long ,long > mp;
    map < long ,long > ::iterator it;
    set < long > s;
    long n,a,b,i,ta,tb,ans=0;
    cin>>n;
    for(i=0;i<n;++i)
    {
        cin>>a>>b;
        if(mp[a]==0) mp[a]=a;
        if(mp[b]==0) mp[b]=b;
        ta=mp[a];
        tb=mp[b];
        mp[a]=tb;
        mp[b]=ta;
    }
    for(it=mp.begin();it!=mp.end();it++)
    {
        v.pb(it->second);
        p.pb(it->first);
    }
    n=v.size();
    build(1,0,n-1);
    for(i=0;i<n;++i)
    {
        ans+=query(1,0,n-1,i,n-1,v[i]);
        if(i>0)
        {
            ans+=(p[i]-p[i-1]-1)*(query(1,0,n-1,i,n-1,p[i-1]+1));
            ans+=(p[i]-p[i-1]-1)*(i-query(1,0,n-1,0,i-1,p[i-1]+1));
        }
    }
    cout<<ans;
    return 0;
}