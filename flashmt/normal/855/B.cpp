#include <bits/stdc++.h>
using namespace std;
const long long oo = 1LL << 62;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(NULL);
  int n, x;
  long long f[3] = {-oo, -oo, -oo}, c[3];
  cin >> n;
  for (int i = 0; i < 3; i++)
    cin >> c[i];
  for (int i = 0; i < n; i++)
  {
    cin >> x;
    for (int j = 0; j < 3; j++)
      f[j] = max(f[j], c[j] * x + (j ? f[j - 1] : 0));
  }
  cout << f[2] << endl;
}