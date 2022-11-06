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
  int n, ret;

  cin >> n;

  if (n >= 0) ret = n;
  if (n < 0) {
    int inv = -n;
    ret = max(-inv/10, -((inv/100)*10 + inv%10));
  }

  cout << ret << endl;

  return 0;
}