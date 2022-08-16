#include<bits/stdc++.h>
using namespace std;
const int INF = 1 << 30;

int main()
{
  int N, dp[100000];
  fill_n(dp, 100000, INF);
  
  cin >> N;
  for(int i = 0; i < N; i++) {
    int A;
    cin >> A;
    *lower_bound(dp, dp + N, A) = A;
  } 
  cout << lower_bound(dp, dp + N, INF) - dp << endl;
}