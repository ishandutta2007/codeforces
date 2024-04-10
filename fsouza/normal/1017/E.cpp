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
typedef complex<lint> point_t;

template<typename T>
struct kmp_t {
  vector<T> word;
  vector<int> failure;
  kmp_t(const vector<T> &_word): word(_word) {
    int n = word.size();
    failure.resize(n + 1, 0);
    for (int s = 2; s <= n; ++s) {
      failure[s] = failure[s - 1];
      while (failure[s] > 0 && word[failure[s]] != word[s - 1])
        failure[s] = failure[failure[s]];
      if (word[failure[s]] == word[s - 1])
        failure[s] += 1;
    }
  }
  vector<int> matches_in(const vector<T> &text) {
    vector<int> result;
    int s = 0;
    for (int i = 0; i < (int)text.size(); ++i) {
      while (s > 0 && word[s] != text[i])
        s = failure[s];
      if (word[s] == text[i])
        s += 1;
      if (s == (int)word.size()) {
        result.push_back(i - (int)word.size() + 1);
        s = failure[s];
      }
    }
    return result;
  }
};

lint dot(const point_t &a, const point_t &b) {
  return a.real() * b.real() + a.imag() * b.imag();
}

lint cross(const point_t &a, const point_t &b) {
  return a.real() * b.imag() - a.imag() * b.real();
}

lint cross(const point_t &a, const point_t &b, const point_t &c) {
  return cross(b - a, c - a);
}

vector<point_t> convex_hull(vector<point_t> points) {
  sort(points.begin(), points.end(),
       [](const point_t &lhs, const point_t &rhs) {
         if (lhs.real() != rhs.real()) return lhs.real() < rhs.real();
         return lhs.imag() < rhs.imag();
       });

  vector<point_t> upper;
  for (const point_t &p : points) {
    while ((int)upper.size() >= 2 &&
           cross(p, upper.end()[-1], upper.end()[-2]) <= 0LL) {
      upper.pop_back();
    }
    upper.push_back(p);
  }

  vector<point_t> lower;
  reverse(points.begin(), points.end());
  for (const point_t &p : points) {
    while ((int)lower.size() >= 2 &&
           cross(p, lower.end()[-1], lower.end()[-2]) <= 0LL) {
      lower.pop_back();
    }
    lower.push_back(p);
  }

  if ((int)lower.size() > 2)
    upper.insert(upper.end(), lower.begin() + 1, lower.end() - 1);
  return upper;
}

vector<pair<lint, lint>> get_seq(int n) {
  vector<point_t> points(n);
  for (int i = 0; i < n; ++i) {
    int x, y;
    scanf("%d %d", &x, &y);
    points[i] = point_t(x, y);
  }

  vector<point_t> chull = convex_hull(points);
  if (chull.size() <= 1) return {};

  vector<pair<lint, lint>> result;
  for (int i = 0; i < (int)chull.size(); ++i) {
    int pi = i - 1;
    if (pi == -1) pi = (int)chull.size() - 1;
    int ni = i + 1;
    if (ni == (int)chull.size()) ni = 0;

    result.emplace_back(norm(chull[ni] - chull[i]),
                        dot(chull[ni] - chull[i], chull[pi] - chull[i]));
  }
  return result;
}

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  vector<pair<lint, lint>> seq1 = get_seq(n);
  vector<pair<lint, lint>> seq2 = get_seq(m);

  kmp_t<pair<lint, lint>> kmp(seq1);
  seq2.insert(seq2.end(), seq2.begin(), seq2.end());
  if ((int)seq1.size() == (int)seq2.size() / 2 &&
      !kmp.matches_in(seq2).empty()) {
    printf("Yes\n");
  } else {
    printf("No\n");
  }

  return 0;
}