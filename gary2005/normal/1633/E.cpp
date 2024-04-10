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
const int MAXN=505;
struct DSU{
    int fa[MAXN];
    void clear(){
        rep(i,MAXN) fa[i]=i;
    }
    int root(int x){
        return fa[x]=(fa[x]==x? x:root(fa[x]));
    }
    DSU(){clear();}
}L,R,M;
int n,m;
vector<pair<int,mp > > edges;
vector<int> Q;
vector<pair<int,mp > > suf[100000+10];
vector<int> Que;
vector<pair<int,mp> > El,Eg;
vector<pair<int,mp> > mergesort(vector<pair<int,mp > > &A,vector<pair<int,mp > > &B,int X){
    int pt0,pt1;
    pt0=pt1=0;
    vector<pair<int,mp > > rest;
    while (pt0<A.size()||pt1<B.size()){
        if(pt0==A.size()||(pt1!=B.size()&&B[pt1].first-X<X-A[pt0].first)) rest.PB(B[pt1++]);
        else rest.PB(II(A[pt0].first-INF,A[pt0].second)),pt0++;
    }
    return rest;
}
LL ans=0;
void solve(int l,int r,pair<LL,LL> L,pair<LL,LL> R){
    if(l>=r) return ;
    if(L==R){
        rb(i,l,r-1){
            // cout<<":"<<Que[i]<<endl;
            // printf("%lld\n",L.first*Que[i]+L.second);
            ans^=L.first*Que[i]+L.second;
        }
        return ;
    }
    int mid=(l+r)>>1;
    pair<LL,LL> T=II(0,0);
    auto tmp=mergesort(El,Eg,Que[mid]);
    M.clear();
    for(auto it:tmp){
        int u,v;
        u=it.second.first;
        v=it.second.second;
        if(M.root(u)!=M.root(v)){
            M.fa[M.root(u)]=M.root(v);
            // cout<<it.first<<" "<<u<<" "<<v<<endl;
            if(it.first<0){
                T.first++;
                T.second+=-(it.first+INF);
            }
            else{
                T.first--;
                T.second+=it.first;
            }
        }
    }
    // cout<<":"<<Que[mid]<<endl;
    // cout<<T.first<<" "<<T.second<<endl;
    solve(l,mid,L,T);
    // printf("%lld\n",T.first*Que[mid]+T.second);
    ans^=T.first*Que[mid]+T.second;
    solve(mid+1,r,T,R);
}
int main(){
    scanf("%d%d",&n,&m);
    rb(i,1,m){
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        edges.PB(II(w,II(u,v)));
    }
    sort(ALL(edges));
    int p,q,a,b,c;
    scanf("%d%d%d%d%d",&p,&q,&a,&b,&c);
    Q.resize(q);
    rep(i,p) scanf("%d",&Q[i]);
    rb(i,p,q-1) Q[i]=(1ll*Q[i-1]*a+b)%c;
    sort(ALL(Q));
    // for(auto it:Q) cout<<it<<endl;
    vector<int> newq;
    for(auto it:Q){
        if(newq.size()&&newq.back()==it) newq.pop_back();
        else newq.PB(it);
    }
    Q=newq;
    q=Q.size();
    rl(i,m,1){
        suf[i].PB(edges[i-1]);
        for(auto it:suf[i+1]) suf[i].PB(it);
        R.clear();
        vector<pair<int,mp> > z;
        for(auto it:suf[i]){
            if(R.root(it.second.first)!=R.root(it.second.second)){
                z.PB(it);
                R.fa[R.root(it.second.first)]=R.root(it.second.second);
            }
        }
        suf[i]=z;
    }
    vector<pair<int,mp > > pre;
    int pt=0;
    rb(i,0,m){
        vector<pair<int,mp > > nw;
        if(i!=0) nw.PB(edges[i-1]);
        for(auto it:pre) nw.PB(it);
        pre.clear();
        L.clear();
        for(auto it:nw){
            if(L.root(it.second.first)!=L.root(it.second.second)){
                pre.PB(it);
                L.fa[L.root(it.second.first)]=L.root(it.second.second);
            }
        }
        Que.clear();
        while (pt<Q.size()&&(i==m||Q[pt]<=edges[i].first)){
            Que.PB(Q[pt++]);
        }
        if(Que.size()){
            El=pre;
            Eg=suf[i+1];
            // for(auto it:Que){
                // cout<<i<<","<<it<<" "<<El.size()<<" "<<Eg.size()<<endl;
            // }
            solve(0,Que.size(),II(-INF,-INF),II(INF,INF));
        }
    }
    printf("%lld\n",ans);
    return 0;
}