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
  int n;
  scanf("%d", &n);

  vector<int> v;
  long long s = 0;
  for (int i = 0; i < n; ++i) {
    int a;
    scanf("%d", &a);
    if (a & 1) v.push_back(a);
    else s += a;
  }
  sort(v.rbegin(), v.rend());
  for (int i = 0; i + 1 < v.size(); i += 2) {
    s += v[i] + v[i + 1];
  }
  cout << s << endl;
  return 0;
}