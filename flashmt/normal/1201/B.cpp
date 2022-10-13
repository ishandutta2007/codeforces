#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, maxA = 0, x;
  long long sum = 0;
  cin >> n;
  while (n--)
  {
    cin >> x;
    sum += x;
    maxA = max(maxA, x);
  }

  cout << (sum % 2 == 0 && maxA * 2 <= sum ? "YES" : "NO") << endl;
}