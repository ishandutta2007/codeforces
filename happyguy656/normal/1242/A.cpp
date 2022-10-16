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

ll n;
ll gg(){
    if(n==1)return 1;
    for(int i=2;1ll*i*i<=n;++i)if(n%i==0){
        while(n%i==0)n/=i;return n==1?i:1;
    }
    return n;
}
int main(){
    scanf("%lld",&n);printf("%lld\n",gg());
    return 0;
}