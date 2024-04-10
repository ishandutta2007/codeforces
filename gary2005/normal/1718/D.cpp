/**
 *    author:  gary
 *    created: 19.08.2022 19:50:10
**/
#include<bits/stdc++.h>
#define rb(a,b,c) for(int a=(b);a<=(c);++a)
#define rl(a,b,c) for(int a=(b);a>=(c);--a)
#define rep(a,b) for(int a=0;a<(b);++a)
#define LL long long
#define II(a,b) make_pair(a,b)
#define SRAND mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define random(a) rng()%a
#define ALL(a) a.begin(),a.end()
#define check_min(a,b) a=min(a,b)
#define check_max(a,b) a=max(a,b)
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
template <class T>
struct RMQ { // 0-based
  vector<vector<T>> rmq;
  T kInf = numeric_limits<T>::max();
  void build(const vector<T>& V) {
    int n = V.size(), on = 1, dep = 1;
    while (on < n) on *= 2, ++dep;
    rmq.assign(dep, V);
 
    for (int i = 0; i < dep - 1; ++i)
      for (int j = 0; j < n; ++j) {
        rmq[i + 1][j] = min(rmq[i][j], rmq[i][min(n - 1, j + (1 << i))]);
      }
  }
  T query(int a, int b) { // [a, b)
    if (b <= a) return kInf;
    int dep = 31 - __builtin_clz(b - a); // log(b - a)
    return min(rmq[dep][a], rmq[dep][b - (1 << dep)]);
  }
};
const int N=1<<20;
struct Segment_Tree{
    bitset<N+N> modified_node;
    int tag[N+N],tree[N+N];
    Segment_Tree(){memset(tag,0,sizeof(tag));memset(tree,0,sizeof(tree));}
    void pd(int now){
        tree[now]+=tag[now];
        modified_node.set(now);
        if(now<N) tag[now<<1]+=tag[now],tag[now<<1|1]+=tag[now],modified_node.set(now<<1),modified_node.set(now<<1|1);
        tag[now]=0;
    }
    void pu(int now){
        tree[now]=min(tree[now<<1],tree[now<<1|1]);
    }
    void add(int a,int b,int val,int now=1,int l=1,int r=N+1){
        pd(now);
        if(r<=a||l>=b) return;
        if(r<=b&&l>=a) {
            tag[now]+=val;
            pd(now);
            return ;
        }
        int mid=(l+r)>>1;
        add(a,b,val,now<<1,l,mid);
        add(a,b,val,now<<1|1,mid,r);
        pu(now);
    }
    int binary_search(int now=1,int l=1,int r=N+1){
        if(l==r-1) return l;
        pd(now<<1);pd(now<<1|1);
        int mid=(l+r)>>1;
        if(tree[now<<1|1]==tree[now]) return binary_search(now<<1|1,mid,r);
        return binary_search(now<<1,l,mid);
    }
    void clear(){
        for(int i=modified_node._Find_first();i!=N+N;i=modified_node._Find_next(i)){
            tag[i]=tree[i]=0;
        }
        modified_node.reset();
    }
}sgt;
RMQ<mp> ds;
const int MAXN=3e5+20;
int n,q,p[MAXN],a[MAXN],l[MAXN],r[MAXN],root,s[MAXN],leq[MAXN],geq[MAXN];
int calc(int L,int R){
    if(L>R) return 0;
    int mid=ds.query(L,R+1).second;
    l[mid]=calc(L,mid-1);
    r[mid]=calc(mid+1,R);
    if(a[mid]) geq[mid]=leq[mid]=a[mid];
    else{
        leq[mid]=1e6;
        geq[mid]=1;
    }
    if(l[mid]) check_max(geq[mid],geq[l[mid]]+1);
    if(r[mid]) check_max(geq[mid],geq[r[mid]]+1);
    return mid;
}
void calc2(int now){
    if(l[now]) check_min(leq[l[now]],leq[now]-1),calc2(l[now]);
    if(r[now]) check_min(leq[r[now]],leq[now]-1),calc2(r[now]);
}
bool cmp(mp A,mp B){
    return A.second<B.second;
}
void solve(){
    vector<mp> V;
    cin>>n>>q;
    rb(i,1,n) cin>>p[i],l[i]=r[i]=0;
    rb(i,1,n) cin>>a[i];
    V.resize(n+1);
    rb(i,1,n) V[i]=II(-p[i],i);
    ds.build(V);
    root=calc(1,n);
    int k=0;
    rb(i,1,n) k+=a[i]==0;
    rb(i,1,k-1) cin>>s[i];
    calc2(root);
    vector<mp> seg;
    rb(i,1,n) if(!a[i]) seg.emplace_back(geq[i],leq[i]);
    sort(ALL(seg),cmp);
    sort(s+1,s+k);
    int p=1;
    int L,R;
    L=-INF,R=INF;
    sgt.clear();
    // for(auto it:seg){
    //     cout<<it.first<<" "<<it.second<<endl;
    // }
    rep(i,seg.size()){
        while(p<=k-1&&s[p]<=seg[i].second){
            sgt.add(1,s[p]+1,1);
            ++p;
        }
        if(seg[i].first>seg[i].second) L=INF,R=-INF;
        sgt.add(1,seg[i].first+1,-1);
        if(sgt.tree[1]<-1) L=INF,R=-INF;
        if(sgt.tree[1]==-1){
            check_min(R,seg[i].second);
            check_max(L,sgt.binary_search());
        }
    }
    rb(i,1,n) if(a[i]&&!(a[i]<=leq[i]&&a[i]>=geq[i])) L=INF,R=-INF;
    // cout<<L<<" "<<R<<endl;
    while(q--){
        int d;
        cin>>d;
        cout<<(d<=R&&d>=L? "YES":"NO")<<'\n';
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}