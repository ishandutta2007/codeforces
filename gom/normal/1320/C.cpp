#include <bits/stdc++.h>
#pragma GCC target("avx2")
#pragma GCC optimization("O3")
#pragma GCC optimization("unroll-loops")
#define x first
#define y second
#define mp make_pair
using namespace std;
typedef long long ll;
typedef long double db;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<db,db> pdb;
typedef tuple<int,int,int> tii;
typedef tuple<ll,ll,ll> tll;
typedef tuple<int,int,int,ll> tup;
typedef vector<vector<ll>> mat;
const ll mod=998244353,inf=1e18;
const int N=2e5+5,M=55,K=1e5+5;
int n,m,p;
pll a[N],b[N];
tll c[N];
ll ans=-inf;
struct seg{
    ll tree[4*N]={0},lazy[4*N]={0};
    void pd(int nd,int l,int r){
        tree[nd]+=lazy[nd];
        if(l!=r){
            lazy[nd<<1]+=lazy[nd];
            lazy[nd<<1|1]+=lazy[nd];
        }
        lazy[nd]=0;
    }
    void upd(int nd,int l,int r,int s,int e,ll v){
        pd(nd,l,r);
        if(r<s||e<l) return;
        if(s<=l&&r<=e){
            lazy[nd]=v; pd(nd,l,r); return;
        }
        int m=(l+r)>>1;
        upd(nd<<1,l,m,s,e,v); upd(nd<<1|1,m+1,r,s,e,v);
        tree[nd]=max(tree[nd<<1],tree[nd<<1|1]);
    }
}tree;
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    cin>>n>>m>>p;
    for(int i=1;i<=n;i++) cin>>a[i].x>>a[i].y;
    for(int i=1;i<=m;i++) cin>>b[i].x>>b[i].y;
    sort(a+1,a+1+n); sort(b+1,b+1+m);
    for(int i=1;i<=m;i++) tree.upd(1,1,m,i,i,-b[i].y);
    for(int i=1;i<=p;i++) cin>>get<0>(c[i])>>get<1>(c[i])>>get<2>(c[i]);
    sort(c+1,c+1+p);
    for(int i=1,j=1;i<=n;){
        if(j>p||a[i].x<=get<0>(c[j])){
            ans=max(ans,tree.tree[1]-a[i].y);
            i++;
        } else{
            if(b[m].x<=get<1>(c[j])){
                j++; continue;
            }
            int L=1,R=m,res=m;
            while(L<=R){
                int M=(L+R)>>1;
                if(b[M].x>get<1>(c[j])){
                    res=M; R=M-1;
                } else L=M+1;
            }
            tree.upd(1,1,m,res,m,get<2>(c[j]));
            j++;
        }
    }
    cout<<ans;
    return 0;
}