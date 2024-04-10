/**
 *    author:  gary
 *    created: 22.05.2022 22:29:40
**/
#include<bits/stdc++.h>
#define rb(a,b,c) for(int a=b;a<=c;++a)
#define rl(a,b,c) for(int a=b;a>=c;--a)
#define rep(a,b) for(int a=0;a<b;++a)
#define LL long long
#define PB push_back
#define POB pop_back
#define II(a,b) make_pair(a,b)
#define FIR first
#define SEC second
#define SRAND mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define random(a) rng()%a
#define ALL(a) a.begin(),a.end()
#define check_min(a,b) a=min(a,b)
#define check_max(a,b) a=max(a,b)
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
const int N=1<<18;
const int MOD=1e9+7;
int n,q;
LL pre[N],a[N];
void add(int &A,int B){
    A+=B;
    if(A>=MOD) A-=MOD;
}
void sub(int &A,int B){
    A-=B;
    if(A<0) A+=MOD;
}
LL Getmod(LL x){
    if(x>=0) return x%MOD;
    return (x+(-x/MOD+1)*MOD)%MOD;
}
vector<pair<LL,int> > tree[N+N];
vector<int> prea[N+N],suma[N+N];
int query(int a,int b,LL x,int now=1,int l=1,int r=N+1){
    if(r<=a||l>=b) return 0;
    if(r<=b&&l>=a){
        int s=0;
        int i=lower_bound(ALL(tree[now]),II(x,0))-tree[now].begin();
        if(i!=0) add(s,Getmod(x)*suma[now][i-1]%MOD),sub(s,prea[now][i-1]);
        if(i==0) add(s,prea[now].back()),sub(s,Getmod(x)*suma[now].back()%MOD);
        else
        if(i!=tree[now].size()) add(s,prea[now].back()),sub(s,prea[now][i-1]),sub(s,Getmod(x)*suma[now].back()%MOD),add(s,Getmod(x)*suma[now][i-1]%MOD);
        return s;
    }
    int mid=(l+r)>>1;
    return (query(a,b,x,now<<1,l,mid)+query(a,b,x,now<<1|1,mid,r))%MOD;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>q;
    rb(i,1,n) cin>>a[i],a[i-1]=a[i]-a[i-1];
    rb(i,1,n) cin>>pre[i],pre[i]+=pre[i-1];
    rb(i,1,n) tree[i+N-1].emplace_back(pre[i],i);
    rl(i,N+N-1,1){
        int s;
        if(i<N){
        s=tree[i<<1].size()+tree[i<<1|1].size();
        tree[i].resize(s);
        prea[i].resize(s);
        suma[i].resize(s);
        merge(ALL(tree[i<<1]),ALL(tree[i<<1|1]),tree[i].begin());
        }
        else{
        s=tree[i].size();
        prea[i].resize(s);
        suma[i].resize(s);
        }
        rep(j,s) prea[i][j]=Getmod(pre[tree[i][j].second])*a[tree[i][j].second]%MOD;
        rep(j,s) suma[i][j]=a[tree[i][j].second]%MOD;
        rep(j,s) if(j) add(prea[i][j],prea[i][j-1]),add(suma[i][j],suma[i][j-1]);
    }
    rb(i,1,q){
        int l,r;
        cin>>l>>r;
        cout<<query(l,r,pre[l-1])<<endl;
    }
    return 0;
}