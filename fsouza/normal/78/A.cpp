#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <numeric>
#include <utility>

using namespace std;

typedef long long lint;

int main() {
  bool ok = true;
  
  for (int y = 0; y < 3; y++) {
    int v = 0;

    static char line[128];
    fgets(line, 128, stdin);
    
    for (int i = 0; line[i]; i++)
      if (strchr("aeiou", line[i]))
	v++;
    
    if (v != (int[]){5, 7, 5}[y])
      ok = false;
  }

  if (ok) printf("YES\n");
  else printf("NO\n");

  return 0;
}