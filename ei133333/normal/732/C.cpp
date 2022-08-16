#include <bits/stdc++.h>

using namespace std;

int main()
{
  long long A, B, C;
  cin >> A >> B >> C;
  long long big = max({A, B, C});
  cout << max(0LL, big - A - 1) + max(0LL, big - B - 1) + max(0LL, big - C - 1) << endl;
}