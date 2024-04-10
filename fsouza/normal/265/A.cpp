#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <numeric>

typedef long long lint;

using namespace std;

int main() {
  string s, t;
  cin >> s >> t;
  int i = 0;

  for (int j = 0; j < (int)t.size(); j++)
    if (s[i] == t[j])
      i++;

  cout << i+1 << endl;

  return 0;
}