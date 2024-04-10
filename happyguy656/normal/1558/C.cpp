#include<bits/stdc++.h>
using namespace std;
#define uu unsigned
#define scanf abc=scanf
#define forg(i,x) for(int i=fir[x];i;i=nxt[i])
#define fre(x) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
int abc;
typedef long long ll;
typedef uu long long ull;
typedef vector<int>VI;
typedef pair<int,int>pii;
int rd(int l,int r){return rand()%(r-l+1)+l;}

const int mxn=3003;
int n,a[mxn],an,ans[mxn*5],po[mxn];
void cz(int x){ans[++an]=x;for(int i=1;i*2<x;++i)swap(a[i],a[x+1-i]),swap(po[a[i]],po[a[x+1-i]]);}
bool wk(){
    an=0;
    for(int i=1;i<=n;++i)if((i&1)^(a[i]&1))return 0;
    for(int t=n;t>1;t-=2){
        cz(po[t]),cz(po[t-1]-1),cz(po[t-1]+1),cz(3),cz(t);
    }
    for(int i=1;i<=n;++i)assert(a[i]==i);
    return 1;
}
int main(){
    int ca;scanf("%d",&ca);while(ca--){
        scanf("%d",&n);for(int i=1;i<=n;++i)scanf("%d",a+i),po[a[i]]=i;
        if(wk()){printf("%d\n",an);for(int i=1;i<=an;++i)printf("%d ",ans[i]);puts("");}else puts("-1");
    }
    return 0;
}