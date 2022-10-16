#include<bits/stdc++.h>
using namespace std;
#define uu unsigned
#define scanf abc=scanf
#define forg(i,x) for(int i=fir[x];i;i=nxt[i])
#define fre(x) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
int abc;
typedef long long ll;
typedef uu long long ull;
typedef vector<int>VI;
typedef pair<int,int>pii;
int rd(int l,int r){return rand()%(r-l+1)+l;}

const int mxn=2e5+3,T=mxn;
int n,a[mxn],ee[mxn],cs[mxn],ans,po[mxn*2],wz[mxn],pr[mxn],nm[mxn];

int main(){
    scanf("%d",&n);for(int i=1;i<=n;++i)scanf("%d",a+i),pr[i]=wz[a[i]],wz[a[i]]=i,nm[i]=nm[pr[i]]+1;
    int P=n,X=0,mx=0;
    for(int i=n;i;--i){
        int x=a[i];--cs[ee[x]],++cs[++ee[x]];if(ee[x]>mx)X=x,mx=ee[x];
        if(cs[mx]>1)ans=n-i+1,P=i-1;
    }
    for(int v=1;v<mxn;++v)if(v!=X&&ee[v]){
        int e=T,ls=T,o=0;
        int p1=wz[X],p2=wz[v],fr=n+1,t;
        while(p1||p2){
            ls-=o;if(!po[ls])po[ls]=fr-1;e=ls;
            if(p1>p2){
                t=p1;p1=pr[p1];
                if(t+1!=fr&&po[e])ans=max(ans,po[e]-t);
                fr=t;if(a[t]==X)e=ls-1,o=1;else if(a[t]==v)e=ls+1,o=-1;else e=ls,o=0;
                if(po[e])ans=max(ans,po[e]-t+1);
//                if(mx-nm[p1]>400&&nm[wz[v]]<400)goto tb;
            }else{
                t=p2;p2=pr[p2];
                if(t+1!=fr&&po[e])ans=max(ans,po[e]-t);
                fr=t;if(a[t]==X)e=ls-1,o=1;else if(a[t]==v)e=ls+1,o=-1;else e=ls,o=0;
                if(po[e])ans=max(ans,po[e]-t+1);
            }
        }
        if(fr>1){ls-=o;if(!po[ls])po[ls]=fr-1;ans=max(ans,po[ls]);}
        tb:
/*        for(int t=n;t;--t){
            ls-=o;if(!po[ls])po[ls]=t;
            if(a[t]==X){
                e=ls-1;
                o=1;
            }else if(a[t]==v){
                e=ls+1;
                o=-1;
            }else e=ls,o=0;
            if(po[e])ans=max(ans,po[e]-t+1);
        }*/
        for(int i=ls;po[i];--i)po[i]=0;
        for(int i=ls+1;po[i];++i)po[i]=0;
    }
    printf("%d\n",ans);
    return 0;
}