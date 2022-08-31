#include<bits/stdc++.h>

using namespace std;

int main()
{
  int N;
  cin >> N;
  ++N;

  bool dp[100003] = {};
  for(int i = 2; i * i <= N; i++) {
    if(!dp[i]) {
      for(int j = i + i; j <= N; j += i) {
        dp[j] = true;
      }
    }
  }

  cout << 1 + (N >= 4) << endl;
  for(int i = 2; i <= N; i++) {
    cout << dp[i] + 1 << " ";
  }
  cout << endl;

}