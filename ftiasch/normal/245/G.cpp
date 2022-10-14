#include <bits/stdc++.h>

#define SIZE(v) static_cast<int>(v.size())
#define ALL(v) (v).begin(), (v).end()

const int M = 5000;

int m;
std::string a_name[M], b_name[M];

std::vector<std::string> names;

int get_id(std::string name) {
  return std::lower_bound(ALL(names), name) - names.begin();
}

const int N = M << 1;

std::vector<int> friends[N];

struct {
  void reset() { now++; }

  void set(int i, int v) {
    count[i] = v;
    timestamp[i] = now;
  }

  int add(int i) {
    if (timestamp[i] != now) {
      count[i] = 0;
      timestamp[i] = now;
    }
    return ++count[i];
  }

  int now = -1, count[N], timestamp[N];
} counter;

int main() {
  std::cin >> m;
  for (int i = 0; i < m; ++i) {
    std::cin >> a_name[i] >> b_name[i];
    names.push_back(a_name[i]);
    names.push_back(b_name[i]);
  }
  std::sort(ALL(names));
  names.erase(std::unique(ALL(names)), names.end());
  for (int i = 0; i < m; ++i) {
    int a = get_id(a_name[i]);
    int b = get_id(b_name[i]);
    friends[a].push_back(b);
    friends[b].push_back(a);
  }
  int n = SIZE(names);
  printf("%d\n", n);
  for (int u = 0; u < n; ++u) {
    counter.reset();
    counter.set(u, -n);
    for (int v : friends[u]) {
      counter.set(v, -n);
    }
    int max = 0;
    int count = 0;
    for (int v : friends[u]) {
      for (int w : friends[v]) {
        int value = counter.add(w);
        if (max < value) {
          max = value;
          count = 0;
        }
        if (max == value) {
          count++;
        }
      }
    }
    if (max == 0) {
      count = n - 1 - SIZE(friends[u]);
    }
    printf("%s %d\n", names[u].c_str(), count);
  }
}