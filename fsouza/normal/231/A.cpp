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
  int n;
  cin >> n;

  int ret = 0;

  for (int i = 0; i < n; i++) {
    int many = 0;

    for (int j = 0; j < 3; j++) {
      int v;
      cin >> v;
      many += v;
    }
    if (many >= 2) ret++;
  }

  cout << ret << endl;

  return 0;
}