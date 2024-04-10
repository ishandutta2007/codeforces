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
  int ret = 0;
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    if (s[1] == '+') ret++;
    else ret--;
  }

  cout << ret << endl;

  return 0;
}