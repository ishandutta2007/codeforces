/**
 *    author:  gary
 *    created: 06.02.2022 08:41:23
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
const int MAXN=1e5+1;
const int MOD=1e9+9;
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
int n,k,x[MAXN],y[MAXN],a,b,c,d;
vector<int> vx;
mp p[MAXN];
RMQ<mp> tree;
int ch[MAXN][2];
int X[MAXN],L[MAXN],R[MAXN];
struct node{
    int fr,rest;
    node(){fr=0;rest=0;}
    node(int _,int __){fr=_,rest=__;}
};
node calc[MAXN];
node merge(node A,node B){
    int ok=A.fr|B.fr;
    return node(ok^1,A.rest+B.rest+ok);
}
int kt(int l,int r){
    // [l,r)
    if(l==r) return 0;
    mp tmp=tree.query(l,r);
    ch[tmp.second][0]=kt(l,p[tmp.second].first);
    ch[tmp.second][1]=kt(p[tmp.second].first+1,r);
    X[tmp.second]=vx[p[tmp.second].first];
    L[tmp.second]=R[tmp.second]=X[tmp.second];
    if(ch[tmp.second][0]) L[tmp.second]=L[ch[tmp.second][0]];
    if(ch[tmp.second][1]) R[tmp.second]=R[ch[tmp.second][1]];
    calc[tmp.second]=merge(calc[ch[tmp.second][0]],calc[ch[tmp.second][1]]);
    return tmp.second;
}
node dfs(int now,int l,int r){
    if(now==0) return node();
    if(X[now]<l) return dfs(ch[now][1],l,r);
    if(X[now]>r) return dfs(ch[now][0],l,r);
    if(L[now]>=l&&R[now]<=r) return calc[now];
    return merge(dfs(ch[now][0],l,r),dfs(ch[now][1],l,r));
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>k;
    rb(i,1,k) cin>>x[i]>>y[i];
    cin>>a>>b>>c>>d;
    rb(i,k+1,n) x[i]=(1ll*a*x[i-1]+b)%MOD,y[i]=(1ll*c*y[i-1]+d)%MOD;
    rb(i,1,n) vx.PB(x[i]);
    sort(ALL(vx));
    rb(i,1,n) x[i]=lower_bound(ALL(vx),x[i])-vx.begin();
    rb(i,1,n) p[i]=II(x[i],y[i]);
    sort(p+1,p+1+n);
    vector<mp> t(n);
    rb(i,1,n) t[p[i].first]=II(-p[i].second,i);
    tree.build(t);
    int root=kt(0,n);
    int m;
    cin>>m;
    while(m--){
        int l,r;
        cin>>l>>r;
        cout<<dfs(root,l,r).rest<<endl;
    }
    return 0;
}