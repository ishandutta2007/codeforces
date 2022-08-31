#include <bits/stdc++.h>

using namespace std;

const int lim = 13;

int calc(const string &s, set< pair< int, int > > &vs)
{
  int ans = 0;
  for(int k = lim; k >= 1; k--) {
    int found = true;
    for(int i = 0; i < (1 << k); i++) {
      if(vs.count({k, i})) continue;
      string f;
      for(int j = 0; j < k; j++) f += "01"[(i >> j) & 1];
      if(s.find(f) == string::npos) found = false;
      else vs.emplace(k, i);
    }
    if(!found) ans = k - 1;
  }
  return (ans);
}

int main()
{
  int N, M;
  string S[200];
  int pre[200] = {};
  set< pair< int, int > > found[200];


  cin >> N;
  for(int i = 0; i < N; i++) {
    cin >> S[i];
  }
  cin >> M;
  for(int i = 0; i < M; i++) {
    int a, b;
    cin >> a >> b;
    S[i + N] = S[--a] + S[--b];
    for(auto &p : found[a]) found[i + N].emplace(p);
    for(auto &p : found[b]) found[i + N].emplace(p);
    pre[i + N] = max({pre[a], pre[b], calc(S[i + N], found[i + N])});
    cout << pre[i + N] << endl;
    if(S[i + N].size() > 24) {
      S[i + N] = S[i + N].substr(0, 12) + "#" + S[i + N].substr(S[i + N].size() - 12);
    }
  }
}