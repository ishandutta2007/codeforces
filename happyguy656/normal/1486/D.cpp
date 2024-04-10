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

const int mxn=2e5+3;
int n,k,a[mxn],sum[mxn];
inline bool can(int x){
    for(int i=1;i<=n;++i)sum[i]=sum[i-1]+(a[i]>x?1:-1);
    for(int i=k,mn=1e9;i<=n;++i){
        mn=min(mn,sum[i-k]);if(sum[i]>mn)return 1;
    }
    return 0;
}

int main(){
    scanf("%d%d",&n,&k);for(int i=1;i<=n;++i)scanf("%d",a+i);
    int l=1,r=n,mid;
    while(l<r){
        mid=(l+r)>>1;
        if(can(mid))l=mid+1;else r=mid;
    }
    printf("%d\n",l);
    return 0;
}