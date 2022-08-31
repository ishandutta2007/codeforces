#include <bits/stdc++.h>

using namespace std;

string str[5000];
vector< int > idx[26];

int main() {
  cin >> str[0];
  int sz = (int) str[0].size();
  for(int i = 1; i < sz; i++) {
    str[i] = str[i - 1].substr(1);
    str[i] += str[i - 1][0];
  }
  for(int i = 0; i < str[0].size(); i++) {
    idx[str[i][0] - 'a'].push_back(i);
  }
  int ret = 0;
  for(int i = 0; i < 26; i++) {
    int sum[5001][26] = {{}};
    for(int j : idx[i]) {
      for(int k = 0; k < sz; k++) {
        sum[k][str[j][k] - 'a']++;
      }
    }
    int beet = 0;
    for(int j = 0; j < sz; j++) {
      int odd = 0;
      for(int k = 0; k < 26; k++) {
        odd += sum[j][k] == 1;
      }
      beet = max(beet, odd);
    }
    ret += beet;
  }
  cout << fixed << setprecision(10) << 1.0 * ret / sz << endl;
}