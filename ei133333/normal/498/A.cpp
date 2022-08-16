#include <bits/stdc++.h>

using namespace std;

using int64 = long long;

int main()
{
  int N;
  int64 a, b, c, d;

  cin >> a >> b;
  cin >> c >> d;
  cin >> N;

  int ret = 0;
  for(int i = 0; i < N; i++) {
    int64 x, y, z;
    cin >> x >> y >> z;

    auto p = x * a + y * b + z;
    auto q = x * c + y * d + z;
    if(p > q) swap(p, q);
    if(p < 0 && q > 0) ++ret;
  }

  cout << ret << endl;
}