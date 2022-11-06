#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <numeric>

typedef long long lint;

using namespace std;

int main() {
  int n;
  cin >> n;

  vector <int> v(n);
  int ret = 0;

  for (int j = 0; j < n; j++) {
    cin >> v[j];

    int xxor = 0;
    for (int i = j; i >= 0; i--) {
      xxor ^= v[i];
      ret = max(ret, xxor);
    }
  }
  
  cout << ret << endl;

  return 0;
}