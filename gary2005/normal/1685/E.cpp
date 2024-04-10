/**
 *    author:  gary
 *    created: 27.05.2022 16:47:02
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
const int N=1<<19;
struct segmenttree{
    // + 
    mp tree[N+N];
    int tag[N+N];
    void pushup(int pos){
        tree[pos]=min(tree[pos<<1],tree[pos<<1|1]);
    }
    void givetag(int pos,int t){
        tree[pos].first+=t;
        tag[pos]+=t;
    }
    void pushdown(int pos){
        if(pos<N) givetag(pos<<1,tag[pos]),givetag(pos<<1|1,tag[pos]);
        tag[pos]=0;
    }
    segmenttree(){
        memset(tag,0,sizeof(tag));
        rb(i,1,N) tree[i+N-1]=II(0,i);
        rl(i,N-1,1) pushup(i);
    }
    void add(int a,int b,int d,int now=1,int l=1,int r=N+1){
        if(r<=a||l>=b) return ;
        if(r<=b&&l>=a) {givetag(now,d);return;}
        pushdown(now);
        int mid=(l+r)>>1;
        add(a,b,d,now<<1,l,mid);
        add(a,b,d,now<<1|1,mid,r);
        pushup(now);
    }
}t1;
int n;
mp mergepair(mp A,mp B){
    if(A.first==INF||B.first==INF) return II(INF,INF-1);
    if(A.first==-1) return B;
    if(B.first==-1) return A;
    if(A.second>B.first) return II(INF,INF-1);
    return II(A.first,B.second);
}
struct segmenttree2{
    struct node{
        mp info[2];
        node(){info[0]=info[1]=II(-1,-2);}
    };
    node merge(node A,node B){
        node C;
        C.info[0]=mergepair(A.info[0],B.info[0]);
        C.info[1]=mergepair(A.info[1],B.info[1]);
        return C;
    }
    node tree[N+N];
    void build(){
        rl(i,N-1,1) tree[i]=merge(tree[i<<1],tree[i<<1|1]);
    }
    node query(int a,int b,int now=1,int l=1,int r=N+1){
        if(r<=a||l>=b) return node();
        if(r<=b&&l>=a) return tree[now];
        int mid=(l+r)>>1;
        return merge(query(a,b,now<<1,l,mid),query(a,b,now<<1|1,mid,r));
    }
    void modify(int pos,int val){
        pos+=N-1;
        tree[pos]=node();
        tree[pos].info[val>(n+1)]=II(val,val);
        pos>>=1;
        while (pos)
        {
            tree[pos]=merge(tree[pos<<1],tree[pos<<1|1]);
            pos>>=1;
        }
    }
}t2;
struct BIT{
    int tree[N];
    void clear(){memset(tree,0,sizeof(tree));}
    void add(int pos,int val){
        while(pos<N){tree[pos]+=val;pos+=pos&-pos;}
    }
    int query(int pos){
        int s=0;
        while(pos){
            s+=tree[pos];
            pos-=pos&-pos;
        }
        return s;
    }
    int query(int l,int r){
        return query(r)-query(l-1);
    }
    BIT(){clear();}
}t3,t4;
int a[N];
int pos[N];
void sub(int pos){
    if(a[pos]<n+1) t1.add(pos,N+1,1),t3.add(pos,-1);
    if(a[pos]>n+1) t1.add(pos,N+1,-1),t4.add(pos,-1);
}
void add(int pos){
    if(a[pos]<n+1) t1.add(pos,N+1,-1),t3.add(pos,1);
    if(a[pos]>n+1) t1.add(pos,N+1,1),t4.add(pos,1);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int q;
    cin>>n>>q;
    t1.add(2*n+2,N+1,INF);
    rb(i,1,2*n+1) cin>>a[i],pos[a[i]]=i,a[i+2*n+1]=a[i];
    rb(i,1,(2*n+1)*2){
        add(i);
    }
    rb(i,1,2*(2*n+1)) t2.tree[i+N-1].info[a[i]>(n+1)]=II(a[i],a[i]);
    t2.build();
    // bool ok=(a[1]==179&&a[2]==1181&&a[3]==180);
    rb(T,1,q){
        int u,v;
        cin>>u>>v;
        sub(u),sub(v);
        sub(u+2*n+1),sub(v+2*n+1);
        swap(a[u],a[v]);
        swap(a[u+(n<<1|1)],a[v+(n<<1|1)]);
        add(u),add(v);
        add(u+2*n+1),add(v+2*n+1);
        swap(pos[a[u]],pos[a[v]]);
        t2.modify(u,a[u]),t2.modify(v,a[v]);
        t2.modify(u+n*2+1,a[u]),t2.modify(v+n*2+1,a[v]);
        int p=t1.tree[1].second;
        p++;
        // rb(i,1,2*n+1){
            // cout<<a[i]<<" ";
        // }
        // cout<<endl;
        // cout<<p<<endl;
        if(p==2*n+2) p=1;
        int L=pos[n+1],R=pos[n+1]+2*n+1;
        // cout<<L<<" "<<R<<endl;
        int ans;
        int p2=pos[n+1];
        if(p2<p) p2+=2*n+1;
        auto Lx=t2.query(p,p2).info[0],Rx=t2.query(p2+1,p+2*n+1).info[1];
        // cout<<p<<" "<<p2<<' '<<Lx.first<<' '<<Lx.second<<" "<<Rx.first<<" "<<Rx.second<<endl;
        // if(T==6713){
        //     int sum=0;
        //     rb(i,p,p+2*n){
        //         sum+=(a[i]<n+1? -1:(a[i]==n+1? 0:1));
        //         assert(sum>=0);
        //     }
        //     cout<<p<<" "<<p2<<" "<<Len<<" "<<Lx.first<<" "<<Lx.second<<" "<<Rx.first<<" "<<Rx.second<<endl;
        // }
        // cout<<p<<" "<<p2<<" "<<p+2*n<<' '<<t3.query(p,p2-1)<<" "<<t4.query(p2+1,p+2*n)<<" "<<t4.query(3)<<endl;
        if(Lx.first!=INF&&Rx.first!=INF&&t3.query(p,p2-1)+t4.query(p2+1,p+2*n)==n){
            auto t=t2.query(L+1,R);
            if(t.info[0]==II(1,n)){
                if(t.info[1]==II(n+2,2*n+1))
                {
                    // if(T==6713||!ok)
                    cout<<-1<<endl;
                    continue;
                }
            }
            ans=p2;
            if(t.info[0]==II(1,n)) ans=p2;
            if(t.info[1]==II(n+2,2*n+1)) ans=p2+1;
        }
        else ans=p;
        if(ans>2*n+1) ans-=2*n+1;
        ans--;
        // if(T==6713||!ok)
        cout<<ans%(2*n+1)<<endl;
    }
    return 0;
}