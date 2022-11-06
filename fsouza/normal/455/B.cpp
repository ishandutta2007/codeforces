#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <map>
#include <set>

using namespace std;

typedef long long lint;

struct node {
  map <char, node> child;
  void add(const char *s) {
    if (*s)
      child[*s].add(s+1);
  }
  pair <bool, bool> dp() {
    if (child.empty())
      return make_pair(true, false);
    bool first = false, second = false;
    for (map <char, node>::iterator it = child.begin(); it != child.end(); it++) {
      pair <bool, bool> dpchild = it -> second.dp();
      first |= !dpchild.first;
      second |= !dpchild.second;
    }
    return make_pair(first, second);
  }
};

int main() {
  int n, k;
  node root;

  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    root.add(s.c_str());
  }

  pair <bool, bool> dp = root.dp();
  int ret;
  
  if (dp.first && dp.second) ret = 0;
  else if (!dp.first && !dp.second) ret = 1;
  else if (dp.first) ret = 1;
  else if (k%2 == 1) ret = 0;
  else ret = 1;

  cout << (ret == 0 ? "First" : "Second") << endl;
  
  return 0;
}