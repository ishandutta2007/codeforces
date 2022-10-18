#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <memory.h>

using namespace std;

vector<int> a1, a2;

int main() {
  int n, a;
  scanf("%d", &n);
  long long s1 = 0, s2 = 0;
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a);
    if (a > 0) {
      s1 += a;
      a1.push_back(a);
    }
    else {
      s2 -= a;
      a2.push_back(-a);
    }
  }
  int win = -1;
  if (s1 == s2) {
    for (int i = 0; i < a1.size() && i < a2.size(); ++i) {
      if (a1[i] > a2[i]) {
        win = 1;
        break;
      }
      if (a2[i] > a1[i]) {
        win = 0;
        break;
      }
    }
    if (win == -1) {
      if (a1.size() == a2.size()) {
        win = a > 0;   
      } else win = a1.size() > a2.size();
    }
  } else win = s1 > s2;
  puts(win ? "first" : "second");
  return 0;
}