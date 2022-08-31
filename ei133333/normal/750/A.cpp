#include <bits/stdc++.h>

using namespace std;


int main()
{
  int N, K;
  cin >> N >> K;
  K = 240 - K;

  int ret = 1;
  while(K - 5 * ret >= 0) K -= 5 * ret++;

  cout << min(N, ret - 1) << endl;
}