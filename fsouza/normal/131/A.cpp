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
#include <cctype>

using namespace std;

int main() {
  char s[128];
  scanf(" %s", s);
  
  bool allup = true;

  for (int i = 1; s[i]; i++)
    if (islower(s[i]))
      allup = false;

  if (allup) {
    for (int i = 0; s[i]; i++)
      if (islower(s[i])) s[i] = s[i]-'a'+'A';
      else if (isupper(s[i])) s[i] = s[i]-'A'+'a';
  }

  printf("%s\n", s);

  return 0;
}