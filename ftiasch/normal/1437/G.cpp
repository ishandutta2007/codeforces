#line 1 "sol.cpp"
#include <bits/stdc++.h>

const int N = 300'001;
const int C = 26;

int n, q, trie_sz, trie[N][C], end[N], value[N], best_value[N], go[N][C],
    fail[N], fast[N];
char buf[N];
bool is_end[N];
std::set<std::pair<int, int>> values[N];

int main() {
  scanf("%d%d", &n, &q);
  memset(trie, -1, sizeof(trie));
  trie_sz = 1;
  for (int i = 0; i < n; ++i) {
    scanf("%s", buf);
    int &p = end[i] = 0;
    for (int j = 0; buf[j]; ++j) {
      int c = buf[j] - 'a';
      if (!~trie[p][c]) {
        trie[p][c] = trie_sz++;
      }
      p = trie[p][c];
    }
    is_end[p] = true;
    values[p].emplace(0, i);
  }
  {
    std::vector<int> queue;
    queue.reserve(trie_sz);
    for (int c = 0; c < C; ++c) {
      if (~trie[0][c]) {
        fail[go[0][c] = trie[0][c]] = 0;
        queue.push_back(go[0][c]);
      } else {
        go[0][c] = 0;
      }
    }
    for (int head = 0; head < static_cast<int>(queue.size()); ++head) {
      int u = queue[head];
      fast[u] = is_end[u] ? u : fast[fail[u]];
      for (int c = 0; c < C; ++c) {
        if (~trie[u][c]) {
          fail[go[u][c] = trie[u][c]] = go[fail[u]][c];
          queue.push_back(trie[u][c]);
        } else {
          go[u][c] = go[fail[u]][c];
        }
      }
    }
  }
  while (q--) {
    int op;
    scanf("%d", &op);
    if (op == 1) {
      int id, v;
      scanf("%d%d", &id, &v);
      id--;
      int p = end[id];
      values[p].erase({value[id], id});
      value[id] = v;
      values[p].emplace(value[id], id);
      best_value[p] = values[p].rbegin()->first;
    } else {
      int result = -1;
      int p = 0;
      scanf("%s", buf);
      for (int j = 0; buf[j]; ++j) {
        int c = buf[j] - 'a';
        p = go[p][c];
        int q = fast[p];
        while (q) {
          result = std::max(result, best_value[q]);
          q = fast[fail[q]];
        }
      }
      printf("%d\n", result);
    }
  }
}