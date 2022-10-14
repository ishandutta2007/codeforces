#include <bits/stdc++.h>

const int N = 100'000;

int n, m, len, degree[N];
char p[N][5];
std::vector<int> graph[N];
std::unordered_map<std::string, int> pattern_map;

bool work() {
  char s[5], t[5];
  t[len] = '\0';
  for (int i = 0, mt; i < m; ++i) {
    scanf("%s%d", s, &mt);
    mt--;
    for (int i = 0; i < len; ++i) {
      if (p[mt][i] != '_' && p[mt][i] != s[i]) {
        return false;
      }
    }
    for (int mask = 0; mask < 1 << len; ++mask) {
      for (int i = 0; i < len; ++i) {
        t[i] = (mask >> i & 1) ? s[i] : '_';
      }
      auto iterator = pattern_map.find(t);
      if (iterator != pattern_map.end() && iterator->second != mt) {
        int v = iterator->second;
        degree[v]++;
        graph[mt].push_back(v);
      }
    }
  }
  std::vector<int> queue;
  for (int i = 0; i < n; ++i) {
    if (!degree[i]) {
      queue.push_back(i);
    }
  }
  for (int head = 0; head < static_cast<int>(queue.size()); ++head) {
    int u = queue[head];
    for (int v : graph[u]) {
      degree[v]--;
      if (!degree[v]) {
        queue.push_back(v);
      }
    }
  }
  if (static_cast<int>(queue.size()) < n) {
    return false;
  }
  puts("YES");
  for (int i = 0; i < n; ++i) {
    printf("%d%c", queue[i] + 1, " \n"[i + 1 == n]);
  }
  return true;
}

int main() {
  scanf("%d%d%d", &n, &m, &len);
  for (int i = 0; i < n; ++i) {
    scanf("%s", p[i]);
    pattern_map[p[i]] = i;
  }
  if (!work()) {
    puts("NO");
  }
}