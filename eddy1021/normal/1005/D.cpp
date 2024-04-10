#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=202020;
const int MAGIC=42;
char c[N];
int dp[N];
int main(){
  scanf("%s", c+1);
  int n=strlen(c+1);
  for(int i=1; i<=n; i++){
    int s=0;
    for(int j=0; j<MAGIC and i-j>=1; j++){
      s+=c[i-j]-'0';
      if(s%3) continue;
      dp[i]=max(dp[i], dp[i-j-1]+1);
    }
    dp[i]=max(dp[i], dp[i-1]);
  }
  cout<<*max_element(dp, dp+n+1)<<endl;
}