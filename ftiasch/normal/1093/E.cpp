#line 1 "sol.cpp"
#include <bits/stdc++.h>

const int N = 200'000;
const int M = N + 4 * N;

struct Op {
  int id, x, yl, yr;
};

int n, m, inv_a[N], b[N], result[N];
Op op[M];

bool by_x(int i, int j) {
  if (op[i].x != op[j].x) {
    return op[i].x > op[j].x;
  }
  return op[i].id < op[j].id;
}

std::vector<int> events;

int fenwick_clock;
std::pair<int, int> fenwick[N];

void add(int y, int delta) {
  for (; ~y; y -= ~y & y + 1) {
    if (fenwick[y].first != fenwick_clock) {
      fenwick[y] = {fenwick_clock, 0};
    }
    fenwick[y].second += delta;
  }
}

int ask(int y) {
  int result = 0;
  for (; y < n; y += ~y & y + 1) {
    result += fenwick[y].first == fenwick_clock ? fenwick[y].second : 0;
  }
  return result;
}

void work(int l, int r) {
  if (l + 1 < r) {
    int m = (l + r) >> 1;

    events.clear();

    for (int i = m; i < r; ++i) {
      if (~op[i].id) {
        events.push_back(i);
      }
    }

    if (!events.empty()) {
      for (int i = l; i < m; ++i) {
        if (!~op[i].id) {
          events.push_back(i);
        }
      }

      std::sort(events.begin(), events.end(), by_x);

      fenwick_clock++;

      for (int op_id : events) {
        const Op &o = op[op_id];
        if (~o.id) {
          int count = ask(o.yl) - ask(o.yr);
          if (o.id & 1) {
            result[o.id >> 1] -= count;
          } else {
            result[o.id >> 1] += count;
          }
        } else {
          add(o.yl, o.yr);
        }
      }
    }

    work(l, m);
    work(m, r);
  }
}

int main() {
  int q;
  scanf("%d%d", &n, &q);
  for (int i = 0, a; i < n; ++i) {
    scanf("%d", &a);
    inv_a[a - 1] = i;
  }
  for (int i = 0; i < n; ++i) {
    scanf("%d", &b[i]);
    b[i]--;
    op[m++] = {-1, inv_a[b[i]], i, 1};
  }
  int queries = 0;
  for (int i = 0; i < q; ++i) {
    int code;
    scanf("%d", &code);
    if (code == 1) {
      int la, ra, lb, rb;
      scanf("%d%d%d%d", &la, &ra, &lb, &rb);
      la--;
      lb--;
      op[m++] = {queries++, la, lb, rb};
      op[m++] = {queries++, ra, lb, rb};
    } else {
      int x, y;
      scanf("%d%d", &x, &y);
      x--;
      y--;
      op[m++] = {-1, inv_a[b[x]], x, -1};
      op[m++] = {-1, inv_a[b[y]], y, -1};
      std::swap(b[x], b[y]);
      op[m++] = {-1, inv_a[b[x]], x, 1};
      op[m++] = {-1, inv_a[b[y]], y, 1};
    }
  }
  work(0, m);
  for (int i = 0; i < queries >> 1; ++i) {
    printf("%d\n", result[i]);
  }
}