#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
#define forg(i,x) for(register int i=fir[x];i;i=nxt[i])
#define uu unsigned
#define scanf a1234=scanf
#define rint register int
#define fre(x) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
int a1234;
inline void xxx(){for(;;);}
inline int rd(int l,int r){return rand()%(r-l+1)+l;}

int n;long long h[105];
inline bool can(){
    h[0]=-1;
    for(int i=1;i<=n;++i){
        if(h[i]<=h[i-1])return 0;
        int t=h[i-1]+1;
        h[i+1]+=h[i]-t,h[i]=t;
    }
    return 1;
}
int main(){
    int ca;scanf("%d",&ca);while(ca--){
        scanf("%d",&n);for(int i=1;i<=n;++i)scanf("%lld",h+i);
        puts(can()?"YES":"NO");
    }
    return 0;
}