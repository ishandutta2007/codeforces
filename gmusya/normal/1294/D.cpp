#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int q, x;
  cin >> q >> x;
  set <pair <int, int>> s;
  for (int i = 0; i < x; i++)
    s.insert({0, i});
  vector <int> cnt(x);
  while (q--) {
    int val;
    cin >> val;
    val %= x;
    s.erase({cnt[val], val});
    cnt[val]++;
    s.insert({cnt[val], val});
    cout << x * s.begin()->first + s.begin()->second << '\n';
  }
  return 0;
}