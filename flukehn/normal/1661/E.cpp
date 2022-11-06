#include<bits/stdc++.h>
using namespace std;
#define For(i,a,b) for(int i=(a),i##_end=(b);i<i##_end;++i)
using ll=long long;
#ifdef flukehn
#include "algo/debug.h"
#else
#define dbg(...) 0
#define debug(...) 0
#endif
const int N=500'011;
char s[3][N];
int n;
int g[8][8];
int b[N];
int s1[N],s2[N];
const int M=300'011;
int ans[M];
vector<int> ad[N];
int Q;
using pa=pair<int,int>;
vector<pa> qry[N];
int c[N];
void add(int x,int v){
  for(;x<=n;x+=x&-x)c[x]+=v;
}
int ask(int x){
  int r=0;
  for(;x;x-=x&-x)r+=c[x];
  return r;
}
int main(){
#ifdef flukehn
  freopen("A.in","r",stdin);
#endif
  ios::sync_with_stdio(0),cin.tie(0);
  cin>>n;
  cin.getline(s[0]+1,N);
  For(i,0,3) cin.getline(s[i]+1,N);
  for(int i=1;i<=n;++i) {
    int w=0;
    For(j,0,3) w=w*2+s[j][i]-'0';
    b[i]=w;
  }
  b[0]=b[n+1]=0;
  For(v,0,8) {
    g[0][v]=0;

    g[1][v]=~v>>0&1;
    g[2][v]=~v>>1&1;
    g[4][v]=~v>>2&1;

    g[6][v]=(~v>>2&1) && (~v>>1&1);
    g[3][v]=(~v>>1&1) && (~v>>0&1);

    g[5][v]=(~v>>2&1) + (~v>>0&1);

    g[7][v]=(v==0);
  }
  for(int i=1;i<n;++i) s1[i]=s1[i-1]+g[b[i]][b[i+1]];
  for(int i=1;i<n;++i) s2[i]=s2[i-1]+(b[i]==7&&b[i+1]==5);
  for(int i=1;i+2<=n;++i) {
    if(b[i]!=7) continue;
    if(b[i+1]!=5) continue;
    int j;
    for(j=i+2;j<=n&&b[j]==5;++j);
    if(j<=n && b[j] ==7) {
     // ad[i].push_back(j);
      dbg(i,j);
      ad[j].push_back(i);
    }
    i=j-1;
  }
  cin>>Q;
  for(int i=1;i<=Q;++i) {
    int l,r;
    cin>>l>>r;
    ans[i]=s1[r-1]-s1[l-1]+g[b[r]][0];
    ans[i]-=s2[r-1]-s2[l-1];
    qry[r].emplace_back(l,i);
  }
  int tot=0;
  for(int i=1;i<=n;++i) {
    for(int x:ad[i]) add(x,1);
    tot+=ad[i].size();
    for(auto [l,id]:qry[i]) {
      ans[id]+=tot-ask(l-1);
      dbg(id,l,i,tot-ask(l-1));
    }
  }
  for(int i=1;i<=Q;++i)cout<<ans[i]<<"\n";
}