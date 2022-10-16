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

int ca,n,a[19];
int main(){
    cin>>ca;while(ca--){
        scanf("%d",&n);for(int i=1;i<=n;++i)scanf("%d",a+i);
        int cc=0;
        for(int i=1;i<=n;++i){while(a[i]%2==0)a[i]>>=1,++cc;}
        ll p=1;for(int i=1;i<=n;++i)if(a[i]>a[p])p=i;
        ll ans=(1ll*a[p])<<cc;
        for(int i=1;i<=n;++i)if(i!=p)ans+=a[i];
        cout<<ans<<endl;
    }
    return 0;
}