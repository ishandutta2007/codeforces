#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
#define forg(i,x) for(int i=first[x];i;i=nxt[i])
#define uu unsigned
#define fi first
#define se second
#define ran() ((unsigned)rand())
#define lam(z,k) [&](const z &a,const z &b){ return k; }
#define od(x) ((x)&1)
#define ev(x) (od(x)^1)
#define scanf a1234=scanf
int a1234;
char buf[1<<18],*bufs=buf,*buft=buf;
inline int gc(){
    return bufs==buft&&(buft=(bufs=buf)+fread(buf,1,1<<18,stdin)),bufs==buft?-1:*bufs++;
}
inline void xxx(){for(;;);}

const int mxn=1e5+3;int n,a,b,c,h[mxn];
long long sum[mxn];

inline long long calc(long long x){
    int pos=lower_bound(h+1,h+n+1,x)-h-1;
    long long cnt1=x*pos-sum[pos],cnt2=sum[n]-sum[pos]-(n-pos)*x,cnt3=min(cnt1,cnt2);
    return cnt3*c+(cnt1-cnt3)*a+(cnt2-cnt3)*b;
}

inline long long sanfen(int l,int r){
    int lmid,rmid;
    long long ans=0x3f3f3f3f3f3f3f3fll;
    while(l+5<r){
        lmid=l+(r-l+1)/3,rmid=r-(r-l+1)/3;
        if(calc(lmid)>calc(rmid))l=lmid;else r=rmid;
//        printf("%d %d\n",l,r);
    }
    for(int i=l;i<=r;++i)ans=min(ans,calc(i));
    return ans;
//    return min(calc(l),calc(l+1));
}

int main(){
    scanf("%d%d%d%d",&n,&a,&b,&c);for(int i=1;i<=n;++i)scanf("%d",h+i);
    c=min(c,a+b);sort(h+1,h+n+1);
    for(int i=1;i<=n;++i)sum[i]=sum[i-1]+h[i];
//    for(int i=0;i<=h[n]+1;++i)printf("%lld ",calc(i));puts("");
    printf("%lld\n",sanfen(h[1],h[n]));
    return 0;
}