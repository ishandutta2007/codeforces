#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <memory.h>

using namespace std;

int main() {
  int n, my;
  cin >> n >> my;

  vector<int> who(1, 1);

  int a, total = my, cur = my;
  for (int i = 1; i < n; ++i) {
    cin >> a;
    if (my >= 2 * a) {
      who.push_back(i + 1);
      cur += a;
    }
    total += a;
  }

  if (2 * cur > total) {
    cout << who.size() << endl;
    for (int x : who)
      cout << x << " ";
    cout << endl;
  } else {
    cout << 0 << endl;
  }
  return 0;
}