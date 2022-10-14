/**
 *    author:  gary
 *    created: 14.02.2022 13:55:56
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
const int MAXANS=303;
const int MAXN=15001;
int n,a[MAXN];
int minr[MAXN][MAXANS],maxl[MAXN][MAXANS];
template <class T>
struct BIT { //1-indexed
  vector<T> t;
  BIT(){
    t.assign(n + 1, INF);
  }
  T query(int i) {
    i=n-i+1;
    T ans = INF;
    for (; i >= 1; i -= (i & -i)) check_min(ans,t[i]);
    return ans;
  }
  void upd(int i, T val) {
    i=n-i+1;
    if (i <= 0) return;
    for (; i <= n; i += (i & -i)) check_min(t[i],val);
  }
};
vector<pair<pair<bool,int>,pair<int,int> > > info[MAXN];
int trans(){
    BIT<int> updr[MAXANS],updl[MAXANS];
    rb(i,0,n) info[i].clear();
    int answer=1;
    rl(i,n,1){
        for(auto it:info[i]){
            if(it.first.first==0){
                // -> maxl
                updl[it.second.second].upd(n-it.first.second+1,-it.second.first);
            }
            else{
                updr[it.second.second].upd(it.first.second,it.second.first);
            }
        }
        rb(j,1,300){
            check_min(minr[i][j],updr[j].query(a[i]));
            check_max(maxl[i][j],-updl[j].query(n-a[i]+1));
            // cout<<j<<endl;
            if(minr[i][j]<=n){
                // cout<<a[i]<<" "<<i<<" "<<j<<" "<<minr[i][j]<<endl;
                check_max(answer,j);
                info[i-1].PB({{1,a[i]-1},{minr[i][j],j+1}});
                if(i>j)
                info[i-j].PB({{0,minr[i][j]+1},{a[i],j+1}});
            }
            if(maxl[i][j]>=1){
                check_max(answer,j);
                info[i-1].PB({{0,a[i]+1},{maxl[i][j],j+1}});
                if(i>j)
                info[i-j].PB({{1,maxl[i][j]-1},{a[i],j+1}});
            }
        }
    }
    return answer;
}
int isin(){
    rb(i,1,n) memset(minr[i],63,sizeof(minr[i])),memset(maxl[i],-63,sizeof(maxl[i]));
    minr[n][1]=a[n];
    maxl[n][1]=a[n];
    return trans();
}
int notin(){
    rb(i,1,n) memset(minr[i],63,sizeof(minr[i])),memset(maxl[i],-63,sizeof(maxl[i]));
    rb(i,1,n-1) minr[i][2]=a[i],maxl[i][2]=a[i];
    return trans()-1;
}
void solve(){
    cin>>n;
    rb(i,1,n) cin>>a[i];
    cout<<max(isin(),notin())<<endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while (t--){
        solve();
    }
    return 0;
}