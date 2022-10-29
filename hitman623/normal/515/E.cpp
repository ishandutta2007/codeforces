#include <bits/stdc++.h>
#define long long long
using namespace std;

long a[200005][2],seg[800005][4];
long n,q,x,y,i,z,d[200005]={0},h[100005];

void build(long node , long start , long end)
{
    long mid;
    if(start==end) {seg[node][0]=start;seg[node][1]=2*n+2;seg[node][2]=start;seg[node][3]=2*n+2;}
    else
    {
        mid=(start+end)/2;
        build(2*node,start,mid);
        build(2*node+1,mid+1,end);
        if (a[seg[2*node][0]][0]>a[seg[2*node+1][0]][0])
        {
            seg[node][0]=seg[2*node][0];
            if(a[seg[2*node+1][0]][0]>a[seg[2*node][1]][0])
            seg[node][1]=seg[2*node+1][0];
            else seg[node][1]=seg[2*node][1];
        }
        else
        {
            seg[node][0]=seg[2*node+1][0];
            if(a[seg[2*node][0]][0]>a[seg[2*node+1][1]][0])
            seg[node][1]=seg[2*node][0];
            else seg[node][1]=seg[2*node+1][1];
        }
        if (a[seg[2*node][2]][1]>a[seg[2*node+1][2]][1])
        {
            seg[node][2]=seg[2*node][2];
            if(a[seg[2*node+1][2]][1]>a[seg[2*node][3]][1])
            seg[node][3]=seg[2*node+1][2];
            else seg[node][3]=seg[2*node][3];
        }
        else
        {
            seg[node][2]=seg[2*node+1][2];
            if(a[seg[2*node][2]][1]>a[seg[2*node+1][3]][1])
            seg[node][3]=seg[2*node][2];
            else seg[node][3]=seg[2*node+1][3];
        }
    }
}
struct s
{
    long aa,bb,cc,dd;
}q1;
s query(long node , long start , long end , long l , long r)
{
    long mid;
    s w,p1,p2;
    if(l>end || r<start || l>r) return {2*n+2,2*n+2,2*n+2,2*n+2};
    if(start>=l && end<=r) return {seg[node][0],seg[node][1],seg[node][2],seg[node][3]};
    else
    {
        mid=(start+end)/2;
        p1=query(2*node,start,mid,l,r);
        p2=query(2*node+1,mid+1,end,l,r);
        if(a[p1.aa][0]>a[p2.aa][0])
        {
            w.aa=p1.aa;
            if(a[p1.bb][0]>a[p2.aa][0])
            w.bb=p1.bb;
            else w.bb=p2.aa;
        }
        else
        {
            w.aa=p2.aa;
            if(a[p1.aa][0]>a[p2.bb][0])
            w.bb=p1.aa;
            else w.bb=p2.bb;
        }
        if(a[p1.cc][1]>a[p2.cc][1])
        {
            w.cc=p1.cc;
            if(a[p1.dd][1]>a[p2.cc][1])
            w.dd=p1.dd;
            else w.dd=p2.cc;
        }
        else
        {
            w.cc=p2.cc;
            if(a[p1.cc][1]>a[p2.dd][1])
            w.dd=p1.cc;
            else w.dd=p2.dd;
        }
        return w;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>q;
    a[2*n+2][0]=-10000000000000000;
    a[2*n+2][1]=-10000000000000000;
    for(i=0;i<n;++i)
    {
        cin>>d[i];
        if(i>0)
        d[i]+=d[i-1];
    }
    for(i=n;i<2*n;++i)
    d[i]+=d[i-1]+d[i-n]-((i>=n+1)?d[i-n-1]:0);
    for(i=0;i<n;++i)
    cin>>h[i];
    for(i=1;i<=2*n;++i)
    {
        a[i][0]=2*h[i%n]+d[i-1];
        a[i][1]=2*h[i%n]-d[i-1];
    }
    build(1,1,2*n);
    while(q--)
    {
        cin>>x>>y;
        if(x<=y)
        {
            q1=query(1,1,2*n,y,n+x-2);
            if(q1.aa!=q1.cc)
            cout<<a[q1.aa][0]+a[q1.cc][1]<<endl;
            else cout<<max(a[q1.aa][0]+a[q1.dd][1],a[q1.bb][0]+a[q1.cc][1])<<endl;
        }
        else
        {
            q1=query(1,1,2*n,y,x-2);
            if(q1.aa!=q1.cc)
            cout<<a[q1.aa][0]+a[q1.cc][1]<<endl;
            else cout<<max(a[q1.aa][0]+a[q1.dd][1],a[q1.bb][0]+a[q1.cc][1])<<endl;
        }
    }
    return 0;
}