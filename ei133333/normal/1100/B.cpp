#include <bits/stdc++.h>

using namespace std;

using int64 = long long;

int main() {
  int N, M;
  cin >> N >> M;
  vector< int > uku(N);
  int add = 0;
  for(int i = 0; i < M; i++) {
    int x;
    cin >> x;
    --x;
    uku[x]++;
    add += uku[x] == 1;
    if(add == N) {
      cout << 1;
      for(int j = 0; j < N; j++) {
        uku[j]--;
        add -= uku[j] == 0;
      }
    } else {
      cout << 0;
    }
  }
  cout << endl;
}