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
  long long n, k;
  cin >> n >> k;
  vector<int> v;
  while (n > 0) {
    v.push_back(n % 10);
    n /= 10;
  }
  reverse(v.begin(), v.end());
  for (int i = 0; i < v.size(); ++i) {
    for (int d = 9; d > v[i]; --d) {
      for (int j = i + 1; j < v.size(); ++j) {
        if (v[j] == d && (j - i) <= k) {
          v.erase(v.begin() + j);
          v.insert(v.begin() + i, d);
          k -= (j - i);
          break;
        }
      }
    }
  }
  for (int i = 0; i < v.size(); ++i)
    cout << v[i];
  cout << endl;
  return 0;
}