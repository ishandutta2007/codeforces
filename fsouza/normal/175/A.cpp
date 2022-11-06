#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <set>

using namespace std;

int main() {
  string s;
  cin >> s;
  int n = s.size();

  int ret = -1;

  for (int a = 1; a < n; a++)
    for (int b = a+1; b < n; b++) {
      if (max(a-0, max(b-a, n-b)) > 7) continue;
      string s1 = s.substr(0, a-0);
      string s2 = s.substr(a, b-a);
      string s3 = s.substr(b, n-b);
      if (s1[0] == '0' && s1.size() != 1) continue;
      if (s2[0] == '0' && s2.size() != 1) continue;
      if (s3[0] == '0' && s3.size() != 1) continue;
      int v1, v2, v3;
      sscanf(s1.c_str(), "%d", &v1);
      sscanf(s2.c_str(), "%d", &v2);
      sscanf(s3.c_str(), "%d", &v3);
      if (max(v1, max(v2, v3)) > 1000000) continue;
      ret = max(ret, v1+v2+v3);
    }

  printf("%d\n", ret);

  return 0;
}