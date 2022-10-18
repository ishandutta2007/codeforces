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
  cin >> n;
  if (n & 1) cout << "black\n";
  else cout << "white\n1 2\n";
  return 0;
}