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

const int mxn=2e5+3,mod=1e9+7;
ll por(ll x,int y=mod-2){ll r=1;for(;y;y>>=1){if(y&1)r=r*x%mod;x=x*x%mod;}return r;}
int n,a[mxn];
ll ans;
int gg(int x){int c=0;while(x%2==0)x>>=1,++c;return c;}
int main(){
    cin>>n;int cc=0;for(int i=1,x;i<=n;++i){scanf("%d",&x);a[i]=gg(x);cc+=a[i]!=0;}
    sort(a+1,a+n+1);ans=por(2,n)-por(2,cc);
    for(int l=1,r;l<=n;l=r+1){
        r=l;while(r!=n&&a[r+1]==a[l])++r;
        if(a[l]&&l!=r){
            int k=r-l+1;
            ans+=(por(2,k-1)-1)*por(2,n-r);ans%=mod;
        }
    }
    ans=(ans%mod+mod)%mod;cout<<ans<<endl;
    return 0;
}