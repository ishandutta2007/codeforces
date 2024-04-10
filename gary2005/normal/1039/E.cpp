/**
 *    author:  gary
 *    created: 27.02.2022 17:25:48
**/
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse","avx")
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
int n,w,q,x[100000+10],ans[100000+10],k[100000+10],mx[100000+10],mn[100000+10];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>w>>q;
    rb(i,1,n) cin>>x[i];
    rb(i,1,q){
      int ki;
      cin>>ki;
      k[i]=w-ki;
      mx[i]=mn[i]=x[1];
    }
    rb(i,1,n){
      int t=x[i];
      for(int j=1;j<=q;j++){
        mx[j]=max(mx[j],t),mn[j]=min(mn[j],t);
        if(mx[j]-mn[j]>k[j])mx[j]=mn[j]=t,ans[j]++;
      }
    }
    rb(i,1,q) cout<<ans[i]<<endl;
    return 0;
}