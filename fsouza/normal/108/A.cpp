#include<iostream>
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

typedef long long lint;

void advance(int &h, int &m) {
  m++;
  if (m == 60) {
    m = 0;
    h++;
    if (h == 24)
      h = 0;
  }
}

int main() {
  int h, m;
  scanf("%d:%d", &h, &m);
  
  advance(h, m);
  while(1) {
    char bla[6];
    snprintf(bla, 6, "%02d:%02d", h, m);
    if (bla[0] == bla[4] && bla[1] == bla[3]) {
      printf("%s\n", bla);
      break;
    }
    advance(h, m);
  }

  return 0;
}