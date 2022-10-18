#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <memory.h>

using namespace std;

struct item {
  item() {
    memset(next, -1, sizeof(next));
  };
  int next[26];
};

int bsz = 1;
item bor[100005];
char str[100005];

void add(char s[]) {
  int n = strlen(s), cur = 0;
  for (int i = 0; i < n; ++i) {
    if (bor[cur].next[s[i] - 'a'] == -1) {
      bor[cur].next[s[i] - 'a'] = bsz++;
    }
    cur = bor[cur].next[s[i] - 'a'];
  } 
}

bool win(int i) {
  bool ret = false;
  for (int j = 0; j < 26; ++j) {
    if (bor[i].next[j] != -1 && !win(bor[i].next[j]))
      ret = true;
  }
  return ret;
}

bool nwin(int i) {
  int cnt = 0;
  for (int j = 0; j < 26; ++j) {
    if (bor[i].next[j] != -1) ++cnt;
    if (bor[i].next[j] != -1 && !nwin(bor[i].next[j]))
      return true;
  }
  return cnt == 0;
}

int main() {
  int n, k;
  scanf("%d%d\n", &n, &k);
  for (int i = 0; i < n; ++i) {
    gets(str);
    add(str);
  }
  int wn = win(0);
  if (wn && (k & 1) || nwin(0) && wn)
    puts("First");
  else
    puts("Second");
  return 0;
}