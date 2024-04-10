#include <bits/stdc++.h>
#define pb push_back
#define long long long
#define pll pair < long , long >
#define vll vector < pll >
#define ml map < long , long >
#define mll map < pll , long >
#define x first
#define y second
#define vl vector < long >
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
long seg[4000005]={0},lazy[4000005]={0};
long n,a[1000006],i,d,ans=0;
long j=0,x[1000006];
void update(int node, int start, int end, int l, int r)
{
    if(lazy[node] != 0)
    {
        seg[node]+=(end-start+1)*lazy[node];
        if(start!=end)
        {
            lazy[node*2]+=lazy[node];
            lazy[node*2+1]+=lazy[node];
        }
        lazy[node]=0;
    }
    if(start>end or start>r or end<l) return;
    if(start>=l and end<=r)
    {
        seg[node]+=end-start+1;
        if(start!=end)
        {
            lazy[node*2]++;
            lazy[node*2+1]++;
        }
        return;
    }
    long mid=(start+end)/2;
    update(node*2, start, mid, l, r);
    update(node*2 + 1, mid + 1, end, l, r);
    seg[node]=seg[node*2]+seg[node*2+1];
}

long query(long node , long start , long end , long r)
{
    long mid;
    if(lazy[node] != 0)
    {
        seg[node]+=(end-start+1)*lazy[node];
        if(start!=end)
        {
            lazy[node*2]+=lazy[node];
            lazy[node*2+1]+=lazy[node];
        }
        lazy[node]=0;
    }
    if(start==r && end==r) return seg[node];
    else
    {
        mid=(start+end)/2;
        if(r<=mid)
        return query(2*node,start,mid,r);
        else return query(2*node+1,mid+1,end,r);
    }
}
int main()
{
    map < long , int > mp;
    map < long , int > :: iterator it;
    cin>>n;
    for(i=0;i<n;++i)
    {
        cin>>a[i];
        mp[a[i]]=1;
    }
    for(it=mp.begin();it!=mp.end();it++)
    mp[it->x]=j++;
    for(i=0;i<n;++i)
    x[i]=mp[a[i]];
    for(i=0;i<n;++i)
    {
        d=query(1,0,n-1,x[i]);
        ans+=d*(x[i]-(i-d));
        update(1,0,n-1,0,x[i]);
    }
    cout<<ans;
    return 0;
}