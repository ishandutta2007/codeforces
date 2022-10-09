#include <iostream>
#include <vector>

using namespace std;

int main() {
  long long n, k, ans = 0;
  cin >> n >> k;
  ans += 2 * n / k + 5 * n / k + 8 * n / k;
  if(2 * n % k != 0) ans++;
  if(5 * n % k != 0) ans++;
  if(8 * n % k != 0) ans++;
  cout << ans;
}