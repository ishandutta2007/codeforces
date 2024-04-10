#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <utility>
#include <numeric>

using namespace std;

int main() {
  int c;

  while ((c = getchar()) != -1)
      if (c == 'H' || c == 'Q' || c == '9') {
	printf("YES\n");
	return 0;
      }
  
  printf("NO\n");

  return 0;
}