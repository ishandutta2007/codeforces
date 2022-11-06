#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <set>

using namespace std;

int main() {
  int n, t;

  scanf("%d %d", &n, &t); t--;

  vector<bool> reach(n, false);

  reach[0] = true;

  for (int i = 0; i < n-1; i++) {
    int ai;
    scanf("%d", &ai);
    reach[i + ai] = reach[i+ai] | reach[i];
  }

  printf(reach[t] ? "YES\n" : "NO\n");

  return 0;
}