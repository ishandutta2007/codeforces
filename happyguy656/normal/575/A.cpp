

#include<bits/stdc++.h>
using namespace std;
typedef pair<long long,int>pii;
#define forg(i,x) for(int i=first[x];i;i=nxt[i])
#define od(x) ((x)&1)
#define ev(x) (od(x)^1)
#define fi first
#define se second
#define uu unsigned
#define fre(x) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
inline void xxx(){}
inline int rd(int l,int r){return rand()%(r-l+1)+l;}

const int mxn=1e5+3;
int mo,m,a[mxn],n;long long k;
pii b[mxn];

struct mat{
    int x,y;long long a[2][2];
    mat(){}
    mat(int xx,int yy){x=xx,y=yy,memset(a,0,sizeof(a));}
    inline void pr(){puts("--------");for(int i=0;i<=x;++i,puts(""))for(int j=0;j<=y;++j)printf("%lld ",a[i][j]);}
};
inline mat operator*(const mat &a,const mat &b){
    mat res=mat(a.x,b.y);
    for(int i=0;i<=a.y;++i)for(int j=0;j<=a.x;++j)for(int k=0;k<=b.y;++k) (res.a[j][k]+=a.a[j][i]*b.a[i][k])%=mo;
    return res;
}
inline mat nem(int a,int b){
    mat mt=mat(1,1);
    mt.a[0][0]=0,mt.a[1][0]=1,mt.a[0][1]=a,mt.a[1][1]=b;
    return mt;
}
inline void mpor(mat &fi,mat zy,long long y){
    for(;y;y>>=1){
        if(y&1)fi=fi*zy;
        zy=zy*zy;
    }
}

mat zy[mxn],dw;
#define mid ((l+r)>>1)
class seee{
    public:
    mat d[mxn*4];
    inline void build(int x,int l,int r){
        if(l==r)return d[x]=zy[l],void();
        build(x*2,l,mid),build(x*2+1,mid+1,r);
        d[x]=d[x*2]*d[x*2+1];
    }
    inline void ask(int x,int l,int r,int lc,int rc,mat& su){
        if(lc<=l&&r<=rc)return su=su*d[x],void();
        if(lc<=mid)ask(x*2,l,mid,lc,rc,su);
        if(rc>mid)ask(x*2+1,mid+1,r,lc,rc,su);
    }
}seg;
#undef mid
inline mat ask(int l,int r){
    mat res=dw;
    if(l>r)return res;
    seg.ask(1,1,n,l,r,res);
    //res.pr();
    return res;
}
long long id[mxn],kd,di[mxn];
int nn,kn;
struct thr{
    int a,b,c;
    thr(){}
    thr(int aa,int bb,int cc){a=aa,b=bb,c=cc;}
};
vector<thr>gai[mxn];
int main(){//fre(fibonotci);
    scanf("%lld%d%d",&k,&mo,&n);for(int i=0;i<n;++i)scanf("%d",a+i);scanf("%d",&m);for(int i=1;i<=m;++i)scanf("%lld%d",&b[i].fi,&b[i].se);
    if(k==0)return puts("0"),0;
    if(k==1)return printf("%d\n",mo==1?0:1),0;
    sort(b+1,b+m+1);
    while(m&&b[m].fi>=k)--m;
    for(int i=1;i<=m;++i)id[i]=(b[i].fi-1)/n+1; kd=(k-2)/n+1;
    kn=(k-1)%n;
    if(kn==0)kn=n;
    for(int i=1;i<=m;++i){
        if(di[nn]<id[i])di[++nn]=id[i];
        if(b[i].fi+1<k&&b[i].fi%n==0&&di[nn]<id[i]+1)di[++nn]=id[i]+1;
    }
    for(int i=1;i<=n;++i)zy[i]=nem(a[i-1],a[i==n?0:i]);
    zy[0]=zy[n];
    seg.build(1,1,n);
    for(int i=1,p=0;i<=m;++i){
        long long x=b[i].fi;int y=b[i].se;
        if(id[i]!=di[p])++p;
        x%=n;
        if(x==0)x=n;
        gai[p].push_back(thr(x,1,y));
        if(b[i].fi+1>=k)break;
        if(x==n){
            gai[++p].push_back(thr(1,0,y));
        }else gai[p].push_back(thr(x+1,0,y));
    }
    mat res=mat(0,1);res.a[0][0]=0,res.a[0][1]=1;
    dw=mat(1,1);dw.a[0][0]=dw.a[1][1]=1;
    if(di[nn]!=kd)di[++nn]=kd,gai[nn].push_back(thr(kn,1,zy[kn].a[1][1]));
    for(int i=1,x;i<=nn;++i){
        mpor(res,seg.d[1],di[i]-di[i-1]-1);
        int sz=gai[i].size();
        for(int jj=0;jj<sz;++jj){
            x=gai[i][jj].a;
            if(jj==0)res=res*ask(1,x-1);
            else res=res*ask(gai[i][jj-1].a+1,x-1);
            if(jj+1!=sz&&x==gai[i][jj+1].a){
                if(gai[i][jj].b)res=res*nem(gai[i][jj+1].c,gai[i][jj].c);
                else            res=res*nem(gai[i][jj].c,gai[i][jj+1].c);
                ++jj;
            }else{
                if(gai[i][jj].b){
                    res=res*nem(zy[x].a[0][1],gai[i][jj].c);
                }else res=res*nem(gai[i][jj].c,zy[x].a[1][1]);
            }
        }
        x=gai[i][sz-1].a;
        if(di[i]!=kd)res=res*ask(x+1,n);
    }
    printf("%lld\n",res.a[0][1]);
    return 0;
}