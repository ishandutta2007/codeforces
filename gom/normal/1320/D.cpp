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
int n,q;
string s;
ll hp1=319217,hq1=7331423,hv1=10007,hm1=998244353,hpw1[N]={1};
ll hp2=271941,hq2=9931207,hv2=9371,hm2=1e9+7,hpw2[N]={1};
struct node{
    ll h11,h12,h21,h22; int l,l2; // ,  
    node(){h11=h12=h21=h22=l=l2=0;}
    node(ll a,ll b,ll c,ll d,int e,int f){
        h11=a; h12=b; h21=c; h22=d; l=e; l2=f;
    }
};
node mrg(node n1,node n2){
    ll h11=0,h12=0,h21=0,h22=0;
    if(n1.l&1){
        h11=(n1.h11+n2.h12*hpw1[n1.l2]%hm1)%hm1;
        h12=(n1.h12+n2.h11*hpw1[n1.l2]%hm1)%hm1;
        h21=(n1.h21+n2.h22*hpw2[n1.l2]%hm2)%hm2;
        h22=(n1.h22+n2.h21*hpw2[n1.l2]%hm2)%hm2;
    }
    else{
        h11=(n1.h11+n2.h11*hpw1[n1.l2]%hm1)%hm1;
        h12=(n1.h12+n2.h12*hpw1[n1.l2]%hm1)%hm1;
        h21=(n1.h21+n2.h21*hpw2[n1.l2]%hm2)%hm2;
        h22=(n1.h22+n2.h22*hpw2[n1.l2]%hm2)%hm2;
    }
    int l=n1.l+n2.l,l2=n1.l2+n2.l2;
    return node(h11,h12,h21,h22,l,l2);
}
node tree[4*N];
void init(int nd,int l,int r){
    if(l==r){
        if(s[l]=='0') tree[nd]=node(hp1,hq1,hp2,hq2,1,1);
        else tree[nd]=node(0,0,0,0,1,0);
        return;
    }
    int m=(l+r)>>1;
    init(nd<<1,l,m); init(nd<<1|1,m+1,r);
    tree[nd]=mrg(tree[nd<<1],tree[nd<<1|1]);
}
node qry(int nd,int l,int r,int s,int e){
    if(r<s||e<l) return node(0,0,0,0,0,0);
    if(s<=l&&r<=e) return tree[nd];
    int m=(l+r)>>1;
    return mrg(qry(nd<<1,l,m,s,e),qry(nd<<1|1,m+1,r,s,e));
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    cin>>n>>s>>q;
    for(int i=1;i<=n+1;i++){
        hpw1[i]=hpw1[i-1]*hv1%hm1;
        hpw2[i]=hpw2[i-1]*hv2%hm2;
    }
    s=" "+s;
    init(1,1,n);
    for(int l1,l2,l,i=1;i<=q;i++){
        cin>>l1>>l2>>l;
        node n1=qry(1,1,n,l1,l1+l-1),n2=qry(1,1,n,l2,l2+l-1);
        if(n1.h11==n2.h11&&n1.h21==n2.h21) cout<<"Yes\n";
        else cout<<"No\n";
    }
    return 0;
}