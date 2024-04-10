#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

typedef long long ll;

using namespace std;

int main() {
  int n;
  cin >> n;
  vector <ll> a(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];
  map <ll, int> m;
  m[a[0]]++;
  for (int i = 1; i < n; i++) {
    a[i] += a[i - 1];
    m[a[i]]++;
  }
  int ans = 0;
  for (auto &now : m)
    ans = max(ans, now.second);
  cout << n - ans;
  return 0;
}