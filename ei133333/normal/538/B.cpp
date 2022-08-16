#include<bits/stdc++.h>

using namespace std;

const int INF = 1 << 30;

int pv[1000001];
int dp[1000001];

int main()
{
  vector< int > beet;
  for(int i = 1; i < 1000001; i++) {
    string s = to_string(i);
    if(count(begin(s), end(s), '0') + count(begin(s), end(s), '1') == s.size()) {
      beet.push_back(i);
    }
  }


  fill_n(dp, 1000001, INF);
  dp[0] = 0;

  for(int i : beet) {
    for(int j = 0; j <= 1000000 - i; j++) {
      if(dp[j] + 1 < dp[j + i]) {
        dp[j + i] = dp[j] + 1;
        pv[j + i] = i;
      }
    }
  }

  int N;
  cin >> N;
  cout << dp[N] << endl;
  while(N != 0) {
    cout << pv[N] << " ";
    N -= pv[N];
  }
  cout << endl;
}