#include <algorithm>
#include <cassert>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <vector>

#define MAXS 800000

using namespace std;

typedef long long lint;

struct Trie {
  struct node {
    node *children[26];
    list<int> ids[2];
    void add(const char *s, int kind, int id) {
      if (!*s) ids[kind].push_back(id);
      else {
	node *&child = children[*s-'a'];
	if (!child) child = new node();
	child->add(s+1, kind, id);
      }
    }
    tuple<int, list<int>, list<int>> solve(vector<pair<int, int>> &matching, int depth = 0) {
      int result = 0;
      for (int c = 0; c < 26; ++c) {
	node *child = children[c];
	if (child) {
	  int res;
	  list<int> ids0, ids1;
	  tie(res, ids0, ids1) = child->solve(matching, depth+1);
	  result += res;
	  ids[0].splice(ids[0].end(), ids0);
	  ids[1].splice(ids[1].end(), ids1);
	}
      }
      while (!ids[0].empty() && !ids[1].empty()) {
	int id0 = ids[0].back(), id1 = ids[1].back();
	matching.push_back({id0, id1});
	ids[0].pop_back();
	ids[1].pop_back();
	result += depth;
      }
      return make_tuple(result, move(ids[0]), move(ids[1]));
    }
  } *root = new node();
};

int main() {
  Trie trie;
  int n;
  scanf("%d", &n);
  for (int kind = 0; kind < 2; ++kind)
    for (int i = 0; i < n; ++i) {
      static char str[MAXS+1];
      scanf("%s", str);
      trie.root->add(str, kind, i);
    }

  vector<pair<int, int>> matching;
  int result = get<0>(trie.root->solve(matching));

  printf("%d\n", result);
  for (pair<int, int> lr : matching) {
    int l, r; tie(l, r) = lr;
    printf("%d %d\n", l+1, r+1);
  }
  
  return 0;
}