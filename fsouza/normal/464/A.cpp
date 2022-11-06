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

#define MAXN 1000
#define MAXP 26

using namespace std;

typedef long long lint;

int n, p;
char s[MAXN+1];

bool fail[MAXN][MAXP+1][MAXP+1][2];

vector<char> ret;

bool go(int i, int l0, int l1, int up) {
  if (i == n) {
    return up;
  }

  if (fail[i][l0][l1][up]) return false;

  int start;
  
  if (up) start = 0;
  else start = s[i] - 'a';
  
  for (int v = start; v < p; v++) {
    if (v != l0 && v != l1 && go(i+1, l1, v, (up || v > start))) {
      ret.push_back('a' + v);
      return true;
    }
  }

  fail[i][l0][l1][up] = true;
  return false;
}

int main() {
  scanf("%d %d %s", &n, &p, s);

  memset(fail, 0, sizeof(fail));

  if (go(0, p, p, 0)) {
    reverse(ret.begin(), ret.end());
    for (int i = 0; i < (int)ret.size(); i++)
      printf("%c", ret[i]);
    printf("\n");
  } else {
    printf("NO\n");
  }

  return 0;
}