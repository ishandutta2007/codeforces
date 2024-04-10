#include <iostream>
#include <vector>
#include <algorithm>

typedef long long ll;

using namespace std;

int main() {
  int n;
  cin >> n;
  vector <ll> a(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];
  ll sum = 0, ans = 0;
  for (int i = 0; i < n; i++)
    sum += a[i], ans = max(ans, a[i]);
  cout << max((sum + n - 2) / (n - 1), ans);
  return 0;
}