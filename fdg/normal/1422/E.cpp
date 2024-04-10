#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cstring>
#include <memory.h>

using namespace std;

char s[100005];
char pnx[100005];

string ret[100005];
int len[100005];

string get(const string &ss) {
  if (ss.size() <= 10) {
    string xx = ss;
    reverse(xx.begin(), xx.end());
    return xx;
  }
  string x;
  for (int i = 0; i < 5; ++i)
    x += ss[ss.size() - 1 - i];
  x += "...";
  x += ss[1];
  x += ss[0];
  return x;
}

int main() {
  scanf("%s", s);
  int n = strlen(s);

  string suf; char nx = '\0';
  pnx[n] = nx;
  bool canPop = false;
  for (int i = n - 1; i >= 0; --i) {
    if (suf.size() == 0) {
      suf += s[i];
      canPop = true;
    } else if (suf.back() == s[i]) {
      if (nx <= s[i] && canPop) {
        suf.pop_back();
        nx = pnx[i + 2];
        canPop = false;
      } else {
        suf += s[i];
        canPop = true;
      }
    } else {
      nx = suf.back();
      suf += s[i];
      canPop = true;
    }

    len[i] = suf.size();
    ret[i] = get(suf);
  
    pnx[i] = nx;
  }

  for (int i = 0; i < n; ++i) {
    printf("%d %s\n", len[i], ret[i].c_str());
  }

  return 0;
}