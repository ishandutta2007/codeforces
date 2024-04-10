#include<bits/stdc++.h>
using namespace std;
#define forg(i,x) for(register int i=fir[x];i;i=nxt[i])
#define uu unsigned
#define scanf a14=scanf
#define rint register int
#define fre(x) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
typedef long long ll;
typedef uu long long ull;
typedef pair<int,int> pii;
int a14;
inline int rd(int l,int r){return rand()%(r-l+1)+l;}

const int mxn=2e5+3,T=400;
int n,qn,lg[mxn];char s[mxn];
int rn[mxn],ln[mxn],sm[26][mxn];

struct SSS{
    int cnt[mxn],sa[mxn],rk[mxn],h[mxn],tmp[mxn*2];char ss[mxn];
    int b[22][mxn];
    bool rv;
    inline int lcp(int l,int r){
        if(rv)l=n-l+1,r=n-r+1;
        l=rk[l],r=rk[r];if(l>r)swap(l,r);
        ++l;int k=lg[r-l+1];return min(b[k][l],b[k][r-(1<<k)+1]);
    }
    void W(){
        memcpy(ss,s,sizeof(s));if(rv)reverse(ss+1,ss+n+1);
        for(int i=1;i<=n;++i)rk[i]=ss[i],++cnt[rk[i]];for(int i=1;i<=200;++i)cnt[i]+=cnt[i-1];for(int i=n;i;--i)sa[cnt[rk[i]]--]=i;
        for(int i=0;i<=200;++i)cnt[i]=0;
        for(int k=1,m=200;;k*=2){
            int p=0; for(int i=n-k+1;i<=n;++i)tmp[++p]=i;
            for(int i=1;i<=n;++i)if(sa[i]>k)tmp[++p]=sa[i]-k;
            for(int i=1;i<=n;++i)++cnt[rk[i]];
            for(int i=1;i<=m;++i)cnt[i]+=cnt[i-1];
            for(int i=n;i;--i)sa[cnt[rk[tmp[i]]]--]=tmp[i];
            for(int i=1;i<=m;++i)cnt[i]=0;
            memcpy(tmp+1,rk+1,sizeof(int)*n);
            p=1,rk[sa[1]]=1;
            for(int i=2;i<=n;++i)rk[sa[i]]=tmp[sa[i]]==tmp[sa[i-1]]&&tmp[sa[i]+k]==tmp[sa[i-1]+k]?p:++p;
            if(p==n)break;m=p;
        }
        for(int i=1,j,k=0;i<=n;++i){
            if(rk[i]==1)continue;
            if(k)--k;j=sa[rk[i]-1];
            while(ss[i+k]==ss[j+k])++k;
            h[rk[i]]=k;
        }
        for(int i=1;i<=n;++i)b[0][i]=h[i];
        for(int j=1;j<=lg[n];++j)for(int i=1;i+(1<<j)-1<=n;++i)b[j][i]=min(b[j-1][i],b[j-1][i+(1<<(j-1))]);
    }
}S1,S2;
#define mid ((l+r)>>1)
struct asfdas{
    int mn[mxn*4],tg[mxn*4];
    inline void _(){memset(mn,0x3f,sizeof(mn));}
    inline void put(int x,int k){mn[x]=tg[x]=k;}
    inline void down(int x){if(tg[x])put(x*2,tg[x]),put(x*2+1,tg[x]),tg[x]=0;}
    inline void up(int x){mn[x]=min(mn[x*2],mn[x*2+1]);}
    inline void cg(int lc,int rc,int k,int x=1,int l=1,int r=n){
        if(lc>rc)return;
        if(lc<=l&&r<=rc)return put(x,k);
        down(x);
        if(lc<=mid)cg(lc,rc,k,x*2,l,mid);if(rc>mid)cg(lc,rc,k,x*2+1,mid+1,r);
        up(x);
    }
    inline int ask(int lc,int rc,int x=1,int l=1,int r=n){
        if(lc>rc)return 1e9;
        if(lc<=l&&r<=rc)return mn[x]; down(x);
        int res=1e9;if(lc<=mid)res=ask(lc,rc,x*2,l,mid);if(rc>mid)res=min(res,ask(lc,rc,x*2+1,mid+1,r));return res;
    }
    inline void dfs1(int a[],int x=1,int l=1,int r=n){
        if(l==r)return a[l]=mn[x]=l+mn[x]*2-1,void();
        down(x);dfs1(a,x*2,l,mid),dfs1(a,x*2+1,mid+1,r);up(x);
    }
    inline void dfs2(int a[],int x=1,int l=1,int r=n){
        if(l==r)return a[l]=l-2*mn[x]+1,void();
        down(x);dfs2(a,x*2,l,mid),dfs2(a,x*2+1,mid+1,r);
    }
}S3,S4;
#undef mid
#define sa S1.sa
#define rk S1.rk
#define h S1.h
inline int gg(int l,int r){
    bool ok=1;for(int c=0;c<26;++c)ok&=sm[c][r]-sm[c][l-1]<=1;
    if(ok)return -1;
    int c=s[l]-'a';
    if(sm[c][r]-sm[c][l-1]==r-l+1)return 1;
    int L=r-l+1;
    for(int i=2;i*i<=L;++i)if(L%i==0){
        if(S1.lcp(l,l+i)>=L-i||S1.lcp(l,l+L/i)>=L-L/i)return 1;
    }
    if(ln[l]<=r||rn[r]>=l)return 2;
    
    int J=(r-l+1)>>1;
    for(int i=1;i<=J&&i<=T;++i)if(S1.lcp(l,r-i+1)>=i)return 2;
    for(int i=rk[l]-1,k=h[i+1]; i&&i>=rk[l]-500&&k>T ;k=min(k,h[i]),--i)
        if(sa[i]>=l&&sa[i]<=r&&k>=r-sa[i]+1&&r-sa[i]+1<=J)return 2;
    for(int i=rk[l]+1,k=h[i]; i<=n&&i<=rk[l]+500&&k>T ;++i,k=min(k,h[i]))
        if(sa[i]>=l&&sa[i]<=r&&k>=r-sa[i]+1&&r-sa[i]+1<=J)return 2;
    if(sm[c][r]-sm[c][l])return 3;
    c=s[r]-'a';if(sm[c][r-1]-sm[c][l-1])return 3;
    if(S3.ask(l,r)<=r)return 3;
    return 4;
}

int main(){
    for(int i=2;i<mxn;++i)lg[i]=lg[i>>1]+1;
    scanf("%d%s%d",&n,s+1,&qn);
    for(int c=0;c<26;++c)for(int i=1;i<=n;++i)sm[c][i]=sm[c][i-1]+(s[i]==c+'a');
    S1.rv=0,S2.rv=1,S1.W(),S2.W();
    S3._(),S4._();
    for(int i=n;i;--i)for(int j=2*i;j<=n;j+=i)if(s[j]==s[j-i]){
        int l2=S1.lcp(j-i,j),l1=S2.lcp(j-i,j);
        S3.cg(j-i-l1+1,j-i+l2-i,i),S4.cg(j-l1+i,j+l2-1,i);
    }
    S3.dfs1(ln),S4.dfs2(rn);
    while(qn--){
        int l,r;scanf("%d%d",&l,&r);printf("%d\n",gg(l,r));
    }
    return 0;
}