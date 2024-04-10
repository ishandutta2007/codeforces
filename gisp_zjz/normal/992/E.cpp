#include<bits/stdc++.h>
#define maxn 300001

using namespace std;
typedef long long ll;
ll a[maxn],b[maxn],n,k,r,q,p;

ll qry(int x){
    ll rt=0;
    while (x){
        rt+=b[x];
        x-=x&(-x);
    }
    return rt;
}

void add(int x,ll y){
    while (x<maxn){
        b[x]+=y;
        x+=x&(-x);
    }
}

int f(int l,int r){
    if (l+1==r) return qry(r)==qry(l)*2?r:-1;
    int rt=-1,mid=(l+r)>>1;
    if (qry(mid)>=qry(l)*2) rt=max(rt,f(l,mid));
    if (qry(r)>=qry(mid)*2) rt=max(rt,f(mid,r));
    return rt;
}

int main(){
    cin >> n >> q;
    for (int i=1;i<=n;i++) scanf("%d",&a[i]);
    for (int i=1;i<=n;i++) add(i,a[i]);
    while (q--){
        scanf("%I64d%I64d",&k,&r);
        add(k,r-a[k]); a[k]=r;
        printf("%d\n",f(0,n));
    }
    return 0;
}