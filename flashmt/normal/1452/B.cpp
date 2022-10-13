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
    int n, a[100100];
    cin >> n;
    for (int i = 0; i < n; i++)
      cin >> a[i];

    long long sum = accumulate(a, a + n, 0LL);
    int maxA = *max_element(a, a + n);
    long long target = max(sum, maxA * (n - 1LL));
    if (target % (n - 1))
      target += n - 1 - target % (n - 1);
    cout << target - sum << endl;
  }
}