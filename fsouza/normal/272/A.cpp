#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <map>
#include <algorithm>
#include <numeric>
#include <set>

typedef long long lint;

using namespace std;

int main() {
  int n;
  cin >> n;
  int sum = 0;
  for (int i = 0; i < n; i++) {
    int v;
    cin >> v;
    sum += v;
  }
  int ret = 0;
  for (int v = 1; v <= 5; v++) {
    int sum2 = sum + v;
    if ((sum2-1) % (n+1) != 0)
      ret++;
  }

  cout << ret << endl;

  return 0;
}