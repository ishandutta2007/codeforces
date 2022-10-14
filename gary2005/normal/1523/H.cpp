/**
 *    author:  gary
 *    created: 12.08.2022 10:57:40
**/
#pragma GCC target("avx,sse2,sse3,sse4,mmx")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
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
const int MAXK=30;
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
        rmq[i + 1][j] = max(rmq[i][j], rmq[i][min(n - 1, j + (1 << i))]);
      }
  }
  T query(int a, int b) {
    if (b <= a) return kInf;
    int dep = 31 - __builtin_clz(b - a);
    return max(rmq[dep][a], rmq[dep][b - (1 << dep)]);
  }
};
RMQ<int> ds[MAXK+1];
int dp[15][20000+20][MAXK+1],n,q,a[20000+20],l[20000+20],r[20000+20],k[20000+20],ans[20000+20],f[20000+20][MAXK+1];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>q;
    rb(i,1,n) cin>>a[i];
    rb(i,1,n) rb(j,0,MAXK) dp[0][i][j]=min(n,i+a[i]+j);
    rb(f,1,14){
        rb(j,0,MAXK){
            vector<int> V(n+1,0);
            rb(i,1,n) V[i]=dp[f-1][i][j];
            ds[j].build(V);
        }
        rb(i,1,n){
            rb(j,0,MAXK){
                rb(j2,0,MAXK-j){
                    check_max(dp[f][i][j+j2],ds[j2].query(i,dp[f-1][i][j]+1));
                }
            }
        }
    }
    rb(i,1,q) {
        cin>>l[i]>>r[i]>>k[i];
        rb(j,0,MAXK) f[i][j]=l[i];
    }
    int TEMP[MAXK+1];
    rl(i,14,0){
        rb(j,0,MAXK){
            vector<int> V(n+1,0);
            rb(k,1,n) V[k]=dp[i][k][j];
            ds[j].build(V);
        }
        rb(id,1,q){
            memset(TEMP,-63,sizeof(TEMP));
            rb(j1,0,k[id]){
                rb(j2,0,k[id]-j1){
                    check_max(TEMP[j1+j2],ds[j2].query(l[id],f[id][j1]+1));
                }
            }
            if(*max_element(TEMP,TEMP+k[id]+1)<r[id]){
                ans[id]|=1<<i;
                memcpy(f[id],TEMP,sizeof(TEMP));
            }
        }
    }
    rb(i,1,q) cout<<ans[i]+(l[i]!=r[i])<<'\n';
    return 0;
}