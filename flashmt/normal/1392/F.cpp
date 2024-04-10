#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  vector<long long> a(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];
  long long sum = accumulate(begin(a), end(a), 0LL);
  long long each = (sum - n * (n - 1LL) / 2) / n;
  int rem = (sum - n * (n - 1LL) / 2) % n;
  for (int i = 0; i < n; i++)
    cout << each + (i < rem) + i << " \n"[i == n - 1];
}