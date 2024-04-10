#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

const ll MOD = 998244353;

int main() {
  vector <ll> rec(1'000'001);
  rec[1] = 1;
  ll fact = 1;
  for (int i = 2; i <= 1'000'000; i++) {
    rec[i] = (rec[i - 1] + fact - 1) % MOD * i % MOD;
    fact = fact * i % MOD;
  }
  int n;
  cin >> n;
  cout << rec[n];
  return 0;
}