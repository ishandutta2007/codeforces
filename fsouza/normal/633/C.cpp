#include <algorithm>
#include <cassert>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <vector>

#define MAXW 1000

using namespace std;

typedef long long lint;

struct Trie {
  struct node {
    node *child[26] = {};
    int many = 0;
    string orig;
  } root;
  void add(const string &s, const string &orig) {
    node *v = &root;
    for (int i = 0; i < (int)s.size(); ++i) {
      char c = s[i];
      node *&next = v->child[c-'a'];
      if (next == nullptr) next = new node();
      v = next;
    }
    ++v->many;
    v->orig = orig;
  }
};

int main() {
  int n;
  scanf("%d", &n);
  string text(n, ' ');
  scanf("%s", &text[0]);
  int nword;
  scanf("%d", &nword);
  Trie trie;
  for (int i = 0; i < nword; ++i) {
    static char cstr[MAXW+1];
    scanf("%s", cstr);
    string s(cstr), origs = s;
    int len = s.size();
    for (int i = 0; i < len; ++i)
      s[i] = tolower(s[i]);
    reverse(s.begin(), s.end());
    trie.add(s, origs);
  }

  vector<int> dp(n+1);
  vector<string*> word(n+1);
  dp[n] = -2;
  word[n] = nullptr;
  for (int i = n-1; i >= 0; --i) {
    Trie::node *v = &trie.root;
    dp[i] = -1;
    for (int j = i; j < n; ++j) {
      v = v->child[text[j]-'a'];
      if (v == nullptr) break;
      if (v->many > 0 && dp[j+1] != -1) {
	dp[i] = j+1;
	word[i] = &(v->orig);
	break;
      }
    }
  }

  for (int i = 0, j = dp[i]; i < n; i = j, j = dp[i]) {
    if (i > 0) printf(" ");
    printf("%s", word[i]->c_str());
  }
  printf("\n");
  
  return 0;
}