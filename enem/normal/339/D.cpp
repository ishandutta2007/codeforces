#include<bits/stdc++.h>
using namespace std;

void build(int v,int tl,int tr,bool isitxor,int st[],int a[])
{
    if(tl==tr)
    {
        st[v]=a[tl];
        return;
    }
    int tm=(tl+tr)/2;
    build(v*2,tl,tm,!isitxor,st,a);
    build(v*2+1,tm+1,tr,!isitxor,st,a);
    if(isitxor) st[v]=(st[v*2]^st[v*2+1]);
    else st[v]=(st[v*2]|st[v*2+1]);
    return;
}

void update(int v,int tl,int tr,bool isitxor,int pos,int val,int st[])
{
    if(pos<tl||pos>tr)
    {
        return;
    }
    if(tl==tr&&tl==pos)
    {
        st[v]=val;
        return;
    }
    int tm=(tl+tr)/2;
    update(v*2,tl,tm,!isitxor,pos,val,st);
    update(v*2+1,tm+1,tr,!isitxor,pos,val,st);
    if(isitxor) st[v]=(st[v*2]^st[v*2+1]);
    else st[v]=(st[v*2]|st[v*2+1]);
}

int main()
{
    int n,m;
    cin>>n>>m;
    int a[1<<n],st[4*(1<<n)];
    for(int i=0;i<(1<<n);i++)
    {
        cin>>a[i];
    }
    build(1,0,(1<<n)-1,n%2==1?false:true,st,a);
    for(int i=0;i<m;i++)
    {
        int pos,val;
        cin>>pos>>val;
        pos--;
        update(1,0,(1<<n)-1,n%2==1?false:true,pos,val,st);
        cout<<st[1]<<'\n';
    }
    return 0;
}