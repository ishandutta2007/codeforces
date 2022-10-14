/**
 *    author:  gary
 *    created: 08.05.2022 23:31:34
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
struct segment_tree{
    struct node{
        long long his;
        int tag,cnt;
        int t;
        node(){his=0;tag=cnt=t=0;}
    }tree[N+N];
    void upd(int now){
        tree[now].his=tree[now<<1].his+tree[now<<1|1].his;
        if(tree[now].tag) tree[now].cnt=0;
        else tree[now].cnt=tree[now<<1].cnt+tree[now<<1|1].cnt;
    }
    void givetag(int now,int x){
        if(!tree[now].tag){
            tree[now].his+=1ll*tree[now].cnt*x;
            tree[now].t+=x;
        }
    }
    void pud(int now){
        if(!tree[now].tag){
            if(now<N) givetag(now<<1,tree[now].t),givetag(now<<1|1,tree[now].t);
        }
        tree[now].t=0;
    }
    void build(){
        rb(i,1,N) tree[i+N-1].his=tree[i+N-1].t=0,tree[i+N-1].tag=0,tree[i+N-1].cnt=1;
        rl(i,N-1,1) upd(i);
    }
    void add(int a,int b,int x,int now=1,int l=1,int r=N+1){
        if(r<=a||l>=b) return;
        if(tree[now].t)
        pud(now);
        if(r<=b&&l>=a) {
            tree[now].tag+=x;
            if(now>=N){
                if(!tree[now].tag) tree[now].cnt=1;
                else tree[now].cnt=0;
            }
            else{
                upd(now);
            }
            return;
        }
        int mid=(l+r)>>1;
        add(a,b,x,now<<1,l,mid);
        add(a,b,x,now<<1|1,mid,r);
        upd(now);
    }
    long long query(int a,int b,int now=1,int l=1,int r=N+1){
        if(r<=a||l>=b) return 0;
        if(r<=b&&l>=a) return tree[now].his;
        if(tree[now].t)
        pud(now);
        int mid=(l+r)>>1;
        return query(a,b,now<<1,l,mid)+query(a,b,now<<1|1,mid,r);
    }
}tr;
vector<pair<mp,mp> > Mat;
int pos[N],p[N],n,q;
vector<pair<mp,int> > Q;
int QQ[N];
mp insect(mp A,mp B){
    return II(max(A.first,B.first),min(A.second,B.second));
}
void Nw(pair<pair<int,pair<mp,mp> >,int> aa,int nowt){
    if(aa.first.second.first.first<=aa.first.second.first.second)
    Mat.PB(II(II(nowt,aa.second),aa.first.second.first));
}
LL ans[1000000+10];
vector<pair<int,mp> > event[N];
vector<pair<pair<int,mp> ,int> > qs[N];
int main(){
    // cout<<tree[262151].a[2]<<endl;
    cin>>n>>q;
    rb(i,1,n){
        scanf("%d",&p[i]);
        pos[p[i]]=i;
    }
    rb(i,1,n) QQ[i]=INF;
    pos[n+1]=n+1;
    deque<pair<pair<int,pair<mp,mp> >,int> > dq;
    dq.PB(II(II(n+1,II(II(n+1,n+1),II(n+1,n+1))),n+1));
    stack<int> sta;
    sta.push(n+1);
    rl(i,n,1){
        while (dq.front().first.first<p[i]){
            Nw(dq.front(),i+1);
            // Mat.PB(II(II(i+1,dq.front().second),dq.front().first.second.first));
            dq.pop_front();
        }
        while (sta.top()<p[i]){
            sta.pop();
        }
        int r=pos[sta.top()]-1;
        sta.push(p[i]);
        dq.push_front(II(II(p[i],II(II(QQ[p[i]],r),II(i,r))),i));
        rb(j,1,n/p[i]){
            int k=j*p[i];
            if(pos[j]>i){
                check_min(QQ[k],pos[j]);
                auto ite=lower_bound(ALL(dq),II(II(k,II(II(-INF,-INF),II(-INF,-INF))),-INF));
                if(ite->first.first==k){
                    if(ite->first.second.first!=insect(II(QQ[k],INF),ite->first.second.second))
                    {Nw(*ite,i+1);
                    ite->first.second.first=insect(II(QQ[k],INF),ite->first.second.second);
                    ite->second=i;}
                }
            }
        }
    }
    for(auto it:dq) Nw(it,1);
    for(auto it:Mat){
        if(it.first.second==it.first.first-1) continue;
        event[it.first.second].PB(II(1,it.second)),event[it.first.first-1].PB(II(-1,it.second));
    }
    rb(i,1,q){
        int l,r;
        scanf("%d%d",&l,&r);
        qs[r+1].PB(II(II(i,II(l,r)),-1));
        qs[l].PB(II(II(i,II(l,r)),1));
        ans[i]=1ll*(r-l+1)*(r-l+1);
    }
    tr.build();
    rl(i,n,1){
        for(auto it:event[i]){
            tr.add(it.second.first,it.second.second+1,it.first);
        }
        tr.givetag(1,1);
        for(auto it:qs[i]){
            ans[it.first.first]-=tr.query(it.first.second.first,it.first.second.second+1)*it.second;
        }
    }
    rb(i,1,q) printf("%lld\n",ans[i]);
    return 0;
}