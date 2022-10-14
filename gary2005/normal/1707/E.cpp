/**
 *    author:  gary
 *    created: 17.07.2022 00:03:21
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
const int MAXN=1e5+20;
map<mp,int> vis;
int n,q,a[MAXN];
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
    int dep = 31 - __builtin_clz(b - a); // log(b - a)
    return min(rmq[dep][a], rmq[dep][b - (1 << dep)]);
  }
};
RMQ <int> pos,neg;
int tol[MAXN],tor[MAXN];
mp f(int l,int r){
    int mn=pos.query(l,r+1);
    int mx=-neg.query(l,r+1);
    return II(mn,mx);
}
mp seg[35][MAXN];
RMQ<int> mn[35],mx[35];
mp f_k(int l,int r,int k){
    // f^{2^k}(l,r)
    if(l==r) return II(l,r);
    return II(mn[k].query(l,r),-mx[k].query(l,r));
}
void init(int j){
    vector<int> v(n+1);
    rb(i,1,n-1) v[i]=seg[j][i].first;
    mn[j].build(v);
    rb(i,1,n-1) v[i]=-seg[j][i].second;
    mx[j].build(v);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>q;
    rb(i,1,n) cin>>a[i];
    vector<int> v(n+1,0),v2(n+1,0);
    rb(i,1,n) v[i]=a[i],v2[i]=-a[i];
    pos.build(v);
    neg.build(v2);
    rb(i,1,n-1) seg[0][i]=f(i,i+1);
    init(0);
    rb(j,1,34){ rb(i,1,n-1) {
        auto tmp=seg[j-1][i];
        seg[j][i]=f_k(tmp.first,tmp.second,j-1);
    }
    init(j);
    }
    // cout<<f_k(1,n,0).first<<" "<<f_k(1,n,0).second<<endl;
    while (q--){
        int l,r;
        cin>>l>>r;
        if(f_k(l,r,34)!=II(1,n)&&II(l,r)!=II(1,n)){
            cout<<-1<<endl;
        }
        else{
            if(II(l,r)==II(1,n)){
                cout<<0<<endl;
            }
            else{
                int ans=0;
                rl(i,34,0){
                    auto tmp=f_k(l,r,i);
                    if(tmp!=II(1,n)){
                        l=tmp.first;
                        r=tmp.second;
                        ans|=1<<i;
                    }
                }
                cout<<ans+1<<endl;
            }
        }
    }
    return 0;
}