#include <bits/stdc++.h>

using namespace std;

using int64 = long long;

int main() {
  int N, L[1000000];
  cin >> N;
  int add[1000001] = {};
  for(int i = 0; i < N; i++) {
    cin >> L[i];
    add[max(0, i - L[i] + 1)]++;
    add[i + 1]--;
  }
  int ret = 0;
  for(int i = 1; i <= N; i++) {
    add[i] += add[i - 1];
    ret += add[i] == 0;
  }
  cout << ret << endl;
}