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
  string s;
  cin >> n >> s;

  cout << s.size() - (unique(s.begin(), s.end()) - s.begin()) << endl;

  return 0;
}