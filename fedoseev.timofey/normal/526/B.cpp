#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

int main() {
  int n;
  cin >> n;
  int cnt = (1 << (n + 1)) - 1;
  vector<int> a(cnt + 1);
  for (int i = 2; i <= cnt; ++i) {
    cin >> a[i];
  } 
  vector<long long> sum(cnt + 1);
  ll ans = 0;
  for (int x = cnt; x >= 2; x -= 2) {
    int y = x ^ 1;
    ans += max(sum[x] + a[x], sum[y] + a[y]) - min(sum[x] + a[x], sum[y] + a[y]);
    sum[x / 2] = max(sum[x] + a[x], sum[y] + a[y]);
  }
  cout << ans << '\n';
}