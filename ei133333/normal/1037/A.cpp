#include <bits/stdc++.h>

using namespace std;

using int64 = long long;

int main() {
  int N;
  cin >> N;
  int64 ret = 0;
  while((1LL << ret) <= N) ret++;
  cout << ret << endl;
}