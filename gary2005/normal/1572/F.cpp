/**
 *    author:  gary
 *    created: 18.12.2021 10:08:58
**/
#include<bits/stdc++.h>
#define rb(a,b,c) for(int a=b;a<=c;++a)
#define rl(a,b,c) for(int a=b;a>=c;--a)
#define rep(a,b) for(int a=0;a<b;++a)
#define LL long long
#define PB push_back
#define POB pop_back
#define II(a,b) make_pair(a,b)
#define FIR first
#define SEC second
#define SRAND mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define random(a) rng()%a
#define ALL(a) a.begin(),a.end()
#define check_min(a,b) a=min(a,b)
#define check_max(a,b) a=max(a,b)
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
const int N=1<<18;
struct segment_tree
{
    LL tree[N+N],tag[N+N];
    int siz[N+N];
    void clear(){
        memset(tree,0,sizeof(tree)),memset(tag,0,sizeof(tag));
    }
    segment_tree(){
        clear();
        rb(i,1,N) siz[i+N-1]=1;
        rl(i,N-1,1) siz[i]=siz[i<<1]<<1;
    }
    void pd(int now){
        tree[now]+=tag[now]*siz[now];
        if(now<N) tag[now<<1]+=tag[now],tag[now<<1|1]+=tag[now];
        tag[now]=0;
    }
    void add(int a,int b,int val,int now=1,int l=1,int r=N+1){
        pd(now);
        if(r<=a||l>=b) return ;
        if(r<=b&&l>=a){
            tag[now]+=val;
            pd(now);
            return ;
        }
        int mid=(l+r)>>1;
        add(a,b,val,now<<1,l,mid);
        add(a,b,val,now<<1|1,mid,r);
        tree[now]=tree[now<<1]+tree[now<<1|1];
    }
    LL query(int a,int b,int now=1,int l=1,int r=N+1){
        pd(now);
        if(r<=a||l>=b) return 0;
        if(r<=b&&l>=a) return tree[now];
        int mid=(l+r)/2;
        return query(a,b,now<<1,l,mid)+query(a,b,now<<1|1,mid,r);
    }
};
segment_tree sgt;
struct segment_tree_beats
{
    struct node
    {
        int mx1,cnt1,mx2;
        void i(){
            mx1=mx2=-INF;
            cnt1=0;
        }
        node(){i();}
        node(int A,int B,int C){
            tie(mx1,cnt1,mx2)={A,B,C};
        }
    };
    node tree[N+N];
    void pd(int now){
        if(now<N){
            check_min(tree[now<<1].mx1,tree[now].mx1);
            check_min(tree[now<<1|1].mx1,tree[now].mx1);
        }
    }
    void pu(int now){
        tree[now].i();
        if(tree[now<<1].mx1==tree[now<<1|1].mx1){
            tree[now].mx1=tree[now<<1].mx1;
            tree[now].cnt1=tree[now<<1].cnt1+tree[now<<1|1].cnt1;
            tree[now].mx2=max(tree[now<<1].mx2,tree[now<<1|1].mx2);
        }
        if(tree[now<<1].mx1<tree[now<<1|1].mx1){
            tree[now].mx1=tree[now<<1|1].mx1;
            tree[now].cnt1=tree[now<<1|1].cnt1;
            tree[now].mx2=max(tree[now<<1].mx1,tree[now<<1|1].mx2);        
        }
        if(tree[now<<1].mx1>tree[now<<1|1].mx1){
            tree[now].mx1=tree[now<<1].mx1;
            tree[now].cnt1=tree[now<<1].cnt1;
            tree[now].mx2=max(tree[now<<1|1].mx1,tree[now<<1].mx2);        
        }
    }
    void modify(int pos,int val,int now=1,int l=1,int r=N+1){
        pd(now);
        if(r<=pos||l>pos) return ;
        if(l==r-1){
            if(tree[now].cnt1){
                sgt.add(l,tree[now].mx1+1,-1);
            }
            tree[now]=node(val,1,-INF);
            sgt.add(l,tree[now].mx1+1,1);
            // cout<<l<<' '<<tree[now].mx1<<endl;
            return ;
        }
        int mid=(l+r)>>1;
        modify(pos,val,now<<1,l,mid);
        modify(pos,val,now<<1|1,mid,r);
        pu(now);
    }
    void chk_min(int a,int b,int val,int now=1,int l=1,int r=N+1){
        pd(now);
        if(r<=a||l>=b) return ;
        if(r<=b&&l>=a){
            if(tree[now].mx1<=val) return ;
            if(tree[now].mx2<val){
                // cout<<"!"<<endl;
                sgt.add(val+1,tree[now].mx1+1,-tree[now].cnt1);
                tree[now].mx1=val;
                return ;
            }
        }
        int mid=(l+r)>>1;
        chk_min(a,b,val,now<<1,l,mid);
        chk_min(a,b,val,now<<1|1,mid,r);
        pu(now);
    }
};
segment_tree_beats sgtb;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,q;
    cin>>n>>q;
    rb(i,1,n) sgtb.modify(i,i);
    rb(T,1,q){
        int p,a,b;
        cin>>p>>a>>b;
        if(p==1){
            if(a!=1)
                sgtb.chk_min(1,a,a-1);
            sgtb.modify(a,b);
        }
        else{
            cout<<sgt.query(a,b+1)<<endl;
        }
    }
    return 0;
}