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

const int mxn=5e5+3,mod=998244353,B=10;
int n,m,a[mxn],b[mxn];
ll h1[mxn],mi[mxn],h2[mxn];
ull h3[mxn],h4[mxn],im[mxn];
char ss[mxn];
ll g1(int l,int r){return (h1[r]-h1[l-1]*mi[r-l+1]+1ll*mod*mod)%mod;}
ll g2(int l,int r){return (h2[r]-h2[l-1]*mi[r-l+1]+1ll*mod*mod)%mod;}
ull g3(int l,int r){return h3[r]-h3[l-1]*im[r-l+1];}
ull g4(int l,int r){return h4[r]-h4[l-1]*im[r-l+1];}

bool chk0(int k1,int k2,int l){return g1(k1,k1+l-1)==g2(k2,k2+l-1)&&g3(k1,k1+l-1)==g4(k2,k2+l-1);}
int lcp(int k1,int k2){
    int l=0,r=min(n-k1+1,m-k2+1),md;while(l!=r){md=(l+r+1)>>1;if(chk0(k1,k2,md))l=md;else r=md-1;}
    return l;
}
int gw(int l,int r){
    if(l>r||l<=0||r>n)return -1;
    int k=1;
    if(r-l+1<m-1)return m;
    if(r-l+1==m-1){if(b[1]>1)return m;}
    else{
        int t=lcp(l,k);l+=t,k+=t;
        if(k>m||b[k]<a[l])return -1;
        if(b[k]>a[l]+1)return m-k+1;
        ++l;
    }
    int e=m-k+1;++k;
    int t=lcp(l,k);l+=t,k+=t;
    if(k>m||b[k]>a[l])return e;
    return e-1;
}
bool slv(int l1,int r1,int l2,int r2){
    if(l1>r1||l2>r2)return 0;if(l1<=0||r1>n)return 0;if(l2<=0||r2>n)return 0;
    if(g3(l1,r1)+g3(l2,r2)==g4(1,m)&&(g1(l1,r1)+g1(l2,r2)-g2(1,m))%mod==0)return printf("%d %d\n%d %d\n",l1,r1,l2,r2),1;
    return 0;
}

int main(){
    mi[0]=im[0]=1;for(int i=1;i<mxn;++i)mi[i]=mi[i-1]*B%mod,im[i]=im[i-1]*B;
    scanf("%s",ss+1);n=strlen(ss+1);for(int i=1;i<=n;++i)a[i]=ss[i]-'0',h1[i]=(h1[i-1]*B+a[i])%mod,h3[i]=h3[i-1]*B+a[i];
    scanf("%s",ss+1);m=strlen(ss+1);for(int i=1;i<=m;++i)b[i]=ss[i]-'0',h2[i]=(h2[i-1]*B+b[i])%mod,h4[i]=h4[i-1]*B+b[i];
    for(int i=1;i<=n;++i){
        int k=gw(i-m+2,i);if(slv(i-m+2,i,i+1,i+k))return 0;
        k=gw(i-m+1,i);if(slv(i-m+1,i,i+1,i+k))return 0;
        k=gw(i,i+m-2);if(slv(i-k,i-1,i,i+m-2))return 0;
        k=gw(i,i+m-1);if(slv(i-k,i-1,i,i+m-1))return 0;
    }
    assert(0);
    return 0;
}