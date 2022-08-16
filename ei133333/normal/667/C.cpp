#include <bits/stdc++.h>
using namespace std;

int main()
{
  string S;
  cin >> S;
  if(S.size() <= 6) {
    cout << 0 << endl;
    exit(0);
  }
  
  S = S.substr(5);
  reverse(S.begin(), S.end());
  bool dp[10002][4] = {{}};

  dp[0][2] = S.size() >= 2;
  dp[0][3] = S.size() >= 3;
  
  for(int i = 0; i < S.size(); i++) {
    if(dp[i][2]) {
      int s = i + 2;
      dp[s][2] |= s + 1 < S.size() && (S[i] != S[s] || S[i + 1] != S[s + 1]);
      dp[s][3] |= s + 2 < S.size();
    }
    if(dp[i][3]) {
      int s = i + 3;
      dp[s][2] |= s + 1 < S.size();
      dp[s][3] |= s + 2 < S.size() && (S[i] != S[s] || S[i + 1] != S[s + 1] || S[i + 2] != S[s + 2]);
    }
  }

  set< string > ss;
  for(int i = 0; i < S.size(); i++) {
    if(dp[i][2]) {
      string s = "";
      s += S[i + 1];
      s += S[i];
      ss.insert(s);
    }
    if(dp[i][3]) {
      string s = "";
      s += S[i + 2];
      s += S[i + 1];
      s += S[i];
      ss.insert(s);
    }
  }
  cout << ss.size() << endl;
  for(const string& s : ss) cout << s << endl;
}