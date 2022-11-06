#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <numeric>
#include <utility>

using namespace std;

typedef long long lint;

char line[201];

int main() {
  const char *wub = "WUB";

  scanf(" %s", line);
  int n = strlen(line);
  int nword = 0;

  for (int i = 0; i < n;) {
    if (!strncmp(line+i, wub, 3))
      i += 3;
    else {
      if (nword > 0) printf(" ");
      while (i < n && strncmp(line+i, wub, 3))
	printf("%c", line[i++]);
      nword++;
    }
  }
  printf("\n");
  
  return 0;
}