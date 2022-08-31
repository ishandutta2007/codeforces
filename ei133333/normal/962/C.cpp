#include <bits/stdc++.h>

using namespace std;

using int64 = long long;
const int INF = 1 << 30;

int main() {
  string S;
  cin >> S;
  int ret = INF;
  for(int i = 1; i < (1 << S.size()); i++) {
    string T;
    for(int j = 0; j < S.size(); j++) {
      if((i >> j) & 1) T += S[j];
    }
    if(T[0] == '0') continue;
    int v = stoi(T);
    for(int64 j = 1; j * j <= v; j++) {
      if(j * j == v) {
        ret = min< int >(ret, S.size() - T.size());
      }
    }
  }

  if(ret == INF) ret = -1;
  cout << ret << endl;
}