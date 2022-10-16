#include<bits/stdc++.h>
using namespace std;
#define forg(i,x) for(int i=fir[x];i;i=nxt[i])
#define uu unsigned
#define scanf abc=scanf
#define fre(x) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
typedef long long ll;
typedef uu long long ull;
typedef pair<int,int>pii;
int abc;
inline int rd(int l,int r){return rand()%(r-l+1)+l;}

const int mxn=15003;
int n,a[mxn],pa[mxn];
int fl[mxn],fr[mxn];
void qmax(int&x,int y){x=max(x,y);}void qmin(int&x,int y){x=min(x,y);}
#define mid ((l+r)>>1)
struct ss1{
    void init(){memset(vs,1,sizeof(vs)),get();}
    void get(int x=1,int l=1,int r=n){
        if(!vs[x])return;if(l==r)qmin(fl[pa[l]],nm[x]);else down(x),get(x*2,l,mid),get(x*2+1,mid+1,r);
        vs[x]=0,nm[x]=tg[x]=1e9;
    }
    int nm[mxn*4],tg[mxn*4];bool vs[mxn*4];
    void ch1(int k,int v){
        if(k<=1||k>n||v<1||v>n)return;
        chg1(k-1,v);
    }
    void chg1(int k,int v,int x=1,int l=1,int r=n){
        if(!vs[x])return;
        if(r<=k)return put(x,v);
        down(x);if(k>mid)chg1(k,v,x*2+1,mid+1,r);chg1(k,v,x*2,l,mid);
    }
    void ins(int k,int x=1,int l=1,int r=n){vs[x]=1;if(l==r)return;down(x);if(k<=mid)ins(k,x*2,l,mid);else ins(k,x*2+1,mid+1,r);}
    void down(int x){if(tg[x]==(int)1e9)return;put(x*2,tg[x]),put(x*2+1,tg[x]),tg[x]=1e9;}
    void put(int x,int v){if(!vs[x])return;tg[x]=min(tg[x],v),nm[x]=min(nm[x],v);}
}s1;
struct ss2{
    void init(){memset(vs,1,sizeof(vs)),get();}
    void get(int x=1,int l=1,int r=n){
        if(!vs[x])return;if(l==r)qmax(fr[pa[l]],nm[x]);else down(x),get(x*2,l,mid),get(x*2+1,mid+1,r);
        vs[x]=0,tg[x]=nm[x]=0;
    }
    int nm[mxn*4],tg[mxn*4];bool vs[mxn*4];
    void ch2(int k,int v){
        if(k<1||k>=n||v<1||v>n)return;
        chg2(k+1,v);
    }
    void chg2(int k,int v,int x=1,int l=1,int r=n){
        if(!vs[x])return;
        if(l>=k)return put(x,v);
        down(x);if(k<=mid)chg2(k,v,x*2,l,mid);chg2(k,v,x*2+1,mid+1,r);
    }
    void ins(int k,int x=1,int l=1,int r=n){vs[x]=1;if(l==r)return;down(x);if(k<=mid)ins(k,x*2,l,mid);else ins(k,x*2+1,mid+1,r);}
    void down(int x){if(!tg[x])return;put(x*2,tg[x]),put(x*2+1,tg[x]),tg[x]=0;}
    void put(int x,int v){if(!vs[x])return;tg[x]=max(tg[x],v),nm[x]=max(nm[x],v);}
}s2;
#undef mid
int main(){
    int ca;scanf("%d",&ca);while(ca--){
        scanf("%d",&n);for(int i=n;i;--i)scanf("%d",a+i),pa[a[i]]=i;
        s1.init(),s2.init();
        memset(fl,0x3f,sizeof(fl)),memset(fr,0,sizeof(fr));
        fl[1]=fr[1]=a[1];
        int r1=1,r2=1;
        for(int T=1;;++T){
            if(T!=1){
                memset(fl,0x3f,sizeof(fl)),memset(fr,0,sizeof(fr)),s1.get(),s2.get();
                for(int i=1;i<=n;++i)if(fl[i]<=n||fr[i]>0)r1=T;
                if(r1<T)break;
            }
            for(int i=n;i;--i){
                s1.ins(a[i]),s2.ins(a[i]);
                if(i-1>0)s1.ch1(a[i-1],fl[i-1]),s2.ch2(a[i-1],fr[i-1]);
                if(i-T>0)s1.ch1(fr[i-T],a[i-T]),s2.ch2(fl[i-T],a[i-T]);
            }
        }
        s1.get(),s2.get();
        for(int i=1;i<=n;++i)fl[i]=fr[i]=a[i];
        for(int T=1;;++T){
            if(T!=1){
                memset(fl,0x3f,sizeof(fl)),memset(fr,0,sizeof(fr)),s1.get(),s2.get();
                for(int i=1;i<=n;++i)if(fl[i]<=n||fr[i]>0)r2=T;
                if(r2<T)break;
            }
            for(int i=n;i;--i){
                s1.ins(a[i]),s2.ins(a[i]);
                if(i-1>0)s1.ch1(a[i-1],fl[i-1]),s2.ch2(a[i-1],fr[i-1]);
                if(i-T-1>0)s1.ch1(fr[i-T-1],a[i-T-1]),s2.ch2(fl[i-T-1],a[i-T-1]);
            }
        }
        printf("%d\n",max(r1,r2));
    }
    return 0;
}