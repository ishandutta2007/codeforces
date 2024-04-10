#include <bits/stdc++.h>
using namespace std;

int main()
{
  long long n, k;
  cin >> n >> k;
  if (k > n * 2 + 1 || k < 3) cout << 0 << endl;
  else
  {
    long long to = min(n, k - 1), from = k - to;
    cout << (to - from + 1) / 2 << endl;
  }
}