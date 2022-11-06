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

bool isvowel(char c) {
  const char *v = "aeiouy";
  for (int i = 0; v[i]; i++)
    if (v[i] == tolower(c))
      return true;
  return false;
}

int main() {
  int c;
  while ((c = getchar()) != -1)
    if (!isspace(c) && !isvowel(c))
      printf(".%c", tolower(c));
  printf("\n");

  return 0;
}