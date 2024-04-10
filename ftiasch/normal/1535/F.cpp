#include <bits/stdc++.h>

#define ALL(v) (v).begin(), (v).end()

namespace {

struct Node {
  Node() { memset(go, -1, sizeof(go)); }

  int go[26];
  std::vector<int> indices;
};

int count(const std::vector<int> &indices, int begin, int end) {
  return std::lower_bound(ALL(indices), end) -
         std::lower_bound(ALL(indices), begin);
}

long long solve(std::vector<std::string> &&s) {
  const int n = s.size();
  const int m = s[0].size();
  std::sort(ALL(s));
  std::vector<Node> trie(n * m + 1);
  std::vector<std::vector<int>> position(n, std::vector<int>(m + 1));
  int trie_size = 1;
  for (int i = 0; i < n; ++i) {
    int p = 0;
    trie[0].indices.push_back(i);
    position[i][m] = 0;
    for (int j = m; j--;) {
      int c = s[i][j] - 'a';
      if (!~trie[p].go[c]) {
        trie[p].go[c] = trie_size++;
      }
      p = trie[p].go[c];
      trie[p].indices.push_back(i);
      position[i][j] = p;
    }
  }
//   for (int i = 0; i < n; ++i) {
//     std::cerr << s[i] << std::endl;
//   }
  long long result = 0;
  std::vector<std::pair<int, int>> stack{{n, -1}};
  for (int i = n - 1; i--;) {
    int cur_lcp = 0;
    while (cur_lcp < m && s[i][cur_lcp] == s[i + 1][cur_lcp]) {
      cur_lcp++;
    }
    while (cur_lcp <= stack.back().second) {
      stack.pop_back();
    }
    stack.emplace_back(i + 1, cur_lcp);
    int first_descent = m;
    for (int j = m - 2; j >= cur_lcp; j--) {
      if (s[i][j] > s[i][j + 1]) {
        first_descent = j + 1;
      }
    }
    for (int j = stack.size(); j-- > 1;) {
      int begin = stack[j].first;
      int end = stack[j - 1].first;
      int lcp = stack[j].second;
      if (lcp < m) {
        while (cur_lcp > lcp) {
          int j = --cur_lcp;
          if (s[i][j] > s[i][j + 1]) {
            first_descent = j + 1;
          }
        }
        // std::cerr << "i=" << i << "|begin=" << begin << "|end=" << end
        //           << "|lcp=" << lcp << "|first=" << first_descent << std::endl;
        result += (end - begin) << 1;
        result -= count(trie[position[i][first_descent]].indices, begin, end);
      }
    }
  }
//   std::cerr << "---" << std::endl;
  return result;
}

} // namespace

int main() {
  std::ios::sync_with_stdio(false);
  int n;
  std::cin >> n;
  std::unordered_map<std::string, std::vector<std::string>> strings;
  for (int _ = 0; _ < n; ++_) {
    std::string s;
    std::cin >> s;
    auto sorted_s = s;
    std::sort(ALL(sorted_s));
    strings[sorted_s].push_back(s);
  }
  long long result = 0;
  int count = 0;
  for (auto &&[_, s] : strings) {
    result += 1337LL * count * s.size();
    count += s.size();
    result += solve(std::move(s));
  }
  std::cout << result << std::endl;
}