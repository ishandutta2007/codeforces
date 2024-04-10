#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <map>
#include <vector>
#include <set>
#include <algorithm>
#include <numeric>

using namespace std;

int main() {
  int s, n;

  cin >> s >> n;

  bool ok = true;

  vector <pair <int, int> > drag;

  for (int i = 0; i < n; i++) {
    int x, y;
    cin >> x >> y;
    drag.push_back(make_pair(x, y));
  }

  sort(drag.begin(), drag.end());

  for (int i = 0; i < n; i++) {
    if (s <= drag[i].first) {
      ok = false;
      break;
    }
    s += drag[i].second;
  }

  cout << (ok ? "YES" : "NO") << endl;

  return 0;
}