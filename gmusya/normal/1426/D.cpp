#include <iostream>
#include <vector>
#include <set>

using namespace std;

typedef long long ll;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector <ll> a(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];
  set <ll> s;
  ll sum = 0, ans = 0;
  for (int i = 0; i < n; i++) {
    sum += a[i];
    if (s.find(sum) != s.end() || sum == 0) {
      ans++;
      s = set <ll>();
      sum = a[i];
    }
    s.insert(sum);
  }
  cout << ans;
  return 0;
}