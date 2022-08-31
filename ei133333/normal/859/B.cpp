#include <bits/stdc++.h>

using namespace std;

using int64 = long long;
const int64 INF = 1LL << 58;

int main()
{
  int N;
  cin >> N;

  int64 ret = INF;
  for(int64 i = 1; i <= N; i++) {
    ret = min(ret, ((N + i - 1) / i + i) * 2);
  }
  cout << ret << endl;
}