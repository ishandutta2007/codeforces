#include <bits/stdc++.h>

using namespace std;

using int64 = long long;
const int INF = 1 << 30;
string U = "RGB";

int main() {
  int N;
  string S;
  cin >> N;
  cin >> S;

  sort(begin(U), end(U));
  int best = INF;
  string v;
  do {
    int cost = 0;
    string add;
    for(int i = 0; i < N; i++) {
      cost += S[i] != U[i % 3];
      add += U[i % 3];
    }
    if(best > cost) {
      best = cost;
      v = add;
    }
  } while(next_permutation(begin(U), end(U)));
  cout << best << endl;
  cout << v << endl;
}