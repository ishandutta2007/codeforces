#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int M=998244353;
const int maxn=234567;
int inv[105],n,q,a[maxn],ans;
int pow_(int x,int y){int ret=1;while (y){if (y&1) ret=1ll*ret*x%M;x=1ll*x*x%M;y>>=1;}return ret;}
void add(int &x,int y){x+=y;if(x>=M)x-=M;}
void sub(int &x,int y){x-=y;if(x<0) x+=M;}
struct node{
    int val,sum;
}b[maxn*4],o;
node _merge(node u,node v){
    node tmp;
    tmp.val=(1ll*u.val*v.sum+v.val)%M;
    tmp.sum=1ll*u.sum*v.sum%M;
    return tmp;
}
void build(int x,int l,int r){
    if (l==r){
        b[x].val=b[x].sum=100ll*inv[a[l]]%M;
        return;
    }
    int mid=(l+r)/2;
    build(x*2,l,mid);
    build(x*2+1,mid+1,r);
    b[x]=_merge(b[x*2],b[x*2+1]);
}
node qry(int x,int l,int r,int ll,int rr){
    if (ll>rr) return o;
    if (l>=ll&&r<=rr) return b[x];
    int mid=(l+r)/2;
    if (rr<=mid) return qry(x*2,l,mid,ll,rr);
    if (ll>mid) return qry(x*2+1,mid+1,r,ll,rr);
    return _merge(qry(x*2,l,mid,ll,rr),qry(x*2+1,mid+1,r,ll,rr));
}
set <int> S;
int main(){
    scanf("%d%d",&n,&q); o=(node){0,1};
    inv[1]=1; for (int i=2;i<=100;i++) inv[i]=M-1ll*(M/i)*inv[M%i]%M;
    for (int i=1;i<=n;i++) scanf("%d",&a[i]);
    build(1,1,n); ans=qry(1,1,n,1,n).val;
    S.insert(1); S.insert(n+1);
    for (int i=1;i<=q;i++){
        int x;scanf("%d",&x);
        if (S.find(x)==S.end()){
            auto tmp=S.lower_bound(x);
            int r=*tmp; tmp--;
            int l=*tmp;
            sub(ans,qry(1,1,n,l,r-1).val);
            add(ans,qry(1,1,n,l,x-1).val);
            add(ans,qry(1,1,n,x,r-1).val);
            S.insert(x);
        } else {
            S.erase(S.find(x));
            auto tmp=S.lower_bound(x);
            int r=*tmp; tmp--;
            int l=*tmp;
            add(ans,qry(1,1,n,l,r-1).val);
            sub(ans,qry(1,1,n,l,x-1).val);
            sub(ans,qry(1,1,n,x,r-1).val);
        }
        printf("%d\n",ans);
    }
    return 0;
}