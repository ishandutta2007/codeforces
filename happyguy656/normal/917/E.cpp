#include<bits/stdc++.h>
using namespace std;
#define forg(i,x) for(register int i=fir[x];i;i=nxt[i])
#define FORG(i,x) for(register int i=FIR[x];i;i=NXT[i])
#define uu unsigned
#define scanf a14=scanf
#define rint register int
#define fre(x) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
typedef long long ll;
typedef uu long long ull;
typedef pair<int,int> pii;
typedef vector<int>::iterator VP;
int a14;
inline int rd(int l,int r){return rand()%(r-l+1)+l;}

const int mxn=2e5+3;
int n,m,qn,to[mxn],nxt[mxn],fir[mxn],gn=1,co[mxn];
inline void gadd(int x,int y,char c){to[++gn]=y,nxt[gn]=fir[x],fir[x]=gn,co[gn]=c;}
int lp[mxn],rp[mxn],bs[mxn],sb[mxn];char ss[mxn];
int a1[mxn],a2[mxn],a3[mxn],a4[mxn],a5[mxn];
int dfn[mxn],dfa[mxn],siz[mxn],top[mxn],zs[mxn],dep[mxn],fa[mxn],dt,qa[mxn];
vector<int>jp[mxn];
inline void dfs1(int x,int f){
    fa[x]=f,dep[x]=dep[f]+1,siz[x]=1;
    forg(i,x)if(to[i]!=f){dfs1(to[i],x),siz[x]+=siz[to[i]];if(siz[to[i]]>siz[zs[x]])zs[x]=to[i];}
}
inline void dfs2(int x,int f){
    top[x]=x==zs[f]?top[f]:x,dfn[x]=++dt,dfa[dt]=x;
    jp[top[x]].push_back(x);
    if(zs[x])dfs2(zs[x],x);forg(i,x)if(!dfn[to[i]])dfs2(to[i],x);
}
inline int lca(int x,int y){while(top[x]!=top[y]){if(dep[top[x]]<dep[top[y]])swap(x,y); x=fa[top[x]];}return dep[x]<dep[y]?x:y;}
inline int kzx(int x,int k){while(x&&dep[x]-dep[top[x]]<k)k-=dep[x]-dep[top[x]]+1,x=fa[top[x]]; if(!x||!k)return x; return jp[top[x]][dep[x]-dep[top[x]]-k];}
struct thr{int a,b,c;};
struct awe{
    int fail[mxn],ac[mxn][26],tt,q[mxn],qh,qt,po[mxn],b1[mxn],b2[mxn],bn;
    vector<thr>vc[mxn];
    inline void w1(){
        for(int i=1;i<=m;++i){
            int d=0;
            for(int j=rp[i];j>=lp[i];--j){
                int c=ss[j]-'a';if(!ac[d][c])ac[d][c]=++tt;d=ac[d][c];
            }
            po[i]=d;
        }
        W();
    }
    inline void w2(){
        for(int i=1;i<=m;++i){
            int d=0;
            for(int j=lp[i];j<=rp[i];++j){
                int c=ss[j]-'a';if(!ac[d][c])ac[d][c]=++tt;d=ac[d][c];
            }
            po[i]=d;
        }
        W();
    }
    inline void W(){
        qh=1,qt=0;for(int c=0;c<26;++c)if(ac[0][c])q[++qt]=ac[0][c];
        while(qh<=qt){
            int x=q[qh++];
            for(int c=0;c<26;++c)
                if(ac[x][c])q[++qt]=ac[x][c],fail[ac[x][c]]=ac[fail[x]][c];
                else ac[x][c]=ac[fail[x]][c];
        }
        for(int i=1;i<=tt;++i)G(fail[i],i);
        dfs0(0,0);
        dfs1(1,0);
    }
    int TO[mxn],NXT[mxn],FIR[mxn],GN;
    inline void G(int x,int y){TO[++GN]=y,NXT[GN]=FIR[x],FIR[x]=GN;}
    inline void dfs0(int x,int f){
        b1[x]=++bn;
        FORG(i,x)if(TO[i]!=f)dfs0(TO[i],x);
        b2[x]=bn;
    }
    inline void dfs1(int x,int f,int d=0){
        add(b1[d],1);
        for(auto &i:vc[x]){
            int t=po[i.a];
            qa[i.c]+=i.b*ask(b1[t],b2[t]);
        }
        forg(i,x)if(to[i]!=f)dfs1(to[i],x,ac[d][co[i]-'a']);
        add(b1[d],-1);
    }
    int ar[mxn];
    inline void add(int x,int y){for(;x<=tt+1;x+=x&-x)ar[x]+=y;}
    inline int ask(int x){int res=0;for(;x;x-=x&-x)res+=ar[x];return res;}
    inline int ask(int l,int r){return ask(r)-ask(l-1);}
}A1,A2;
const int B=137,mod=1e9+9;
ll bin[mxn];
int pp[mxn][2];
struct aweg{
    int sa[mxn],rk[mxn],tmp[mxn],cnt[mxn],sn;
    char s[mxn],s1[mxn];
    ll ha[mxn],hs[mxn];
    vector<thr>oh[mxn];
    bool rv;
    inline ll ha1(int l,int r){return (ha[r]-ha[l-1]*bin[r-l+1]%mod+mod)%mod;}
    inline ll ha2(int l,int r){return (hs[r]-hs[l-1]*bin[r-l+1]%mod+mod)%mod;}
    int bor[mxn],ju[mxn],der[mxn];
    inline void SA(int n,char s[],int rk[],int sa[]){
        for(int i=1;i<=n;++i)rk[i]=s[i],++cnt[rk[i]];for(int i=1;i<=200;++i)cnt[i]+=cnt[i-1];for(int i=n;i;--i)sa[cnt[rk[i]]--]=i;
        for(int i=0;i<=200;++i)cnt[i]=0;  for(int i=1;i<=2*n;++i)tmp[i]=0;
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
    }
    inline void W(bool RV){
        rv=RV;
        memcpy(s,ss,sizeof(ss));
        if(rv)for(int i=1;i<=m;++i)reverse(s+lp[i],s+rp[i]+1);
        sn=rp[m];
        for(int k=1;k<=m;++k){
            int L=lp[k],R=rp[k];
            bor[R+1]=R+2;
            for(int i=R,j=R+2;i>=L;--i){
                while(j!=R+2&&s[j-1]!=s[i])j=bor[j];
                bor[i]=--j;
                assert(j>i);
                if(j==R+1)ju[i]=i,der[i]=0;else der[i]=j-i,ju[i]=der[i]==der[j]?ju[j]:i;
            }
        }
        for(int i=1;i<=sn;++i)ha[i]=(ha[i-1]*B+s[i])%mod;
        for(int i=1;i<=m;++i)SA(rp[i]-lp[i]+1,s+lp[i]-1,rk+lp[i]-1,sa+lp[i]-1);
        for(int i=1;i<=m;++i)for(int j=lp[i];j<=rp[i];++j)sa[j]+=lp[i]-1,rk[sa[j]]=j;
        dfs(1);
    }
    inline int llen(int L,int R,int k){
        int l=0,r=min(R-L+1,sb[k]-k+1),mid;
        while(l!=r){mid=(l+r+1)>>1;if(ha1(k,k+mid-1)==ha2(L,L+mid-1))l=mid;else r=mid-1;}
        return l;
    }
    inline bool cmp(int L,int R,int k){
        k=sa[k];
        int x=llen(L,R,k);
        if(x==R-L+1||x==sb[k]-k+1)return 1;
        return s[k+x]<s1[L+x];
    }
    inline int gpo(int L,int R,int k){
        int l=lp[k]-1,r=rp[k],mid;
        while(l<r){mid=(l+r+1)>>1;if(cmp(L,R,mid))l=mid;else r=mid-1;}
        if(l==rp[k])return sa[l];
        if(l==lp[k]-1)return sa[l+1];
        int x=sa[l],y=sa[l+1];
        return llen(L,R,x)<llen(L,R,y)?y:x;
    }
    inline int gd(int x,int R,int lm){
        if(lm==0)return 0;
        while(x<=R&&R-ju[x]+1>lm)x=bor[ju[x]];
        if(x>R)return 0;
        int dd=der[x];
        int ln=R-x+1;
        if(ln<=lm)return x;
        int kk=(ln-lm-1)/dd+1;
        return x+kk*dd;
    }
    inline void dfs(int x,int f=0,int d=0){
        for(auto &h:oh[x]){
            int L=dep[h.a],xh=h.c,k=h.b;
            int p=gpo(L,d,k),len=llen(L,d,p);
            pp[xh][rv]=gd(p,rp[k],len);
            p=pp[xh][rv];//if(p)assert(llen(L,d,p)==sb[p]-p+1);
        }
        forg(i,x)if(to[i]!=f){
            s1[d+1]=co[i],hs[d+1]=(hs[d]*B+co[i])%mod;
            dfs(to[i],x,d+1);
        }
    }
}B1,B2;                                                                                                                 
inline int gcd(int a,int b){int c;for(;b;c=a%b,a=b,b=c);return a;}
inline void exgcd(int a,int b,ll &x,ll &y){
    if(!b)return x=a,y=0,void();
    exgcd(b,a%b,x,y);
    //bx+(a-a/b*b)y
    ll tmp=x;x=y,y=tmp-a/b*y;
}
inline int fc(int x,int y,int z,int l1,int l2){
    if(z<0)return 0;
    if(x==0&&y==0)return z==0;
    if(x==0)return z%y==0&&z/y<=l2;
    if(y==0)return z%x==0&&z/x<=l1;
    int X=gcd(x,y);if(z%X)return 0;x/=X,y/=X,z/=X;
    ll A,B;exgcd(x,y,A,B);
    A=(A*z%y+y)%y;B=(z-A*x)/y; if(B<0)return 0;
    assert(A*x+B*y==z);
    if(l1<A)return 0;
    int U=min((l1-A)/y,B/x),D=B<=l2?0:(B-l2-1)/x+1;
    if(U<D)return 0;
    return U-D+1;

}
inline int ask(int x,int y,int h){
    int*t1=B1.ju,*t2=B2.ju,*d1=B1.der,*d2=B2.der;
    int L1=sb[x],L2=sb[y],res=0;
    for(int i=x;i<=L1;i=B1.bor[t1[i]])for(int j=y;j<=L2;j=B2.bor[t2[j]]){
        res+=fc(d1[i],d2[j],L1-i+1+L2-j+1-h,d1[i]?(t1[i]-i)/d1[i]:-1,d2[j]?(t2[j]-j)/d2[j]:-1);
    }
    return res;
}
int main(){
    bin[0]=1;for(int i=1;i<mxn;++i)bin[i]=bin[i-1]*B%mod;
    scanf("%d%d%d",&n,&m,&qn);{char hh[5];for(int i=1,u,v;i<n;++i)scanf("%d%d%s",&u,&v,hh),gadd(u,v,hh[0]),gadd(v,u,hh[0]);}
    for(int i=1,j=1;i<=m;++i)scanf("%s",ss+j),lp[i]=j,j+=strlen(ss+j),rp[i]=j-1;
    for(int i=1;i<=m;++i)for(int j=lp[i];j<=rp[i];++j)bs[j]=i,sb[j]=rp[i];
    for(int i=1;i<=qn;++i)scanf("%d%d%d",a1+i,a2+i,a3+i);
    dfs1(1,0),dfs2(1,0);
    for(int t=1;t<=qn;++t){
        int x=a1[t],y=a2[t],z=lca(x,y),k=a3[t],len=rp[k]-lp[k]+1;
        a4[t]=z,a5[t]=len;
        if(dep[x]-dep[z]>=len){
            int u=kzx(x,dep[x]-dep[z]-len+1);
            A1.vc[u].push_back((thr){k,-1,t}),A1.vc[x].push_back((thr){k,1,t});
        }
        if(dep[y]-dep[z]>=len){
            int u=kzx(y,dep[y]-dep[z]-len+1);
            A2.vc[u].push_back((thr){k,-1,t}),A2.vc[y].push_back((thr){k,1,t});
        }
        if(x!=z&&y!=z){
            B1.oh[x].push_back((thr){z,k,t}),B2.oh[y].push_back((thr){z,k,t});
        }
    }
    A1.w1(),A2.w2();
    B1.W(1),B2.W(0);
    for(int t=1;t<=qn;++t)if(pp[t][0]&&pp[t][1])qa[t]+=ask(pp[t][1],pp[t][0],a5[t]);
    for(int i=1;i<=qn;++i)printf("%d\n",qa[i]);
    return 0;
}