/**
 *    author:  gary
 *    created: 22.02.2022 13:02:31
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
SRAND;
struct node{
    LL val;
    int siz,l,r;
    uint_fast32_t ran;
    LL tag,delta;
    LL leftval,rightval;
    node(){val=leftval=rightval=siz=tag=l=r=ran=delta=0;}
    node(LL v){val=leftval=rightval=v;siz=1;l=r=0;tag=delta=0;ran=rng();}
};
vector<node> v(1);
int root=0;
void pushdown(int now){
    v[now].val+=v[now].delta;
    v[now].val+=(v[v[now].l].siz+1)*v[now].tag;
    v[now].leftval+=v[now].delta;
    v[now].leftval+=v[now].tag;
    v[now].rightval+=v[now].delta;
    v[now].rightval+=(v[v[now].l].siz+1+v[v[now].r].siz)*v[now].tag;
    if(v[now].l) v[v[now].l].tag+=v[now].tag,v[v[now].l].delta+=v[now].delta;
    if(v[now].r) v[v[now].r].tag+=v[now].tag,v[v[now].r].delta+=v[now].delta+(v[v[now].l].siz+1)*v[now].tag;
    v[now].delta=v[now].tag=0;
}
void upd(int now){
    v[now].siz=1;
    v[now].leftval=v[now].val;
    v[now].rightval=v[now].val;
    if(v[now].l) pushdown(v[now].l),v[now].siz+=v[v[now].l].siz,v[now].leftval=v[v[now].l].leftval;
    if(v[now].r) pushdown(v[now].r),v[now].siz+=v[v[now].r].siz,v[now].rightval=v[v[now].r].rightval;
}
int merge(int a,int b){
    if(a==0||b==0) return a|b;
    if(v[a].ran>v[b].ran){
        if(v[a].tag||v[a].delta)
        pushdown(a);
        v[a].r=merge(v[a].r,b);
        upd(a);
        return a;
    }
    else{
        if(v[b].tag||v[b].delta)
        pushdown(b);
        v[b].l=merge(a,v[b].l);
        upd(b);
        return b;
    }
    return 0;
}
void split(int r,int &x,int &y,int pick){
    if(r==0){
        x=0;
        y=0;
        return ;
    }
    if(v[r].tag||v[r].delta)
    pushdown(r);
    if(pick==0){
        x=0;
        y=r;
        return ;
    }
    if(pick==v[r].siz){
        x=r;
        y=0;
        return ;
    }
    if(v[v[r].l].siz+1<=pick){
        x=r;
        split(v[r].r,v[r].r,y,pick-(v[v[r].l].siz+1));
        upd(x);
    }
    else{
        y=r;
        split(v[r].l,x,v[r].l,pick);
        upd(y);
    }
}
long long query(int r,int i){
    if(v[r].tag||v[r].delta)
    pushdown(r);
    if(i==v[v[r].l].siz+1) return v[r].val;
    if(i<=v[v[r].l].siz) return query(v[r].l,i);
    return query(v[r].r,i-(v[v[r].l].siz+1));
}
long long dp(int i){
    if(i==0) return 0;
    if(i>v[root].siz) return -1e18;
    return query(root,i);
}
int A_I;
int binary_search(int r,int pre=0){
    if(v[r].siz==1) return pre+1;
    if(v[r].l)
    pushdown(v[r].l);
    if(v[r].r)
    pushdown(v[r].r);
    if(v[r].l&&v[v[r].l].rightval+1ll*(pre+v[v[r].l].siz+1)*A_I>=v[r].val){
        return binary_search(v[r].l,pre);
    }
    pre+=v[v[r].l].siz+1;
    if(!v[r].r) return pre;
    if(v[r].val+1ll*(pre+1)*A_I>=v[v[r].r].leftval) return pre;
    return binary_search(v[r].r,pre);
}
const int MAXN=1e6+1;
int a[MAXN],n;
int main(){
    // freopen("opt.in","r",stdin);
    // freopen("opt.out","w",stdout);
    scanf("%d",&n);
    rb(i,1,n) scanf("%d",&a[i]);
    rb(i,1,n){
        int l;
        if(dp(0)+a[i]>dp(1)) l=0;
        else A_I=a[i],pushdown(root),l=binary_search(root);
        // cout<<l<<' '<<i<<endl;
        long long dp_l=dp(l);
        int x,y;
        split(root,x,y,l);
        v.PB(node(dp_l));
        y=merge(v.size()-1,y);
        v[y].tag+=a[i];
        v[y].delta+=1ll*a[i]*v[x].siz;
        root=merge(x,y);
    }
    long long answer=0;
    rb(i,1,n) check_max(answer,dp(i));
    cout<<answer<<endl;
    return 0;
}
/*

5
-2 -8 0 5 -3

6
-1 2 -3 4 -5 6



*/