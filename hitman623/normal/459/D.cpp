#include <bits/stdc++.h>
#define pb push_back
#define pll pair < int , int >
#define vll vector < pll >
#define ml map < int , int >
#define mll map < pll , int >
#define x first
#define y second
#define vl vector < int >
#define io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
vl seg[4000001];
int a[1000001];
void build(int node , int start , int end)
{
    if(start>end) return;
    if(start==end) seg[node].pb(a[start]);
    else
    {
        build(2*node,start,(start+end)/2);
        build(2*node+1,(start+end)/2+1,end);
        if(seg[2*node].size()!=0)
        seg[node]=seg[2*node];
        if(seg[2*node+1].size()!=0)
        seg[node].insert(seg[node].end(),seg[2*node+1].begin(),seg[2*node+1].end());
        sort(seg[node].begin(),seg[node].end());
    }
}
long long query(int node , int start , int end , int l , int r , int val)
{
    if(l>r) return 0;
    if(l>end || r<start) return 0;
    if(start>=l && end<=r) return lower_bound(seg[node].begin(),seg[node].end(),val)-seg[node].begin();
    else return query(2*node,start,(start+end)/2,l,r,val)+query(2*node+1,(start+end)/2+1,end,l,r,val);
}
int n,i;
long long ans=0;
vl b(1000001),l(1000001);
int main()
{
    io
    ml m;
    cin>>n;
    for(i=0;i<n;++i)
    cin>>b[i];
    for(i=0;i<n;++i)
    {
        m[b[i]]++;
        l[i]=m[b[i]];
    }
    m.clear();
    for(i=n-1;i>=0;--i)
    {
        m[b[i]]++;
        a[i]=m[b[i]];
    }
    b.clear();
    m.clear();
    build(1,0,n-1);
    for(i=0;i<n-1;++i)
    ans+=query(1,0,n-1,i+1,n-1,l[i]);
    cout<<ans;
    return 0;
}