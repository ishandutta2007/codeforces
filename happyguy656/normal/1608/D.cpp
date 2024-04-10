#include<bits/stdc++.h>
using namespace std;
#define uu unsigned
#define fre(x) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
#define scanf abc=scanf
#define forg(i,x) for(int i=fir[x];i;i=nxt[i])
int abc;
typedef long long ll;
typedef uu long long ull;
typedef pair<int,int>pii;
typedef vector<int>VI;
mt19937 rnd((ull)(new char));
int rd(int l,int r){uniform_int_distribution<>ee(l,r);return ee(rnd);}
void NC(ull k){cout<<(k>>20)<<endl;}

const int mxn=1e5+3,mod=998244353;
ll por(ll x,int y=mod-2){ll r=1;for(;y;y>>=1){if(y&1)r=r*x%mod;x=x*x%mod;}return r;}
ll jc[mxn],inv[mxn],ans;
char ss[9];int b[mxn][2];
ll C(int x,int y){if(x<y||y<0)return 0;return jc[x]*inv[y]%mod*inv[x-y]%mod;}
int gg(char c){if(c=='?')return 0;if(c=='B')return 1;return -1;}
int n,n1,n2,c3,x;
ll calc(int c1,int c2){
    return C(c1+c2,c2-x);
}
ll ee(){
    for(int i=1;i<=n;++i)if(b[i][0]&&b[i][1]&&b[i][0]==b[i][1])return 0;
    int cc=0;for(int i=1;i<=n;++i)cc+=b[i][0]==0&&b[i][1]==0;
    return por(2,cc);
}
int e1(){
    for(int i=1;i<=n;++i)if(b[i][0]==1||b[i][1]==-1)return 0;
    return 1;
}
int e2(){
    for(int i=1;i<=n;++i)if(b[i][0]==-1||b[i][1]==1)return 0;
    return 1;
}
int main(){
    n=mxn-1;jc[0]=1;for(int i=1;i<=n;++i)jc[i]=jc[i-1]*i%mod;inv[n]=por(jc[n]);for(int i=n;i;--i)inv[i-1]=inv[i]*i%mod;
    cin>>n;for(int i=1;i<=n;++i)scanf("%s",ss),b[i][0]=gg(ss[0]),b[i][1]=gg(ss[1]);
    for(int i=1;i<=n;++i){
        if(b[i][0]&&b[i][1]){if(b[i][0]==b[i][1])x+=b[i][0];}
        else if(b[i][0]==1||b[i][1]==1)++n1;else if(b[i][0]==-1||b[i][1]==-1)++n2;
        else ++c3;
    }    
    for(int i=0;i<=c3;++i)ans+=calc(n1+i,n2+c3-i)*C(c3,i),ans%=mod;
    ans-=ee();
    ans+=e1()+e2();
    ans=(ans%mod+mod)%mod;printf("%lld\n",ans);
    return 0;
}