#include <algorithm>
#include <array>
#include <bitset>
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
#include <memory>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <unordered_map>
#include <vector>

using namespace std;

typedef long long lint;

const int nlet = 26;

string solve(const vector<string> &strs) {
  const int n = strs.size();
  vector<vector<pair<int, int>>> letter_at(nlet);
  for (int j = 0; j < n; ++j) {
    const string &s = strs[j];
    int count[nlet] = {};
    for (int i = 0; i < (int)s.size(); ++i) {
      char c = s[i];
      if (++count[c - 'a'] >= 2)
        return "NO";
      letter_at[c - 'a'].emplace_back(j, i);
    }
  }

  vector<vector<pair<int, int>>> adj(n);
  for (int let = 0; let < nlet; ++let) {
    for (int i = 0; i + 1 < (int)letter_at[let].size(); ++i) {
      pair<int, int> a = letter_at[let][i];
      pair<int, int> b = letter_at[let][i + 1];
      adj[a.first].emplace_back(b.first, a.second - b.second);
      adj[b.first].emplace_back(a.first, b.second - a.second);
    }
  }

  vector<vector<int>> cnts;
  vector<int> pos(n, INT_MIN);
  bool ok = true;

  function<void(int, int)> dfs = [&](int v, int pos_v) {
    pos[v] = pos_v;
    cnts.back().push_back(v);
    for (pair<int, int> ed : adj[v]) {
      int u = ed.first, delta = ed.second;
      if (pos[u] == INT_MIN) {
        dfs(u, pos[v] + delta);
      } else if (pos[u] != pos[v] + delta) {
        ok = false;
      }
    }
  };
  for (int i = 0; i < n; ++i) {
    if (pos[i] == INT_MIN) {
      cnts.push_back({});
      dfs(i, 0);
    }
  }
  if (!ok)
    return "NO";

  vector<string> pieces;
  for (const vector<int> &cnt : cnts) {
    int leftmostpos = INT_MAX, rightmostpos = INT_MIN;
    for (int v : cnt) {
      leftmostpos = min(leftmostpos, pos[v]);
      rightmostpos = max(rightmostpos, pos[v] + (int)strs[v].size() - 1);
    }
    vector<int> piece(rightmostpos - leftmostpos + 1, -1);
    for (int v : cnt) {
      for (int i = 0; i < (int)strs[v].size(); ++i) {
        int c = strs[v][i] - 'a';
        if (piece[pos[v] + i - leftmostpos] != -1 &&
            piece[pos[v] + i - leftmostpos] != c) {
          ok = false;
        }
        piece[pos[v] + i - leftmostpos] = c;
      }
    }
    string piece_str(piece.size(), ' ');
    for (int i = 0; i < (int)piece.size(); ++i) {
      assert(piece[i] != -1);
      piece_str[i] = 'a' + piece[i];
    }
    pieces.push_back(move(piece_str));
  }
  if (!ok)
    return "NO";
  sort(pieces.begin(), pieces.end());
  string result;
  for (const string &piece : pieces) result += piece;
  return result;
}

int main() {
  int n;
  scanf("%d", &n);
  vector<string> strs;
  for (int i = 0; i < n; ++i) {
    const int maxsize = 1e5;
    static char str[maxsize + 1];
    scanf(" %s", str);
    strs.push_back(string(str));
  }
  printf("%s\n", solve(strs).c_str());
  return 0;
}