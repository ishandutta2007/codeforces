#include <iostream>
#include <vector>
#include <iomanip>

#define fsp(x) fixed << setprecision(x)

using namespace std;

typedef long long ll;
typedef long double ld;

int main() {
  int n;
  cin >> n;
  vector <int> a(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];
  vector <int> last(1'000'001, -1);
  vector <ll> ans(n);
  ans[0] = 1;
  last[a[0]] = 0;
  for (int i = 1; i < n; i++) {
    ans[i] = ans[i - 1] + (i - last[a[i]]);
    last[a[i]] = i;
  }
  ll sum = 0;
  for (int i = 0; i < n; i++)
    sum += 2 * ans[i] - 1;
  cout << fsp(15) << (ld) sum / (ld)(n * 1ll * n);
  return 0;
}