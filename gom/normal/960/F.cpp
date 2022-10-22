#include <bits/stdc++.h>
#define N 100005
using namespace std;
typedef long long ll;
struct node
{
    int s,e,v;
    node *l,*r;
    node(){
        s=0,e=1e5,v=0;
        l=r=nullptr;
    }
    void extend(){
        if(l==nullptr){
            l=new node();
            r=new node();
            l->s=s;
            l->e=(s+e)/2;
            r->s=(s+e)/2+1;
            r->e=e;
        }
    }
};
void update(node *curr,int idx,int v)
{
    if(curr->s>idx||curr->e<idx)
        return;
    if(curr->s==curr->e){
        curr->v=max(curr->v,v);
        return;
    }
    curr->extend();
    update(curr->l,idx,v);
    update(curr->r,idx,v);
    curr->v=max(curr->l->v,curr->r->v);
}
int query(node *curr,int l,int r)
{
    if(curr->s>r||curr->e<l)
        return 0;
    if(l<=curr->s&&curr->e<=r)
        return curr->v;
    curr->extend();
    return max(query(curr->l,l,r),query(curr->r,l,r));
}
int n,m,ans;
node *tree[N];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        tree[i]=new node();
    for(int i=1;i<=m;i++){
        int s,e,w,dp;
        cin>>s>>e>>w;
        dp=query(tree[s],0,w-1);
        ans=max(ans,dp+1);
        update(tree[e],w,dp+1);
    }
    cout<<ans;
    return 0;
}