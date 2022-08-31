#include <bits/stdc++.h>

using namespace std;

using int64 = long long;
const int INF = 1 << 30;

int main()
{
  int N, A, B;
  cin >> N >> A >> B;

  for(int i = 114514; i > 0; i--) {
    if(A / i + B / i >= N && A >= i && B >= i) {
      cout << i << endl;
      return (0);
    }
  }

  cout << 0 << endl;
}