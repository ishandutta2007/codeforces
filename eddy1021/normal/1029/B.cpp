#include <bits/stdc++.h>
using namespace std;
const int N=202020;
int n, a[N], dp[N];
int main(){
  scanf("%d", &n);
  for(int i=0; i<n; i++)
    scanf("%d", &a[i]);
  deque<int> dq;
  for(int i=0; i<n; i++){
    while(dq.size() and a[dq.front()]*2<a[i]) dq.pop_front();
    dp[i]=1+(dq.empty()?0:dp[dq.front()]);
    while(dq.size() and dp[i]>=dp[dq.back()]) dq.pop_back();
    dq.push_back(i);
  }
  printf("%d\n", *max_element(dp, dp+n));
}