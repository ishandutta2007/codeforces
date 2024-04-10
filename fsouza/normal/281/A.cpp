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
  string s;
  cin >> s;
  if ('a' <= s[0] && s[0] <= 'z') s[0] = (s[0] - 'a') + 'A';
  cout << s << endl;
  return 0;
}