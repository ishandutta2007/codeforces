#include <cmath>
#include <ctime>
#include <cctype>
#include <cstdio>
#include <cstring>
#include <cstdlib>

#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>

#include <stack>
#include <queue>
#include <vector>

#include <bitset>

#include <string>

#include <algorithm>
#include <functional>

#include <iostream>
#include <sstream>

using namespace std;
typedef long long llint;

#define pb push_back

#define MAX 100005

int N, K;
char buf[MAX];

struct node {
  node *c[26];
  node() {
    memset(c, 0, sizeof c);
  }
};

node *root;

void insert(char *s, int len, int pos, node *n) {
  if (pos == len) return;

  int i = s[pos] - 'a';
  if (n->c[i] == NULL) 
    n->c[i] = new node();

  insert(s, len, pos + 1, n->c[i]);
}

bool win(node *n) {
  for (int i = 0; i < 26; ++i)
    if (n->c[i] && !win(n->c[i]))
      return true;
  return false;
}

bool lose(node *n) {
  int cnt = 0;
  for (int i = 0; i < 26; ++i)
    if (n->c[i]) ++cnt;

  if (!cnt) return true;

  for (int i = 0; i < 26; ++i)
    if (n->c[i] && !lose(n->c[i]))
      return true;

  return false;
}

int main(void)
{
  root = new node();

  scanf("%d%d", &N, &K);

  for (int i = 0; i < N; ++i) {
    scanf("%s", buf);
    insert(buf, strlen(buf), 0, root);
  }

  int W = win(root);
  int L = lose(root);

  if (W && L)
    puts("First");
  else if (W) 
    puts(K % 2 == 1 ? "First" : "Second");
  else
    puts("Second");

  return 0;
}