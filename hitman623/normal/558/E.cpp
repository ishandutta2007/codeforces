#include <bits/stdc++.h>
#define pb push_back
#define pll pair < int , int >
#define vll vector < pll >
#define ml map < int , int >
#define mll map < pll , int >
#define x first
#define y second
#define vl vector < int >
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
int seg[400005][26],lazy[400005][26],cur,j;
int n,q,i,l,r,k;
string s;
void build(int node ,int start ,int end,int x)
{
    int mid,m;
    if(start==end) seg[node][x]=(s[start]==('a'+x));
    else
    {
        mid=(start+end)/2;
        build(2*node,start,mid,x);
        build(2*node+1,mid+1,end,x);
        seg[node][x]=seg[2*node][x]+seg[2*node+1][x];
    }
}

void update(int node, int start, int end,int x, int l, int r, int val)
{
    if(lazy[node][x]!=-1)
    {
        seg[node][x]=(end-start+1)*lazy[node][x];
        if(start!=end)
        {
            lazy[node*2][x]=lazy[node][x];
            lazy[node*2+1][x]=lazy[node][x];
        }
        lazy[node][x]=-1;
    }
    if(start>end or start>r or end<l) return;
    if(start>=l and end<=r)
    {
        seg[node][x]=(end-start+1)*val;
        if(start!=end)
        {
            lazy[node*2][x]=val;
            lazy[node*2+1][x]=val;
        }
        return;
    }
    int mid=(start+end)/2;
    update(node*2, start, mid,x, l, r, val);
    update(node*2 + 1, mid + 1, end,x, l, r, val);
    seg[node][x]=seg[node*2][x]+seg[node*2+1][x];
}

int query(int node , int start , int end ,int x, int l , int r)
{
    int mid,p1,p2,m;
    if(l>end || r<start || start>end) return 0;
    if(lazy[node][x]!=-1)
    {
        seg[node][x]=(end-start+1)*lazy[node][x];
        if(start!=end)
        {
            lazy[node*2][x]=lazy[node][x];
            lazy[node*2+1][x]=lazy[node][x];
        }
        lazy[node][x]=-1;
    }
    if(start>=l && end<=r) return seg[node][x];
    else
    {
        mid=(start+end)/2;
        p1=query(2*node,start,mid,x,l,r);
        p2=query(2*node+1,mid+1,end,x,l,r);
        return p1+p2;
    }
}

int main()
{
    io
    cin>>n>>q>>s;
    memset(lazy,-1,sizeof lazy);
    for(i=0;i<26;++i)
    build(1,0,n-1,i);
    while(q--)
    {
        cin>>l>>r>>k;
        if(k==1)
        {
            int cur=0,d;
            for(i=0;i<26;++i)
            {
                d=query(1,0,n-1,i,l-1,r-1);
                update(1,0,n-1,i,l-1,r-1,0);
                update(1,0,n-1,i,l-1+cur,l-1+cur+d-1,1);
                cur+=d;
            }
        }
        else
        {
            int cur=0,d;
            for(i=25;i>=0;--i)
            {
                d=query(1,0,n-1,i,l-1,r-1);
                update(1,0,n-1,i,l-1,r-1,0);
                update(1,0,n-1,i,l-1+cur,l-1+cur+d-1,1);
                cur+=d;
            }
        }
    }
    for(i=0;i<n;++i)
    {
        for(j=0;j<26;++j)
        if(query(1,0,n-1,j,i,i)==1)
        s[i]='a'+j;
    }
    cout<<s;
    return 0;
}