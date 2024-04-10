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

const int mxn=1e5+3,sq=400,qs=320;
int n,b[mxn],lp[mxn],rp[mxn],kn,be[mxn],po[mxn],qn;
int ju[mxn/sq+2][mxn],ad[mxn/sq+2][mxn/qs+1];
int TG;
struct shu{
    int a[mxn],tg[mxn];
    void add(int x){for(;x<=n;x+=x&-x){if(tg[x]!=TG)tg[x]=TG,a[x]=0;++a[x];}}
    int ask(int x){
        int su=0,p=0;
        for(int i=1<<16;i;i>>=1){
            if(p+i>=n)continue;
            p+=i;if(tg[p]!=TG)tg[p]=TG,a[p]=0;
            if(p+a[p]+su>=x)p-=i;else su+=a[p];
        }
        return p+1;
    }
    void gb(int t){for(int i=1;i<=n;++i){if(tg[i]!=TG)a[i]=0;ju[t][i]=ju[t][i-(i&-i)]+a[i];}for(int i=1;i<=n;++i)ju[t][i]+=i;}
}ar;
void add2(int t,int x,int y){
    int k=(x-1)/qs;
    for(int i=x;i<=(k+1)*qs;++i)ju[t][i]+=y;
    for(++k;k*qs+1<=n;++k)ad[t][k]+=y;
}
int main(){
//cout<<(sizeof(ju)>>20)<<endl;
    scanf("%d",&n);for(int i=1;i<=n;++i)scanf("%d",b+i),b[i]=i-b[i];scanf("%d",&qn);
    for(int l=1,r;r!=n;l=r+1){r=min(l+sq-1,n);lp[++kn]=l,rp[kn]=r;for(int i=l;i<=r;++i)be[i]=kn;}
    for(int t=1;t<=kn;++t){
        ++TG; for(int i=lp[t];i<=rp[t];++i)po[i]=ar.ask(b[i]),ar.add(po[i]);
        ar.gb(t);
    }
    while(qn--){
        int o,x,y;scanf("%d%d",&o,&x);if(o==1){
            scanf("%d",&y);b[x]=x-y;int k=be[x],ls;
            ++TG;for(int i=lp[k];i<=rp[k];++i){
                if(i<x)ar.add(po[i]);else{
                    ls=po[i],po[i]=ar.ask(b[i]),ar.add(po[i]);
                    if(ls==po[i])continue;
                    if(ls==po[i]-1){--ju[k][ls];continue;}
                    if(ls==po[i]+1){++ju[k][po[i]];continue;}
                    assert(i==x);
                    add2(k,ls,-1),add2(k,po[i],1);
                }
            }
        }else{
            int t=be[x],re=b[x];for(int i=x+1;i<=rp[t];++i)re+=b[i]<=re;
            for(++t;t<=kn;++t)re=ju[t][re]+ad[t][(re-1)/qs];
            printf("%d\n",re);
        }
    }
    return 0;
}