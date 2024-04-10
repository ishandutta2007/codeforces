#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
int dp[100005]={},num[100005];
int main() {
int n;
  scanf("%d",&n);
  for(int i=0;i<n;i++){
    scanf("%d",&num[i]);
  }
  int ans=0;
  for(int i=0;i<n;i++){
    vector<int>vec;
    for(int j=2;j*j<=num[i];j++){
      if(num[i]%j==0) vec.push_back(j);
      while(num[i]%j==0){
        num[i]/=j;
      }
      if(num[i]==1) break;
    }
    if(num[i]!=1){
      vec.push_back(num[i]);
    }
    int maxi=0;
    for(int j=0;j<vec.size();j++){
      maxi=max(maxi,dp[vec[j]]);
    }
    for(int j=0;j<vec.size();j++){
      dp[vec[j]]=maxi+1;
      ans=max(ans,dp[vec[j]]);
    }
  }
  printf("%d%c",max(1,ans),10);
}