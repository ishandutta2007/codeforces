#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <set>

using namespace std;

typedef long long lint;

int main() {
  char s1[1024], s2[1024];

  scanf("%1024[^.].%1024[^.]", s1, s2);

  if (s1[strlen(s1)-1] == '9') printf("GOTO Vasilisa.\n");
  else if (s2[0] < '5') printf("%s\n", s1);
  else {
    s1[strlen(s1)-1]++;
    printf("%s\n", s1);
  }

  return 0;
}