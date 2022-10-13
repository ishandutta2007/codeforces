#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int b, k, x = 0, a;
  cin >> b >> k;
  for (int i = 0; i < k; i++)
  {
    cin >> a;
    x = (x * b + a) % 2;
  }
  cout << (x ? "odd" : "even") << endl;
}