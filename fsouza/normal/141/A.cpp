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
  map<char, int> m[2];

  for (int y = 0; y < 3; y++) {
    int c;
    while ((c = getchar()) != '\n') {
      if ('A' <= c && c <= 'Z')
	m[y/2][c]++;
    }
  }

  printf((m[0] == m[1]) ? "YES\n" : "NO\n");

  return 0;
}