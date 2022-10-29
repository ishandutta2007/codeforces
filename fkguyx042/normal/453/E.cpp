#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <string>
#define For(i,x,y)  for(int i=(x);i<=(y);i++)
#define Forn(i,x,y) for(int i=(y);i>=(x);i--)
#define ls x<<1,L,mid
#define rs (x<<1)|1,mid+1,R
#define maxn 100005
#define T 20
using namespace std;
typedef long long skydec;

long long ans;
int vt[maxn*T],curvt,curA,curB;
skydec A[maxn*T],B[maxn*T];
struct node{
    int lA,rA,lB,rB,lvt,rvt;
    int fg,lst;
    void Fg(int GTW){fg=lst=GTW;}
    int getA(int x){if(x<=lA)return 0;return A[x];}
    int getB(int x){if(x<=lB)return 0;return B[x];}
}tre[maxn<<2];
skydec s[maxn],m[maxn],r[maxn];
int ql,qr,tms,n;
double t[maxn];

inline int cmp(const int &x,const int &y){return t[x]<t[y];}

void build(int x,int L,int R)
{
    tre[x].lst=tre[x].fg=-1;
    tre[x].lvt=curvt+1;
    tre[x].lA=curA;
    tre[x].lB=curB;
    skydec psA=0,psB=0;
    For(i,L,R){if(!r[i])continue;vt[++curvt]=i;}
    tre[x].rvt=curvt;
    sort(vt+tre[x].lvt,vt+tre[x].rvt+1,cmp);
    For(i,tre[x].lvt,tre[x].rvt){
        psA+=r[vt[i]];A[++curA]=psA;
        psB+=m[vt[i]];B[++curB]=psB;
    }tre[x].rA=curA;
    tre[x].rB=curB;
    if(L==R)return;
    int mid=(L+R)>>1;
    build(ls);
    build(rs);
}

inline void Fg(int x){tre[x].fg=tre[x].lst=tms;}

inline void setIO(string a)
{
#ifndef ONLINE_JUDGE
    string in=a+".in",out=a+".out";
    freopen(in.c_str(),"r",stdin);
    freopen(out.c_str(),"w",stdout);
#endif
}

void down(int x){
    if(tre[x].fg<0)return;
    For(i,0,1) tre[(x<<1)|i].Fg(tre[x].fg);
    tre[x].fg=-1;
}

void sol(int x,int L,int R){
    if(L==R && tre[x].fg<0){
        ans+=min(m[L],s[L]+tms*r[L]);
        return;
    }
    if(tre[x].fg>=0){
        int L=tre[x].lvt,R=tre[x].rvt;
        skydec dT=skydec(tms-tre[x].lst);
        if(L>R)return;
        while(L^R){
            int mid=(L+R)>>1;
            if(1ll*dT*r[vt[mid]]<=m[vt[mid]]) R=mid;else L=mid+1;
        }
        if(1ll*dT*r[vt[L]]<=m[vt[L]]) --L;
        ans+=tre[x].getB(L);
 //       printf("%d ",tre[x].getB(L));
        ans+=1ll*(A[tre[x].rA]-tre[x].getA(L))*dT;
 //       printf("%d\n",1ll*(A[tre[x].rA]-tre[x].getA(L))*dT);
        return;
    }int mid=(L+R)>>1;
    sol(ls);
    sol(rs);
}

void work(int x,int L,int R)
{
    if(ql<=L&&R<=qr){
        sol(x,L,R);
        tre[x].Fg(tms);
        return;
    }down(x);
    int mid=(L+R)>>1;
    if(ql<=mid)work(ls);
    if(mid<qr) work(rs);
}

int main()
{
//    setIO("fc");
    scanf("%d",&n);
    For(i,1,n) scanf("%I64d%I64d%I64d",s+i,m+i,r+i);
    For(i,1,n) if(r[i]) t[i]=1.*m[i]/r[i];
    build(1,1,n);
    int Q;scanf("%d",&Q);
    For(i,1,Q){
        scanf("%d%d%d",&tms,&ql,&qr);
        ans=0;
        work(1,1,n);
        printf("%I64d\n",ans);
//        puts("");
    }scanf("\n");
    return 0;
}