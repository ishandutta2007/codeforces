#include<bits/stdc++.h>

using namespace std;

using int64 = long long;
const int INF = 1 << 30;

map< vector< int >, int64 > dp;
int can;

int64 rec(vector< int > &v, int used) {
  if(dp.count(v)) return dp[v];
  int64 ret = can == used;
  for(int i = 0; i < 10; i++) {
    if(v[i] > 0) {
      --v[i];
      ret += rec(v, used | (1 << i));
      ++v[i];
    }
  }
  return dp[v] = ret;
}

int main() {
  string x;
  cin >> x;
  vector< int > s(10);
  for(int i = 0; i < x.size(); i++) {
    int d = x[i] - '0';
    ++s[d];
    can |= 1 << d;
  }
  int64 ret = 0;
  for(int i = 1; i < s.size(); i++) {
    if(s[i] > 0) {
      --s[i];
      ret += rec(s, 1 << i);
      ++s[i];
    }
  }

  cout << ret << endl;
}