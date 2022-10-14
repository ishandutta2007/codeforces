/**
 *    author:  gary
 *    created: 06.03.2022 17:47:58
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
const int MAXN=5e5+10;
int n,q;
long long a[MAXN];
long long b[MAXN];
long long A[3][MAXN];
struct RMQ {
  vector<vector<pair<long long,int>>> rmq;
  pair<long long,int> kInf = numeric_limits<pair<long long,int>>::max();
  void build(const vector<pair<long long,int>>& V) {
    int n = V.size(), on = 1, dep = 1;
    while (on < n) on *= 2, ++dep;
    rmq.assign(dep, V);
 
    for (int i = 0; i < dep - 1; ++i)
      for (int j = 0; j < n; ++j) {
        rmq[i + 1][j] = max(rmq[i][j], rmq[i][min(n - 1, j + (1 << i))]);
      }
  }
  pair<long long,int> query(int a, int b) {
    if (b <= a) return kInf;
    int dep = 31 - __builtin_clz(b - a);
    return max(rmq[dep][a], rmq[dep][b - (1 << dep)]);
  }
};
const int N=1<<19;
struct seg{
    struct node{
        long long best,maxa,maxb;
        node(){
            best=maxa=maxb=-1e18;
        }
        node(long long _,long long __,long long ___){
            best=_;
            maxa=__;
            maxb=___;
        }
    };
    node tree[N+N];
    node merge(node A,node B){
        node C;
        C.best=max(A.best,B.best);
        check_max(C.best,A.maxa+B.maxb);
        C.maxa=max(A.maxa,B.maxa);
        C.maxb=max(A.maxb,B.maxb);
        return C;
    }
    node query(int a,int b,int now=1,int l=1,int r=N+1){
        if(r<=a||l>=b){
            return node();
        }
        if(r<=b&&l>=a){
            return tree[now];
        }
        int mid=(l+r)>>1;
        return merge(query(a,b,now<<1,l,mid),query(a,b,now<<1|1,mid,r));
    }
    void upd(int pos){
        check_max(tree[pos].best,tree[pos].maxa+tree[pos].maxb);
        pos>>=1;
        while(pos){
            tree[pos]=merge(tree[pos<<1],tree[pos<<1|1]);
            pos>>=1;
        }
    }
    void modifya(int pos,long long val){
        pos+=N-1;
        check_max(tree[pos].maxa,val);
        upd(pos);
    }
    void modifyb(int pos,long long val){
        pos+=N-1;
        check_max(tree[pos].maxb,val);
        upd(pos);
    }
}tree1,tree2;
struct segment_tree
{
    LL tree[N+N];
    void clear(){
        rep(i,N+N) tree[i]=-1e18;
     }
    segment_tree(){
        clear();
    }
    void upd(int pos,long long val){
        pos+=N-1;
        while(pos){
            check_max(tree[pos],val);
            pos>>=1;
        }
    }
    LL query(int a,int b,int now=1,int l=1,int r=N+1){
        if(r<=a||l>=b) return -1e18;
        if(r<=b&&l>=a) return tree[now];
        int mid=(l+r)/2;
        return max(query(a,b,now<<1,l,mid),query(a,b,now<<1|1,mid,r));
    }
}tree3;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>q;
    rep(i,3) rb(j,1,n) cin>>A[i][j],A[i][j]+=A[i][j-1];
    rb(i,1,n){
        a[i]=A[0][i]-A[1][i-1];
        b[i]=A[2][n]-A[2][i-1]+A[1][i];
    }
    vector<pair<mp,int> > seg;
    vector<pair<long long ,int> > va(n+1);
    rb(i,1,n) va[i]=II(a[i],i);
    RMQ ds;
    ds.build(va);
    rb(i,1,q){
        int l,r,k;
        cin>>l>>r>>k;
        seg.PB(II(II(l,r),k));
    }
    sort(ALL(seg));
    long long ans=-1e18;
    rb(i,1,n) tree1.modifya(i,a[i]),tree1.modifyb(i,b[i]),tree2.modifyb(i,b[i]);
    for(auto it:seg){
        check_max(ans,tree1.query(it.first.first,it.first.second+1).best-it.second);
    }
    for(auto it:seg){
        int l,r,k;
        l=it.first.first;
        r=it.first.second;
        k=it.second;
        check_max(ans,tree2.query(l,r+1).best-k);
        long long dp=ds.query(l,r+1).first-k;
        check_max(dp,tree3.query(l,r+1)-k);
        tree3.upd(r+1,dp);
        tree2.modifya(r+1,dp);
    }
    cout<<ans<<endl;
    return 0;
}