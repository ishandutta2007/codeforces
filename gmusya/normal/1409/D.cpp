#include <iostream>
#include <vector>
#include <string>

typedef unsigned long long ull;

using namespace std;

int sum (ull val) {
  int res = 0;
  while (val) {
    res += val % 10;
    val /= 10;
  }
  return res;
}

int main () {
  vector <ull> p10(20);
  p10[0] = 1;
  for (int i = 1; i < 20; i++)
    p10[i] = p10[i - 1] * 10;
  int t;
  cin >> t;
  while (t--) {
    ull val, s;
    cin >> val >> s;
    ull old_val = val;
    int id = 0;
    while (sum(val) > s) {
      int dig = val / p10[id] % 10;
      val += p10[id] * (10 - dig);
      id++;
    }
    cout << val - old_val << '\n';
  }
  return 0;
}