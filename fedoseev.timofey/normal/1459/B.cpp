#include <iostream>

using namespace std;

int main() {
  int n;
  cin >> n;
  int cnt1 = (n + 1) / 2;
  int cnt2 = n - cnt1;
  auto calc = [&](int n) {
    int ok = 0;
    for (int x = -n; x <= n; ++x) {
      if (((x % 2) + 2) % 2 == n % 2) {
        ++ok;
      }
    }
    return (long long)ok;
  };
  cout << (n % 2 == 1 ? 2 : 1) * calc(cnt1) * calc(cnt2) << '\n';
}