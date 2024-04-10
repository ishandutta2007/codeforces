#include<bits/stdc++.h>
#define maxn 262155

using namespace std;
typedef long long ll;
const ll M=1000000007;
ll b[maxn],c[maxn],d[maxn],a[maxn],s[maxn],n,q,l,r,lf,rt;
ll sl,sr,sm,ans;
void add_(ll &x,ll y){
    x+=y;
    if (x>=M) x-=M; if (x<0) x+=M;
}
void add1(ll x,ll y){
    while (x<maxn) c[x]+=y,x+=x&(-x);
}
void add2(ll x,ll y){
    while (x<maxn) add_(d[x],y),x+=x&(-x);
}
ll qry1(ll x){
    ll res=0;
    while (x) res+=c[x],x-=x&(-x);
    return res;
}
ll qry2(ll x){
    ll res=0;
    while (x) res+=d[x],x-=x&(-x);
    return res%M;
}

int main(){
    cin >> n >> q;
    for (int i=1;i<=n;i++) {
        scanf("%I64d",&a[i]);
        a[i]+=n-i;
    }
    for (int i=1;i<=n;i++) {
        scanf("%I64d",&b[i]);
        add1(i,b[i]); add2(i,a[i]*b[i]%M);
    }
    while (q--){
        scanf("%I64d%I64d",&l,&r);
        if (l<0){
            l=-l; add1(l,-b[l]+r);
            add2(l,a[l]*(r-b[l])%M);
            b[l]=r;
        } else {
            l--; lf=l; rt=r;
            sl=qry1(l); sr=qry1(r);
            while (rt-lf>1){
                int mid=(lf+rt)/2; sm=qry1(mid);
                if (sm-sl>=sr-sm) rt=mid; else lf=mid;
            }
            ans=qry2(r)-qry2(lf)-(qry1(r)-qry1(lf))%M*a[rt]%M;
            ans+=(qry1(lf)-qry1(l))%M*a[rt]%M-qry2(lf)+qry2(l);
            printf("%I64d\n",(ans%M+M)%M);
        }
    }
    return 0;
}