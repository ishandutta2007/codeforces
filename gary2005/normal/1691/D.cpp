/**
 *    author:  gary
 *    created: 31.05.2022 22:34:12
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
template <class T>
struct RMQ {
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
    int dep = 31 - __builtin_clz(b - a);
    return min(rmq[dep][a], rmq[dep][b - (1 << dep)]);
  }
};
RMQ<pair<int,int> > A;
RMQ<LL> B;
RMQ<LL> C;
vector<int> v;
bool check(int l,int r){
    if(l>=r) return 1;
    int x=A.query(l,r+1).second;
    LL mxr=-C.query(x+1,r+2);
    LL mnl=B.query(l,x+1);
    if(mxr-mnl<=v[x]) return check(l,x-1)&&check(x+1,r);
    return 0;
}
void solve(){
    int n;
    cin>>n;
    v.resize(n);
    vector<LL> pre(n+1,0);
    rep(i,n) cin>>v[i];
    vector<mp> id(n);
    rep(i,n) id[i]=II(-v[i],i);
    rb(i,1,n) pre[i]=pre[i-1]+v[i-1];
    A.build(id);
    B.build(pre);
    rep(i,n+1) pre[i]=-pre[i];
    C.build(pre);
    if(check(0,n-1)){
        cout<<"YES\n";
    }
    else{
        cout<<"NO\n";
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while (t--)
    {
        solve();
    }
    
    return 0;
}