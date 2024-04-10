#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

const ll MOD = 998244353;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector <int> a(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];
  vector <ll> old(1'001);
  old[0] = 1;
  for (int i = 0; i < n; i++) {
    vector <ll> ne(1'001);
    for (int j = 0; j < 1'000; j++)
      ne[j] = old[j + 1];
    if (1 <= a[i] && a[i] <= 999)
      ne[a[i]] += old[0];
    for (int i = 0; i <= 1'000; i++) {
      old[i] += ne[i];
      while (old[i] >= MOD)
        old[i] -= MOD;
    }
  }
  old[0] += MOD - 1;
  if (old[0] >= MOD)
    old[0] -= MOD;
  cout << old[0];
  return 0;
}