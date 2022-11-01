#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector <ll> a(n + 1);
  for (int i = 1; i <= n; i++)
    cin >> a[i];
  vector <ll> odd(n + 1), even(n + 1);
  for (int i = 1; i <= n; i++) {
    if (i & 1) {
      odd[i] = odd[i - 1] + a[i];
      even[i] = even[i - 1];
    } else {
      even[i] = even[i - 1] + a[i];
      odd[i] = odd[i - 1];
    }
  }
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    ll od = 0, ev = 0;
    od = odd[i - 1], ev = even[i - 1];
    od += even[n] - even[i];
    ev += odd[n] - odd[i];
    if (od == ev)
      ans++;
  }
  cout << ans;
  return 0;
}