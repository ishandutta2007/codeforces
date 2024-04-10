#include<bits/stdc++.h>
using namespace std;
#define forg(i,x) for(int i=fir[x];i;i=nxt[i])
#define fre(x) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
#define scanf abc=scanf
#define uu unsigned
int abc;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int>pii;
typedef vector<int>VI;
mt19937 rnd((ull)(new char));
int rd(int l,int r){uniform_int_distribution<>ee(l,r);return ee(rnd);}

const int mxn=2e6+3;
int n,m,a[mxn],b[mxn],px[mxn];
bool cmp1(int x,int y){return a[x]!=a[y]?a[x]<a[y]:x<y;}
#define mid ((l+r)>>1)
struct seeee{
    int z[mxn*4],tg[mxn*4];
    void bu(int x=1,int l=0,int r=n){
        tg[x]=0;
        if(l==r)return z[x]=l,void();bu(x*2,l,mid),bu(x*2+1,mid+1,r),up(x);
    }
    void up(int x){z[x]=min(z[x*2],z[x*2+1]);}
    void de(int lc,int x=1,int l=0,int r=n){
        if(lc<=l)return put(x,-1);down(x);
        if(lc<=mid)de(lc,x*2,l,mid);de(lc,x*2+1,mid+1,r);up(x);
    }
    void put(int x,int v){tg[x]+=v,z[x]+=v;}
    void down(int x){if(tg[x])put(x*2,tg[x]),put(x*2+1,tg[x]),tg[x]=0;}
}se;
#undef mid
struct arrrrr{int a[mxn];void add(int x){for(;x<=n;x+=x&-x)++a[x];}int ask(int x){int r=0;for(;x;x&=x-1)r+=a[x];return r;}void clr(){for(int i=1;i<=n;++i)a[i]=0;}}ar;
int main(){
    int ca;cin>>ca;while(ca--){
        scanf("%d%d",&n,&m);for(int i=1;i<=n;++i)scanf("%d",a+i),px[i]=i;sort(px+1,px+n+1,cmp1);for(int i=1;i<=m;++i)scanf("%d",b+i);px[n+1]=0,a[0]=2e9;
        sort(b+1,b+m+1);se.bu();
        ll ans=0;
        ar.clr();for(int i=n;i;--i)ans+=ar.ask(px[i]),ar.add(px[i]);
        for(int i=1,p=1,h=0;i<=m;++i){
            if(b[i]!=b[i-1]){
                while(a[px[p]]==b[i-1])se.de(px[p++]),++h;
                while(a[px[p]]<b[i])se.de(px[p]),se.de(px[p++]),++h;
                for(int j=p;a[px[j]]==b[i];++j)se.de(px[j]);
            }
            ans+=h+se.z[1];
        }

        printf("%lld\n",ans);
        
    }
    
    return 0;
}