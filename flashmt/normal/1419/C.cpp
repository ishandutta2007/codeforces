#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int test;
  cin >> test;
  while (test--)
  {
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
      cin >> a[i];
    sort(begin(a), end(a));

    if (a[0] == x && a[n - 1] == x) cout << 0 << endl;
    else if (accumulate(begin(a), end(a), 0) == x * n || find(begin(a), end(a), x) != end(a)) cout << 1 << endl;
    else cout << 2 << endl;
  }
}