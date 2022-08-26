#include<bits/stdc++.h>
#define pb push_back
#define F first
#define S second
using namespace std;
const int maxn=5e5+10;
const int INF=1e9;
set<int> s0,s1,t0,t1;
int _,n,a[maxn],p[maxn];
struct node{
    int l , r , ma, lazy;
};
struct Segment_Tree{
    node tree[maxn<<2];
    void pushup(int root){
        tree[root].ma = max(tree[root<<1].ma , tree[root<<1|1].ma);
    }
    void pushdown(int root){
        tree[root<<1].ma += tree[root].lazy;
        tree[root<<1|1].ma += tree[root].lazy;
        tree[root<<1].lazy += tree[root].lazy;
        tree[root<<1|1].lazy += tree[root].lazy;
        tree[root].lazy = 0;
    }
    void build(int l , int r , int root){
        if(l == r){
            tree[root].l = l , tree[root].r = r , tree[root].lazy = 0 , tree[root].ma = l-1;
            return ;
        }
        int mid = (l + r) >> 1;
        build(l, mid, root<<1);
        build(mid+1, r, root<<1|1);
        tree[root].l = l, tree[root].r = r, tree[root].lazy = 0;
        pushup(root);
    }
    void update(int l , int r , int root , int va){
        if(tree[root].l >= l && tree[root].r <= r){
            tree[root].lazy += va ;
            tree[root].ma += va;
            return ;
        }
        if(tree[root].lazy) pushdown(root);
        int mid = (tree[root].l + tree[root].r) >> 1;
        if(l <= mid)
            update(l , r , root<<1 , va);
        if(r > mid)
            update(l , r , root<<1|1 , va);
        pushup(root);
    }
    int query(int l , int r , int root){
        int ma = -INF;
        if(tree[root].l >= l && tree[root].r <= r){
            return tree[root].ma;
        }
        if(tree[root].lazy) pushdown(root);
        int mid = (tree[root].l + tree[root].r) >> 1;
        if(mid >= l)
            ma = max(ma , query(l , r , root<<1));
        if(r > mid)
            ma = max(ma , query(l , r , root<<1|1));
        return ma ;
    }
}A;
void chg(int x){
    s1.erase(x);
    t1.erase(-x);
    s0.insert(x);
    t0.insert(-x);
}
int f0(int x){
    auto gt=s0.lower_bound(x);
    return *gt;
}
int f1(int x){
    auto gt=s1.lower_bound(x);
    return *gt;
}
int g0(int x){
    auto gt=t0.lower_bound(-x);
    return -(*gt);
}
int g1(int x){
    auto gt=t1.lower_bound(-x);
    return -(*gt);
}
int main(){
    scanf("%d",&_);
    while (_--){
        scanf("%d",&n);
        s0.clear(); t0.clear();
        s1.clear(); t1.clear();
        for (int i=1;i<=n;i++) s1.insert(i),t1.insert(-i);
        A.build(1,n,1);
        for (int i=1;i<=n;i++) {
            scanf("%d",&a[i]);
            p[a[i]]=i;
        }
        for (int i=2;i<=n;i+=2) A.update(i,i,1,1);
        int ans=0;
        for (int i=1;i<n;i++){
            int x=p[i];
            chg(x);
            if (x>1) A.update(1,x-1,1,1);
            if (x<n) A.update(x+1,n,1,-1);
            if (x&1) A.update(x,x,1,1); else A.update(x,x,1,-1);
            int L=f1(0),R=g0(n+1);
            if (L>R) continue;
            //if (p0&1) A.update(p0,p0,1,1);
            //if ((p1+1)&1) A.update(p1,p1,1,1);
            ans=max(ans,A.query(L,R,1));
            //if (p0&1) A.update(p0,p0,1,-1);
            //if ((p1+1)&1) A.update(p1,p1,1,-1);
        }
        printf("%d\n",ans);
    }
    return 0;
}