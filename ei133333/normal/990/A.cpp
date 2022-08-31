#include <bits/stdc++.h>

using namespace std;

using int64 = long long;

int main() {
  int64 N, M, A, B;
  cin >> N >> M >> A >> B;
  int64 highN = (N + M - 1) / M * M;
  int64 lowN = N / M * M;
  cout << min((highN - N) * A, (N - lowN) * B) << endl;
}