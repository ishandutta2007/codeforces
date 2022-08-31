#include <bits/stdc++.h>

using namespace std;

using int64 = long long;
const int INF = 1 << 30;

int main() {
  int N, M;
  cin >> N >> M;
  int v[1000] = {};
  for(int i = 0; i < M; i++) {
    int x;
    cin >> x;
    --x;
    v[x]++;
  }
  int st = INF;
  for(int i = 0; i < N; i++) {
    st = min(st, v[i]);
  }
  cout << st << endl;
}