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

const int mxn=1e5+3;
int n,a[mxn],b[mxn];

int main(){
    int ca;scanf("%d",&ca);while(ca--){
        int A;long long B;
        scanf("%d%lld%d",&A,&B,&n);for(int i=1;i<=n;++i)scanf("%d",a+i);for(int i=1;i<=n;++i)scanf("%d",b+i);
        int mx=1;for(int i=2;i<=n;++i)if(a[i]>a[mx])mx=i;
        bool ok=1;
        for(int i=1;i<=n;++i)if(i!=mx){
            long long k=(b[i]-1)/A+1;
            B-=k*a[i];
            if(B<=0){ok=0;break;}
        }
        int k=(b[mx]-1)/A;B-=1ll*k*a[mx];
        if(B>0&&ok)puts("YES");
        else puts("NO");
    }
    return 0;
}