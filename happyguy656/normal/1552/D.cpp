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

int a[13],n,sm[1<<10];
bool can(){
    int U=(1<<n)-1;
    for(int i=1;i<=U;++i)for(int j=0;j<n;++j)if(i>>j&1){sm[i]=sm[i^(1<<j)]+a[j+1];break;}
    for(int z=1;z<(1<<n);++z)for(int h=U^z;~h;--h){
        h&=U^z;
        if(sm[z]==sm[h])return 1;
    }
    return 0;
}
int main(){
    int ca;scanf("%d",&ca);while(ca--){
        scanf("%d",&n);for(int i=1;i<=n;++i)scanf("%d",a+i),a[i]=abs(a[i]);
        puts(can()?"Yes":"nO");
    }
    
    return 0;
}