#include <bits/stdc++.h>

const int MOD = 998244353;

void add(int &x, int a) {
  x += a;
  if (x >= MOD) {
    x -= MOD;
  }
}

struct Alt {
  Alt(int n) : cntcnt(), cnt(n), two(n + 1) {
    cntcnt[2] = n;
    two[0] = 1;
    for (int i = 1; i <= n; ++i) {
      two[i] = two[i - 1] + two[i - 1];
      if (two[i] >= MOD) {
        two[i] -= MOD;
      }
    }
  }

  void update(int x, int y, int prec, int c) {
    cntcnt[!cnt[x][0] + !cnt[x][1]]--;
    if (~prec) {
      cnt[x][(y & 1) ^ prec]--;
    }
    if (~c) {
      cnt[x][(y & 1) ^ c]++;
    }
    cntcnt[!cnt[x][0] + !cnt[x][1]]++;
  }

  int ways() const { return cntcnt[0] ? 0 : two[cntcnt[2]]; }

  std::array<int, 3> cntcnt;
  std::vector<std::array<int, 2>> cnt;
  std::vector<int> two;
};

int main() {
  int n, m, q;
  scanf("%d%d%d", &n, &m, &q);
  Alt row(n), col(m);
  int alt[]{0, 0};
  std::map<std::pair<int, int>, int> cmap;
  while (q--) {
    int x, y, c;
    scanf("%d%d%d", &x, &y, &c);
    x--;
    y--;
    auto [iterator, emplaced] = cmap.emplace(std::make_pair(x, y), c);
    int prec;
    if (emplaced) {
      prec = -1;
    } else {
      prec = iterator->second;
      iterator->second = c;
    }
    row.update(x, y, prec, c);
    col.update(y, x, prec, c);
    if (~prec) {
      alt[((x + y) & 1) ^ prec]--;
    }
    if (~c) {
      alt[((x + y) & 1) ^ c]++;
    }
    int result = row.ways();
    add(result, col.ways());
    if (!alt[0]) {
      add(result, MOD - 1);
    }
    if (!alt[1]) {
      add(result, MOD - 1);
    }
    printf("%d\n", result);
  }
}