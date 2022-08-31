#include <bits/stdc++.h>

using namespace std;

typedef long long int64;

int main()
{
  int64 R[3];
  cin >> R[0] >> R[1] >> R[2];
  sort(R, R + 3);
  if((R[0] + R[1]) * 2 < R[2]) cout << R[0] + R[1] << endl;
  else cout << (R[0] + R[1] + R[2]) / 3 << endl;
}