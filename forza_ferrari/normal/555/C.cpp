#include<iostream>
#include<cstdio>
using namespace std;
struct tree
{
    int tot,root,ls[200001*30],rs[200001*30],maxn[200001*30],tag[200001*30];
    inline void push_up(int k)
    {
        maxn[k]=max(maxn[ls[k]],maxn[rs[k]]);
    }
    inline void push_down(int k)
    {
        if(tag[k])
        {
            if(!ls[k])
                ls[k]=++tot;
            if(!rs[k])
                rs[k]=++tot;
            maxn[ls[k]]=max(maxn[ls[k]],tag[k]);
            maxn[rs[k]]=max(maxn[rs[k]],tag[k]);
            tag[ls[k]]=max(tag[ls[k]],tag[k]);
            tag[rs[k]]=max(tag[rs[k]],tag[k]);
            tag[k]=0;
        }
    }
    inline void update(int nl,int nr,int l,int r,int &k,int p)
    {
        if(nl>nr)
            return;
        if(!k)
            k=++tot;
        if(l>=nl&&r<=nr)
        {
            maxn[k]=max(maxn[k],p);
            tag[k]=max(tag[k],p);
            return;
        }
        push_down(k);
        int mid=(l+r)>>1;
        if(nl<=mid)
            update(nl,nr,l,mid,ls[k],p);
        if(nr>mid)
            update(nl,nr,mid+1,r,rs[k],p);
        push_up(k);
    }
    inline int query(int node,int l,int r,int k)
    {
        if(!k)
            return 0;
        if(l==r)
            return maxn[k];
        push_down(k);
        int mid=(l+r)>>1;
        if(node<=mid)
            return query(node,l,mid,ls[k]);
        return query(node,mid+1,r,rs[k]);
    }
}T[2];
int n,m;
int main()
{
    cin>>n>>m;
    while(m--)
    {
        int x,y,f;
        char c;
        cin>>x>>y>>c;
        f=c=='U';
        if(f)
            x^=y^=x^=y;
        int lst=T[f].query(y,1,n,T[f].root);
        cout<<x-lst<<'\n';
        T[f].update(y,y,1,n,T[f].root,x);
        T[f^1].update(lst+1,x,1,n,T[f^1].root,y);
    }
    return 0;
}