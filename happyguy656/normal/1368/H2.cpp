#include<bits/stdc++.h>
using namespace std;
#define forg(i,x) for(register int i=fir[x];i;i=nxt[i])
#define uu unsigned
#define scanf a14=scanf
#define rint register int
#define fre(x) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
typedef long long ll;
typedef uu long long ull;
typedef pair<int,int>pii;
int a14;
inline int rd(int l,int r){return rand()%(r-l+1)+l;}

const int mxn=1e5+3;
int n,m,qn;char s1[mxn],s2[mxn],s3[mxn],s4[mxn];
struct mat{
    int a0,a1,a2,a3;mat operator*(const mat&a)const{return{min(a0+a.a0,a1+a.a2),min(a0+a.a1,a1+a.a3),min(a2+a.a0,a3+a.a2),min(a2+a.a1,a3+a.a3)};}
    void pr()const{printf("%d %d %d %d\n",a0,a1,a2,a3);}
};
const mat I={0,(int)1e9,(int)1e9,0};
#define mid ((l+r)>>1)
struct xdd1{
    mat a[mxn*4][4];int tg[mxn*4],S,S2;
    void bu(char s1[],char s2[],int x=1,int l=2,int r=-1){
        if(x==1)r=S,a[x][0]=I;if(l>r)return;
        if(l==r){
            int t1=s1[l],t2=s2[l];a[x][0]={t1+t2,2-t1-t2+S2,t1+t2+S2,2-t1-t2};
            t1^=1;a[x][1]={t1+t2,2-t1-t2+S2,t1+t2+S2,2-t1-t2};
            t2^=1,t1^=1;a[x][2]={t1+t2,2-t1-t2+S2,t1+t2+S2,2-t1-t2};
            t1^=1;a[x][3]={t1+t2,2-t1-t2+S2,t1+t2+S2,2-t1-t2};return;
        }
        bu(s1,s2,x*2,l,mid),bu(s1,s2,x*2+1,mid+1,r);up(x);
    }
    void xg(int lc,int rc,int t,int x=1,int l=2,int r=-1){
        if(x==1)r=S;if(l>r||rc==1)return;
        if(lc<=l&&r<=rc)return put(x,t);down(x);if(lc<=mid)xg(lc,rc,t,x*2,l,mid);if(rc>mid)xg(lc,rc,t,x*2+1,mid+1,r);up(x);
    }
    mat ask(){return a[1][0];}
    void down(int x){if(!tg[x])return;put(x*2,tg[x]),put(x*2+1,tg[x]),tg[x]=0;}
    void put(int x,int t){tg[x]^=t;if(t&1)swap(a[x][0],a[x][1]),swap(a[x][2],a[x][3]);if(t&2)swap(a[x][0],a[x][2]),swap(a[x][1],a[x][3]);}
    void up(int x){for(int i=0;i<4;++i)a[x][i]=a[x*2][i]*a[x*2+1][i];}
}e1,e2;
struct xdd2{
    int a[mxn*4],le[mxn*4],S;bool tg[mxn*4];
    void bu(char s[],int x=1,int l=1,int r=-1){if(x==1)r=S;le[x]=r-l+1;if(l==r)return a[x]=s[l],void();bu(s,x*2,l,mid),bu(s,x*2+1,mid+1,r),up(x);}
    void put(int x){tg[x]^=1,a[x]=le[x]-a[x];}
    void down(int x){if(!tg[x])return;tg[x]=0,put(x*2),put(x*2+1);}
    void up(int x){a[x]=a[x*2]+a[x*2+1];}
    void xg(int lc,int rc,int x=1,int l=1,int r=-1){if(x==1)r=S;if(lc<=l&&r<=rc)return put(x);down(x);if(lc<=mid)xg(lc,rc,x*2,l,mid);if(rc>mid)xg(lc,rc,x*2+1,mid+1,r);up(x);}
    int ask(){return a[1];}
    int as(int k,int x=1,int l=1,int r=-1){if(x==1)r=S;if(l==r)return a[x];down(x);return k<=mid?as(k,x*2,l,mid):as(k,x*2+1,mid+1,r);}
//    void pr(int x=1,int l=1,int r=-1){if(x==1)r=S;if(l==r)putchar(a[x]+'0');else{down(x);pr(x*2,l,mid),pr(x*2+1,mid+1,r);}if(x==1)puts("");}
}r1,r2,r3,r4;
#undef mid
int gag(){
    int r,k;mat t;
    k=r3.ask()+r1.as(1)+r2.as(1);t={k,m+2-k};t=t*e1.ask();k=r4.ask();r=min(t.a0+k,t.a1+m-k);
    k=r1.ask()+r3.as(1)+r4.as(1);t={k,n+2-k};t=t*e2.ask();k=r2.ask();r=min(r,min(t.a0+k,t.a1+n-k));
    return r;
}
int main(){
    scanf("%d%d%d%s%s%s%s",&n,&m,&qn,s1+1,s2+1,s3+1,s4+1);for(int i=1;i<=n;++i)s1[i]=s1[i]=='B',s2[i]=s2[i]=='B';for(int i=1;i<=m;++i)s3[i]=s3[i]=='B',s4[i]=s4[i]=='B';
    e1.S=e2.S2=n,e1.S2=e2.S=m,e1.bu(s1,s2),e2.bu(s3,s4);
    r1.S=r2.S=n,r3.S=r4.S=m;r1.bu(s1),r2.bu(s2),r3.bu(s3),r4.bu(s4);
    printf("%d\n",gag());
    while(qn--){int l,r;scanf("%s%d%d",s1,&l,&r);
        if(s1[0]=='L')r1.xg(l,r),e1.xg(l,r,1);
        else if(s1[0]=='R')r2.xg(l,r),e1.xg(l,r,2);
        else if(s1[0]=='U')r3.xg(l,r),e2.xg(l,r,1);
        else if(s1[0]=='D')r4.xg(l,r),e2.xg(l,r,2);
        printf("%d\n",gag());
    }
    return 0;
}