#include<bits/stdc++.h>
using namespace std;
#define forg(i,x) for(register int i=fir[x];i;i=nxt[i])
#define uu unsigned
#define scanf a13=scanf
#define rint register int
#define fre(x) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
typedef long long ll;
typedef uu long long ull;
typedef pair<int,int>pii;
int a13;
inline int rd(int l,int r){return rand()%(r-l+1)+l;}

int n,c0,c1;
int main(){
    int ca;scanf("%d",&ca);while(ca--){
        scanf("%d",&n);int x;c0=c1=0;for(int i=1;i<=2*n;++i)scanf("%d",&x),x%2?++c0:++c1;
        puts(c0==c1?"Yes":"no");
    }
    return 0;
}