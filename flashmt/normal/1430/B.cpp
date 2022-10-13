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
    int n, k, a[200200];
    cin >> n >> k;
    for (int i = 0; i < n; i++)
      cin >> a[i];
    sort(a, a + n, greater<int>());
    long long sum = 0;
    for (int i = 0; i <= k; i++)
      sum += a[i];
    cout << sum << endl;
  }
}