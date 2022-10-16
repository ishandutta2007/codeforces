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

const int mxn=2e5+3,mod=998244353;
ll por(ll x,int y=mod-2){ll r=1;for(;y;y>>=1){if(y&1)r=r*x%mod;x=x*x%mod;}return r;}
int n,m,nn,b[mxn][2],d[mxn];
ll jc[mxn*2],inv[mxn*2];
struct zZz{
    int a[mxn],tk[mxn],nn;
    void add(int x){tk[++nn]=x;for(;x<=n;x+=x&-x)++a[x];}
    int ask(int k){
        int p=0,z=0;
        for(int i=1<<17;i;i>>=1){
            if(p+i>n)continue;p+=i;
            if(p-z-a[p]>=k)p-=i;else z+=a[p];
        }
        return p+1;
    }
    void clr(){while(nn){int x=tk[nn--];for(;x<=n;x+=x&-x)a[x]=0;}}
}ar;
priority_queue<int>q;
ll C(int x,int y){return jc[x]*inv[y]%mod*inv[x-y]%mod;}
int main(){
    n=2*mxn-1;jc[0]=inv[0]=1;for(int i=1;i<=n;++i)jc[i]=jc[i-1]*i%mod;inv[n]=por(jc[n]);for(int i=n-1;i;--i)inv[i]=inv[i+1]*(i+1)%mod;
    int ca;scanf("%d",&ca);while(ca--){
        ar.clr();
        scanf("%d%d",&n,&m);for(int i=1;i<=m;++i)scanf("%d%d",&b[i][0],&b[i][1]);b[m+1][0]=n+1;if(b[1][0]!=1)b[0][0]=b[0][1]=1;else b[0][0]=0;
        nn=0;int ls=n+1,nm=0;q=priority_queue<int>();d[n+1]=-1;
        for(int t=m;~t&&b[t][0];--t){
            int x=b[t][0],y=b[t][1],k=ar.ask(y),k2=ar.ask(x+1),xx=b[t+1][0];
            ar.add(k);d[k]=x;q.push(k);
            if(x+1!=xx){
                while(q.size()&&q.top()>k2){
                    k=q.top();q.pop();
                    if(k+1==ls)nm+=d[k]>d[k+1];else nm+=xx-1>d[ls],xx-=ls-k+1,nm+=d[k]>xx;
                    ls=k;
                }
                nm+=xx-1>d[ls];
                ls=k2,d[k2]=x+1;
            }
        }
        for(int i=ls-1;i;--i)nm+=d[i]>d[i+1];
        printf("%lld\n",C(2*n-nm,n));
    }
    return 0;
}