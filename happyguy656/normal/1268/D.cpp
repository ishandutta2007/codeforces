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

const int mxn=2003;const ull A=-1;
int n;bool g[mxn][mxn];char ss[mxn];
struct bits{
    ull a[mxn/64+1];int n;
    inline void init(int x,bool b=0){n=x/64;clr();}
    inline void clr(){for(int i=0;i<=n;++i)a[i]=0;}
    inline bool get(uu x){return a[x/64]>>(x%64)&1;}
    inline void fli(uu x){a[x/64]^=1ull<<(x%64);}
    inline void fz(uu x,int y){if(y==get(x))return;fli(x);}
    inline int cnt1(ull x){int r=0;for(int i=0;i<64;++i)r+=x>>i&1;return r;}
    inline int cnt(){int r=0;for(int i=0;i<=n;++i)r+=cnt1(a[i]);return r;}
    inline int ffir(){for(int i=0;i<=n;++i)if(a[i]){ull t=a[i];t=t&-t;for(int j=0;j<64;++j)if(t==(1ull<<j))return i*64+j;}}
    inline bool hav(){for(int i=0;i<=n;++i)if(a[i])return 1;return 0;}
    void operator&=(const bits&b){for(int i=0;i<=n;++i)a[i]&=b.a[i];}
    void operator|=(const bits&b){for(int i=0;i<=n;++i)a[i]|=b.a[i];}
    void operator^=(const bits&b){for(int i=0;i<=n;++i)a[i]^=b.a[i];}
    bits operator~(){bits t;t.init(n);for(int i=0;i<=n;++i)t.a[i]=a[i]^A;return t;}
};
bits cb[mxn],I,h1,h2;
int qu[mxn*mxn],qh,qt;
bool OO(){
    for(int T=0;T<2;++T){
        h1.clr(),h1.fz(1,1);qh=qt=1,qu[1]=1;
        while(qh<=qt){
            int x=qu[qh++];h2=cb[x],h2&=~h1;
            while(h2.hav()){
                int k=h2.ffir();h2.fz(k,0);
                qu[++qt]=k,h1.fz(k,1);
            }
        }
        if(h1.cnt()!=n)return 0;
        for(int i=1;i<=n;++i)cb[i]^=I;
    }
    return 1;
}
void fz(int x){
    for(int i=1;i<=n;++i)cb[x].fli(i),cb[i].fli(x);
}
int main(){
    scanf("%d",&n);for(int i=1;i<=n;++i)cb[i].init(n);h1.init(n),h2.init(n),I.init(n);
    for(int i=1;i<=n;++i){scanf("%s",ss+1);for(int j=1;j<=n;++j)g[i][j]=ss[j]=='1';for(int j=1;j<=n;++j)if(g[i][j])cb[i].fz(j,1);}
    for(int i=1;i<=n;++i)I.fz(i,1);
    if(n<=6){
        int ans=1e9,cc=0;
        for(int z=0;z<1<<n;++z){
            int kk=0;
            for(int i=0;i<n;++i)if(z>>i&1)++kk,fz(i+1);
            if(kk<=ans&&OO()){if(kk==ans)++cc;else cc=1,ans=kk;}
            for(int i=0;i<n;++i)if(z>>i&1)fz(i+1);
        }
        if(ans>n)puts("-1");else{for(int i=1;i<=ans;++i)cc*=i;printf("%d %d\n",ans,cc);}
        return 0;
    }
    if(OO())return puts("0 1"),0;
    int cc=0;
    for(int i=1;i<=n;++i){
        fz(i);cc+=OO();fz(i);
    }
    printf("1 %d\n",cc);
    return 0;
}