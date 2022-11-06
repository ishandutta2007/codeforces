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
#include <unordered_map>
#include <vector>

#define MAXN 1000
#define MAXS 50

using namespace std;

typedef long long lint;

const int mod = 1e9 + 7;

struct AhoCorasick {
  static const int nletter = 10;
  struct node {
    node *go[nletter] = {}, *failure = {};
    int dp[2][2][MAXS+1]; // any keyword, "down"
    bool anykeyword = false;
    template <typename F> void each(const F &func) {
      func(this);
      for (int i = 0; i < nletter; ++i) {
	node *child = go[i];
	if (child != nullptr && child != this)
	  child->each(func);
      }
    }
  };

  node pool[1+MAXN*MAXS/2], *root = pool;
  int nnode = 1;

  void calc_dp(vector<int> &limit) {
    int size = limit.size();

    root->each([&](node *v) {
	for (int fk = 0; fk < 2; ++fk)
	  for (int down = 0; down < 2; ++down)
	    for (int i = 0; i <= size; ++i)
	      v->dp[fk][down][i] = 0;
      });
    root->dp[0][0][0] = 1;

    for (int i = 0; i < size; ++i)
      root->each([&](node *v) {
	  for (int val = 0; val < nletter; ++val) {
	    node *v2 = iterate(v, val);
	    for (int fk = 0; fk < 2; ++fk)
	      for (int down = 0; down < 2; ++down) {
		int newfk = fk || v2->anykeyword;
		if (down || val <= limit[i]) {
		  int newdown = down || val < limit[i];
		  v2->dp[newfk][newdown][i+1] = (v2->dp[newfk][newdown][i+1] + v->dp[fk][down][i]) % mod;
		}
	      }
	  }
	});
  }
  node *add(int size, int *values, int keywordid) {
    assert(size > 0);
    node *v = root;
    for (int i = 0; i < size; ++i) {
      node *&u = v->go[values[i]];
      if (!u) u = &pool[nnode++];
      v = u;
    }
    v->anykeyword = true;
    return v;
  }
  void build() {
    queue<node*> q;
    for (int i = 0; i < nletter; ++i) {
      node *&v = root->go[i];
      if (v) {
	v->failure = root;
	q.push(v);
      } else {
	v = root;
      }
    }
    while (!q.empty()) {
      node *u = q.front(); q.pop();
      for (int i = 0; i < nletter; ++i) {
	node *v = u->go[i];
	if (v) {
	  node *x = u->failure;
	  while (!x->go[i]) x = x->failure;
	  v->failure = x->go[i];
	  if (v->failure)
	    v->anykeyword |= v->failure->anykeyword;
	  q.push(v);
	}
      }
    }
  }
  node *iterate(node *v, int value) {
    while (!v->go[value]) v = v->failure;
    return v->go[value];
  }
};

vector<int> read() {
  string s;
  cin >> s;
  vector<int> result(s.size());
  for (int i = 0; i < (int)result.size(); ++i)
    result[i] = s[i] - '0';
  return result;
}

AhoCorasick aho;

int main() {
  vector<int> text = read(), start = read(), end = read();
  int size = start.size(), half = size/2;
  using node = AhoCorasick::node;

  for (int i = 0; i + half <= (int)text.size(); ++i)
    aho.add(half, &text[i], i);
  aho.build();

  lint result = 0;

  aho.calc_dp(end);
  aho.root->each([&](node *v) {
      result += v->dp[1][0][end.size()];
      result += v->dp[1][1][end.size()];
    });
  aho.calc_dp(start);
  aho.root->each([&](node *v) {
      result -= v->dp[1][1][end.size()];
    });
  result %= mod; if (result < 0) result += mod;

  printf("%d\n", (int)result);

  return 0;
}