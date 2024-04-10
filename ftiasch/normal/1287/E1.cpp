#include <bits/stdc++.h>

struct Mock {
  Mock(int n, const std::string &s) : n(n), s(s) {}

  std::vector<std::string> ask(int l, int r) {
    if (l > r) {
      return {};
    }
    std::vector<std::string> substrings;
    for (int i = l - 1; i < r; ++i) {
      for (int j = 1; i + j <= r; ++j) {
        auto ss = s.substr(i, j);
        std::shuffle(ss.begin(), ss.end(), gen);
        substrings.push_back(ss);
      }
    }
    std::shuffle(substrings.begin(), substrings.end(), gen);
    return substrings;
  }

  void out(const std::string &t) { assert(s == t); }

  int n;

private:
  std::string s;
  std::mt19937 gen;
};

struct IO {
  IO() { scanf("%d", &n); }

  std::vector<std::string> ask(int l, int r) {
    if (l > r) {
      return {};
    }
    printf("? %d %d\n", l, r);
    fflush(stdout);

    std::vector<char> buf(r - l + 2);
    std::vector<std::string> substrings;
    int size = (r - l + 2) * (r - l + 1) / 2;
    for (int i = 0; i < size; ++i) {
      scanf("%s", buf.data());
      substrings.push_back(buf.data());
    }
    return substrings;
  }

  void out(const std::string &t) {
    printf("! %s\n", t.c_str());
    fflush(stdout);
  }

  int n;
};

static const int C = 26;

using Count = std::array<int, C>;

Count toCount(const std::string &s) {
  Count result;
  memset(result.data(), 0, sizeof(result));
  for (char c : s) {
    result[c - 'a']++;
  }
  return result;
}

template <typename IO> std::string solve(IO &io) {
  int n = io.n;
  if (n == 1) {
    return io.ask(1, 1)[0];
  }
  int n2 = n >> 1;
  std::vector<int> s(n, 0);
  {
    std::map<Count, int> halfs;
    for (auto &&s : io.ask(1, n2)) {
      halfs[toCount(s)]++;
    }
    for (auto &&s : io.ask(2, n2)) {
      halfs[toCount(s)]--;
    }
    std::vector<std::pair<int, Count>> counts;
    for (auto &&kv : halfs) {
      if (kv.second) {
        int size = 0;
        for (int c : kv.first) {
          size += c;
        }
        counts.emplace_back(size, kv.first);
      }
    }
    std::sort(counts.begin(), counts.end());
    assert(static_cast<int>(counts.size()) == n2);
    for (int i = 0; i < n2; ++i) {
      auto count = counts[i].second;
      for (int j = 0; j < i; ++j) {
        count[s[j]]--;
      }
      while (!count[s[i]]) {
        s[i]++;
      }
    }
  }
  {
    std::vector<Count> counts(n + 1);
    for (auto &&s : io.ask(1, n)) {
      auto count = toCount(s);
      for (int j = 0; j < C; ++j) {
        counts[s.length()][j] += count[j];
      }
    }
    for (int i = n + 1 >> 1; i >= 1; --i) {
      auto count = counts[i];
      for (int j = 0; j < C; ++j) {
        count[j] -= counts[i - 1][j];
      }
      int left = i - 1, right = n - i;
      for (int j = left; j < right; ++j) {
        count[s[j]]--;
      }
      while (!count[s[right]]) {
        s[right]++;
      }
    }
  }
  std::string buf(n, ' ');
  for (int i = 0; i < n; ++i) {
    buf[i] = 'a' + s[i];
  }
  // fprintf(stderr, "%s\n", buf.c_str());
  return buf;
}

int main() {
  IO io;
  io.out(solve(io));
}