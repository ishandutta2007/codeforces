#include<bits/stdc++.h>
using namespace std;
typedef pair<double,int>pii;
#define forg(i,x) for(int i=first[x];i;i=nxt[i])
#define od(x) ((x)&1)
#define ev(x) (od(x)^1)
#define fi first
#define se second
#define uu unsigned
#define fre(x) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
inline void xxx(){}
inline int rd(int l,int r){return rand()%(r-l+1)+l;}

const int mxn=103;
int n;double g[mxn],a[mxn];
double ans;
priority_queue<pii>q;

int main(){
    double gg=1;
    scanf("%d",&n);for(int i=1,x;i<=n;++i)scanf("%d",&x),g[i]=x/100.0,gg*=g[i],a[i]=g[i];
    ans=n*gg;
    for(int i=1;i<=n;++i)q.push(pii((1-a[i])/a[i]*g[i],i));
    for(int T=1;T<=3e5;++T){
        double x=q.top().fi;int i=q.top().se; q.pop();
        ans+=gg*x*(T+n);
        gg/=a[i];
        a[i]+=(1-a[i])*g[i];
        gg*=a[i];
//        double aa=a[xh]+gg*x;
  //      gg=gg/a[xh]*aa;
    //    a[xh]=aa;
        q.push(pii((1-a[i])/a[i]*g[i],i));
    }
    printf("%.7f\n",ans);
    return 0;
}