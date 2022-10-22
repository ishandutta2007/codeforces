//2019.3.20 by ljz
#include<bits/stdc++.h>
using namespace std;
#define res register int
#define LL long long
#define inf 0x3f3f3f3f
#define eps 1e-10
#define RG register
inline int read() {
    res s=0;
    bool w=0;
    char ch=getchar();
    while(ch<'0'||ch>'9') {
        if(ch=='-')w=1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9')s=s*10+ch-'0',ch=getchar();
    return w?-s:s;
}
inline void _swap(res &x,res &y) {
    x^=y^=x^=y;
}
inline int _max(const res &x,const res &y) {
    return x>y?x:y;
}
inline int _min(const res &x,const res &y) {
    return x<y?x:y;
}
const int N=1e4+10;
namespace MAIN {
    int n;
    int ans[N],tmp[N];
    typedef pair<int,int> Pair;
#define mp make_pair
#define fi first
#define se second
    struct TR{
        set<Pair> edge;
        set<int> lj[N];
        int du[N];
        inline void addedge(const res &u,const res &v){
            edge.insert(mp(u,v)),edge.insert(mp(v,u)),lj[u].insert(v),lj[v].insert(u),du[u]++,du[v]++;
        }
        set<int> cz;
        set<Pair> qb,leaf;
        inline void init(){
            for(res i=1;i<=n;i++){
                cz.insert(i),qb.insert(mp(du[i],i));
                if(du[i]==1)leaf.insert(mp(*lj[i].begin(),i));
            }
        }
        inline int checkjh(){
            return int(cz.size()-(*qb.rbegin()).fi-1);
        }
        inline int pushin(res *p,const res &U,const res &V,const res &W){
            res px=0;
            for(auto it:cz)if(U!=it&&V!=it&&W!=it)p[++px]=it;
            return px;
        }
        Pair S[5];
        inline Pair get_leaf(){
            S[1]=*leaf.begin(),S[2]=*++leaf.begin(),S[3]=*leaf.rbegin(),S[4]=*++leaf.rbegin(),sort(S+1,S+4+1);
            res mxid=-1;
            for(res i=1;i<=4;i++){
                RG Pair it=S[i];
                if(du[it.fi]>2){mxid=it.fi;break;}
            }
            if(mxid==-1)return mp((*leaf.begin()).se,(*leaf.rbegin()).se);
            res u=-1,v=-1;
            for(res i=1;i<=4;i++){
                RG Pair it=S[i];
                if(it.fi==mxid)u=it.se;
                else v=it.se;
            }
            return mp(u,v);
        }
        inline void erase(const res &id){
            res x=*lj[id].begin();
            cz.erase(id),leaf.erase(mp(x,id)),qb.erase(mp(1,id)),lj[id].erase(x),lj[x].erase(id),qb.erase(mp(du[x],x)),du[x]--,qb.insert(mp(du[x],x));
            if(du[x]==1)leaf.insert(mp(*lj[x].begin(),x));
        }
    }A,B;
    inline void put(){
        puts("Yes");
        for(res i=1;i<=n;i++)printf("%d ",ans[i]+n);
        exit(0);
    }
    int g[N],h[N];
    inline bool check(const res &nw){
        for(res i=1;i<=nw;i++)
            for(res j=1;j<i;j++)
                if(A.edge.find(mp(g[i],g[j]))!=A.edge.end()&&B.edge.find(mp(h[i],h[j]))!=B.edge.end())return 0;
        return 1;
    }
    inline void blsolve(){
        res nw=A.pushin(g,0,0,0);
        B.pushin(h,0,0,0);
        do{
            if(check(nw)){
                for(res i=1;i<=nw;i++)ans[g[i]]=h[i];
                return;
            }
        }while(next_permutation(g+1,g+nw+1));
    }
    inline void onesolve(TR &A,TR &B){
        res u=((*++A.qb.rbegin()).se),v=*A.lj[u].begin(),w=*A.lj[u].rbegin();
        if(A.du[w]==1)_swap(v,w);
        res U=-1,W=(*B.leaf.begin()).se,V=(*B.leaf.begin()).fi;
        for(auto it:B.cz)if(B.edge.find(mp(it,V))==B.edge.end()&&B.edge.find(mp(it,W))==B.edge.end()){U=it;break;}
        ans[u]=U,ans[v]=V,ans[w]=W;
        res nw=A.pushin(g,u,v,w);
        B.pushin(h,U,V,W);
        for(res i=1;i<=nw;i++)ans[g[i]]=h[i];
    }
    inline void zh(){
        for(res i=1;i<=n;i++)tmp[ans[i]]=i;
        for(res i=1;i<=n;i++)ans[i]=tmp[i];
    }
    void solve(){
        if((A.cz.size())<=3||!A.checkjh()||!B.checkjh()){puts("No");exit(0);}
        if((A.cz.size())<=5){blsolve();return;}
        if(A.checkjh()==1){onesolve(A,B);return;}
        if(B.checkjh()==1){onesolve(B,A),zh();return;}
        RG Pair a=A.get_leaf(),c=B.get_leaf(),b=mp(*A.lj[a.fi].begin(),*A.lj[a.se].begin()),d=mp(*B.lj[c.fi].begin(),*B.lj[c.se].begin());
        A.erase(a.fi),A.erase(a.se),B.erase(c.fi),B.erase(c.se),solve();
        if(ans[b.fi]!=d.fi&&ans[b.se]!=d.se)ans[a.fi]=c.fi,ans[a.se]=c.se;
        else ans[a.fi]=c.se,ans[a.se]=c.fi;
    }
    inline void MAIN(){
        n=read();
        for(res i=1;i<n;i++){
            res u=read(),v=read();
            A.addedge(u,v);
        }
        for(res i=1;i<n;i++){
            res u=read()-n,v=read()-n;
            B.addedge(u,v);
        }
        A.init(),B.init(),solve(),put();
    }
}
int main() {
    MAIN::MAIN();
    return 0;
}