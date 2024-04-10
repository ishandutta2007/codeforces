#include <bits/stdc++.h>
using namespace std;
const int N=5140;
int n, k, a[N], p[N];
int dp[2][N];
int main(){
  scanf("%d%d", &n, &k);
  for(int i=1; i<=n; i++) scanf("%d", &a[i]);
  sort(a+1, a+n+1);
  for(int i=1; i<=n; i++){
    p[i]=i;
    while(p[i] and a[p[i]]>=a[i]-5) p[i]--;
  }
  for(int i=1; i<=k; i++){
    int now=i&1, pre=1^now;
    auto eval = [&pre](int pos){
      return dp[pre][pos]-pos;
    };
    deque<int> dq;
    for(int j=1; j<=n; j++){
      dp[now][j]=dp[now][j-1];
      while(dq.size() and eval(j-1) >= eval(dq.back())) dq.pop_back();
      dq.push_back(j-1);
      while(dq.size() and dq.front() < p[j]) dq.pop_front();
      if(dq.empty()) continue;
      dp[now][j]=max(dp[now][j], eval(dq.front())+j);
    }
  }
  printf("%d\n", dp[k&1][n]);
}