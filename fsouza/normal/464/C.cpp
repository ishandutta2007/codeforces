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

#define MAXS 100000
#define MAXQS (100000+5)

using namespace std;

typedef long long lint;

const int p = 1000000007;

struct node;

char s[MAXS+1];
char target[MAXQS+4];
vector<node> nodes;

struct node {
  int v;
  vector<int> child;
  bool calc;
  int modp, p10l;
  node(int v): v(v) {}

  void go() {
    if (calc) return;
    calc = true;
    
    if (v != -1) {
      p10l = 10;
      modp = v;
    } else {
      int ret = 0;
      int fullp10 = 1;
      for (int i = (int)child.size()-1; i >= 0; i--) {
	nodes[child[i]].go();
	ret = (ret + (lint)nodes[child[i]].modp * fullp10) % p;
	fullp10 = ((lint)fullp10 * nodes[child[i]].p10l) % p;
      }
      modp = ret;
      p10l = fullp10;
    }
  }
};

int main() {
  scanf(" %s", s);

  int n;

  scanf("%d", &n);
  nodes.clear();

  int last[10];

  for (int i = 0; i < 10; i++) {
    nodes.push_back(node(i));
    last[i] = i;
  }

  for (int i = 0; i < n; i++) {
    int digit;
    scanf("%d->", &digit);
    fgets(target, MAXQS+3, stdin);
    target[strlen(target)-1] = '\0';
    
    int newlastd = nodes.size();
    nodes.push_back(node(digit));

    int oldlast = last[digit];

    last[digit] = newlastd;

    node &old = nodes[oldlast];
    
    old.v = -1;
    old.child.clear();
    for (int j = 0; target[j]; j++)
      old.child.push_back(last[target[j]-'0']);
  }

  int root = nodes.size();
  nodes.push_back(node(-1));

  for (int i = 0; s[i]; i++)
    nodes[root].child.push_back(s[i]-'0');

  for (int i = 0; i < (int)nodes.size(); i++)
    nodes[i].calc = false;

  nodes[root].go();

  printf("%d\n", nodes[root].modp);

  return 0;
}