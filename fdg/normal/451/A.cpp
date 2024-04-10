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
  int n, m;
  cin >> n >> m;
  if (min(n, m) & 1) cout << "Akshat\n";
  else cout << "Malvika\n";
  return 0;
}