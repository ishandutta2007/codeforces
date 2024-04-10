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

  int ret = 0;
  int hc = 0, hp = 0;

  while ((c = getchar()) != -1) {
    if (c == 'C') {
      if (hp == 0 && hc+1 <= 5)
	hc++;
      else {
	ret++;
	hc = 1, hp = 0;
      }
    } else if (c == 'P') {
      if (hc == 0 && hp+1 <= 5)
	hp++;
      else {
	ret++;
	hc = 0, hp = 1;
      }
    }
  }

  if (hc || hp) ret++;
  
  printf("%d\n", ret);

  return 0;
}