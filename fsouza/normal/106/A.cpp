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

typedef long long lint;

pair<char, int> read() {
  char c1, c2;
  scanf(" %c %c", &c1, &c2);

  int r;

  if ('6' <= c1 && c1 <= '9') r = c1-'0';

  if (c1 == 'T') r = 10;
  if (c1 == 'J') r = 11;
  if (c1 == 'Q') r = 12;
  if (c1 == 'K') r = 13;
  if (c1 == 'A') r = 14;

  return make_pair(c2, r);
}

int main() {
  char trump;
  
  scanf(" %c", &trump);

  pair<char, int> c1 = read();
  pair<char, int> c2 = read();

  bool win = (c1.first == trump && c2.first != trump) || (c1.first == c2.first && c1.second > c2.second);

  if (win) printf("YES\n");
  else printf("NO\n");

  return 0;
}