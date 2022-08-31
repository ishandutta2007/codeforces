#include<bits/stdc++.h>

using namespace std;

const int INF = 1 << 29;

void chmin(int &a, int b)
{
  a = min(a, b);
}

int main()
{
  int n;
  string s[500000];

  cin >> n;
  for(int i = 0; i < n; i++) cin >> s[i];

  vector< vector< int > > dp(n);
  vector< vector< pair< int, int > > > rev(n);

  for(int i = 0; i < n; i++) {
    dp[i].assign(s[i].size(), i == 0 ? 0 : INF);
    rev[i].assign(s[i].size(), make_pair(-1, -1));
  }

  for(int i = 0; i < n; i++) {

    if(i > 0) {
      int move = INF;
      pair< int, int > pv;
      for(int j = 0; j < s[i].size(); j++) {
        if(dp[i][j] > move) {
          dp[i][j] = move;
          rev[i][j] = pv;
        }
        if(move > dp[i][j]) {
          move = dp[i][j];
          pv = {i, j};
        }
      }
    }
    if(i == n - 1) break;


    bool latte = false;
    int rock;
    for(int j = 0; j < s[i].size(); j++) {
      int cost = dp[i][j] + ((int) s[i].size() - j - 1);
      if(latte) {
        if(dp[i + 1][rock] > cost) {
          dp[i + 1][rock] = cost;
          rev[i + 1][rock] = {i, j};
        }
      } else if(j >= s[i + 1].size() || s[i][j] > s[i + 1][j]) {
        break;
      } else {
        if(s[i][j] < s[i + 1][j]) {
          rock = j;
          latte = true;
        }
        if(dp[i + 1][j] > cost) {
          dp[i + 1][j] = cost;
          rev[i + 1][j] = {i, j};
        }
      }
    }
  }

  int ret = INF;
  for(int i = 0; i < s[n - 1].size(); i++) {
    chmin(ret, dp[n - 1][i] + ((int)s[n - 1].size() - i - 1));
  }

  vector< string > sub;
  for(int i = 0; i < s[n - 1].size(); i++) {
    if(dp[n - 1][i] + ((int)s[n - 1].size() - i - 1) == ret) {
      pair< int, int > now = {n - 1, i};
      sub.push_back(s[n - 1].substr(0, i + 1));
      int remake = n - 1;
      while(rev[now.first][now.second] != make_pair(-1, -1)) {
        now = rev[now.first][now.second];
        if(remake != now.first) {
          remake = now.first;
          sub.push_back(s[remake].substr(0, now.second + 1));
        }
      }
    }
  }

  reverse(begin(sub), end(sub));
  for(auto& s : sub) cout << s << endl;

}