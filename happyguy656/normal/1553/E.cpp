#include<bits/stdc++.h>
using namespace std;
#define forg(i,x) for(int i=fir[x];i;i=nxt[i])
#define uu unsigned
#define scanf abc=scanf
#define fre(x) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
typedef long long ll;
typedef uu long long ull;
typedef pair<int,int>pii;
int abc;
inline int rd(int l,int r){return rand()%(r-l+1)+l;}

const int mxn=3e5+3;
int n,m,a[mxn],cc[mxn],b[mxn],po[mxn];
bool chk(int x){
    for(int i=1;i<=n;++i)b[i]=a[(i+x-1)%n+1],po[b[i]]=i;
    int c=0;
    for(int i=1;i<=n;++i)if(b[i]!=i)++c,po[b[i]]=po[i],swap(b[i],b[po[i]]);
    return c<=m;
}
int main(){
    int ca;scanf("%d",&ca);while(ca--){
        scanf("%d%d",&n,&m);for(int i=1;i<=n;++i)scanf("%d",a+i),cc[i-1]=0;
        for(int i=1;i<=n;++i)++cc[(i-a[i]+n)%n];
        int re[5],rn=0;
        for(int i=0;i<n;++i)if(cc[i]>=n/3&&chk(i))re[++rn]=i;
        printf("%d ",rn);for(int i=1;i<=rn;++i)printf("%d ",re[i]);puts("");
    }
    return 0;
}