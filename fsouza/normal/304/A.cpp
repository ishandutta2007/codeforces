#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
#include <algorithm>
#include <cstdlib>
#include <map>
#include <numeric>

using namespace std;

typedef long long lint;

int main() {
  int n, ret = 0;
  cin >> n;
  for (int a = 1; a <= n; a++) {
    int c = a;
    for (int b = a; a*a + b*b <= n*n; b++) {
      while (c*c < a*a + b*b) c++;
      if (c*c == a*a + b*b) ret++;
    }
  }
  cout << ret << endl;
  return 0;
}