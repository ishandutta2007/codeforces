#include<bits/stdc++.h>
using namespace std;
#define uu unsigned
#define scanf abc=scanf
#define fre(x) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
#define forg(i,x) for(int i=fir[x];i;i=nxt[i])
int abc;
typedef pair<int,int>pii;
typedef long long ll;
typedef uu long long ull;
typedef vector<int>VI;
inline int rd(int l,int r){return rand()%(r-l+1)+l;}

const int mxn=2e5+3;
int n,a[mxn],m;

int main(){
    cin>>n>>m;for(int i=1;i<=n;++i)cin>>a[i];
    if(n>m)return puts("0"),0;
    ll res=1;for(int i=1;i<=n;++i)for(int j=i+1;j<=n;++j)res=res*abs(a[i]-a[j])%m;printf("%lld\n",res);
    return 0;
}