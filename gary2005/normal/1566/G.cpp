/**
 *    author:  gary
 *    created: 12.09.2021 22:33:08
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
const int INF=2e9;
typedef pair<int,int> mp;
const int MAXN=1e5+1;
int n,m;
struct edge{
    int u,v,w;
    bool operator < (edge ano){
        return w<ano.w;
    }
    edge(){
        u=v=w=INF;
    }
    edge(int A,int B,int C){
        u=A;
        v=B;
        w=C;
    }
};
bool f(edge A,edge B){
    return A.u!=B.u&&A.v!=B.u&&A.u!=B.v&&A.v!=B.v;
}
edge TTmp[3];
struct node{
    edge mn1,mn2,mn3,a1,a2,a3;
    node(){}
    node(edge a,edge b,edge c,edge d,edge e,edge f){
        tie(mn1,mn2,mn3,a1,a2,a3)=make_tuple(a,b,c,d,e,f);
    }
    vector<edge> get(){
        vector<edge> v;
        v.PB(mn1);
        v.PB(mn2);
        v.PB(mn3);
        v.PB(a1);
        v.PB(a2);
        v.PB(a3);
        return v;
    }
    node operator + (edge ano){
        node rest;
        tie(rest.mn1,rest.mn2,rest.mn3)=make_tuple(mn1,mn2,mn3);
        if(ano<rest.mn3) rest.mn3=ano;
        if(rest.mn3<rest.mn2) swap(rest.mn3,rest.mn2);
        if(rest.mn2<rest.mn1) swap(rest.mn2,rest.mn1);
        vector<edge> Tmp=this->get();
        Tmp.PB(ano);
        for(auto it:Tmp){
            if(f(rest.mn1,it)&&it<rest.a1) rest.a1=it;
            if(f(rest.mn2,it)&&it<rest.a2) rest.a2=it;
            if(f(rest.mn3,it)&&it<rest.a3) rest.a3=it;
        }
        return rest;
    }
};
LL answer=1e18;
void upd(node x){
    vector<edge> v=x.get();
    check_min(answer,1ll*v[0].w+v[1].w+v[2].w);
    for(auto it:v) for(auto it2:v) if(f(it,it2)) check_min(answer,1ll*it.w+it2.w);
}
struct DSU{
    int tp=0;
    pair<LL,node> inf[MAXN<<2];
    node z;
    void addedge(int u,int v,int w){
        inf[++tp]=(II(answer,z));
        z=z+edge(u,v,w);
        upd(z);
    }
    void undo(){
        auto tmpoid=inf[tp--];
        tie(answer,z)=make_tuple(tmpoid.FIR,tmpoid.SEC);
    }
}dsu;
const int N=1<<17;
vector<edge> tree[N+N];
void add(int a,int b,edge id,int now=1,int l=1,int r=N+1){
    if(r<=a||l>=b) return ;
    if(r<=b&&l>=a) {
        tree[now].PB(id);
        return ;
    }
    int mid=(l+r)>>1;
    add(a,b,id,now<<1,l,mid);
    add(a,b,id,now<<1|1,mid,r);
}
map<mp ,mp > M;
int t=1;
void travel(int now,int l=1,int r=N+1){
    if(l>=t) return ;
    for(auto it:tree[now]) dsu.addedge(it.u,it.v,it.w);
    if(l==r-1){
        printf("%lld\n",answer);
        for(auto it:tree[now]) dsu.undo();
        return ;
    }
    int mid=(l+r)>>1;
    
    travel(now<<1,l,mid);
    travel(now<<1|1,mid,r);
    
    for(auto it:tree[now]) dsu.undo();

}
inline int read(){
   int x=0;
   char ch=getchar();
   while(ch<'0'||ch>'9'){
       ch=getchar();
   }
   while(ch>='0'&&ch<='9'){
       x=(x<<1)+(x<<3)+(ch^48);
       ch=getchar();
   }
   return x;
}
int main(){
    scanf("%d%d",&n,&m);
    int q;
    rb(i,1,m) {
        int u,v,w;
        u=read();
        v=read();
        w=read();
        if(u>v) swap(u,v);
        M[II(u,v)]=II(w,t);
    }
    cin>>q;
    rb(i,1,q){
        t++;
        int ty,u,v,w;
        ty=read();
        if(ty==0){
            u=read();
            v=read();
            if(u>v) swap(u,v);
            auto ite=M.find(II(u,v));
            add((ite->SEC).SEC,t,edge(ite->FIR.FIR,ite->FIR.SEC,ite->SEC.FIR));
            M.erase(ite);
        }
        else{
            u=read();
            v=read();
            w=read();
            if(u>v) swap(u,v);
            M[II(u,v)]=II(w,t);
        }
    }
    t++;
    for(auto ite=M.begin();ite!=M.end();ite++){
        add((ite->SEC).SEC,t,edge(ite->FIR.FIR,ite->FIR.SEC,ite->SEC.FIR));
    }
    travel(1,1,N+1);
    return 0;
}