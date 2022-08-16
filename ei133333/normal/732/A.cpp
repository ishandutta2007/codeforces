#include <bits/stdc++.h>

using namespace std;

typedef long long int64;

int main()
{
  int64 K, R;
  cin >> K >> R;

  int64 curr = K, ret = 1;
  while(!(curr % 10 == R || curr % 10 == 0)) {
    curr += K;
    ++ret;
  }

  cout << ret << endl;
}