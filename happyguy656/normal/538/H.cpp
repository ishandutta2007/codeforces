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

const int mxn=2e5+3;
int n,m,L,R,to[mxn*3],nxt[mxn*3],fir[mxn],gn=1,lx[mxn],rx[mxn],vs[mxn],co[mxn],xl[mxn],xn,be[mxn],ca[mxn];
void gadd(int x,int y){to[++gn]=y,nxt[gn]=fir[x],fir[x]=gn;to[++gn]=x,nxt[gn]=fir[y],fir[y]=gn;}
int bn,bb[mxn][4],tp[mxn],rt[mxn];
bool dfs(int x){
    vs[x]=1;xl[++xn]=x;
    forg(i,x)if(vs[to[i]]){
        if(co[to[i]]!=(co[x]^1))return 0;
    }else if(co[to[i]]=co[x]^1,!dfs(to[i]))return 0;
    return 1;
}
void dfs2(int x){
    vs[x]=1;forg(i,x)if(!vs[to[i]])ca[to[i]]=ca[x]^1,dfs2(to[i]);
}
bool DFS(){
    memset(vs,0,sizeof(vs));bn=0;for(int i=1;i<=n;++i)if(!vs[i]){
        xn=0;if(!dfs(i))return 0;
        ++bn;rt[bn]=i;
        int l1=-1,l2=-1,r1=R,r2=R;for(int j=1;j<=xn;++j){int t=xl[j];be[t]=bn;if(co[t])l2=max(l2,lx[t]),r2=min(r2,rx[t]);else l1=max(l1,lx[t]),r1=min(r1,rx[t]);}
        bb[bn][0]=l1,bb[bn][1]=r1,bb[bn][2]=l2,bb[bn][3]=r2;
    }
    return 1;
}
int l1,r1,l2,r2,l3,r3,l4,r4;
bool wk(){
    int mn=2e9,mx=-1,b1=0,b2=0;for(int i=1;i<=n;++i)mn=min(mn,rx[i]),mx=max(mx,lx[i]);
    for(int i=1;i<=n;++i){if(rx[i]==mn)b1=i;if(lx[i]==mx)b2=i;}
    for(int i=1;i<=n;++i){if(lx[i]>mn)gadd(b1,i);if(rx[i]<mx)gadd(b2,i);}
    
    if(!DFS())return 0;

    if(!(be[b1]==be[b2]&&co[b1]==co[b2])){
        l1=0,r1=mn,l2=mx,r2=1.1e9;
        for(int i=1;i<=bn;++i){
            if(l3=max(l1,bb[i][0]),r3=min(r1,bb[i][1]),l4=max(l2,bb[i][2]),r4=min(r2,bb[i][3]),l3<=r3&&l4<=r4&&l3+l4<=R&&r3+r4>=L)tp[i]=0,l1=l3,r1=r3,l2=l4,r2=r4;
            else if(l3=max(l1,bb[i][2]),r3=min(r1,bb[i][3]),l4=max(l2,bb[i][0]),r4=min(r2,bb[i][1]),l3<=r3&&l4<=r4&&l3+l4<=R&&r3+r4>=L)tp[i]=1,l1=l3,r1=r3,l2=l4,r2=r4;
            else goto tb;
        }
        return 1;
        tb:;
    }
    if(!(be[b1]==be[b2]&&co[b1]!=co[b2])&&mx<=mn){
        l1=mx,r1=mn,l2=0,r2=1.1e9;
        for(int i=1;i<=bn;++i){
            if(l3=max(l2,bb[i][0]),r3=min(r2,bb[i][1]),l3<=r3&&l3+l1<=R&&r3+r1>=L)tp[i]=1,l2=l3,r2=r3;
            else if(l3=max(l2,bb[i][2]),r3=min(r2,bb[i][3]),l3<=r3&&l3+l1<=R&&r3+r1>=L)tp[i]=0,l2=l3,r2=r3;
            else goto tb2;
        }
        return 1;
        tb2:;
    }
    return 0;
}
int main(){
//cout<<((sizeof(to)*2+sizeof(bb)+sizeof(lx)*8)>>20)<<endl;
    scanf("%d%d%d%d",&L,&R,&n,&m);for(int i=1;i<=n;++i)scanf("%d%d",lx+i,rx+i);for(int i=1,x,y;i<=m;++i)scanf("%d%d",&x,&y),gadd(x,y);
    if(!wk())puts("IMPOSSIBLE");else{
        puts("POSSIBLE");
        if(l1+l2>=L)printf("%d %d\n",l1,l2);else{int t=L-l1-l2;if(l1+t<=r1)printf("%d %d\n",l1+t,l2);else printf("%d %d\n",r1,l2+t-(r1-l1));}
        memset(vs,0,sizeof(vs));
        for(int i=1;i<=bn;++i){ca[rt[i]]=tp[i]?1:0;dfs2(rt[i]);}for(int i=1;i<=n;++i)printf("%d",ca[i]+1);puts("");
    }
    return 0;
}