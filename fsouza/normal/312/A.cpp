#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <set>
#include <algorithm>
#include <cstdlib>
#include <map>
#include <numeric>

using namespace std;

typedef long long lint;

int main() {
  int n;
  static char line[128];

  scanf("%d", &n);
  fgets(line, 128, stdin);

  for (int i = 0; i < n; i++) {
    fgets(line, 128, stdin);
    line[strlen(line)-1] = '\0';
    int linelen = strlen(line);
    const char *miao = "miao.";
    const char *lala = "lala.";
    int miaolen = strlen(miao);
    int lalalen = strlen(lala);
    bool didmiao = false;
    bool didlala = false;

    if (strstr(line, miao) == line) didmiao = true;
    if (linelen >= lalalen && strstr(line + linelen - lalalen, lala) == line + linelen - lalalen) didlala = true;

    if (didmiao + didlala != 1) cout << "OMG>.< I don't know!" << endl;
    else if (didmiao) cout << "Rainbow's" << endl;
    else cout << "Freda's" << endl;
  }

  return 0;
}