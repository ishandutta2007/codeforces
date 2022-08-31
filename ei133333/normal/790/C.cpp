#include <bits/stdc++.h>

using namespace std;

void chmin(int &a, int b)
{
  a = min(a, b);
}

const int INF = 1 << 30;
string S;
int dp[78][78][78][2];

int main()
{
  int N;
  cin >> N;
  cin >> S;

  vector< int > a, b, c;
  for(int i = 0; i < N; i++) {
    if(S[i] == 'V') a.push_back(i);
    else if(S[i] == 'K') b.push_back(i);
    else c.push_back(i);
  }


  fill_n(***dp, 78 * 78 * 78 * 2, INF);
  dp[0][0][0][0] = 0;
  for(int i = 0; i <= a.size(); i++) {
    for(int j = 0; j <= b.size(); j++) {
      for(int k = 0; k <= c.size(); k++) {
        for(int l = 0; l < 2; l++) {
          if(dp[i][j][k][l] == INF) continue;

          auto f = [&](int x)
          {
            int latte = 0;
            for(int p = i; p < a.size(); p++) if(a[p] < x) ++latte;
            for(int p = j; p < b.size(); p++) if(b[p] < x) ++latte;
            for(int p = k; p < c.size(); p++) if(c[p] < x) ++latte;
            return (latte);
          };

          if(i < a.size()) chmin(dp[i + 1][j][k][1], dp[i][j][k][l] + f(a[i]));
          if(j < b.size() && l == 0) chmin(dp[i][j + 1][k][0], dp[i][j][k][l] + f(b[j]));
          if(k < c.size()) chmin(dp[i][j][k + 1][0], dp[i][j][k][l] + f(c[k]));
        }
      }
    }
  }
  cout << min(dp[a.size()][b.size()][c.size()][0], dp[a.size()][b.size()][c.size()][1]) << endl;
}