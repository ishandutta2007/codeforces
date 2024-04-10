#include <bits/stdc++.h>
using namespace std;
const int N=5050;
typedef long long LL;
const LL inf=1e16;
LL n, k, x, a[N];
LL dp[2][N];
int main(){
  cin>>n>>k>>x;
  for(int i=1; i<=n; i++) cin>>a[i];
  for(int i=1; i<=n; i++) dp[0][i]=-inf;
  for(int i=1; i<=x; i++){
    int cur=i&1, pre=1^cur;
    for(int j=0; j<=n; j++) dp[cur][j]=-inf;
    deque<int> dq;
    int ptr=0;
    for(int j=1; j<=n; j++){
      while(ptr < j){
        while(dq.size() and dp[pre][ptr]>=dp[pre][dq.back()])
          dq.pop_back();
        dq.push_back(ptr++);
      }
      while(dq.size() and dq.front()<j-k)
        dq.pop_front();
      dp[cur][j]=a[j]+(dq.empty()?-inf:dp[pre][dq.front()]);
    }
  }
  LL ans=-1;
  for(int i=0; i<k; i++)
    ans=max(ans, dp[x&1][n-i]);
  cout<<ans<<endl;
}