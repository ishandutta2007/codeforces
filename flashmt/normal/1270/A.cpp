#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t;
  cin >> t;
  while (t--)
  {
    int n, k1, k2, a[111], b[111];
    cin >> n >> k1 >> k2;
    for (int i = 0; i < k1; i++)
      cin >> a[i];
    for (int i = 0; i < k2; i++)
      cin >> b[i];
    cout << (*max_element(a, a + k1) > *max_element(b, b + k2) ? "YES" : "NO") << endl;
  }
}