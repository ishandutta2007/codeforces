#include<bits/stdc++.h>
using namespace std;

typedef long long int64;

const int N=500000;

int n,cq,a[3][N+9];
int64 pre[N+9],suf[N+9],sum[N+9];
vector<tuple<int,int,int>>q[N+9];

void work(){
  scanf("%d%d",&n,&cq);
  for (int i=0;i<3;++i)
    for (int j=1;j<=n;++j)
      scanf("%d",&a[i][j]);
  for (int i=1;i<=n;++i) pre[i]=pre[i-1]+a[0][i];
  for (int i=n;i>=1;--i) suf[i]=suf[i+1]+a[2][i];
  for (int i=1;i<=n;++i) sum[i]=sum[i-1]+a[1][i];
  for (int i=1;i<=cq;++i){
    int l,r,v;
    scanf("%d%d%d",&l,&r,&v);
    q[l].emplace_back(l-1,v,0);
    q[r+1].emplace_back(l-1,v,1);
  }
  int64 ans=1-(1LL<<60);
  static int64 dp[N+9];
  map<int,multiset<int>>mp;
  multiset<int64>s;
  for (int i=0;i<=n;++i){
    dp[i]=1-(1LL<<60);
    if (i){
      for (auto [l,v,o]:q[i]){
        int p=mp.lower_bound(l)->first;
        if (o){
          s.erase(s.find(dp[p]-*mp[p].begin()));
          mp[p].erase(mp[p].find(v));
          if (!mp[p].empty()) s.insert(dp[p]-*mp[p].begin());
        }else{
          if (!mp[p].empty()) s.erase(s.find(dp[p]-*mp[p].begin()));
          mp[p].insert(v);
          s.insert(dp[p]-*mp[p].begin());
        }
      }
      if (!s.empty()) dp[i]=*s.rbegin();
      ans=max(ans,dp[i]+sum[i]+suf[i]);
    }
    dp[i]=max(dp[i],pre[i+1]-sum[i]);
    multiset<int>tmp;
    for (;!mp.empty();){
      int p=mp.rbegin()->first;
      if (dp[p]>dp[i]) break;
      if (!mp[p].empty()) s.erase(s.find(dp[p]-*mp[p].begin()));
      if (tmp.size()<mp[p].size()) swap(tmp,mp[p]);
      for (int x:mp[p]) tmp.insert(x);
      mp.erase(p);
    }
    mp[i].swap(tmp);
    if (!mp[i].empty()) s.insert(dp[i]-*mp[i].begin());
  }
  printf("%lld\n",ans);
}

int main(){
  int T=1;
  //scanf("%d",&T);
  for (;T--;) work();
  return 0;
}