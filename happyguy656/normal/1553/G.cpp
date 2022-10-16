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

const int mxn=1e6+3;
int n,qn,a[mxn],vs[mxn],m;
struct bcj{int fa[mxn];void init(){for(int i=1;i<=m;++i)fa[i]=i;}int find(int x){while(x!=fa[x])x=fa[x]=fa[fa[x]];return x;}void mer(int x,int y){fa[find(x)]=find(y);}}u;
int mv[mxn],pr[mxn],pt;
void fj(int x,int a[]){
    int&n=a[0];n=0;while(x>1){a[++n]=mv[x];int k=mv[x];while(x%k==0)x/=k;}
}
map<pii,bool>mp;
void add(int x,int y){x=u.find(x),y=u.find(y);if(x>y)swap(x,y);mp[pii(x,y)]=1;}
bool exi(int x,int y){x=u.find(x),y=u.find(y);if(x>y)swap(x,y);return mp[pii(x,y)];}
int f1[9],f2[9];
int cal(int x,int y){
    if(u.find(a[x])==u.find(a[y]))return 0;
    x=a[x],y=a[y];fj(x,f1),fj(y,f2);
    for(int i=1;i<=f1[0];++i)for(int j=1;j<=f2[0];++j)if(exi(f1[i],f2[j]))return 1;
    return 2;
}
int main(){
    scanf("%d%d",&n,&qn);for(int i=1;i<=n;++i)scanf("%d",a+i),m=max(m,a[i]),vs[a[i]]=1;++m;u.init();
    for(int i=2;i<=m;++i){
        if(!mv[i])mv[i]=i,pr[++pt]=i;
        for(int j=1;j<=pt&&i*pr[j]<=m&&pr[j]<=mv[i];++j)mv[i*pr[j]]=pr[j];
    }
    for(int i=2;i<=m;++i)for(int j=i;j<=m;j+=i)if(vs[j])u.mer(i,j);
    for(int t=1;t<=n;++t){
        fj(a[t],f1),fj(a[t]+1,f2);
        for(int i=1;i<=f1[0];++i)for(int j=1;j<=f2[0];++j)add(f1[i],f2[j]);
        for(int i=1;i<=f2[0];++i)for(int j=i-1;j;--j)add(f2[i],f2[j]);
    }
    while(qn--){
        int x,y;scanf("%d%d",&x,&y);printf("%d\n",cal(x,y));
    }
    return 0;
}