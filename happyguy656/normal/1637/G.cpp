#include<bits/stdc++.h>
using namespace std;
#define uu unsigned
#define fre(x) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
#define scanf(x...) assert(scanf(x))
#define forg(i,x) for(int i=fir[x];i;i=nxt[i])
typedef long long ll;
typedef uu long long ull;
typedef pair<int,int>pii;
typedef vector<int>VI;
mt19937 rnd((ull)(new char));
int rd(int l,int r){uniform_int_distribution<>ee(l,r);return ee(rnd);}
void NC(ull k){cerr<<(k>>20)<<endl;}

const int mxn=5e4+3;
int an,jg[mxn*20][2],n,b[mxn],nn;
void cz(int x,int y){jg[++an][0]=x,jg[an][1]=y;}

void slv0(int x,int B=1){
    while(x&&(x&-x)==x)b[++nn]=B*x,--x;
    if(!x)return;
    int K=1<<(31-__builtin_clz(x));
    b[++nn]=B*K;
    int p=K*2-x;
    for(int i=p;i<K;++i)cz(B*i,B*(2*K-i)),b[++nn]=B*2*K;
    slv0(p-1,B),slv0(K-p,B*2);
}

void chk(bool tp=1){
return;
    static int cc[mxn],d[mxn];int n0=0;memset(cc,0,sizeof(cc));for(int i=1;i<=n;++i)cc[i]=1;
    for(int i=1;i<=an;++i){int x=jg[i][0],y=jg[i][1];--cc[x],--cc[y];assert(cc[x]>=0&&cc[y]>=0);if(x>y)swap(x,y);++cc[x+y],++cc[y-x];}
    for(int i=0;i<=n*2;++i){while(cc[i]--)printf("%d ",i),d[++n0]=i;}puts("");
    if(tp){
    sort(b+1,b+nn+1);
    for(int i=1;i<=nn;++i)assert(b[i]==d[i]&&b[i]);
    }else{
        for(int i=2;i<=n;++i)assert(d[i]==d[i-1]);
    }
}
void slv(int v){
    if(v<=2)return puts("-1"),void();
    n=v,an=nn=0;slv0(v,1);chk();
    sort(b+1,b+n+1);
    int p=1;while(b[p]!=b[p+1])++p;
    int K=1;while(K<n)K*=2;
    assert(p<n&&b[p]!=K);
    cz(b[p],b[p]),b[p]=0,b[p+1]*=2;
    for(int i=1;i<=n;++i)if(b[i]){
        int x=b[i];while(x!=K)cz(x,0),cz(x,x),x*=2;
    }
    cz(0,K);
    chk(0);
    printf("%d\n",an);for(int i=1;i<=an;++i)printf("%d %d\n",jg[i][0],jg[i][1]);
}

int main(){
    int ca;cin>>ca;while(ca--){int x;scanf("%d",&x);slv(x);}
    return 0;
}