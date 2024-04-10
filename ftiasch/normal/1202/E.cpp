#line 1 "sol.cpp"
#include <bits/stdc++.h>

const int N = 200000;
const int C = 26;

std::string t, s[N];
int count[2][N], trie[N + 1][C], go[N + 1][C], fail[N + 1], mark[N + 1];

int main() {
  std::ios::sync_with_stdio(false);
  std::cin >> t;
  int n;
  std::cin >> n;
  for (int i = 0; i < n; ++i) {
    std::cin >> s[i];
  }
  int m = t.size();
  for (int _ = 0; _ < 2; ++_) {
    memset(trie, -1, sizeof(trie));
    memset(mark, 0, sizeof(mark));
    int size = 1;
    for (int i = 0; i < n; ++i) {
      int p = 0;
      for (int j = 0; j < static_cast<int>(s[i].size()); ++j) {
        int c = s[i][j] - 'a';
        if (!~trie[p][c]) {
          trie[p][c] = size++;
        }
        p = trie[p][c];
      }
      mark[p]++;
    }
    std::queue<int> queue;
    for (int c = 0; c < C; ++c) {
      int v = trie[0][c];
      if (~v) {
        fail[v] = 0;
        queue.push(go[0][c] = v);
      } else {
        go[0][c] = 0;
      }
    }
    while (!queue.empty()) {
      int u = queue.front();
      queue.pop();
      mark[u] += mark[fail[u]];
      for (int c = 0; c < C; ++c) {
        int v = trie[u][c];
        if (~v) {
          fail[v] = go[fail[u]][c];
          queue.push(go[u][c] = v);
        } else {
          go[u][c] = go[fail[u]][c];
        }
      }
    }
    int p = 0;
    for (int i = 0; i < m; ++i) {
      p = go[p][t[i] - 'a'];
      count[_][i] = mark[p];
    }
    std::reverse(t.begin(), t.end());
    for (int i = 0; i < n; ++i) {
      std::reverse(s[i].begin(), s[i].end());
    }
  }
  long long result = 0;
  for (int i = 0; i < m - 1; ++i) {
    result += 1LL * count[0][i] * count[1][m - 2 - i];
  }
  std::cout << result << std::endl;
}