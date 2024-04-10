#include<bits/stdc++.h>
using namespace std;
typedef pair<long long,int> pii;
#define forg(i,x) for(register int i=fir[x];i;i=nxt[i])
#define uu unsigned
#define scanf a1234=scanf
#define rint register int
#define fre(x) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
int a1234;
inline void xxx(){for(;;);}
inline int rd(int l,int r){return rand()%(r-l+1)+l;}
typedef long long ll;


const int mxn=1e5+3,mxm=5003;
ll a[mxn],now[mxn];
int n,m,k,hh,h[mxn];

queue<int>q[mxm];
int tim[mxm];
inline bool work(ll x){
    for(int i=0;i<=m;++i)q[i]=queue<int>();
    for(int i=1;i<=m;++i)tim[i]=k; tim[0]=tim[m+1]=0;
    for(int i=1;i<=n;++i){
        now[i]=x;
        ll k=now[i]/a[i];
        if(k<m)q[k].push(i);
    }
    
    
    for(int i=0;i<=m;++i){
        int &re=tim[i];
        while(q[i].size()&&re){
            int x=q[i].front();
            while(re&&now[x]-a[x]*(i+1)<0)now[x]+=hh,--re;
            if(now[x]-a[x]*(i+1)>=0){
                q[i].pop();
                ll k=now[x]/a[x];
                if(k<m)q[k].push(x);
            }
        }
        if(q[i].size())return 0;
        tim[i+1]+=re;
    }
    int re=tim[m];
    for(int i=1;i<=n;++i){
        now[i]-=m*a[i];assert(now[i]>=0);
        while(now[i]<h[i]&&re)--re,now[i]+=hh;
        if(now[i]<h[i])return 0;
    }
    return 1;
}

int main(){
    scanf("%d%d%d%d",&n,&m,&k,&hh);
    ll l=0,r=0,mid;
    for(int i=1;i<=n;++i)scanf("%d%lld",h+i,a+i),l=max(l,a[i]),r=max(r,h[i]+m*a[i]);
    while(l<r){
        mid=(l+r)>>1;
        if(work(mid))r=mid;
        else l=mid+1;
    }
    printf("%lld\n",l);
    return 0;
}