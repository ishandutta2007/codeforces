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
int n,a[mxn],vs[mxn],tim[mxn],b[mxn],c[mxn],d[mxn],nn;
int main(){
    int ca;scanf("%d",&ca);while(ca--){
        scanf("%d",&n);for(int i=1;i<=n;++i)scanf("%d",a+i),b[i]=vs[i]=0;
        int re=0;for(int i=1;i<=n;++i)re+=!vs[a[i]],++vs[a[i]],tim[a[i]]=i;
        printf("%d\n",re);
        if(re!=n-1){
            for(int i=1;i<=n;++i)if(vs[i])b[tim[i]]=i;
            nn=0;
            for(int i=1;i<=n;++i)if(!b[i])c[++nn]=i,d[nn]=0;
            for(int i=1;i<=nn;++i){
                int x=c[i];
                if(!vs[x])d[i]=x,vs[x]=-1;
            }
            for(int i=1,p=1;i<=nn;++i)if(!d[i]){
                int x=c[i];
                while(vs[p])++p;
                vs[p]=-1,d[i]=p;
            }
            for(int i=1;i<=nn;++i)b[c[i]]=i!=nn?d[i+1]:d[1];
            
        }else{
            int x=0,y=0;for(int i=1;i<=n;++i)if(vs[i]==0)x=i;else if(vs[i]==2)y=i;
            int p1=0,p2=0;for(int i=1;i<=n;++i)if(vs[a[i]]==2)(p1?p2:p1)=i;
            assert(p1&&p2);
            for(int i=1;i<=n;++i)if(vs[a[i]]==1)b[i]=a[i];
            if(x==p1||y==p2)swap(x,y);
            b[p1]=x,b[p2]=y;
        }
        for(int i=1;i<=n;++i)printf("%d ",b[i]);puts("");
    }
    return 0;
}