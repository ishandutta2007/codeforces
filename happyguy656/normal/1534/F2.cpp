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

const int mxn=4e5+3;
int n,m,za[mxn],be[mxn],po[mxn],bn,ins[mxn],stk[mxn],tn,dfn[mxn],low[mxn],dn;
int to[mxn*4],nxt[mxn*4],fr[mxn*4],fir[mxn],gn;void ga(int x,int y){to[++gn]=y,fr[gn]=x,nxt[gn]=fir[x],fir[x]=gn;}
vector<int>g2[mxn];int dg[mxn];
int bq[mxn],nn,lp[mxn],rp[mxn],can[mxn];
int qu[mxn],qh,qt;
pii lr[mxn];
void gad(int x,int y){if(x==y)return;g2[x].push_back(y),++dg[y];}
char*s[mxn];
inline int id(int x,int y){return (x-1)*m+y;}
void tar(int x){
    dfn[x]=low[x]=++dn,stk[++tn]=x,ins[x]=1;
    forg(i,x)if(!dfn[to[i]])tar(to[i]),low[x]=min(low[x],low[to[i]]);
    else if(ins[to[i]])low[x]=min(low[x],dfn[to[i]]);
    if(dfn[x]==low[x]){
        int y;++bn;
        do y=stk[tn--],be[y]=bn,ins[y]=0;while(y!=x);
    }
}
int main(){
    scanf("%d%d",&n,&m);for(int i=0;i<=n+1;++i)s[i]=new char[m+2];
    for(int i=0;i<=n+1;++i)for(int j=0;j<=m+2;++j)s[i][j]=0;
    for(int i=1;i<=n;++i)scanf("%s",s[i]+1);for(int i=1;i<=m;++i)scanf("%d",za+i);
//    puts(".1");
    for(int j=1;j<=m;++j){
        for(int i=n,ls=0,l1=0,l2=0,c=0;i;--i){
            if(s[i][j-1]=='#')l1=i;if(s[i][j+1]=='#')l2=i;
            if(j==1)assert(!l1);if(j==m)assert(!l2);
            if(s[i][j]=='#'){
                int hh=id(i,j);
                if(s[i-1][j]=='#')ga(hh,id(i-1,j));
                if(ls)ga(hh,id(ls,j));ls=i;
                if(l1)ga(hh,id(l1,j-1));
                if(l2)ga(hh,id(l2,j+1));
                if(++c==za[j])po[j]=hh;
            }
        }
    }
    //    puts(".2");
    for(int i=1;i<=n*m;++i)if(!dfn[i])tar(i);
    for(int i=1;i<=gn;++i)gad(be[fr[i]],be[to[i]]);
    
    qh=1,qt=0;
    memset(lp,0x3f,sizeof(lp));
    for(int j=1,ls=-1;j<=m;++j)for(int i=1;i<=n;++i)if(s[i][j]=='#'){
        int k=be[id(i,j)];if(!dg[k]&&k!=ls)ls=k,bq[k]=++nn,lp[k]=rp[k]=nn,qu[++qt]=k;
    }
    
    while(qh<=qt){int x=qu[qh++];for(int y:g2[x])if(--dg[y]==0)qu[++qt]=y;}
//        puts(".3");
    for(int i=1;i<=bn;++i){int x=qu[i];for(int y:g2[x])lp[y]=min(lp[y],lp[x]),rp[y]=max(rp[y],rp[x]);}
    tn=0;for(int i=1,t;i<=m;++i)if(za[i])t=be[po[i]],lr[++tn]=pii(lp[t],rp[t]);
    sort(lr+1,lr+tn+1);
    for(int i=tn,dd=1e9;i;--i){
        int k=lr[i].second;if(k<dd)dd=k,can[i]=1;else can[i]=0;
    }
    int ans=0;
    for(int i=1,dd=0;i<=tn;++i)if(can[i]&&lr[i].first>dd)++ans,dd=lr[i].second;
    printf("%d\n",ans);
    return 0;
}