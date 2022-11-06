#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <numeric>
#include <utility>

using namespace std;

typedef long long lint;

int main() {
  string s;
  int n;

  cin >> s;
  n = s.size();

  string ret;

  for (int m = 0; m < (1<<n); m++) {
    string s2;
    for (int i = 0; i < n; i++)
      if (m & (1<<i))
	s2 += s[i];
    string s3 = s2;
    reverse(s3.begin(), s3.end());
    if (s2 == s3)
      ret = max(ret, s2);
  }

  cout << ret << endl;
  
  return 0;
}