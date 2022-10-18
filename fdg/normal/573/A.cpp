#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <memory.h>

using namespace std;

vector<int> v;

int main() {
  int n;
  scanf("%d", &n);
  while (n--) {
    int x;
    scanf("%d", &x);
    while (x % 2 == 0) x /= 2;
    while (x % 3 == 0) x /= 3;
    v.push_back(x);
  }
  sort(v.begin(), v.end());
  puts(v[0] == v.back() ? "Yes" : "No");
  return 0;
}