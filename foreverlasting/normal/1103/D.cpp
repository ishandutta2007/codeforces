//2019.1.26 by ljz
#include<bits/stdc++.h>
using namespace std;
#define res register int
#define LL long long
#define inf 0x3f3f3f3f3f3f3f
#define eps 1e-10
inline int read() {
    res s=0;
    bool w=0;
    char ch=getchar();
    while(ch<'0'||ch>'9') {
        if(ch=='-')w=1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9')s=s*10+ch-'0',ch=getchar();
    return w?-s:s;
}
inline void _swap(res &x,res &y) {
    x^=y^=x^=y;
}
inline int _abs(const res &x) {
    return x>0?x:-x;
}
inline int _max(const res &x,const res &y) {
    return x>y?x:y;
}
inline int _min(const res &x,const res &y) {
    return x<y?x:y;
}
const int N=1e6+10;
namespace MAIN {
    int n;
    LL k;
    inline LL gcd(LL x,LL y){
        while(y){
            LL t=x;
            x=y,y=t%y;
        }
        return x;
    }
    LL GCD;
    struct P{
        LL a;
        int e;
        inline bool operator < (const P &b) const {
            return e<b.e;
        }
    }p[N];
    LL f[12][1<<11],g[12][1<<11];
    int f1[(1<<13)+10];
    LL prim[13+10],gx[13+10],part[(1<<13)+10];
    int tot;
    LL ans=inf;
//    const int KCZ=19260817;
//    struct Hash{
//        int head[KCZ+10];
//        struct ED{
//            int next,to,val;
//            ED() {}
//            ED(res next,res to):next(next),to(to) {}
//        }ed[N];
//        int Cnt;
//        inline void add(const res &u,const LL &v){
//            ed[++Cnt]=ED(head[u],v),head[u]=Cnt;
//        }
//        inline bool count(const LL &S){
//            for(res i=head[S%KCZ];i;i=ed[i].next)
//                if(ed[i].to==S)return 1;
//            return 0;
//        }
//        inline int &operator [] (const LL &S){
//            for(res i=head[S%KCZ];i;i=ed[i].next)
//                if(ed[i].to==S)return ed[i].val;
//            add(S%KCZ,S);
//            return ed[Cnt].val;
//        }
//    }f2;
    unordered_map<LL,int> f2;
    inline void MAIN(){
        n=read(),scanf("%lld",&k);
        for(res i=1;i<=n;i++)scanf("%lld",&p[i].a),GCD=gcd(p[i].a,GCD);
        for(res i=1;i<=n;i++)p[i].e=read();
        if(GCD==1){puts("0");return;}
        sort(p+1,p+n+1);
        for(res i=2;1LL*i*i<=GCD;i++){
            if(GCD%i==0){
                prim[++tot]=i;
                while(GCD%i==0)GCD/=i;
            }
        }
        if(GCD>1)prim[++tot]=GCD;
        for(res i=0;i<=tot;i++)
            for(res j=0;j<(1<<tot);j++)f[i][j]=(j==0)?0:inf;
        for(res i=1;i<=n;i++){
            LL nw=1;
            for(res j=1;j<=tot;j++){
                gx[j]=1;
                while(p[i].a%prim[j]==0)nw*=prim[j],gx[j]*=prim[j],p[i].a/=prim[j];
            }
            if(f2[nw]>=tot)continue;
            f2[nw]++;
            memcpy(g,f,sizeof(g));
            part[0]=1;
            for(res s=0;s<tot;s++){
                for(res S=0;S<1<<s;S++){
                    part[S|(1<<s)]=part[S]*gx[s+1];
                    if(part[S|(1<<s)]>k||f1[S|(1<<s)]>=tot)continue;
                    f1[S|(1<<s)]++;
                    for(res l=0;l<tot;l++)
                        for(res SS=0;SS<(1<<tot);SS++)f[l+1][S|SS|(1<<s)]=min(f[l+1][S|SS|(1<<s)],g[l][SS]+p[i].e);

                }
            }
        }
        for(res i=1;i<=tot;i++)ans=min(ans,1LL*f[i][(1<<tot)-1]*i);
        printf("%lld\n",ans==inf?-1:ans);
    }
}
int main() {
    MAIN::MAIN();
    return 0;
}