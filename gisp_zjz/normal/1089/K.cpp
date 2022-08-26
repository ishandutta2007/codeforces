#include<bits/stdc++.h>
using namespace std;
#define M 1000000
#define N 300005
#define ls (o<<1)
#define rs (o<<1)+1
struct pa {
    long long b,v,s;
}f[M*4+5],ans;
long long a[N],n;
char c[N];
inline void up(long long o,long long l,long long r) {
    long long mid=(l+r)>>1;
    if (!(f[ls].b|f[rs].b)) {
        f[o].b=0;
        return ;
    }
    if (!(f[ls].b&f[rs].b)) {
        if (f[ls].b) f[o]=f[ls];
        else f[o]=f[rs],f[o].s+=(mid-l+1);
        return ;
    }
    f[o].b=1;
    mid++;
    if (f[ls].v-mid>=f[rs].s) f[o].v=f[rs].v+(f[ls].v-mid)-f[rs].s,f[o].s=f[ls].s;
    else f[o].v=f[rs].v,f[o].s=f[ls].s+f[rs].s+(mid-f[ls].v);
}
inline void change(long long o,long long l,long long r,long long ll,long long p) {
    if (l==r) {
        f[o].b=1;
        f[o].v=l+p;
        f[o].s=0;
        return ;
    }
    long long mid=(l+r)>>1;
    if (ll<=mid) change(o*2,l,mid,ll,p);
    else change(o*2+1,mid+1,r,ll,p);
    up(o,l,r);
}
inline void del(long long o,long long l,long long r,long long ll) {
    if (l==r) {
        f[o].b=0;
        return ;
    }
    long long mid=(l+r)>>1;
    if (ll<=mid) del(o*2,l,mid,ll);
    else del(o*2+1,mid+1,r,ll);
    up(o,l,r);
}
inline void combine(pa &x,pa y,long long mid) {
    if (!y.b) return ;
    if (!x.b) {
        x=y,x.s+=mid;
        return ;
    }
    mid++;
    if (x.v-mid>=y.s) {
        x.v=y.v+(x.v-mid)-y.s;
        return ;
    }
    x.s+=y.s+mid-x.v;
    x.v=y.v;

}
inline void ask(long long o,long long l,long long r,long long ll,long long rr) {
    if (l==l&&r==rr) {
        combine(ans,f[o],l-1);
        return ;
    }
    long long mid=(l+r)>>1;
    if (rr<=mid) ask(o*2,l,mid,ll,rr);
    else if (ll>mid) ask(o*2+1,mid+1,r,ll,rr);
    else {
        ask(o*2,l,mid,ll,mid);
        ask(o*2+1,mid+1,r,mid+1,rr);
    }
}
inline long long ask(long long x) {
    ans.b=ans.v=ans.s=0;
    ask(1,1,M,1,x);
    if (!ans.b) ans.v=0;
    return max(0ll,ans.v-x);
}
int main() {
    //freopen("k.in","r",stdin);
    scanf("%lld",&n);
    for (long long i=1;i<=n;i++) {
        scanf("%s",c);
        long long x;
        if (c[0]=='?') {
            scanf("%lld",&x);
            printf("%lld\n",ask(x));
        }
        else if (c[0]=='+') {
            scanf("%lld%lld",&a[i],&x);
            change(1,1,M,a[i],x);
        }
        else {
            scanf("%lld",&x);
            del(1,1,M,a[x]);
        }
    }
}