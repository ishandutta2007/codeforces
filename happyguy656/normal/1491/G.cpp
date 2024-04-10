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

const int mxn=2e5+3;
int n,a[mxn],be[mxn],bn,vs[mxn],b[mxn];
void sw(int x,int y){swap(a[x],a[y]),swap(b[a[x]],b[a[y]]),printf("%d %d\n",x,y);}
void wk(int x,int y){
    while(!(a[x]==x&&a[y]==y)){
        if(a[x]!=y)sw(x,a[x]);else sw(y,a[y]);
    }
}
int main(){
    scanf("%d",&n);for(int i=1;i<=n;++i)scanf("%d",a+i),b[a[i]]=i;
    for(int i=1;i<=n;++i)if(!be[i]){be[i]=++bn;for(int j=a[i];j!=i;j=a[j])be[j]=bn;}
    if(bn==1){printf("%d\n",n+1);sw(1,2);if(a[2]==2)sw(2,3);else sw(1,a[2]);wk(1,2);return 0;}
    else printf("%d\n",bn%2==0?n:n+1);
    for(int i=1;i<=n;++i)if(!vs[be[i]]){
        vs[be[i]]=1;
        for(int j=i+1;j<=n;++j)if(!vs[be[j]]){
            sw(i,j),wk(i,j),vs[be[j]]=1;goto tb;
        }
        sw(1,i),wk(1,i);
        tb:;
    }
    return 0;
}