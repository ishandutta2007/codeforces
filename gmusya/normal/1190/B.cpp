#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector <int> a(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];
  sort(a.begin(), a.end());
  int cnt = 0;
  for (int i = 0; i + 1 < n; i++)
    cnt += (a[i] == a[i + 1]);
  if (cnt >= 2 || (n >= 2 && a[1] == 0)) {
    cout << "cslnb";
    return 0;
  }
  for (int i = 1; i + 1 < n; i++)
    if (a[i - 1] + 1 >= a[i] && a[i] == a[i + 1]) {
      cout << "cslnb";
      return 0;
    }
  long long sum = 0;
  for (int i = 0; i < n; i++)
    sum += a[i] - i;
  if (sum % 2)
    cout << "sjfnb";
  else
    cout << "cslnb";
  return 0;
}