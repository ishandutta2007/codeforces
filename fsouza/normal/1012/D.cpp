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

struct seq_t {
  int n = 0;
  char c;
  bool operator<(const seq_t &o) const {
    if (n != o.n) return n < o.n;
    return c < o.c;
  }
};

struct state_t {
  seq_t a, b;
  bool operator<(const state_t &o) const {
    if (a < o.a || o.a < a) return a < o.a;
    return b < o.b;
  }
  bool operator==(const state_t &o) const {
    return !(*this < o || o < *this);
  }
};

struct run_t {
  int n;
  char c;
};

const int threshold = 7;

string read_string() {
  char *str;
  scanf("%ms", &str);
  string result(str);
  free(str);
  return result;
}

deque<run_t> read() {
  string str = read_string();
  deque<run_t> result;
  for (char c : str) {
    if (!result.empty() && result.back().c == c) ++result.back().n;
    else result.push_back({1, c});
  }
  return result;
}

seq_t join(const seq_t &a, const seq_t &b) {
  if (a.n == 0) return b;
  if (b.n == 0) return a;
  int n2 = a.n + b.n;
  char last_a = (a.n % 2 == 1) ? a.c : ('a' + ((a.c - 'a') ^ 1));
  if (last_a == b.c) --n2;
  return {n2, a.c};
}

void split(const seq_t &seq, int psize, seq_t &prefix, seq_t &suffix) {
  prefix = {psize, seq.c};
  suffix = {seq.n - psize,
            (char)((psize % 2 == 0) ? seq.c : ('a' + ((seq.c - 'a') ^ 1)))};
}

state_t next_state(const state_t &state, const pair<int, int> &op) {
  seq_t pa, sa, pb, sb;
  split(state.a, op.first, pa, sa);
  split(state.b, op.second, pb, sb);
  return {join(pb, sa), join(pa, sb)};
}

int main() {
  deque<run_t> a = read(), b = read();
  state_t start{{(int)a.size(), a[0].c}, {(int)b.size(), b[0].c}};

  queue<state_t> q;
  map<state_t, pair<state_t, pair<int, int>>> visited;
  q.push(start);
  visited[start] = {{}, {-1, -1}};

  state_t last_st;

  while (!q.empty()) {
    state_t st = q.front();
    q.pop();

    static vector<pair<int, int>> ops;
    ops.clear();

    if (st.a.n == 1 && st.b.n == 1) {
      last_st = st;
      break;
    }

    if (st.a.n >= threshold && st.b.n >= threshold) {
      pair<int, int> op;
      if (st.a.c != st.b.c) {
        if (st.a.n >= st.b.n) op = {3, 1};
        else op = {1, 3};
      } else {
        if (st.a.n >= st.b.n) op = {2, 1};
        else op = {1, 2};
      }
      ops.push_back(op);
    } else if (st.a.n >= threshold) {
      for (int na = st.a.n / 2 - 1; na <= st.a.n / 2; ++na)
        for (int nb = 0; nb <= st.b.n; ++nb)
          ops.emplace_back(na, nb);
    } else if (st.b.n >= threshold) {
      for (int na = 0; na <= st.a.n; ++na)
        for (int nb = st.b.n / 2 - 1; nb <= st.b.n / 2; ++nb)
          ops.emplace_back(na, nb);
    } else {
      for (int na = 0; na <= st.a.n; ++na)
        for (int nb = 0; nb <= st.b.n; ++nb)
          ops.emplace_back(na, nb);
    }

    for (const pair<int, int> &op : ops) {
      state_t next = next_state(st, op);
      if (visited.insert({next, {st, op}}).second) {
        q.push(next);
      }
    }
  }
  assert(last_st.a.n == 1 && last_st.b.n == 1);

  vector<pair<int, int>> ops;
  for (state_t st = last_st; !(st == start); st = visited[st].first)
    ops.push_back(visited[st].second);
  reverse(ops.begin(), ops.end());

  vector<pair<int, int>> result;
  for (pair<int, int> op : ops) {
    int na, nb;
    tie(na, nb) = op;

    auto split = [](deque<run_t> &seq, int n, deque<run_t> &pref) {
      pref.assign(seq.begin(), seq.begin() + n);
      seq.erase(seq.begin(), seq.begin() + n);
      int sum = 0;
      for (const run_t &run : pref) sum += run.n;
      return sum;
    };

    auto join = [](deque<run_t> &seq, deque<run_t> &pref) {
      if (!seq.empty() && !pref.empty() && seq.front().c == pref.back().c) {
        seq.front().n += pref.back().n;
        pref.pop_back();
      }
      seq.insert(seq.begin(), pref.begin(), pref.end());
    };

    deque<run_t> pa, pb;
    int size_a = split(a, na, pa);
    int size_b = split(b, nb, pb);
    join(a, pb);
    join(b, pa);
    result.emplace_back(size_a, size_b);
  }

  printf("%d\n", (int)result.size());
  for (const pair<int, int> &op : result)
    printf("%d %d\n", op.first, op.second);

  return 0;
}