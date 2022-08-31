#include <bits/stdc++.h>

using namespace std;

using int64 = long long;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int N, M, Q;
  string S, T;

  cin >> N >> M >> Q;
  cin >> S;
  cin >> T;

  vector< pair< int, int > > app;
  for(int i = 0; i <= (int) S.size() - (int) T.size(); i++) {
    bool match = true;
    for(int j = 0; j < T.size(); j++) {
      if(S[i + j] != T[j]) match = false;
    }
    if(match) app.emplace_back(i, i + T.size());
  }
  while(Q--) {
    int X, Y;
    cin >> X >> Y;
    int ret = 0;
    --X;
    for(auto &p : app) {
      ret += X <= p.first && p.second <= Y;
    }
    cout << ret << endl;
  }
}