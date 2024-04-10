/**
 *    author:  gary
 *    created: 30.10.2021 09:09:35
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
const int MAXN=2e5+10;
int n;
vector<int> g[MAXN];
int q;
pair<mp,int> queries[MAXN];// k,v,i
int sumval[MAXN];
int fa[MAXN];
int ans[MAXN];
bool bad[MAXN];
int dfn[MAXN];
int cnt;
int siz[MAXN];
int d[MAXN];
int heavy[MAXN];
int tp[MAXN];
int fafa[MAXN];
int firval[MAXN],secval[MAXN];
bool leaf[MAXN];
set<mp,greater<mp> > se;
void dfsinit(int now,int pre){
    siz[now]=1;
    fa[now]=fafa[now]=pre;
    firval[now]=0;
    secval[now]=1;
    leaf[now]=1;
    for(auto it:g[now]) if(it!=pre) leaf[now]=0,dfsinit(it,now),firval[now]++,siz[now]+=siz[it];
    for(auto it:g[now]) if(it!=pre&&siz[it]>siz[heavy[now]]) heavy[now]=it;
    d[now]=floor((double)(firval[now]-1)/(secval[now]));
    if(now!=1) se.insert(II(d[now],now));
    bad[now]=1;
}
void dfssiz(int now,int pre){
    dfn[now]=++cnt;
    if(heavy[now]) tp[heavy[now]]=tp[now],dfssiz(heavy[now],now);
    for(auto it:g[now]) if(it!=pre&&it!=heavy[now]) {
        tp[it]=it;
        dfssiz(it,now);
    }
}
struct BIT{
    int bit[MAXN];
    BIT(){
        memset(bit,0,sizeof(bit));
    }
    void add(int pos,int val){
        while(pos<MAXN){
            bit[pos]+=val;
            pos+=pos&-pos;
        }
    }
    int query(int pos){
        int res=0;
        while(pos){
            res+=bit[pos];
            pos-=pos&-pos;
        }
        return res;
    }
    void modify(int pos,int val){
        int oldval=query(pos);
        add(pos,val-oldval);
        add(pos+1,oldval-val);
    }
}fir,sec;
int find(int i){
    // i 
    if(!bad[fa[i]]) return fa[i]=find(fa[i]);
    return fa[i];
}
void upd(int pos,int delta1,int delta2){
    int j=find(pos);
    int i=fafa[pos];
    while(true){ 
        int l=dfn[tp[i]],r=dfn[i];
        if(l<=dfn[j]){
            l=dfn[j];
            fir.add(l,delta1);
            fir.add(r+1,-delta1);
            sec.add(l,delta2);
            sec.add(r+1,-delta2);
            break;
        }
        else{
            fir.add(l,delta1);
            fir.add(r+1,-delta1);
            sec.add(l,delta2);
            sec.add(r+1,-delta2);
        }
        i=fafa[tp[i]];
    }
    firval[j]+=delta1;
    secval[j]+=delta2;
    if(j!=1){
        se.erase(II(d[j],j));
        assert(floor((double)(firval[j]-1)/(secval[j]))>=d[j]);
        d[j]=floor((double)(firval[j]-1)/(secval[j]));
        se.insert(II(d[j],j));
    }
}
int main(){
    scanf("%d",&n);
    rb(i,1,n-1){
        int u,v;
        scanf("%d%d",&u,&v);
        g[u].PB(v);
        g[v].PB(u);
    }
    scanf("%d",&q);
    rb(i,1,q){
        int v,k;
        scanf("%d%d",&v,&k);
        queries[i]=II(II(k,v),i);
    }
    sort(queries+1,queries+1+q);
    reverse(queries+1,queries+1+q);
    dfsinit(1,0);
    tp[1]=1;
    dfssiz(1,0);
    assert(cnt==n);
    rb(i,1,n) fir.modify(dfn[i],firval[i]),sec.modify(dfn[i],secval[i]);
    rb(I,1,q){
        int i,v,k;
        i=queries[I].SEC;
        k=queries[I].FIR.FIR;
        v=queries[I].FIR.SEC;
        while(se.size()&&se.begin()->FIR>=k){
            int j=se.begin()->SEC;
            se.erase(se.begin());
            // cout<<val[j]<<" "<<bad[j]<<endl;
            bad[j]=0;
            // j
            // cout<<j<<" "<<val[j]<<endl;
            upd(j,firval[j]-1,secval[j]);
        }
        // cout<<I<<endl;
        // cout<<query(dfn[7])<<" "<<i<<" "<<k<<' '<<v<<endl;
        int A,B;
        A=fir.query(dfn[v]);
        B=sec.query(dfn[v]);
        ans[i]=A-B*k+k;
    }
    rb(i,1,q) printf("%d\n",ans[i]);
    return 0;
}