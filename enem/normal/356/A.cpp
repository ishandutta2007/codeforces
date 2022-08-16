#include<bits/stdc++.h>
using namespace std;

void build(int v,int tl,int tr,int st[],int lz[],bool f[],int a[])
{
    if(tl==tr)
    {
        st[v]=a[tl];
        lz[v]=0;
        f[v]=false;
        return;
    }
    build((v<<1),tl,((tl+tr)>>1),st,lz,f,a);
    build((v<<1)|1,((tl+tr)>>1)+1,tr,st,lz,f,a);
    st[v]=st[(v<<1)]+st[(v<<1)|1];
    lz[v]=0;
    f[v]=false;
    return;
}

void push(int v,int tl,int tr,int st[],int lz[],bool f[])
{
    if(f[v])
    {
        st[(v<<1)]=lz[v]*(((tl+tr)>>1)-tl+1);
        lz[(v<<1)]=lz[v];
        f[(v<<1)]=true;
        st[(v<<1)|1]=lz[v]*(tr-((tl+tr)>>1));
        lz[(v<<1)|1]=lz[v];
        f[(v<<1)|1]=true;
        f[v]=false;
    }
    return;
}

void update(int v,int tl,int tr,int l,int r,int val,int st[],int lz[],bool f[])
{
    if(l>r)
    {
        return;
    }
    if(l==tl&&tr==r)
    {
        st[v]=val*(tr-tl+1);
        lz[v]=val;
        f[v]=true;
        return;
    }
    push(v,tl,tr,st,lz,f);
    update((v<<1),tl,((tl+tr)>>1),l,min(r,((tl+tr)>>1)),val,st,lz,f);
    update((v<<1)|1,((tl+tr)>>1)+1,tr,max(l,((tl+tr)>>1)+1),r,val,st,lz,f);
    st[v]=st[(v<<1)]+st[(v<<1)|1];
    return;
}

int query(int v,int tl,int tr,int l,int r,int st[],int lz[],bool f[])
{
    if(l>r)
    {
        return 0;
    }
    if(l==tl&&tr==r)
    {
        return st[v];
    }
    push(v,tl,tr,st,lz,f);
    return query((v<<1),tl,((tl+tr)>>1),l,min(r,((tl+tr)>>1)),st,lz,f)+query((v<<1)|1,((tl+tr)>>1)+1,tr,max(l,((tl+tr)>>1)+1),r,st,lz,f);
}

int main()
{
    int n,m;
    cin>>n>>m;
    int a[n],st[4*n],lz[4*n];
    bool f[4*n];
    for(int i=0;i<n;i++)
    {
        a[i]=0;
    }
    build(1,0,n-1,st,lz,f,a);
    int l[m],r[m],v[m];
    for(int i=0;i<m;i++)
    {
        cin>>l[i]>>r[i]>>v[i];
        l[i]--;
        r[i]--;
        v[i]--;
    }
    for(int i=m-1;i>=0;i--)
    {
        update(1,0,n-1,l[i],v[i]-1,v[i]+1,st,lz,f);
        update(1,0,n-1,v[i]+1,r[i],v[i]+1,st,lz,f);
    }
    for(int i=0;i<n;i++)
    {
        cout<<query(1,0,n-1,i,i,st,lz,f)<<' ';
    }
    return 0;
}