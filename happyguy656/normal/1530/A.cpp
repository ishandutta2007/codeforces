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

int main(){
    int ca;scanf("%d",&ca);while(ca--){
        int x,mx=0;scanf("%d",&x);while(x)mx=max(mx,x%10),x/=10;printf("%d\n",mx);
    }
    return 0;
}